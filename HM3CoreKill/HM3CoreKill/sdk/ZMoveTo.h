#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZMoveTo : public ZLinkedListNodeBase
	{
	public:
		/// === vftable ===
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_targetSTDOBJ; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[16]; //0x0030

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0077b3dc
		virtual void Function_0001(); //#1 +4 .rdata:0077b3e0
		virtual void Function_0002(); //#2 +8 .rdata:0077b3e4
		virtual void Function_0003(); //#3 +c .rdata:0077b3e8
		virtual void Function_0004(); //#4 +10 .rdata:0077b3ec
		virtual void Function_0005(); //#5 +14 .rdata:0077b3f0
		virtual void Function_0006(); //#6 +18 .rdata:0077b3f4
		virtual void Function_0007(); //#7 +1c .rdata:0077b3f8
		virtual void Function_0008(); //#8 +20 .rdata:0077b3fc
		virtual void Function_0009(); //#9 +24 .rdata:0077b400
		virtual void Function_0010(); //#10 +28 .rdata:0077b404
		virtual void Function_0011(); //#11 +2c .rdata:0077b408
		virtual void Function_0012(); //#12 +30 .rdata:0077b40c
		virtual void Function_0013(); //#13 +34 .rdata:0077b410
		virtual void Function_0014(); //#14 +38 .rdata:0077b414
		virtual void Function_0015(); //#15 +3c .rdata:0077b418
		virtual void Function_0016(); //#16 +40 .rdata:0077b41c
		virtual void Function_0017(); //#17 +44 .rdata:0077b420
		virtual void Function_0018(); //#18 +48 .rdata:0077b424
		virtual void Function_0019(); //#19 +4c .rdata:0077b428
		virtual void Function_0020(); //#20 +50 .rdata:0077b42c
		virtual void Function_0021(); //#21 +54 .rdata:0077b430
		virtual void Function_0022(); //#22 +58 .rdata:0077b434
		virtual void Function_0023(); //#23 +5c .rdata:0077b438
		virtual void Function_0024(); //#24 +60 .rdata:0077b43c
		virtual void Function_0025(); //#25 +64 .rdata:0077b440
		virtual void Function_0026(); //#26 +68 .rdata:0077b444
		virtual void Function_0027(); //#27 +6c .rdata:0077b448
		virtual void Function_0028(); //#28 +70 .rdata:0077b44c
		virtual void Function_0029(); //#29 +74 .rdata:0077b450
		virtual void Function_0030(); //#30 +78 .rdata:0077b454
		virtual void Function_0031(); //#31 +7c .rdata:0077b458
		virtual void Function_0032(); //#32 +80 .rdata:0077b45c
		virtual void Function_0033(); //#33 +84 .rdata:0077b460
		virtual void Function_0034(); //#34 +88 .rdata:0077b464
		virtual void Function_0035(); //#35 +8c .rdata:0077b468
	};

} }