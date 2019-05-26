#pragma once

#include <Windows.h>
#include <Psapi.h>
#include <TlHelp32.h>

#include <unordered_map>

#include <ck/HM3DebugConsole.h>

#ifndef HM3_PROCESS_NAME
#	define HM3_PROCESS_NAME "HitmanBloodMoney.exe"
#endif

struct ModuleInfo_t
{
	DWORD baseAddr = 0;
	DWORD size = 0;

	ModuleInfo_t() = default;
	ModuleInfo_t(DWORD b, DWORD s) : baseAddr(b), size(s) {}

	static ModuleInfo_t GetModule(DWORD targetPid, const char* moduleName);
};

struct ProcessHandleCacheController
{
	struct ProcessCacheRow
	{
		HANDLE handle = nullptr;
		DWORD  pid = 0;

		ProcessCacheRow() = default;
		ProcessCacheRow(HANDLE pHandle, DWORD procId)
			: handle(pHandle)
			, pid(procId)
		{
		}
	};

	static std::unordered_map<std::string, ProcessCacheRow> g_ProcCache;

	static ProcessCacheRow getProcessHandle(const std::string& procName);
};