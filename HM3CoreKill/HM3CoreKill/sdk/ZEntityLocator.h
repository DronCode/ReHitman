#pragma once

#include <sdk/MathCommon.h>

namespace ioi {
namespace hm3 {
	class ZEntityLocator
	{
	public:
		char pad_0000[0x24]; //0x0000
		Vector3 position; //0x0024
		char pad_0030[0x30]; //0x0030
		uint32_t group; //0x0060 [ptr]
		char pad_0064[8]; //0x0064
		char* entityName; //0x006C
		char pad_0070[16]; //0x0070
	}; //Size: 0x0080
}}