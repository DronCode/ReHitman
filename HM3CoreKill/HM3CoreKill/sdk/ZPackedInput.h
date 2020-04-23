#pragma once

#include <cstdint>
#include <sdk/ZInputStream.h>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZPackedInput
	{
	public:
		int32_t m_unk0; //0x0004
		bool m_doesLoadParametersRequiredToGame; //0x0008
		char pad_0009[3]; //0x0009
		uint32_t __MEMCHECK__; //0x000C
		char pad_0010[8]; //0x0010
		uint32_t m_unkPtr; //0x0018
		int32_t m_unkInt; //0x001C
		char pad_0020[4]; //0x0020
		ZInputStream* m_inputStream; //0x0024
		char pad_0028[4]; //0x0028

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0076084c
		virtual void Function_0001(); //#1 +4 .rdata:00760850
		virtual void Function_0002(); //#2 +8 .rdata:00760854
		virtual void Function_0003(); //#3 +c .rdata:00760858
		virtual void Function_0004(); //#4 +10 .rdata:0076085c
		virtual void Function_0005(); //#5 +14 .rdata:00760860
		virtual void Function_0006(); //#6 +18 .rdata:00760864
		virtual void Function_0007(); //#7 +1c .rdata:00760868
		virtual void Function_0008(); //#8 +20 .rdata:0076086c
		virtual void Function_0009(); //#9 +24 .rdata:00760870
		virtual void Function_0010(); //#10 +28 .rdata:00760874
		virtual void Function_0011(); //#11 +2c .rdata:00760878
		virtual void Function_0012(); //#12 +30 .rdata:0076087c
		virtual void Function_0013(); //#13 +34 .rdata:00760880
		virtual void Function_0014(); //#14 +38 .rdata:00760884
		virtual void Function_0015(); //#15 +3c .rdata:00760888
		virtual void Function_0016(); //#16 +40 .rdata:0076088c
		virtual void Function_0017(); //#17 +44 .rdata:00760890
		virtual void Function_0018(); //#18 +48 .rdata:00760894
		virtual void Function_0019(); //#19 +4c .rdata:00760898
		virtual void Function_0020(); //#20 +50 .rdata:0076089c
		virtual void Function_0021(); //#21 +54 .rdata:007608a0
		virtual void Function_0022(); //#22 +58 .rdata:007608a4
		virtual void Function_0023(); //#23 +5c .rdata:007608a8
		virtual void Function_0024(); //#24 +60 .rdata:007608ac
		virtual void Function_0025(); //#25 +64 .rdata:007608b0
		virtual void Function_0026(); //#26 +68 .rdata:007608b4
		virtual void Function_0027(); //#27 +6c .rdata:007608b8
	}; //Size: 0x002C

}}