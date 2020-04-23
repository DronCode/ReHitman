#pragma once

#include <cstdint>
#include <sdk/ZIOInputStream.h>

namespace ioi { namespace hm3 {

	class ZInputStream
	{
	public:
		char pad_0004[4]; //0x0004
		ZIOInputStream* m_IOStream; //0x0008
		char pad_000C[52]; //0x000C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00760b7c
		virtual void Function_0001(); //#1 +4 .rdata:00760b80
		virtual void Function_0002(); //#2 +8 .rdata:00760b84
	}; //Size: 0x0040

}}