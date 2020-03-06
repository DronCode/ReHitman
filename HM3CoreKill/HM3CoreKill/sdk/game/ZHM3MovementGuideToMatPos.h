#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZHM3Hitman3;

	class ZHM3MovementGuideToMatPos
	{
	public:
		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007944cc
		virtual void Function_0001(); //#1 +4 .rdata:007944d0
		virtual void Function_0002(); //#2 +8 .rdata:007944d4
		virtual void Function_0003(); //#3 +c .rdata:007944d8
		virtual void Function_0004(); //#4 +10 .rdata:007944dc
		virtual void Function_0005(); //#5 +14 .rdata:007944e0
		virtual void Function_0006(); //#6 +18 .rdata:007944e4
		virtual void Function_0007(); //#7 +1c .rdata:007944e8
		virtual void Function_0008(); //#8 +20 .rdata:007944ec
		virtual void Function_0009(); //#9 +24 .rdata:007944f0
		virtual void Function_0010(); //#10 +28 .rdata:007944f4
		virtual void Function_0011(); //#11 +2c .rdata:007944f8
		virtual void Function_0012(); //#12 +30 .rdata:007944fc
		virtual void Function_0013(); //#13 +34 .rdata:00794500
		virtual void Function_0014(); //#14 +38 .rdata:00794504
		virtual void Function_0015(); //#15 +3c .rdata:00794508
		virtual void Function_0016(); //#16 +40 .rdata:0079450c
		virtual void Function_0017(); //#17 +44 .rdata:00794510
		virtual void Function_0018(); //#18 +48 .rdata:00794514
		virtual void Function_0019(); //#19 +4c .rdata:00794518
		virtual void Function_0020(int*); //#20 +50 .rdata:0079451c
		virtual void Function_0021(); //#21 +54 .rdata:00794520
		virtual void Function_0022(); //#22 +58 .rdata:00794524
		virtual void Function_0023(); //#23 +5c .rdata:00794528
		virtual void Function_0024(); //#24 +60 .rdata:0079452c
		virtual void Function_0025(); //#25 +64 .rdata:00794530
		virtual void Function_0026(); //#26 +68 .rdata:00794534
		virtual void Function_0027(); //#27 +6c .rdata:00794538
		virtual void Function_0028(); //#28 +70 .rdata:0079453c
		virtual void Function_0029(); //#29 +74 .rdata:00794540
		virtual void Function_0030(); //#30 +78 .rdata:00794544
		virtual int Function_0031(int unk0, int unk1, int unk2, int unk3, int unk4); //#31 +7c .rdata:00794548
		virtual void Function_0032(); //#32 +80 .rdata:0079454c
		virtual void Function_0033(int unk0, int unk1, int unk2, int unk3); //#33 +84 .rdata:00794550
		virtual void Function_0034(); //#34 +88 .rdata:00794554
		virtual void Function_0035(); //#35 +8c .rdata:00794558
		virtual void Function_0036(); //#36 +90 .rdata:0079455c
		virtual void Function_0037(); //#37 +94 .rdata:00794560

		/// === data ===
		char pad_0004[52]; //0x0004
		ZHM3Hitman3* m_hitman3; //0x0038
		char pad_003C[8]; //0x003C
		int32_t m_a3CtorArg; //0x0044

	};

} }