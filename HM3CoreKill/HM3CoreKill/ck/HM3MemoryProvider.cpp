#include <ck/HM3MemoryProvider.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3ProcessCache.h>

#include <Windows.h>

bool HM3MemoryProvider::Write(uint32_t address, uint8_t* buffer, size_t bufferSize) const
{
	ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(HM3_PROCESS_NAME);
	HM3_ASSERT(cacheRow.handle != 0, "Unable to locate our process!");

	DWORD actualBytes;
	ReadProcessMemory(cacheRow.handle, (LPCVOID)address, (LPVOID)buffer, bufferSize, &actualBytes);
	
	return (actualBytes == bufferSize);
}

bool HM3MemoryProvider::Read(uint32_t address, uint8_t* buffer, size_t bufferSize) const
{
	ProcessHandleCacheController::ProcessCacheRow cacheRow = ProcessHandleCacheController::getProcessHandle(HM3_PROCESS_NAME);
	HM3_ASSERT(cacheRow.handle != 0, "Unable to locate our process!");

	DWORD actualWrittenBytes;
	WriteProcessMemory(cacheRow.handle, (LPVOID)address, (LPCVOID)buffer, bufferSize, &actualWrittenBytes);
	
	return (actualWrittenBytes == bufferSize);
}

uint32_t HM3MemoryProvider::AllocateExecutableMemory(size_t memSize) const
{
	uint32_t ptr = (uint32_t)malloc(memSize);
	if (!ptr)
		return 0;

	DWORD oldProtection;
	bool res = VirtualProtect((LPVOID)ptr, memSize, PAGE_EXECUTE_READWRITE, &oldProtection);
	HM3_ASSERT(res, "Unable to use new memory protection!");

	return ptr;
}