#include <Windows.h>
#include <exception>
#include <DbgHelp.h>

#include <ck/HM3DebugConsole.h>
#include <ck/HM3CrashHandler.h>


bool isExceptionRequierMiniDump(EXCEPTION_POINTERS* frame)
{
	if (
			frame->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT  || 
			frame->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP
		)
	{
		return false;
	}
	return true;
}

void WriteMiniDump(EXCEPTION_POINTERS* exception = nullptr)
{
	//
	//	Credits https://stackoverflow.com/questions/5028781/how-to-write-a-sample-code-that-will-crash-and-produce-dump-file
	//
	auto hDbgHelp = LoadLibraryA("dbghelp");
	if (hDbgHelp == nullptr)
		return;
	auto pMiniDumpWriteDump = (decltype(&MiniDumpWriteDump))GetProcAddress(hDbgHelp, "MiniDumpWriteDump");
	if (pMiniDumpWriteDump == nullptr)
		return;

	char name[MAX_PATH];
	{
		auto nameEnd = name + GetModuleFileNameA(GetModuleHandleA(0), name, MAX_PATH);
		SYSTEMTIME t;
		GetSystemTime(&t);

		wsprintfA(nameEnd - strlen(".exe"),
			"_%4d%02d%02d_%02d%02d%02d.dmp",
			t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
	}

	auto hFile = CreateFileA(name, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = exception;
	exceptionInfo.ClientPointers = FALSE;

	auto dumped = pMiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		MINIDUMP_TYPE(MiniDumpWithIndirectlyReferencedMemory | MiniDumpScanMemory),
		exception ? &exceptionInfo : nullptr,
		nullptr,
		nullptr);

	CloseHandle(hFile);
}

LONG WINAPI HM3CrashHandlerFunction(EXCEPTION_POINTERS* exceptionInfoFrame)
{
	if (isExceptionRequierMiniDump(exceptionInfoFrame))
	{
		DWORD    ExceptionCode;
		DWORD ExceptionFlags;
		struct _EXCEPTION_RECORD* ExceptionRecord;
		PVOID ExceptionAddress;
		DWORD NumberParameters;
		ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];

		HM3_DEBUG("******************************************************************************\n");
		HM3_DEBUG("                                 FATAL ERROR!								 \n");
		HM3_DEBUG("******************************************************************************\n");
		HM3_DEBUG("Exception code   : %X\n",   exceptionInfoFrame->ExceptionRecord->ExceptionCode);
		HM3_DEBUG("Exception flags  : %X\n",   exceptionInfoFrame->ExceptionRecord->ExceptionFlags);
		HM3_DEBUG("Exception addr   : 0x%X\n", (DWORD)exceptionInfoFrame->ExceptionRecord->ExceptionAddress);
		HM3_DEBUG("> GG BRO\n");
		MessageBox(
			NULL, 
			"We got an fatal error.\n"				\
			"Minidump will be saved near exe.\n"	\
			"More details in dev console.\n\n\n\n"	\
			"Sorry bro(", 
			"Hitman Blood Money | CoreKill", 
			MB_ICONERROR | MB_OK
		);
		WriteMiniDump(exceptionInfoFrame);
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

void STL_TerminateCallback()
{
	WriteMiniDump(nullptr);
}

void HM3CrashHandler::Setup()
{
	std::set_terminate(STL_TerminateCallback);
	SetUnhandledExceptionFilter(HM3CrashHandlerFunction);
}