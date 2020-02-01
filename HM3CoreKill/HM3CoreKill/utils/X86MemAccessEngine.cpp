#include <utils/X86MemAccessEngine.h>
#include <cstdlib>

#define SAFE_WRITE_PTR(target, what) if (target != nullptr) *target = what;

namespace x86
{
	X86MemAccessEngine& X86MemAccessEngine::getInstance()
	{
		static X86MemAccessEngine instance;
		return instance;
	}

	void X86MemAccessEngine::setAccessorInterface(IMemoryAccessor* accessor)
	{
		if (!accessor)
			return;

		m_currentAccessor = accessor;
	}

	bool X86MemAccessEngine::ReadMemory(uint32_t address, uint8_t* buffer, size_t bufferSize) const
	{
		if (!m_currentAccessor)
			return false;

		if (!buffer || !bufferSize)
			return false;

		return m_currentAccessor->Read(address, buffer, bufferSize);
	}

	bool X86MemAccessEngine::WriteMemory(uint32_t address, uint8_t* buffer, size_t bufferSize) const
	{
		if (!m_currentAccessor)
			return false;

		if (!buffer || !bufferSize)
			return false;

		return m_currentAccessor->Write(address, buffer, bufferSize);
	}

	uint32_t X86MemAccessEngine::AllocateExecutableMemory(size_t memSize) const
	{
		if (!m_currentAccessor || memSize <= 0)
			return 0x0;

		return m_currentAccessor->AllocateExecutableMemory(memSize);
	}

	uint8_t* X86MemAccessEngine::BackendReaderDefaultImpl(uint32_t baseAddr, size_t count, size_t* actualBytesReady)
	{
		if (!count)
		{
			SAFE_WRITE_PTR(actualBytesReady, 0);
			return nullptr;
		}

		uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t) * count);
		const bool result = X86MemAccessEngine::getInstance().ReadMemory(baseAddr, buffer, count);
		
		if (result)
		{
			SAFE_WRITE_PTR(actualBytesReady, count);
			return buffer;
		}

		free(buffer);
		SAFE_WRITE_PTR(actualBytesReady, 0);
		return nullptr;
	}
}