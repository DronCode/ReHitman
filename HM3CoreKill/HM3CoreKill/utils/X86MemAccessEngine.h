#pragma once

#include <cstdint>

namespace x86
{
	class IMemoryAccessor
	{
	public:
		virtual ~IMemoryAccessor() noexcept = default;

		virtual bool Write(uint32_t address, uint8_t* buffer, size_t bufferSize) const = 0;
		virtual bool Read(uint32_t address, uint8_t* buffer, size_t bufferSize) const = 0;
		virtual uint32_t AllocateExecutableMemory(size_t memSize) const = 0;
	};

	class X86MemAccessEngine
	{
		IMemoryAccessor* m_currentAccessor = nullptr;

		X86MemAccessEngine() = default;
	public:
		static X86MemAccessEngine& getInstance();

		void setAccessorInterface(IMemoryAccessor* accessor);

		bool ReadMemory(uint32_t address, uint8_t* buffer, size_t bufferSize) const;
		bool WriteMemory(uint32_t address, uint8_t* buffer, size_t bufferSize) const;
		uint32_t AllocateExecutableMemory(size_t memSize) const;

		static uint8_t* BackendReaderDefaultImpl(uint32_t baseAddr, size_t count, size_t* actualBytesReady);
	};

}