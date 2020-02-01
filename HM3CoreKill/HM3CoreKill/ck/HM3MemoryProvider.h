#pragma once

#include <utils/X86MemAccessEngine.h>

class HM3MemoryProvider : public x86::IMemoryAccessor
{
public:
	bool Write(uint32_t address, uint8_t* buffer, size_t bufferSize) const override;
	bool Read(uint32_t address, uint8_t* buffer, size_t bufferSize) const override;
	uint32_t AllocateExecutableMemory(size_t memSize) const override;
};