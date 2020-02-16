#pragma once

#include <Windows.h>

#include <string>
#include <vector>
#include <type_traits>
#include <unordered_map>

#include <ck/HM3ProcessCache.h>

#include <utils/X86Arch.h>
#include <utils/X86MemTools.h>
#include <utils/X86MemAccessEngine.h>
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

#define GET_MEMBER_BY_OFFSET(base, offset) ((DWORD*)((char*)base + offset))

namespace vtable_hook {
	static int vtablehook_unprotect(void* region) {
#ifdef WIN32
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery((LPCVOID)region, &mbi, sizeof(mbi));
		VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect);
		return mbi.Protect;
#elif __linux__
		mprotect((void*)((intptr_t)region & vtablehook_pagemask), vtablehook_pagesize, PROT_READ | PROT_WRITE | PROT_EXEC);
		return PROT_READ | PROT_EXEC;
#endif
	}

	static void vtablehook_protect(void* region, int protection) {
#ifdef WIN32
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery((LPCVOID)region, &mbi, sizeof(mbi));
		VirtualProtect(mbi.BaseAddress, mbi.RegionSize, protection, &mbi.Protect);
#elif __linux__
		mprotect((void*)((intptr_t)region & vtablehook_pagemask), vtablehook_pagesize, protection);
#endif
	}
}

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

	static DWORD getVirtualFunctionAddress(DWORD instance, DWORD vftableOffset)
	{
		std::intptr_t vftable_ptr = *reinterpret_cast<std::intptr_t*>(instance);
		std::intptr_t entity = vftable_ptr + vftableOffset;
		std::intptr_t original_func = *reinterpret_cast<std::intptr_t*>(entity);
		return original_func;
	}

	static DWORD hookVFTable(DWORD instance, DWORD index, DWORD newAddr, bool doLog = true)
	{
		std::intptr_t vftable_ptr = *reinterpret_cast<std::intptr_t*>(instance);
		std::intptr_t entity = vftable_ptr + sizeof(std::intptr_t) * index;
		std::intptr_t original_func = *reinterpret_cast<std::intptr_t*>(entity);

		int original_protection = vtable_hook::vtablehook_unprotect((void*)entity);
		*reinterpret_cast<std::intptr_t*>(entity) = static_cast<std::intptr_t>(newAddr);
		vtable_hook::vtablehook_protect((void*)entity, original_protection);

		if (doLog)
			HM3_DEBUG(" Override function #%.3d of instance 0x%.8X replace member at 0x%.8X by 0x%.8X\n", index, instance, original_func, newAddr);
		
		return static_cast<DWORD>(original_func);
	}

	static DWORD hookIAT(const std::string& process, const char* functionName, DWORD to)
	{
		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");

		/*
			Credits : Game Hacking: Developing Autonomous Bots for Online Games
		*/

		const DWORD DOSMagic = 0x5A4D;
		const DWORD OptionalHeaderMagicBytes = 0x10B;

		DWORD baseAddr = reinterpret_cast<DWORD>(cacheRow.handle);

		auto dosHeader = (IMAGE_DOS_HEADER*)(baseAddr);
		if (dosHeader->e_magic != DOSMagic)
		{
			HM3_DEBUG(" Failed to hook IAT method \"%s\". Bad DOS header magic bytes.\n", functionName);
			return 0;
		}

		auto optHeader = (IMAGE_OPTIONAL_HEADER*)(baseAddr + dosHeader->e_lfanew + 24);
		if (optHeader->Magic != OptionalHeaderMagicBytes)
		{
			HM3_DEBUG(" Failed to hook IAT method \"%s\". Bad optional header magic bytes.\n", functionName);
			return 0;
		}

		auto IAT = optHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
		if (IAT.Size == 0 || IAT.VirtualAddress == 0)
		{
			HM3_DEBUG(" Failed to hook IAT method \"%s\". Bad IAT table size.\n", functionName);
			return 0;
		}

		auto impDesc = (IMAGE_IMPORT_DESCRIPTOR*)(baseAddr + IAT.VirtualAddress);

		while (impDesc->FirstThunk)
		{
			auto thunkData = (IMAGE_THUNK_DATA*)(baseAddr + impDesc->OriginalFirstThunk);
			
			int n = 0;

			while (thunkData->u1.Function)
			{
				char* importFuncName = (char*)(baseAddr + (DWORD)thunkData->u1.AddressOfData + 2);

				if (strcmp(importFuncName, functionName) == 0)
				{
					auto vfTable = (DWORD*)(baseAddr + impDesc->FirstThunk);
					DWORD original = vfTable[n];
					int originalProtection = vtable_hook::vtablehook_unprotect(&vfTable[n]);
					vfTable[n] = to;
					vtable_hook::vtablehook_protect(&vfTable[n], originalProtection);	
					HM3_DEBUG(" Hook IAT method \"%s\" 0x%.8X -> 0x%.8X DONE\n", functionName, original, to);
					return original;
				}
			}
		}

		HM3_DEBUG(" Failed to hook IAT method \"%s\". Function not found in IAT table of process %s\n", functionName, process);
		return 0;
	}

	static bool dumpVirtualTableOfInstance(DWORD instance, DWORD functionsCount, const char* outputFile, const char* className)
	{
		FILE* fp = fopen(outputFile, "w+");
		if (!fp)
			return false;

		DWORD totalFunctions = functionsCount * 4;

		fprintf(fp, "class %s {\npublic:\n", className);

		for (DWORD funcIndex = 0; funcIndex <= totalFunctions; funcIndex += 4)
		{
			DWORD funcAddr = HM3Function::getVirtualFunctionAddress(instance, funcIndex);
			fprintf(fp, "\tvirtual void Function_%.2d(); //+0x%.X | sub_%.8X\n", (funcIndex == 0 ? 0 : (funcIndex / 4)), funcIndex, funcAddr);
		}

		fprintf(fp, "};");

		fclose(fp);
	}

	static void swapInstructions(const std::string& process, DWORD first, DWORD second, const DWORD count)
	{
		ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(process);
		HANDLE pHandle = cacheRow.handle;
		HM3_ASSERT(pHandle != 0, "Unable to locate required process!");

		uint8_t* buff0 = (uint8_t*)calloc(1, sizeof(uint8_t) * count);
		uint8_t* buff1 = (uint8_t*)calloc(1, sizeof(uint8_t) * count);

		DWORD firstReady, secondReady;

		ReadProcessMemory(pHandle, (LPVOID)first, (LPVOID)buff0, count, &firstReady);
		HM3_ASSERT(firstReady == count, "Not all bytes ready to swap [B0]");

		ReadProcessMemory(pHandle, (LPVOID)second, (LPVOID)buff1, count, &secondReady);
		HM3_ASSERT(secondReady == count, "Not all bytes ready to swap [B1]");

		WriteProcessMemory(pHandle, (LPVOID)first, (LPCVOID)buff1, count, &firstReady);
		HM3_ASSERT(firstReady == count, "Not all bytes written [B0]");

		WriteProcessMemory(pHandle, (LPVOID)second, (LPCVOID)buff0, count, &secondReady);
		HM3_ASSERT(secondReady == count, "Not all bytes written [B1]");
	}
};

template <typename TClass>
struct HM3MemberFunction
{
	static void pureCall(TClass* instance, std::intptr_t index)
	{
		__asm {
			pushad
			pushfd
			mov ecx, instance	//Place pointer to this
		}

		const std::intptr_t funcPtr = *(*((std::intptr_t**)instance) + index);	//extract pointer to function from vftable
		HM3_DEBUG("HM3MemberFunction<TClass>::pureCall| funcPtr at 0x%.8X\n", funcPtr);
		
		__asm call funcPtr	//call the function (args not presented)

		__asm {
			popfd
			popad
		}
	}

	template <typename TArg0>
	static void pureCall1(TClass* instance, std::intptr_t index, TArg0 arg0)
	{
		__asm {
			pushad
			pushfd
			mov ecx, instance	//Place pointer to this

			push arg0
		}

		const std::intptr_t funcPtr = *(*((std::intptr_t**)instance) + index);	//extract pointer to function from vftable

		__asm {
			call funcPtr
			popfd
			popad
		}
	}

	template <typename TRet>
	static TRet callGetter(TClass* instance, std::intptr_t index)
	{
		std::intptr_t result;

		__asm {
			pushad
			pushfd
			mov ecx, instance	//Place pointer to this
		}

		const std::intptr_t funcPtr = *(*((std::intptr_t * *)instance) + index);	//extract pointer to function from vftable

		__asm {
			call funcPtr
			mov result, eax

			popfd
			popad
		}

		return (TRet)result;
	}
};