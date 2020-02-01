#pragma once

#include <cstdint>
#include <sdk/input/ZKeyboardStorage.h>

namespace ioi { namespace hm3 { namespace sysinput {

	class ZKeyboard
	{
	public:
		char pad_0000[40]; //0x0000
		uint32_t unknown_inlined_stuff; //0x0028
		ZKeyboardStorage* activeKeys; //0x002C
		char pad_0030[24]; //0x0030
	}; //Size: 0x0048

}}}