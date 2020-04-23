#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZBoxPrimitive.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class CMetalDetector : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		int32_t m_unkInt0; //0x0014
		int32_t m_unkInt1; //0x0018
		int32_t m_unkInt2; //0x001C
		int32_t m_unkInt3; //0x0020
		ZBoxPrimitive* m_boxPrimitive; //0x0024
		int32_t m_unkInt4; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		REFTAB m_reftab0; //0x0030
		int32_t m_unkInt5; //0x004C
		REFTAB m_reftab1; //0x0050
		REFTAB m_reftab2; //0x006C
		REFTAB m_reftab3; //0x0088
		char pad_00A4[12]; //0x00A4

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0078becc
		virtual void Function_0001(); //#1 +4 .rdata:0078bed0
		virtual void Function_0002(); //#2 +8 .rdata:0078bed4
		virtual void Function_0003(); //#3 +c .rdata:0078bed8
		virtual void Function_0004(); //#4 +10 .rdata:0078bedc
		virtual void Function_0005(); //#5 +14 .rdata:0078bee0
		virtual void Function_0006(); //#6 +18 .rdata:0078bee4
		virtual void Function_0007(); //#7 +1c .rdata:0078bee8
		virtual void Function_0008(); //#8 +20 .rdata:0078beec
		virtual void Function_0009(); //#9 +24 .rdata:0078bef0
		virtual void Function_0010(); //#10 +28 .rdata:0078bef4
		virtual void Function_0011(); //#11 +2c .rdata:0078bef8
		virtual void Function_0012(); //#12 +30 .rdata:0078befc
		virtual void Function_0013(); //#13 +34 .rdata:0078bf00
		virtual void Function_0014(); //#14 +38 .rdata:0078bf04
		virtual void Function_0015(); //#15 +3c .rdata:0078bf08
		virtual void Function_0016(); //#16 +40 .rdata:0078bf0c
		virtual void Function_0017(); //#17 +44 .rdata:0078bf10
		virtual void Function_0018(); //#18 +48 .rdata:0078bf14
		virtual void Function_0019(); //#19 +4c .rdata:0078bf18
		virtual void Function_0020(); //#20 +50 .rdata:0078bf1c
		virtual void Function_0021(); //#21 +54 .rdata:0078bf20
		virtual void Function_0022(); //#22 +58 .rdata:0078bf24
		virtual void Function_0023(); //#23 +5c .rdata:0078bf28
		virtual void Function_0024(); //#24 +60 .rdata:0078bf2c
		virtual void Function_0025(); //#25 +64 .rdata:0078bf30
		virtual void Function_0026(); //#26 +68 .rdata:0078bf34 {possible onUpdate}
		virtual void Function_0027(); //#27 +6c .rdata:0078bf38
		virtual void Function_0028(); //#28 +70 .rdata:0078bf3c
		virtual void Function_0029(); //#29 +74 .rdata:0078bf40
		virtual void Function_0030(); //#30 +78 .rdata:0078bf44
		virtual void Function_0031(); //#31 +7c .rdata:0078bf48
		virtual void Function_0032(); //#32 +80 .rdata:0078bf4c
		virtual void Function_0033(); //#33 +84 .rdata:0078bf50
		virtual void Function_0034(); //#34 +88 .rdata:0078bf54
		virtual void Function_0035(); //#35 +8c .rdata:0078bf58
	}; //Size: 0x00B0

} }