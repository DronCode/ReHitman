#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZKeyboardWintel
	{
	public:
		char pad_0000[44]; //0x0000
		char* m_keyMap; //0x002C [map of keys, see DI_VK
		char pad_0030[60]; //0x0030
		uint32_t m_directInput; //0x006C
		uint32_t m_device2; //0x0070
	}; //Size: 0x0074

}}