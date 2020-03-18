#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>
#include <sdk/ZEntityLocator.h>

namespace ioi
{
	namespace hm3 {
		class ZGlacierRTTI;
	}

	class REFTAB
	{
	public:
		// === members ===
		uint32_t m_raw; //0x0004
		uint32_t m_raw2; //0x0008
		int32_t m_unk0; //0x000C
		int32_t m_unk1; //0x0010
		int32_t m_unk2; //0x0014
		int32_t m_unk3; //0x0018

		// === vftable ==
		virtual void Function_0000(); //#0 +0 .rdata:007569ec
		virtual void Function_0001(); //#1 +4 .rdata:007569f0
		virtual void Function_0002(); //#2 +8 .rdata:007569f4
		virtual void Function_0003(); //#3 +c .rdata:007569f8
		virtual void Function_0004(); //#4 +10 .rdata:007569fc
		virtual int getCapacity(); //#5 +14 .rdata:00756a00
		virtual void Function_0006(); //#6 +18 .rdata:00756a04
		virtual void Function_0007(); //#7 +1c .rdata:00756a08
		virtual void Function_0008(); //#8 +20 .rdata:00756a0c
		virtual void Function_0009(); //#9 +24 .rdata:00756a10
		virtual void Function_0010(); //#10 +28 .rdata:00756a14
		virtual void Function_0011(); //#11 +2c .rdata:00756a18
		virtual void Function_0012(); //#12 +30 .rdata:00756a1c
		virtual int at(int index); //#13 +34 .rdata:00756a20
		virtual void Function_0014(); //#14 +38 .rdata:00756a24
		virtual void Function_0015(); //#15 +3c .rdata:00756a28
		virtual void Function_0016(); //#16 +40 .rdata:00756a2c
		virtual void Function_0017(); //#17 +44 .rdata:00756a30
		virtual void Function_0018(); //#18 +48 .rdata:00756a34
		virtual void Function_0019(); //#19 +4c .rdata:00756a38
		virtual void Function_0020(); //#20 +50 .rdata:00756a3c
		virtual void Function_0021(); //#21 +54 .rdata:00756a40
		virtual void Function_0022(); //#22 +58 .rdata:00756a44
		virtual void Function_0023(); //#23 +5c .rdata:00756a48
		virtual void Function_0024(); //#24 +60 .rdata:00756a4c
		virtual void Function_0025(); //#25 +64 .rdata:00756a50
		virtual void Function_0026(); //#26 +68 .rdata:00756a54
		virtual void Function_0027(); //#27 +6c .rdata:00756a58
		virtual void Function_0028(); //#28 +70 .rdata:00756a5c
		virtual void Function_0029(); //#29 +74 .rdata:00756a60
		virtual void Function_0030(); //#30 +78 .rdata:00756a64
		virtual void Function_0031(); //#31 +7c .rdata:00756a68
		virtual void Function_0032(); //#32 +80 .rdata:00756a6c
		virtual void Function_0033(); //#33 +84 .rdata:00756a70
		virtual void Function_0034(); //#34 +88 .rdata:00756a74
	}; //Size: 0x0020

	class ZSTDOBJ_TeleportEntity
	{
	public:
		char pad_0000[36]; //0x0000
		Vector3 position; //0x0024
		char pad_0030[60]; //0x0030
		char* objectName; //0x006C
		char pad_0070[88]; //0x0070
	}; //Size: 0x00C8

	// Created with ReClass.NET 1.2 by KN4CK3R
	class ZLIST
	{
	public:
		int32_t m_unk0; //possible user data or something else +0x0004
		char pad_0008[4]; //0x0008
		int32_t __MEMCHECK__; //0x000C
		REFTAB* m_reftab; //0x0010
		
		virtual void Function_0000(); //#0 +0 .rdata:0076bedc
		virtual void Function_0001(); //#1 +4 .rdata:0076bee0
		virtual void Function_0002(); //#2 +8 .rdata:0076bee4
		virtual void Function_0003(); //#3 +c .rdata:0076bee8
		virtual void Function_0004(); //#4 +10 .rdata:0076beec
		virtual void Function_0005(); //#5 +14 .rdata:0076bef0
		virtual void Function_0006(); //#6 +18 .rdata:0076bef4
		virtual void Function_0007(); //#7 +1c .rdata:0076bef8
		virtual void Function_0008(); //#8 +20 .rdata:0076befc
		virtual void Function_0009(); //#9 +24 .rdata:0076bf00
		virtual void Function_0010(); //#10 +28 .rdata:0076bf04
		virtual void Function_0011(); //#11 +2c .rdata:0076bf08
		virtual void Function_0012(); //#12 +30 .rdata:0076bf0c
		virtual void Function_0013(); //#13 +34 .rdata:0076bf10
		virtual void Function_0014(); //#14 +38 .rdata:0076bf14
		virtual void Function_0015(); //#15 +3c .rdata:0076bf18
		virtual void Function_0016(); //#16 +40 .rdata:0076bf1c
		virtual void Function_0017(); //#17 +44 .rdata:0076bf20
		virtual void Function_0018(); //#18 +48 .rdata:0076bf24
		virtual void Function_0019(); //#19 +4c .rdata:0076bf28
		virtual void Function_0020(); //#20 +50 .rdata:0076bf2c
		virtual void Function_0021(); //#21 +54 .rdata:0076bf30
		virtual void Function_0022(); //#22 +58 .rdata:0076bf34
		virtual void Function_0023(); //#23 +5c .rdata:0076bf38
		virtual void Function_0024(); //#24 +60 .rdata:0076bf3c
		virtual void Function_0025(); //#25 +64 .rdata:0076bf40
		virtual void Function_0026(); //#26 +68 .rdata:0076bf44
		virtual void Function_0027(); //#27 +6c .rdata:0076bf48
		virtual void Function_0028(); //#28 +70 .rdata:0076bf4c
		virtual void Function_0029(); //#29 +74 .rdata:0076bf50
		virtual void Function_0030(); //#30 +78 .rdata:0076bf54
		virtual void Function_0031(); //#31 +7c .rdata:0076bf58
		virtual void Function_0032(); //#32 +80 .rdata:0076bf5c
		virtual void Function_0033(); //#33 +84 .rdata:0076bf60
		virtual void Function_0034(); //#34 +88 .rdata:0076bf64
		virtual void Function_0035(); //#35 +8c .rdata:0076bf68
		virtual void Function_0036(); //#36 +90 .rdata:0076bf6c
		virtual void Function_0037(); //#37 +94 .rdata:0076bf70
		virtual void Function_0038(); //#38 +98 .rdata:0076bf74
		virtual void Function_0039(); //#39 +9c .rdata:0076bf78
		virtual void Function_0040(); //#40 +a0 .rdata:0076bf7c
		virtual void Function_0041(); //#41 +a4 .rdata:0076bf80
		virtual void Function_0042(); //#42 +a8 .rdata:0076bf84
		virtual void Function_0043(); //#43 +ac .rdata:0076bf88
		virtual void Function_0044(); //#44 +b0 .rdata:0076bf8c
		virtual void Function_0045(); //#45 +b4 .rdata:0076bf90
		virtual void Function_0046(); //#46 +b8 .rdata:0076bf94
		virtual void Function_0047(); //#47 +bc .rdata:0076bf98
		virtual void Function_0048(); //#48 +c0 .rdata:0076bf9c
		virtual void Function_0049(); //#49 +c4 .rdata:0076bfa0
		virtual void Function_0050(); //#50 +c8 .rdata:0076bfa4
		virtual void Function_0051(); //#51 +cc .rdata:0076bfa8
		virtual void Function_0052(); //#52 +d0 .rdata:0076bfac
		virtual void Function_0053(); //#53 +d4 .rdata:0076bfb0
		virtual void Function_0054(); //#54 +d8 .rdata:0076bfb4
		virtual void Function_0055(); //#55 +dc .rdata:0076bfb8
		virtual void Function_0056(); //#56 +e0 .rdata:0076bfbc
		virtual void Function_0057(); //#57 +e4 .rdata:0076bfc0
		virtual void Function_0058(); //#58 +e8 .rdata:0076bfc4
		virtual void Function_0059(); //#59 +ec .rdata:0076bfc8
		virtual void Function_0060(); //#60 +f0 .rdata:0076bfcc
		virtual void Function_0061(); //#61 +f4 .rdata:0076bfd0
		virtual void Function_0062(); //#62 +f8 .rdata:0076bfd4
		virtual void Function_0063(); //#63 +fc .rdata:0076bfd8
		virtual void Function_0064(); //#64 +100 .rdata:0076bfdc
		virtual void Function_0065(); //#65 +104 .rdata:0076bfe0
		virtual void Function_0066(); //#66 +108 .rdata:0076bfe4
		virtual void Function_0067(); //#67 +10c .rdata:0076bfe8
		virtual void Function_0068(); //#68 +110 .rdata:0076bfec
		virtual void Function_0069(); //#69 +114 .rdata:0076bff0
		virtual void Function_0070(); //#70 +118 .rdata:0076bff4
		virtual void Function_0071(); //#71 +11c .rdata:0076bff8
		virtual void Function_0072(); //#72 +120 .rdata:0076bffc
		virtual void Function_0073(); //#73 +124 .rdata:0076c000
		virtual void Function_0074(); //#74 +128 .rdata:0076c004
		virtual void Function_0075(); //#75 +12c .rdata:0076c008
		virtual void Function_0076(); //#76 +130 .rdata:0076c00c
		virtual void Function_0077(); //#77 +134 .rdata:0076c010
		virtual void Function_0078(); //#78 +138 .rdata:0076c014
		virtual void Function_0079(); //#79 +13c .rdata:0076c018
		virtual void Function_0080(); //#80 +140 .rdata:0076c01c
		virtual void Function_0081(); //#81 +144 .rdata:0076c020
		virtual void Function_0082(); //#82 +148 .rdata:0076c024
		virtual void Function_0083(); //#83 +14c .rdata:0076c028
		virtual void Function_0084(); //#84 +150 .rdata:0076c02c
		virtual void Function_0085(); //#85 +154 .rdata:0076c030
		virtual void Function_0086(); //#86 +158 .rdata:0076c034
		virtual void Function_0087(); //#87 +15c .rdata:0076c038
		virtual void Function_0088(); //#88 +160 .rdata:0076c03c
		virtual void Function_0089(); //#89 +164 .rdata:0076c040
		virtual void Function_0090(); //#90 +168 .rdata:0076c044
		virtual void Function_0091(); //#91 +16c .rdata:0076c048
		virtual void Function_0092(); //#92 +170 .rdata:0076c04c
		virtual void Function_0093(); //#93 +174 .rdata:0076c050
		virtual void Function_0094(); //#94 +178 .rdata:0076c054
		virtual void Function_0095(); //#95 +17c .rdata:0076c058
		virtual void Function_0096(); //#96 +180 .rdata:0076c05c
		virtual void Function_0097(); //#97 +184 .rdata:0076c060
		virtual void Function_0098(); //#98 +188 .rdata:0076c064
		virtual void Function_0099(); //#99 +18c .rdata:0076c068
		virtual void Function_0100(); //#100 +190 .rdata:0076c06c
		virtual void Function_0101(); //#101 +194 .rdata:0076c070
		virtual void Function_0102(); //#102 +198 .rdata:0076c074
		virtual void Function_0103(); //#103 +19c .rdata:0076c078
		virtual void Function_0104(); //#104 +1a0 .rdata:0076c07c
		virtual void Function_0105(); //#105 +1a4 .rdata:0076c080
		virtual void Function_0106(); //#106 +1a8 .rdata:0076c084
		virtual void Function_0107(); //#107 +1ac .rdata:0076c088
		virtual void Function_0108(); //#108 +1b0 .rdata:0076c08c
		virtual void Function_0109(); //#109 +1b4 .rdata:0076c090
		virtual void Function_0110(); //#110 +1b8 .rdata:0076c094
		virtual void Function_0111(); //#111 +1bc .rdata:0076c098
		virtual void Function_0112(); //#112 +1c0 .rdata:0076c09c
		virtual void Function_0113(); //#113 +1c4 .rdata:0076c0a0
		virtual void Function_0114(); //#114 +1c8 .rdata:0076c0a4
		virtual void Function_0115(); //#115 +1cc .rdata:0076c0a8
		virtual void Function_0116(); //#116 +1d0 .rdata:0076c0ac
		virtual void Function_0117(); //#117 +1d4 .rdata:0076c0b0
		virtual void Function_0118(); //#118 +1d8 .rdata:0076c0b4
		virtual void Function_0119(); //#119 +1dc .rdata:0076c0b8
		virtual void Function_0120(); //#120 +1e0 .rdata:0076c0bc
		virtual void Function_0121(); //#121 +1e4 .rdata:0076c0c0
		virtual void Function_0122(); //#122 +1e8 .rdata:0076c0c4
		virtual void Function_0123(); //#123 +1ec .rdata:0076c0c8
		virtual void Function_0124(); //#124 +1f0 .rdata:0076c0cc
		virtual void Function_0125(); //#125 +1f4 .rdata:0076c0d0
	}; //Size: 0x0014

	class ZSTDOBJ
	{
	public:
		hm3::ZEntityLocator* m_entityLocation; //0x0004
		uint32_t m_unknown0; //0x0008
		int32_t m_memCheck; //0x000C

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual void Function13();
		virtual void Function14();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
		virtual void Function31();
		virtual void Function32();
		virtual void Function33();
		virtual void Function34();
		virtual void Function35();
		virtual void Function36();
		virtual void Function37();
		virtual void Function38();
		virtual void Function39();
		virtual void Function40();
		virtual void Function41();
		virtual void Function42();
		virtual void Function43();
		virtual void Function44();
		virtual void Function45();
		virtual void Function46();
		virtual void Function47();
		virtual void Function48();
		virtual void Function49();
		virtual void Function50();
		virtual void Function51();
		virtual void Function52();
		virtual void Function53();
		virtual void Function54();
		virtual void Function55();
		virtual void Function56();
		virtual void Function57();
		virtual void Function58();
		virtual void Function59();
		virtual void Function60();
		virtual void Function61();
		virtual void Function62();
		virtual void Function63();
		virtual void Function64();
		virtual void Function65();
		virtual void Function66();
		virtual void Function67();
		virtual void Function68();
		virtual void Function69();
		virtual void Function70();
		virtual void Function71();
		virtual void Function72();
		virtual void Function73();
		virtual void Function74();
		virtual void Function75();
		virtual void Function76();
		virtual void Function77();
		virtual void Function78();
		virtual void Function79();
		virtual void Function80();
		virtual void Function81();
		virtual void Function82();
		virtual void Function83();
		virtual void Function84();
		virtual void Function85();
		virtual void Function86();
		virtual void Function87();
		virtual void Function88();
		virtual void Function89();
		virtual void Function90();
		virtual void Function91();
		virtual void Function92();
		virtual void Function93();
		virtual void Function94();
		virtual void Function95();
		virtual void Function96();
		virtual void Function97();
		virtual void Function98();
		virtual void Function99();
		virtual void Function100();
		virtual void Function101();
		virtual void Function102();
		virtual void Function103();
		virtual void Function104();
		virtual void Function105();
		virtual void Function106();
		virtual void Function107();
		virtual void Function108();
		virtual void Function109();
		virtual void Function110();
		virtual void Function111();
		virtual void Function112();
		virtual void Function113();
		virtual void Function114();
		virtual void Function115();
		virtual void Function116();
		virtual void Function117();
	}; //Size: 0x0010
}