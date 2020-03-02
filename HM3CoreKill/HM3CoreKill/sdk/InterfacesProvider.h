#pragma once

#include <cstdint>
#include <cassert>
#include <sdk/ZGlacierRTTI.h>

namespace ioi {
namespace hm3 {
	template <typename T = std::uintptr_t>
	T* getGlacierInterface(std::uintptr_t baseAddr)
	{
		return ((*(T**)baseAddr));
	}

	
	template <typename T>
	ZGlacierRTTI* getTypeInfo(T* instance, std::uintptr_t rttiOffset = 0x2C)
	{
		assert(rttiOffset >= 0);

		if (!instance)
			return nullptr;

		auto result = reinterpret_cast<ZGlacierRTTI*>(*reinterpret_cast<T**>(reinterpret_cast<char*>(instance) + rttiOffset));
		if (result->TypeID < 0 || result->TypeID >= 0x10000)
			return nullptr; ///Bad type info. TypeID has too much value for it.

		return result;
	}
}}