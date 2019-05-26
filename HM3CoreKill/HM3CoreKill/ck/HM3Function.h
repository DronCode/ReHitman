#pragma once

#include <Windows.h>

#include <string>
#include <vector>
#include <unordered_map>

#include <ck/HM3ProcessCache.h>

#include <x86/X86Arch.h>
#include <x86/X86MemTools.h>
#include <x86/X86MemAccessEngine.h>
/*
									   ________  __    __  ________         ______   _______   ________
									  /        |/  |  /  |/        |       /      \ /       \ /        |
									  $$$$$$$$/ $$ |  $$ |$$$$$$$$/       /$$$$$$  |$$$$$$$  |$$$$$$$$/
										 $$ |   $$ |__$$ |$$ |__          $$ |__$$ |$$ |__$$ |   $$ |
										 $$ |   $$    $$ |$$    |         $$    $$ |$$    $$<    $$ |
										 $$ |   $$$$$$$$ |$$$$$/          $$$$$$$$ |$$$$$$$  |   $$ |
										 $$ |   $$ |  $$ |$$ |_____       $$ |  $$ |$$ |  $$ |   $$ |
										 $$ |   $$ |  $$ |$$       |      $$ |  $$ |$$ |  $$ |   $$ |
										 $$/    $$/   $$/ $$$$$$$$/       $$/   $$/ $$/   $$/    $$/



		  ______   ________        ________  _______    ______   __       __  _______    ______   __        ______  __    __  ________
		 /      \ /        |      /        |/       \  /      \ /  \     /  |/       \  /      \ /  |      /      |/  \  /  |/        |
		/$$$$$$  |$$$$$$$$/       $$$$$$$$/ $$$$$$$  |/$$$$$$  |$$  \   /$$ |$$$$$$$  |/$$$$$$  |$$ |      $$$$$$/ $$  \ $$ |$$$$$$$$/
		$$ |  $$ |$$ |__             $$ |   $$ |__$$ |$$ |__$$ |$$$  \ /$$$ |$$ |__$$ |$$ |  $$ |$$ |        $$ |  $$$  \$$ |$$ |__
		$$ |  $$ |$$    |            $$ |   $$    $$< $$    $$ |$$$$  /$$$$ |$$    $$/ $$ |  $$ |$$ |        $$ |  $$$$  $$ |$$    |
		$$ |  $$ |$$$$$/             $$ |   $$$$$$$  |$$$$$$$$ |$$ $$ $$/$$ |$$$$$$$/  $$ |  $$ |$$ |        $$ |  $$ $$ $$ |$$$$$/
		$$ \__$$ |$$ |               $$ |   $$ |  $$ |$$ |  $$ |$$ |$$$/ $$ |$$ |      $$ \__$$ |$$ |_____  _$$ |_ $$ |$$$$ |$$ |_____
		$$    $$/ $$ |               $$ |   $$ |  $$ |$$ |  $$ |$$ | $/  $$ |$$ |      $$    $$/ $$       |/ $$   |$$ | $$$ |$$       |
		 $$$$$$/  $$/                $$/    $$/   $$/ $$/   $$/ $$/      $$/ $$/        $$$$$$/  $$$$$$$$/ $$$$$$/ $$/   $$/ $$$$$$$$/

																	+--------------+
																	| OUR FUNCTION |
																	+--------------+
																			|
						   +----< 1) NOP & JMP >---------+			   [ 2) CALL ]*
						   |							 |                  |
			+---------+-------------+-------+   	+---------------+--------------+---------------+
			| PROGRAM | TARGET CODE | OTHER |		| ORIGINAL CODE | CALL TO HOOK |   JUMP BACK   |
			+---------+-------------+-------+		+---------------+--------------+---------------+
										|												|
										+-------------------< JUMP + 5 >----------------+
		*/

class HM3Function
{
	// for comparing a region in memory, needed in finding a signature
	static bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask)
	{
		for (; *szMask; ++szMask, ++bData, ++bMask) {
			if (*szMask == 'x' && *bData != *bMask) {
				return false;
			}
		}
		return (*szMask == NULL);
	}

	static DWORD FindSignature(HANDLE targetProc, DWORD start, DWORD size, const char* sig, const char* mask)
	{
		BYTE* data = new BYTE[size];
		SIZE_T bytesRead;

		ReadProcessMemory(targetProc, (LPVOID)start, data, size, &bytesRead);

		for (DWORD i = 0; i < size; i++)
		{
			if (MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask)) {
				return start + i;
			}
		}
		delete[] data;
		return NULL;
	}
public:
	template <typename Functor> 
	static DWORD findFunction(const std::string& process, const std::string& pattern, const std::string& mask)
	{
		/// Find function
		ProcessHandleCacheController::ProcessCacheRow procInfo = ProcessHandleCacheController::getProcessHandle(process);
		ModuleInfo_t mod = ModuleInfo_t::GetModule(procInfo.pid, process.c_str());

		HANDLE pHandle = procInfo.handle;

		HM3_ASSERT(pHandle != 0, "Unable to find target process!");

		DWORD codeAddr = FindSignature(pHandle, mod.baseAddr, mod.size, pattern.c_str(), mask.c_str());
		if (!codeAddr)
		{
#ifdef HM3_TRACE_HOOKS
			HM3_DEBUG("Pattern not found!\n");
#endif
			return 0x0;
		}

		return codeAddr;
	}

	template <typename Functor, int GrabBytes = 5>
	static void hookFunction(
		const std::string& process,
		DWORD addr,
		DWORD destCall,
		const std::vector<uint8_t>& preCode = {},
		const std::vector<uint8_t>& postCode = {}
	)
	{
		static_assert(GrabBytes >= 5, "GrabBytes must be grater or equal than 5 (x86 near jmp)");

		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");

		/**
		 *	-------------------< TRAMPOLINE FACTORY >-------------------
		 **/
		 // VARS
		x86::X86NearCallCommit_t		hookCall;
		x86::X86NearJumpCommit_t		jumpToCaller;
		x86::X86NearJumpCommit_t		jumpToTrampoline;
		//								SRC				   CALL THE HOOK					  EXT PATCH		             JUMP BACK						
		const size_t trampolineSize =
			GrabBytes +																/// Trampoline source size
			preCode.size() +														/// Code before hook call size
			sizeof(hookCall) +														/// Call to hook size
			postCode.size() +														/// Code after hook size
			sizeof(jumpToCaller);													/// Jump back code size
		uint8_t* trampoline = (uint8_t*)malloc(sizeof(uint8_t) * trampolineSize);

		memset((void*)trampoline, x86::instructions::NOP, trampolineSize);

		DWORD trampolineAddr = x86::X86MemAccessEngine::getInstance().AllocateExecutableMemory(trampolineSize);
		//DWORD trampolineAddr = (DWORD)VirtualAlloc(nullptr, trampolineSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		HM3_DEBUG("Trampoline allocated at : 0x%.8X\n", trampolineAddr);

		// 1. Read original code [OK]
		{
			DWORD readyBytes = 0x0;
			ReadProcessMemory(pHandle, (LPCVOID)addr, (LPVOID)trampoline, GrabBytes, &readyBytes);
			HM3_ASSERT(readyBytes == GrabBytes, "Not enough bytes of trampoline source code!");
		}
		// 2. Store pre-code [OK]
		{
			memcpy(
				(void*)(trampoline + GrabBytes),
				(void*)preCode.data(),
				preCode.size()
			);
		}
		// 3. Write CALL to hook commit [OK]
		{
			hookCall.JMP_TO = x86::calculateOffset((uint32_t)destCall, trampolineAddr + GrabBytes + preCode.size());

			memcpy(
				(void*)(trampoline + GrabBytes + preCode.size()),
				(void*)& hookCall,
				sizeof(hookCall)
			);
		}
		// 4. Write additional code after call to hook  [OK]
		{
			memcpy(
				(void*)(trampoline + GrabBytes + preCode.size() + sizeof(hookCall)),
				(void*)postCode.data(),
				postCode.size()
			);
		}
		// 5. Write JMP back to caller  [OK]
		{
			jumpToCaller.JMP_TO = x86::calculateOffset(
				addr + sizeof(jumpToTrampoline),
				(uint32_t)(trampolineAddr + GrabBytes + preCode.size() + sizeof(hookCall) + postCode.size())
			);

			memcpy(
				(void*)(trampoline + GrabBytes + preCode.size() + sizeof(hookCall) + postCode.size()),
				(void*)& jumpToCaller,
				sizeof(jumpToCaller)
			);
		}
		// 6. Override original code  [OK]
		{
			uint8_t originalCodeJumpBuffer[GrabBytes];
			memset((void*)originalCodeJumpBuffer, x86::instructions::NOP, GrabBytes);

			jumpToTrampoline.JMP_TO = x86::calculateOffset((uint32_t)trampolineAddr, addr);

			memcpy((void*)originalCodeJumpBuffer, (void*)& jumpToTrampoline, sizeof(jumpToTrampoline));
			HM3_PRINT_BUFFER("New original code: ", originalCodeJumpBuffer);

			DWORD writtenOfJump = 0x0;
			WriteProcessMemory(
				pHandle,
				(LPVOID)addr,
				(LPCVOID)originalCodeJumpBuffer,
				GrabBytes,
				&writtenOfJump);
			HM3_ASSERT(writtenOfJump == GrabBytes, "Not enough bytes of jump to trampoline");
		}
		// 7. Write trampoline to allocated space  [OK]
		{
			DWORD writtenOfTrampoline;
			WriteProcessMemory(pHandle, (LPVOID)trampolineAddr, (LPCVOID)trampoline, trampolineSize, &writtenOfTrampoline);
			HM3_ASSERT(writtenOfTrampoline == trampolineSize, "Not enough bytes of trampoline was written!");
		}
		// Done
		HM3_PRINT_BUFFER_PTR("Trampoline code: ", trampoline, trampolineSize);
		HM3_DEBUG("Hook ready!\n");
		// Free buffer
		free(trampoline);
	}

	template <typename Functor, int GrabBytes = 5>
	static void hookFunction(
		const std::string& process, 
		const std::string& pattern, 
		const std::string& mask, 
		DWORD destCall,
		const std::vector<uint8_t>& preCode = {},
		const std::vector<uint8_t>& postCode = {}
	) {
		static_assert(GrabBytes >= 5, "GrabBytes must be grater or equal than 5 (x86 near jmp)");
		
		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate target process!");
		
		DWORD codeAddr = findFunction<Functor>(process, pattern, mask);
		if (!codeAddr)
		{
			return;
		}

#ifdef HM3_TRACE_HOOKS
		uint8_t orgCode[GrabBytes];

		ReadProcessMemory(pHandle, (LPCVOID)codeAddr, (LPVOID)orgCode, GrabBytes, nullptr);
		
		HM3_DEBUG(		 "Pattern was found at at : 0x%.8X\n", codeAddr);
		HM3_PRINT_BUFFER("Original code           : ", orgCode);
#endif

		hookFunction<Functor, GrabBytes>(HM3_PROCESS_NAME, codeAddr, destCall, preCode, postCode);
	}

	static void overrideInstruction(const std::string& process, DWORD addr, const std::vector<uint8_t>& newCode)
	{
		HM3_ASSERT(!newCode.empty(), "Code must be not empty!");

		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate target process!");

		DWORD writtenBytes;
		WriteProcessMemory(pHandle, (LPVOID)addr, (LPCVOID)(newCode.data()), newCode.size(), &writtenBytes);
		HM3_ASSERT(writtenBytes == newCode.size(), "Unable to write new code!");

		HM3_DEBUG("Override at 0x%.8X done!\n", addr);
	}

	//------------------------------
	template <typename Functor>
	static void proxyHook(
		const std::string & process,
		DWORD addr,
		DWORD destCall
	)
	{
		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");

		x86::X86NearCallCommit_t commit;
		commit.JMP_TO = x86::calculateOffset(destCall, addr, sizeof(commit));

		DWORD writtenOfCommit;
		WriteProcessMemory(pHandle, (LPVOID)addr, (LPCVOID)& commit, sizeof(commit), &writtenOfCommit);
		HM3_ASSERT(writtenOfCommit == sizeof(commit), "Commit and written bytes must be equal!");

		HM3_DEBUG("[ProxyHook] Hook was installed at 0x%.8X\n", addr);
	}

	template <int chunkSize>
	static void moveInstructions(const std::string& process, DWORD from, DWORD to)
	{
		static_assert(chunkSize > 0, "Chunk size must be greater than 0!");

		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");

		uint8_t originalCode[chunkSize];
		DWORD readyBytes, writtenBytes;

		ReadProcessMemory(pHandle, (LPCVOID)from, (LPVOID)originalCode, chunkSize, &readyBytes);
		HM3_ASSERT(readyBytes == chunkSize, "Count of ready bytes must be equal to count of required bytes");

		WriteProcessMemory(pHandle, (LPVOID)to, (LPCVOID)originalCode, chunkSize, &writtenBytes);
		HM3_ASSERT(writtenBytes == chunkSize, "Count of written to new place bytes must be equal to count of required bytes");
	}

	static void hookVFTable(const std::string& process, DWORD instance, DWORD index, DWORD newAddr)
	{
		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");
		DWORD vftbl;
		DWORD readyVFTBLBYTES;
		DWORD readyFuncAddrBytes;
		DWORD oldProtection;
		DWORD originalFuncAddr;
		DWORD writtenBytesOfAddr;

		ReadProcessMemory(pHandle, (LPCVOID)instance, (LPVOID)& vftbl, sizeof(DWORD), &readyVFTBLBYTES);
		HM3_ASSERT(readyVFTBLBYTES == sizeof(DWORD), "Unable to read vftable");

		DWORD hookAt = vftbl + index * sizeof(DWORD);
		VirtualProtect((LPVOID)hookAt, sizeof(DWORD), PAGE_READWRITE, &oldProtection);

		ReadProcessMemory(pHandle, (LPCVOID)hookAt, (LPVOID)& originalFuncAddr, sizeof(DWORD), &readyFuncAddrBytes);
		HM3_ASSERT(readyFuncAddrBytes == sizeof(DWORD), "Unable to read original address");

		WriteProcessMemory(pHandle, (LPVOID)hookAt, (LPCVOID)& newAddr, sizeof(DWORD), &writtenBytesOfAddr);
		HM3_ASSERT(writtenBytesOfAddr == sizeof(DWORD), "Unable to replace function addr");

		VirtualProtect((LPVOID)hookAt, sizeof(DWORD), oldProtection, nullptr);

		HM3_DEBUG(
			"hookVFTable| Replace func #%d for instance 0x%.8X with new func addr 0x%.8X (old is 0x%.8X)\n", 
			index, 
			instance, 
			newAddr, 
			originalFuncAddr);
	}
};