#pragma once

#include <cstdint>
#include <sdk/FsZip_t.h>

namespace ioi { namespace hm3 {

	class ZIOInputStream
	{
	public:
		/// === members ===
		FsZip_t* m_sourceFS; //0x0004
		char pad_0008[8]; //0x0008
		uint32_t m_PF4RunTime_Data; //0x0010
		char pad_0014[12]; //0x0014
		char m_textArr16PerItem[32][16]; //0x0020

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00760aa8
		virtual void Function_0001(); //#1 +4 .rdata:00760aac
	}; //Size: 0x0030

}}