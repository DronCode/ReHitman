#include <utils/X86MemTools.h>
#include <utils/X86Arch.h>
#include <utils/X86Backend.h>
#include <utils/X86MemAccessEngine.h>

namespace x86
{
	MemJump::MemJump(uint32_t from, uint32_t to, MemJump::JumpType type)
		: m_jumpFrom(from)
		, m_jumpTo(to)
		, m_type(type)
	{
		const size_t jumpSize = (type == MemJump::JumpType::Near) ? sizeof(X86NearJumpCommit_t) : sizeof(X86FarJumpAbsoluteCommit_t);
		size_t requiredBytesFromSource = X86Backend::getLowestCountOfBytesToGetValidInstructionsSet(
			X86MemAccessEngine::BackendReaderDefaultImpl, 
			from, 
			jumpSize);

		m_originalCode.size   = requiredBytesFromSource;
		m_originalCode.buffer = (uint8_t*)malloc(sizeof(uint8_t) * requiredBytesFromSource);

		X86MemAccessEngine::getInstance().ReadMemory(from, m_originalCode.buffer, m_originalCode.size);

		switch (type)
		{
			case MemJump::JumpType::Near:
			{
				X86NearJumpCommit_t commit;
				commit.JMP_TO = x86::calculateOffset(to, from, sizeof(commit));
				
				m_newCode.size = sizeof(commit);
				m_newCode.buffer = (uint8_t*)malloc(m_newCode.size);
				
				memcpy((void*)m_newCode.buffer, (void*)& commit, m_newCode.size);
			}
			break;
			case MemJump::JumpType::Absolute:
			{
				X86FarJumpAbsoluteCommit_t commit;
				commit.JMP_TO = to;

				m_newCode.size = sizeof(commit);
				m_newCode.buffer = (uint8_t*)malloc(m_newCode.size);

				memcpy((void*)m_newCode.buffer, (void*)& commit, m_newCode.size);
			}
			break;
		}
	}

	MemJump MemJump::create(uint32_t from, uint32_t to, MemJump::JumpType type)
	{
		return MemJump(from, to, type);
	}

	void MemJump::apply()
	{
		if (m_isActive)
			return;

		if (X86MemAccessEngine::getInstance().WriteMemory(m_jumpFrom, m_newCode.buffer, m_newCode.size))
			m_isActive = true;
	}

	void MemJump::restore()
	{
		if (!m_isActive)
			return;

		if (X86MemAccessEngine::getInstance().ReadMemory(m_jumpFrom, m_originalCode.buffer, m_originalCode.size))
			m_isActive = false;
	}
}