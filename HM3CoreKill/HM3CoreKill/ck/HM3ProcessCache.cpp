#include <ck/HM3ProcessCache.h>

std::unordered_map<
	std::string,
	ProcessHandleCacheController::ProcessCacheRow
> ProcessHandleCacheController::g_ProcCache = {};

static HANDLE GetProcess(const char* processName, DWORD& pid)
{
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(entry);

	do
	{
		if (!strcmp(entry.szExeFile, processName)) {
			pid = entry.th32ProcessID;
			CloseHandle(handle);
			return OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		}
	} while (Process32Next(handle, &entry));

	return nullptr;
}

// For getting information about the executing module
ModuleInfo_t ModuleInfo_t::GetModule(DWORD targetPid, const char* moduleName)
{
	ModuleInfo_t result;

	HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, targetPid);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);

	do {
		if (!strcmp(mEntry.szModule, (LPSTR)moduleName)) {
			CloseHandle(hmodule);

			result = ModuleInfo_t((DWORD)mEntry.hModule, mEntry.modBaseSize);
			return result;
		}
	} while (Module32Next(hmodule, &mEntry));

	return result;
}

ProcessHandleCacheController::ProcessCacheRow ProcessHandleCacheController::getProcessHandle(const std::string& procName)
{
	auto iter = g_ProcCache.find(procName);
	const bool hasValue(iter != std::end(g_ProcCache));

	if (!hasValue)
	{
		HM3_DEBUG("ProcessHandleCacheController: process '%s' not found in cache. Try to find & save it\n", procName.c_str());

		DWORD pid;
		HANDLE pHandle = GetProcess(procName.c_str(), pid);

		if (!pHandle)
		{
			HM3_DEBUG("ProcessHandleCacheController: process '%s' doesn't exists!\n", procName.c_str());
			return ProcessCacheRow();
		}

		auto subject = ProcessCacheRow(pHandle, pid);
		g_ProcCache[procName] = subject;

		HM3_DEBUG("ProcessHandleCacheController: process '%s' saved into cache!\n", procName.c_str());

		return subject;
	}
	else
	{
		HM3_DEBUG("ProcessHandleCacheController: process '%s' found in cache\n", procName.c_str());
		return (*iter).second;
	}
}