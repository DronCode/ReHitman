#pragma once

#include <cstdint>
#include <type_traits>

/***
	@brief Helpers for x86 platform
		   Instruction defs and base patches
***/

namespace x86
{
	namespace instructions
	{
		static const uint8_t NOP		= 0x90;
		static const uint8_t INT3		= 0xCC;
		static const uint8_t CALL_NEAR  = 0xE8;
		static const uint8_t JMP_NEAR   = 0xE9;
		static const uint16_t CALL_ABS  = 0xFF15;
		static const uint16_t JUMP_ABS  = 0xFF25;
	}
	// Near jump (by offset). Offset = Dest - Source - 5
	#pragma pack(push, 1)
	struct X86NearJumpCommit_t {
		const uint8_t OP = x86::instructions::JMP_NEAR;
		uint32_t JMP_TO;
	};
	
	// Near call (by offset). Offset = Dest - Source - 5
	#pragma pack(push, 1)
	struct X86NearCallCommit_t {
		const uint8_t OP = x86::instructions::CALL_NEAR;
		uint32_t JMP_TO;
	};

	// Absolute jump. 
	#pragma pack(push, 1)
	struct X86FarJumpAbsoluteCommit_t {
		const uint16_t OP1 = x86::instructions::JUMP_ABS;
		uint32_t JMP_TO;
	};

	// Absolute call
	#pragma pack(push, 1)
	struct X86FarCallAbsoluteCommit_t {
		const uint16_t OP1 = x86::instructions::CALL_ABS;
		uint32_t JMP_TO;
	};

	static uint32_t calculateOffset(uint32_t jumpTo, uint32_t jumpFrom, uint32_t jumpInstructionSize = 5)
	{
		uint32_t result;
		result = jumpTo - jumpFrom - jumpInstructionSize;
		return result;
	}
}