#pragma once

#include <cstdint>

namespace ioi {
namespace hm3 {
	template <typename T = std::uintptr_t>
	T* getGlacierInterface(std::uintptr_t baseAddr)
	{
		return ((*(T**)baseAddr));
	}
}}