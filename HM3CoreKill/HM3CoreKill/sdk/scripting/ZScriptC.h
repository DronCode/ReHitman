#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZScheduledScript
	{
	public:
		/// === members ===
		int32_t m_field4; //0x0004
		ZScheduledScript* m_next; //0x0008
		int32_t m_fieldC; //0x000C
		int32_t m_field10; //0x0010
		int32_t m_field14; //0x0014
		int32_t m_field18; //0x0018
		int32_t m_field1C; //0x001C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00761300
		virtual void Function_0001(); //#1 +4 .rdata:00761304
		virtual void Function_0002(); //#2 +8 .rdata:00761308
	}; //Size: 0x0020

	
	class ZScriptC : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		int32_t m_field14; //0x0014
		int32_t m_field18; //0x0018
		int32_t m_field1C; //0x001C
		int32_t m_field20; //0x0020
		ZSTDOBJ* m_boxPrimitive; //0x0024
		ZScheduledScript* m_cheduledEvent; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		uint32_t m_field30; //0x0030
		int32_t m_field34; //0x0034
		int32_t m_field38; //0x0038
		int32_t m_field3C; //0x003C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0077c22c
		virtual void Function_0001(); //#1 +4 .rdata:0077c230
		virtual void Function_0002(); //#2 +8 .rdata:0077c234
		virtual void Function_0003(); //#3 +c .rdata:0077c238
		virtual void Function_0004(); //#4 +10 .rdata:0077c23c
		virtual void Function_0005(); //#5 +14 .rdata:0077c240
		virtual void Function_0006(); //#6 +18 .rdata:0077c244
		virtual void Function_0007(); //#7 +1c .rdata:0077c248
		virtual void Function_0008(); //#8 +20 .rdata:0077c24c
		virtual void Function_0009(); //#9 +24 .rdata:0077c250
		virtual void Function_0010(); //#10 +28 .rdata:0077c254
		virtual void Function_0011(); //#11 +2c .rdata:0077c258
		virtual void Function_0012(); //#12 +30 .rdata:0077c25c
		virtual void Function_0013(); //#13 +34 .rdata:0077c260
		virtual void Function_0014(); //#14 +38 .rdata:0077c264
		virtual void Function_0015(); //#15 +3c .rdata:0077c268
		virtual void Function_0016(); //#16 +40 .rdata:0077c26c
		virtual void Function_0017(); //#17 +44 .rdata:0077c270
		virtual void Function_0018(); //#18 +48 .rdata:0077c274
		virtual void Function_0019(); //#19 +4c .rdata:0077c278
		virtual void Function_0020(); //#20 +50 .rdata:0077c27c
		virtual void Function_0021(); //#21 +54 .rdata:0077c280
		virtual void Function_0022(); //#22 +58 .rdata:0077c284
		virtual void Function_0023(); //#23 +5c .rdata:0077c288
		virtual void Function_0024(); //#24 +60 .rdata:0077c28c
		virtual void Function_0025(); //#25 +64 .rdata:0077c290
		virtual void Function_0026(); //#26 +68 .rdata:0077c294
		virtual void Function_0027(); //#27 +6c .rdata:0077c298
		virtual void Function_0028(); //#28 +70 .rdata:0077c29c
		virtual void Function_0029(); //#29 +74 .rdata:0077c2a0
		virtual void Function_0030(); //#30 +78 .rdata:0077c2a4
		virtual void Function_0031(); //#31 +7c .rdata:0077c2a8
		virtual void Function_0032(); //#32 +80 .rdata:0077c2ac
		virtual void Function_0033(); //#33 +84 .rdata:0077c2b0
		virtual void Function_0034(); //#34 +88 .rdata:0077c2b4
		virtual void Function_0035(); //#35 +8c .rdata:0077c2b8
	}; //Size: 0x0040

}}