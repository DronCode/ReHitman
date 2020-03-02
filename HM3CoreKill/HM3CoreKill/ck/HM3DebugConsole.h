#pragma once

#include <string>
#include <cassert>

class HM3DebugConsole
{
public:
	static void init();

	static void showAssertionFailedDialog(const char* func, const char* file, int line, const char* message, const char* condition);
};

#define HM3_DEBUG(format, ...) fprintf(stdout, format, __VA_ARGS__)

#define HM3_TRACE_BYTES(bytes)													\
	for (int bIndex = 0; bIndex < (sizeof(bytes) / sizeof(uint8_t)); bIndex++)	\
		HM3_DEBUG("%.2X ", bytes[bIndex]);										\
	HM3_DEBUG("\n");

#define HM3_PRINT_BUFFER(message, buffer)	\
	HM3_DEBUG(message);						\
	HM3_TRACE_BYTES(buffer);

#define HM3_PRINT_BUFFER_PTR(message, buffer, len)  \
	HM3_DEBUG(message); \
	for (int bIndex = 0; bIndex < len; bIndex++)	\
		HM3_DEBUG("%.2X ", buffer[bIndex]);			\
	HM3_DEBUG("\n");

#define HM3_ASSERT(condition, message)																\
	if (!(condition)) {																				\
		HM3_DEBUG("%s\n", message);																	\
		HM3DebugConsole::showAssertionFailedDialog(__FUNCTION__, __FILE__, __LINE__, message, #condition);	\
	}

#define HM3_UNUSED(something) (void)something;

#define HM3_PAUSE __asm { int 3 }
#define HM3_PAUSE_UI() MessageBox(nullptr, "Pause", "Paused", MB_OK);