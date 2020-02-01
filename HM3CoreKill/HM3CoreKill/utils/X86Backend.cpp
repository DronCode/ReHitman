#include <utils/X86Backend.h>
#include <Zydis/Zydis.h>

#include <stdexcept>

#define X86_BACKEND_FAILURE(message) throw std::runtime_error(message);

namespace x86
{
	size_t X86Backend::getLowestCountOfBytesToGetValidInstructionsSet(
		X86Backend::ReadDataFromProcessMemoryCallback reader, 
		uint32_t baseAddr, 
		size_t minimumCount
	) {
		size_t actualBytesReady = 0;
		uint8_t* buffer = reader(baseAddr, minimumCount, &actualBytesReady);

		if (actualBytesReady != minimumCount)
		{
			if (buffer)
				free(buffer);

			X86_BACKEND_FAILURE("Unable to read all required bytes from memory");
		}

		// Try to decode via Zydis
		ZydisDecoder decoder;
		ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_COMPAT_32, ZYDIS_ADDRESS_WIDTH_32);
		ZydisDecodedInstruction instruction;

		const bool isDecodeSuccess = ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&decoder, buffer, actualBytesReady, &instruction));
		free(buffer);

		if (isDecodeSuccess)
			return actualBytesReady;
		
		//Try read more bytes and decode it
		return X86Backend::getLowestCountOfBytesToGetValidInstructionsSet(reader, baseAddr, minimumCount + 1);
	}
}