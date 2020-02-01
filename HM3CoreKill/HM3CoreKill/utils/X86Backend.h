#pragma once

#include <cstdint>
#include <functional>

namespace x86
{
	/***
		@class X86Backend
		@brief This is dynamic instruction analyzer
	***/
	class X86Backend
	{
	public:	
		// return pointer to buffer with copy of data, first arg - base addr, second - size of buffer, third - actual ready
		using ReadDataFromProcessMemoryCallback = std::function<uint8_t* (uint32_t, size_t, size_t*)>;
		static size_t getLowestCountOfBytesToGetValidInstructionsSet(
			ReadDataFromProcessMemoryCallback reader,
			uint32_t baseAddr,
			size_t minimumBytesCount = 0
		);
	};
}