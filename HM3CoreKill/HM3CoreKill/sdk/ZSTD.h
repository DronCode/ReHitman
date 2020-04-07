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

	class LINKREFTAB
	{
	public:
		uint32_t m_items; //0x0004
		uint32_t m_items1; //0x0008
		int32_t m_capacity; //0x000C
		int32_t m_field10; //0x0010
		int32_t m_field14; //0x0014
		int32_t m_field18; //0x0018
		int32_t m_field1C_PTR; //0x001C
		int32_t m_field20_PTR; //0x0020
		REFTAB* m_reftab; //0x0024

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00756c0c
		virtual void Function_0001(); //#1 +4 .rdata:00756c10
		virtual void Function_0002(); //#2 +8 .rdata:00756c14
		virtual void Function_0003(); //#3 +c .rdata:00756c18
		virtual void Function_0004(); //#4 +10 .rdata:00756c1c
		virtual void Function_0005(); //#5 +14 .rdata:00756c20
		virtual void Function_0006(); //#6 +18 .rdata:00756c24
		virtual void Function_0007(); //#7 +1c .rdata:00756c28
		virtual void Function_0008(); //#8 +20 .rdata:00756c2c
		virtual void Function_0009(); //#9 +24 .rdata:00756c30
		virtual void Function_0010(); //#10 +28 .rdata:00756c34
		virtual void Function_0011(); //#11 +2c .rdata:00756c38
		virtual void Function_0012(); //#12 +30 .rdata:00756c3c
		virtual int at(int index); //#13 +34 .rdata:00756c40
		virtual void Function_0014(); //#14 +38 .rdata:00756c44
		virtual void Function_0015(); //#15 +3c .rdata:00756c48
		virtual void Function_0016(); //#16 +40 .rdata:00756c4c
		virtual void Function_0017(); //#17 +44 .rdata:00756c50
		virtual void Function_0018(); //#18 +48 .rdata:00756c54
		virtual void Function_0019(); //#19 +4c .rdata:00756c58
		virtual void Function_0020(); //#20 +50 .rdata:00756c5c
		virtual void Function_0021(); //#21 +54 .rdata:00756c60
		virtual void Function_0022(); //#22 +58 .rdata:00756c64
		virtual void Function_0023(); //#23 +5c .rdata:00756c68
		virtual void Function_0024(); //#24 +60 .rdata:00756c6c
		virtual void Function_0025(); //#25 +64 .rdata:00756c70
		virtual void Function_0026(); //#26 +68 .rdata:00756c74
		virtual void Function_0027(); //#27 +6c .rdata:00756c78
		virtual void Function_0028(); //#28 +70 .rdata:00756c7c
		virtual void Function_0029(); //#29 +74 .rdata:00756c80
		virtual void Function_0030(); //#30 +78 .rdata:00756c84
		virtual void Function_0031(); //#31 +7c .rdata:00756c88
		virtual void Function_0032(); //#32 +80 .rdata:00756c8c
		virtual void Function_0033(); //#33 +84 .rdata:00756c90
		virtual void Function_0034(); //#34 +88 .rdata:00756c94
		virtual void Function_0035(); //#35 +8c .rdata:00756c98
		virtual void Function_0036(); //#36 +90 .rdata:00756c9c
		virtual void Function_0037(); //#37 +94 .rdata:00756ca0
		virtual void Function_0038(); //#38 +98 .rdata:00756ca4
		virtual void Function_0039(); //#39 +9c .rdata:00756ca8
		virtual void Function_0040(); //#40 +a0 .rdata:00756cac
		virtual void Function_0041(); //#41 +a4 .rdata:00756cb0
		virtual void Function_0042(); //#42 +a8 .rdata:00756cb4
		virtual void Function_0043(); //#43 +ac .rdata:00756cb8
	};

	class ZSTDOBJ_TeleportEntity /// <<< DEPRECATED, DO NOT USE IT!
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
		virtual int Function_0064(const char* _componentName); //#64 +100 .rdata:0076bfdc
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

		virtual void Function_0000(); //#0 +0 .rdata:0076907c
		virtual void Function_0001(); //#1 +4 .rdata:00769080
		virtual void Function_0002(); //#2 +8 .rdata:00769084
		virtual void Function_0003(); //#3 +c .rdata:00769088
		virtual void Function_0004(); //#4 +10 .rdata:0076908c
		virtual void Function_0005(); //#5 +14 .rdata:00769090
		virtual void Function_0006(); //#6 +18 .rdata:00769094
		virtual void Function_0007(); //#7 +1c .rdata:00769098
		virtual void Function_0008(); //#8 +20 .rdata:0076909c
		virtual void Function_0009(); //#9 +24 .rdata:007690a0
		virtual void Function_0010(); //#10 +28 .rdata:007690a4
		virtual void Function_0011(); //#11 +2c .rdata:007690a8
		virtual void Function_0012(); //#12 +30 .rdata:007690ac
		virtual int  getClassID(); //#13 +34 .rdata:007690b0
		virtual void Function_0014(); //#14 +38 .rdata:007690b4
		virtual void Function_0015(); //#15 +3c .rdata:007690b8
		virtual void Function_0016(); //#16 +40 .rdata:007690bc
		virtual void Function_0017(); //#17 +44 .rdata:007690c0
		virtual void Function_0018(); //#18 +48 .rdata:007690c4
		virtual void Function_0019(); //#19 +4c .rdata:007690c8
		virtual void Function_0020(); //#20 +50 .rdata:007690cc
		virtual void Function_0021(); //#21 +54 .rdata:007690d0
		virtual void Function_0022(); //#22 +58 .rdata:007690d4
		virtual void Function_0023(); //#23 +5c .rdata:007690d8
		virtual void Function_0024(); //#24 +60 .rdata:007690dc
		virtual void Function_0025(); //#25 +64 .rdata:007690e0
		virtual void Function_0026(); //#26 +68 .rdata:007690e4
		virtual void Function_0027(); //#27 +6c .rdata:007690e8
		virtual void Function_0028(); //#28 +70 .rdata:007690ec
		virtual void Function_0029(); //#29 +74 .rdata:007690f0
		virtual void Function_0030(); //#30 +78 .rdata:007690f4
		virtual void Function_0031(); //#31 +7c .rdata:007690f8
		virtual void Function_0032(); //#32 +80 .rdata:007690fc
		virtual void Function_0033(); //#33 +84 .rdata:00769100
		virtual void Function_0034(); //#34 +88 .rdata:00769104
		virtual void Function_0035(); //#35 +8c .rdata:00769108
		virtual void Function_0036(); //#36 +90 .rdata:0076910c
		virtual void Function_0037(); //#37 +94 .rdata:00769110
		virtual void Function_0038(); //#38 +98 .rdata:00769114
		virtual void Function_0039(); //#39 +9c .rdata:00769118
		virtual void Function_0040(); //#40 +a0 .rdata:0076911c
		virtual void Function_0041(); //#41 +a4 .rdata:00769120
		virtual void Function_0042(); //#42 +a8 .rdata:00769124
		virtual void Function_0043(); //#43 +ac .rdata:00769128
		virtual void Function_0044(); //#44 +b0 .rdata:0076912c
		virtual void Function_0045(); //#45 +b4 .rdata:00769130
		virtual void Function_0046(); //#46 +b8 .rdata:00769134
		virtual void Function_0047(); //#47 +bc .rdata:00769138
		virtual void Function_0048(); //#48 +c0 .rdata:0076913c
		virtual void Function_0049(); //#49 +c4 .rdata:00769140
		virtual void Function_0050(); //#50 +c8 .rdata:00769144
		virtual void Function_0051(); //#51 +cc .rdata:00769148
		virtual void Function_0052(); //#52 +d0 .rdata:0076914c
		virtual void Function_0053(); //#53 +d4 .rdata:00769150
		virtual void Function_0054(); //#54 +d8 .rdata:00769154
		virtual void Function_0055(); //#55 +dc .rdata:00769158
		virtual void Function_0056(); //#56 +e0 .rdata:0076915c
		virtual void Function_0057(); //#57 +e4 .rdata:00769160
		virtual void Function_0058(); //#58 +e8 .rdata:00769164
		virtual void Function_0059(); //#59 +ec .rdata:00769168
		virtual void Function_0060(); //#60 +f0 .rdata:0076916c
		virtual void Function_0061(); //#61 +f4 .rdata:00769170
		virtual void Function_0062(); //#62 +f8 .rdata:00769174
		virtual void Function_0063(); //#63 +fc .rdata:00769178
		virtual void Function_0064(); //#64 +100 .rdata:0076917c
		virtual void Function_0065(); //#65 +104 .rdata:00769180
		virtual void Function_0066(); //#66 +108 .rdata:00769184
		virtual void Function_0067(); //#67 +10c .rdata:00769188
		virtual void Function_0068(); //#68 +110 .rdata:0076918c
		virtual void Function_0069(); //#69 +114 .rdata:00769190
		virtual void Function_0070(); //#70 +118 .rdata:00769194
		virtual void Function_0071(); //#71 +11c .rdata:00769198
		virtual void Function_0072(); //#72 +120 .rdata:0076919c
		virtual void Function_0073(); //#73 +124 .rdata:007691a0
		virtual void Function_0074(); //#74 +128 .rdata:007691a4
		virtual void Function_0075(); //#75 +12c .rdata:007691a8
		virtual void Function_0076(); //#76 +130 .rdata:007691ac
		virtual void Function_0077(); //#77 +134 .rdata:007691b0
		virtual void Function_0078(); //#78 +138 .rdata:007691b4
		virtual void Function_0079(); //#79 +13c .rdata:007691b8
		virtual void Function_0080(); //#80 +140 .rdata:007691bc
		virtual void Function_0081(); //#81 +144 .rdata:007691c0
		virtual void Function_0082(); //#82 +148 .rdata:007691c4
		virtual void Function_0083(); //#83 +14c .rdata:007691c8
		virtual void Function_0084(); //#84 +150 .rdata:007691cc
		virtual void Function_0085(); //#85 +154 .rdata:007691d0
		virtual void Function_0086(); //#86 +158 .rdata:007691d4
		virtual void Function_0087(); //#87 +15c .rdata:007691d8
		virtual void Function_0088(); //#88 +160 .rdata:007691dc
		virtual void Function_0089(); //#89 +164 .rdata:007691e0
		virtual void Function_0090(); //#90 +168 .rdata:007691e4
		virtual void Function_0091(); //#91 +16c .rdata:007691e8
		virtual void Function_0092(); //#92 +170 .rdata:007691ec
		virtual void Function_0093(); //#93 +174 .rdata:007691f0
		virtual void Function_0094(); //#94 +178 .rdata:007691f4
		virtual void Function_0095(); //#95 +17c .rdata:007691f8
		virtual void Function_0096(); //#96 +180 .rdata:007691fc
		virtual void Function_0097(); //#97 +184 .rdata:00769200
		virtual void Function_0098(); //#98 +188 .rdata:00769204
		virtual void Function_0099(); //#99 +18c .rdata:00769208
		virtual void Function_0100(); //#100 +190 .rdata:0076920c
		virtual void Function_0101(); //#101 +194 .rdata:00769210
		virtual void Function_0102(); //#102 +198 .rdata:00769214
		virtual void Function_0103(); //#103 +19c .rdata:00769218
		virtual void Function_0104(); //#104 +1a0 .rdata:0076921c
		virtual void Function_0105(); //#105 +1a4 .rdata:00769220
		virtual void Function_0106(); //#106 +1a8 .rdata:00769224
		virtual void Function_0107(); //#107 +1ac .rdata:00769228
		virtual void Function_0108(); //#108 +1b0 .rdata:0076922c
		virtual void Function_0109(); //#109 +1b4 .rdata:00769230
		virtual void Function_0110(); //#110 +1b8 .rdata:00769234
		virtual void Function_0111(); //#111 +1bc .rdata:00769238
		virtual void Function_0112(); //#112 +1c0 .rdata:0076923c
		virtual void Function_0113(); //#113 +1c4 .rdata:00769240
		virtual void Function_0114(); //#114 +1c8 .rdata:00769244
		virtual void Function_0115(); //#115 +1cc .rdata:00769248
		virtual void Function_0116(); //#116 +1d0 .rdata:0076924c
		virtual void Function_0117(); //#117 +1d4 .rdata:00769250
	}; //Size: 0x0010

	class ZOffsetAlloc
	{
	public:
		/// === members ===
		int32_t m_field4; //0x0004
		int32_t m_field8; //0x0008
		int32_t m_fieldC; //0x000C
		int32_t m_field10; //0x0010
		int32_t m_field14; //0x0014

		/// === vftable ===
		virtual void Function0();
	}; //Size: 0x0018

	class ZOctreeCompiled
	{
	public:
		/// === members ===
		int32_t m_field4; //0x0004
		int32_t m_field8; //0x0008
		int32_t m_fieldC; //0x000C
		int32_t m_field10; //0x0010
		uint32_t m_unkData; //0x0014

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00766494
		virtual void Function_0001(); //#1 +4 .rdata:00766498
		virtual void Function_0002(); //#2 +8 .rdata:0076649c
		virtual void Function_0003(); //#3 +c .rdata:007664a0
		virtual void Function_0004(); //#4 +10 .rdata:007664a4
		virtual void Function_0005(); //#5 +14 .rdata:007664a8
		virtual void Function_0006(); //#6 +18 .rdata:007664ac
		virtual void Function_0007(); //#7 +1c .rdata:007664b0
		virtual void Function_0008(); //#8 +20 .rdata:007664b4
		virtual void Function_0009(); //#9 +24 .rdata:007664b8
		virtual void Function_0010(); //#10 +28 .rdata:007664bc
	}; //Size: 0x0018

	/***
	 * @fn stdobj_cast
	 * @brief This function trying to cast any ZSTDOBJ to any in-game object. 
	 *		  If cast available this function will return correct and casted pointer, otherwise it will return nullptr.
	 ***/
	template <typename _T> _T* stdobj_cast(ZSTDOBJ* obj);
}