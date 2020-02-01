#pragma once

#include <utils/X86Arch.h>

namespace x86
{
	//NOT USE (before auto disasm not ready)
	class MemJump
	{
	public:
		enum class JumpType { Near, Absolute };
	private:
		MemJump(uint32_t from, uint32_t to, MemJump::JumpType type);
	public:
		static MemJump create(uint32_t from, uint32_t to, MemJump::JumpType type = MemJump::JumpType::Near);

		void apply();
		void restore();
	private:
		uint32_t			m_jumpFrom;
		uint32_t			m_jumpTo;
		MemJump::JumpType	m_type;
		struct { 
			uint8_t* buffer = nullptr; 
			size_t	 size	= 0;
		} m_originalCode, m_newCode;
		bool m_isActive = false;
	};
}