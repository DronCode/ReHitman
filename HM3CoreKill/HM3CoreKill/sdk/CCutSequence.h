#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class CCutSequence : public ZLinkedListNodeBase
	{
	public:
		// === members ===
		char pad_0014[12]; //0x0014
		int32_t m_flags; //0x0020
		ZLIST* m_list; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[32]; //0x0030

		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0077843c
		virtual void Function_0001(); //#1 +4 .rdata:00778440
		virtual void Function_0002(); //#2 +8 .rdata:00778444
		virtual void Function_0003(); //#3 +c .rdata:00778448
		virtual void Function_0004(); //#4 +10 .rdata:0077844c
		virtual void Function_0005(); //#5 +14 .rdata:00778450
		virtual void Function_0006(); //#6 +18 .rdata:00778454
		virtual void Function_0007(); //#7 +1c .rdata:00778458
		virtual void Function_0008(); //#8 +20 .rdata:0077845c
		virtual void Function_0009(); //#9 +24 .rdata:00778460
		virtual void Function_0010(); //#10 +28 .rdata:00778464
		virtual void Function_0011(); //#11 +2c .rdata:00778468
		virtual void Function_0012(); //#12 +30 .rdata:0077846c
		virtual void Function_0013(); //#13 +34 .rdata:00778470
		virtual void Function_0014(); //#14 +38 .rdata:00778474
		virtual void Function_0015(); //#15 +3c .rdata:00778478
		virtual void Function_0016(); //#16 +40 .rdata:0077847c
		virtual void Function_0017(); //#17 +44 .rdata:00778480
		virtual void Function_0018(); //#18 +48 .rdata:00778484
		virtual void Function_0019(); //#19 +4c .rdata:00778488
		virtual void Function_0020(); //#20 +50 .rdata:0077848c
		virtual void Function_0021(); //#21 +54 .rdata:00778490
		virtual void Function_0022(); //#22 +58 .rdata:00778494
		virtual void Function_0023(); //#23 +5c .rdata:00778498
		virtual void Function_0024(); //#24 +60 .rdata:0077849c
		virtual void Function_0025(); //#25 +64 .rdata:007784a0
		virtual void Function_0026(); //#26 +68 .rdata:007784a4
		virtual void Function_0027(); //#27 +6c .rdata:007784a8
		virtual void Function_0028(); //#28 +70 .rdata:007784ac
		virtual void Function_0029(); //#29 +74 .rdata:007784b0
		virtual void Function_0030(); //#30 +78 .rdata:007784b4
		virtual void Function_0031(); //#31 +7c .rdata:007784b8
		virtual void Function_0032(); //#32 +80 .rdata:007784bc
		virtual void Function_0033(); //#33 +84 .rdata:007784c0
		virtual void Function_0034(); //#34 +88 .rdata:007784c4
		virtual void Function_0035(); //#35 +8c .rdata:007784c8
	}; //Size: 0x0050

} }