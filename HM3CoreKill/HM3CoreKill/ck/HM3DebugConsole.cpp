#include <ck/HM3DebugConsole.h>

#include <windows.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdarg>
#include <fcntl.h>
#include <cstdio>
#include <io.h>

void HM3DebugConsole::init()
{
	if (AllocConsole()) {
		freopen("CONOUT$", "w", stdout);
		SetConsoleTitle("HM3| Dev console");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}

void HM3DebugConsole::showAssertionFailedDialog(const char* func, const char* file, int line, const char* message, const char* condition)
{
	char messageBuffer[2048];
	memset((void*)messageBuffer, 0x0, 2048);
	snprintf(
		messageBuffer, 
		2048, 
		"Assertion failed!\n\n"
		"FUNCTION: \"%s\"\n"
		"LINE: %d\n"
		"CONDITION: \"%s\"\n"
		"FILE: \"%s\"\n\n"
		"Info: %s",
		func, line, condition, file, message
	);
	MessageBox(nullptr, messageBuffer, "ReHitman| Fatal error", MB_ICONEXCLAMATION | MB_OK);
	ExitProcess(0xFF);
}