#pragma once

#include <cstdint>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZBoxPrimitive.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class ZActorCommunication : public ZLinkedListNodeBase
	{
	public:
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_primitive; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[272]; //0x0030

		virtual void Function_0000(); //#0 +0 .rdata:0079dab4
		virtual void Function_0001(); //#1 +4 .rdata:0079dab8
		virtual void Function_0002(); //#2 +8 .rdata:0079dabc
		virtual void Function_0003(); //#3 +c .rdata:0079dac0
		virtual void Function_0004(); //#4 +10 .rdata:0079dac4
		virtual void Function_0005(); //#5 +14 .rdata:0079dac8
		virtual void Function_0006(); //#6 +18 .rdata:0079dacc
		virtual void Function_0007(); //#7 +1c .rdata:0079dad0
		virtual void Function_0008(); //#8 +20 .rdata:0079dad4
		virtual void Function_0009(); //#9 +24 .rdata:0079dad8
		virtual void Function_0010(); //#10 +28 .rdata:0079dadc
		virtual void Function_0011(); //#11 +2c .rdata:0079dae0
		virtual void Function_0012(); //#12 +30 .rdata:0079dae4
		virtual void Function_0013(); //#13 +34 .rdata:0079dae8
		virtual void Function_0014(); //#14 +38 .rdata:0079daec
		virtual void Function_0015(); //#15 +3c .rdata:0079daf0
		virtual void Function_0016(); //#16 +40 .rdata:0079daf4
		virtual void Function_0017(); //#17 +44 .rdata:0079daf8
		virtual void Function_0018(); //#18 +48 .rdata:0079dafc
		virtual void Function_0019(); //#19 +4c .rdata:0079db00
		virtual void Function_0020(); //#20 +50 .rdata:0079db04
		virtual void Function_0021(); //#21 +54 .rdata:0079db08
		virtual void Function_0022(); //#22 +58 .rdata:0079db0c
		virtual void Function_0023(); //#23 +5c .rdata:0079db10
		virtual void Function_0024(); //#24 +60 .rdata:0079db14
		virtual void Function_0025(); //#25 +64 .rdata:0079db18
		virtual void Function_0026(); //#26 +68 .rdata:0079db1c
		virtual void Function_0027(); //#27 +6c .rdata:0079db20
		virtual void Function_0028(); //#28 +70 .rdata:0079db24
		virtual void Function_0029(); //#29 +74 .rdata:0079db28
		virtual void Function_0030(); //#30 +78 .rdata:0079db2c
		virtual void Function_0031(); //#31 +7c .rdata:0079db30
		virtual void Function_0032(); //#32 +80 .rdata:0079db34
		virtual void Function_0033(); //#33 +84 .rdata:0079db38
		virtual void Function_0034(); //#34 +88 .rdata:0079db3c
		virtual void Function_0035(); //#35 +8c .rdata:0079db40
	};

} }