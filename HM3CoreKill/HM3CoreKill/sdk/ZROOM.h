#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 { 
	class ZROOMPOOL;

	class ZROOM
	{
	public:
		/// === members ===
		ZEntityLocator* m_rootEntity; //0x0004
		char pad_0008[4]; //0x0008
		uint32_t __MEMCHECK__; //0x000C
		char pad_0010[44]; //0x0010
		ZEntityLocator* m_entity0; //0x003C
		ZEntityLocator* m_entity1; //0x0040
		char pad_0044[12]; //0x0044
		class ZOctreeCompiled* m_octree0; //0x0050
		class ZOctreeCompiled* m_octree1; //0x0054
		char pad_0058[4]; //0x0058
		class ZOctreeCompiled* m_octree2; //0x005C
		class ZOctreeCompiled* m_octree3; //0x0060
		class ZOctreeCompiled* m_octree4; //0x0064
		char pad_0068[4]; //0x0068
		uint32_t m_roomPool; //0x006C
		char pad_0070[20]; //0x0070

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0076e30c
		virtual void Function_0001(); //#1 +4 .rdata:0076e310
		virtual void Function_0002(); //#2 +8 .rdata:0076e314
		virtual void Function_0003(); //#3 +c .rdata:0076e318
		virtual void Function_0004(); //#4 +10 .rdata:0076e31c
		virtual void Function_0005(); //#5 +14 .rdata:0076e320
		virtual void Function_0006(); //#6 +18 .rdata:0076e324
		virtual void Function_0007(); //#7 +1c .rdata:0076e328
		virtual void Function_0008(); //#8 +20 .rdata:0076e32c
		virtual void Function_0009(); //#9 +24 .rdata:0076e330
		virtual void Function_0010(); //#10 +28 .rdata:0076e334
		virtual void Function_0011(); //#11 +2c .rdata:0076e338
		virtual void Function_0012(); //#12 +30 .rdata:0076e33c
		virtual void Function_0013(); //#13 +34 .rdata:0076e340
		virtual void Function_0014(); //#14 +38 .rdata:0076e344
		virtual void Function_0015(); //#15 +3c .rdata:0076e348
		virtual void Function_0016(); //#16 +40 .rdata:0076e34c
		virtual void Function_0017(); //#17 +44 .rdata:0076e350
		virtual void Function_0018(); //#18 +48 .rdata:0076e354
		virtual void Function_0019(); //#19 +4c .rdata:0076e358
		virtual void Function_0020(); //#20 +50 .rdata:0076e35c
		virtual void Function_0021(); //#21 +54 .rdata:0076e360
		virtual void Function_0022(); //#22 +58 .rdata:0076e364
		virtual void Function_0023(); //#23 +5c .rdata:0076e368
		virtual void Function_0024(); //#24 +60 .rdata:0076e36c
		virtual void Function_0025(); //#25 +64 .rdata:0076e370
		virtual void Function_0026(); //#26 +68 .rdata:0076e374
		virtual void Function_0027(); //#27 +6c .rdata:0076e378
		virtual void Function_0028(); //#28 +70 .rdata:0076e37c
		virtual void Function_0029(); //#29 +74 .rdata:0076e380
		virtual void Function_0030(); //#30 +78 .rdata:0076e384
		virtual void Function_0031(); //#31 +7c .rdata:0076e388
		virtual void Function_0032(); //#32 +80 .rdata:0076e38c
		virtual void Function_0033(); //#33 +84 .rdata:0076e390
		virtual void Function_0034(); //#34 +88 .rdata:0076e394
		virtual void Function_0035(); //#35 +8c .rdata:0076e398
		virtual void Function_0036(); //#36 +90 .rdata:0076e39c
		virtual void Function_0037(); //#37 +94 .rdata:0076e3a0
		virtual void Function_0038(); //#38 +98 .rdata:0076e3a4
		virtual void Function_0039(); //#39 +9c .rdata:0076e3a8
		virtual void Function_0040(); //#40 +a0 .rdata:0076e3ac
		virtual void Function_0041(); //#41 +a4 .rdata:0076e3b0
		virtual void Function_0042(); //#42 +a8 .rdata:0076e3b4
		virtual void Function_0043(); //#43 +ac .rdata:0076e3b8
		virtual void Function_0044(); //#44 +b0 .rdata:0076e3bc
		virtual void Function_0045(); //#45 +b4 .rdata:0076e3c0
		virtual void Function_0046(); //#46 +b8 .rdata:0076e3c4
		virtual void Function_0047(); //#47 +bc .rdata:0076e3c8
		virtual void Function_0048(); //#48 +c0 .rdata:0076e3cc
		virtual void Function_0049(); //#49 +c4 .rdata:0076e3d0
		virtual void Function_0050(); //#50 +c8 .rdata:0076e3d4
		virtual void Function_0051(); //#51 +cc .rdata:0076e3d8
		virtual void Function_0052(); //#52 +d0 .rdata:0076e3dc
		virtual void Function_0053(); //#53 +d4 .rdata:0076e3e0
		virtual void Function_0054(); //#54 +d8 .rdata:0076e3e4
		virtual void Function_0055(); //#55 +dc .rdata:0076e3e8
		virtual void Function_0056(); //#56 +e0 .rdata:0076e3ec
		virtual void Function_0057(); //#57 +e4 .rdata:0076e3f0
		virtual void Function_0058(); //#58 +e8 .rdata:0076e3f4
		virtual void Function_0059(); //#59 +ec .rdata:0076e3f8
		virtual void Function_0060(); //#60 +f0 .rdata:0076e3fc
		virtual void Function_0061(); //#61 +f4 .rdata:0076e400
		virtual void Function_0062(); //#62 +f8 .rdata:0076e404
		virtual void Function_0063(); //#63 +fc .rdata:0076e408
		virtual void Function_0064(); //#64 +100 .rdata:0076e40c
		virtual void Function_0065(); //#65 +104 .rdata:0076e410
		virtual void Function_0066(); //#66 +108 .rdata:0076e414
		virtual void Function_0067(); //#67 +10c .rdata:0076e418
		virtual void Function_0068(); //#68 +110 .rdata:0076e41c
		virtual void Function_0069(); //#69 +114 .rdata:0076e420
		virtual void Function_0070(); //#70 +118 .rdata:0076e424
		virtual void Function_0071(); //#71 +11c .rdata:0076e428
		virtual void Function_0072(); //#72 +120 .rdata:0076e42c
		virtual void Function_0073(); //#73 +124 .rdata:0076e430
		virtual void Function_0074(); //#74 +128 .rdata:0076e434
		virtual void Function_0075(); //#75 +12c .rdata:0076e438
		virtual void Function_0076(); //#76 +130 .rdata:0076e43c
		virtual void Function_0077(); //#77 +134 .rdata:0076e440
		virtual void Function_0078(); //#78 +138 .rdata:0076e444
		virtual void Function_0079(); //#79 +13c .rdata:0076e448
		virtual void Function_0080(); //#80 +140 .rdata:0076e44c
		virtual void Function_0081(); //#81 +144 .rdata:0076e450
		virtual void Function_0082(); //#82 +148 .rdata:0076e454
		virtual void Function_0083(); //#83 +14c .rdata:0076e458
		virtual void Function_0084(); //#84 +150 .rdata:0076e45c
		virtual void Function_0085(); //#85 +154 .rdata:0076e460
		virtual void Function_0086(); //#86 +158 .rdata:0076e464
		virtual void Function_0087(); //#87 +15c .rdata:0076e468
		virtual void Function_0088(); //#88 +160 .rdata:0076e46c
		virtual void Function_0089(); //#89 +164 .rdata:0076e470
		virtual void Function_0090(); //#90 +168 .rdata:0076e474
		virtual void Function_0091(); //#91 +16c .rdata:0076e478
		virtual void Function_0092(); //#92 +170 .rdata:0076e47c
		virtual void Function_0093(); //#93 +174 .rdata:0076e480
		virtual void Function_0094(); //#94 +178 .rdata:0076e484
		virtual void Function_0095(); //#95 +17c .rdata:0076e488
		virtual void Function_0096(); //#96 +180 .rdata:0076e48c
		virtual void Function_0097(); //#97 +184 .rdata:0076e490
		virtual void Function_0098(); //#98 +188 .rdata:0076e494
		virtual void Function_0099(); //#99 +18c .rdata:0076e498
		virtual void Function_0100(); //#100 +190 .rdata:0076e49c
		virtual void Function_0101(); //#101 +194 .rdata:0076e4a0
		virtual void Function_0102(); //#102 +198 .rdata:0076e4a4
		virtual void Function_0103(); //#103 +19c .rdata:0076e4a8
		virtual void Function_0104(); //#104 +1a0 .rdata:0076e4ac
		virtual void Function_0105(); //#105 +1a4 .rdata:0076e4b0
		virtual void Function_0106(); //#106 +1a8 .rdata:0076e4b4
		virtual void Function_0107(); //#107 +1ac .rdata:0076e4b8
		virtual void Function_0108(); //#108 +1b0 .rdata:0076e4bc
		virtual void Function_0109(); //#109 +1b4 .rdata:0076e4c0
		virtual void Function_0110(); //#110 +1b8 .rdata:0076e4c4
		virtual void Function_0111(); //#111 +1bc .rdata:0076e4c8
		virtual void Function_0112(); //#112 +1c0 .rdata:0076e4cc
		virtual void Function_0113(); //#113 +1c4 .rdata:0076e4d0
		virtual void Function_0114(); //#114 +1c8 .rdata:0076e4d4
		virtual void Function_0115(); //#115 +1cc .rdata:0076e4d8
		virtual void Function_0116(); //#116 +1d0 .rdata:0076e4dc
		virtual void Function_0117(); //#117 +1d4 .rdata:0076e4e0
		virtual void Function_0118(); //#118 +1d8 .rdata:0076e4e4
		virtual void Function_0119(); //#119 +1dc .rdata:0076e4e8
		virtual void Function_0120(); //#120 +1e0 .rdata:0076e4ec
		virtual void Function_0121(); //#121 +1e4 .rdata:0076e4f0
		virtual void Function_0122(); //#122 +1e8 .rdata:0076e4f4
		virtual void Function_0123(); //#123 +1ec .rdata:0076e4f8
		virtual void Function_0124(); //#124 +1f0 .rdata:0076e4fc
		virtual void Function_0125(); //#125 +1f4 .rdata:0076e500
		virtual void Function_0126(); //#126 +1f8 .rdata:0076e504
		virtual void Function_0127(); //#127 +1fc .rdata:0076e508
		virtual void Function_0128(); //#128 +200 .rdata:0076e50c
		virtual void Function_0129(); //#129 +204 .rdata:0076e510
		virtual void Function_0130(); //#130 +208 .rdata:0076e514
		virtual void Function_0131(); //#131 +20c .rdata:0076e518
		virtual void Function_0132(); //#132 +210 .rdata:0076e51c
		virtual void Function_0133(); //#133 +214 .rdata:0076e520
		virtual void Function_0134(); //#134 +218 .rdata:0076e524
		virtual void Function_0135(); //#135 +21c .rdata:0076e528
		virtual void Function_0136(); //#136 +220 .rdata:0076e52c
		virtual void Function_0137(); //#137 +224 .rdata:0076e530
		virtual void Function_0138(); //#138 +228 .rdata:0076e534
		virtual void Function_0139(); //#139 +22c .rdata:0076e538
		virtual void Function_0140(); //#140 +230 .rdata:0076e53c
		virtual void Function_0141(); //#141 +234 .rdata:0076e540
		virtual void Function_0142(); //#142 +238 .rdata:0076e544
		virtual void Function_0143(); //#143 +23c .rdata:0076e548
		virtual void Function_0144(); //#144 +240 .rdata:0076e54c
		virtual void Function_0145(); //#145 +244 .rdata:0076e550
		virtual void Function_0146(); //#146 +248 .rdata:0076e554
		virtual void Function_0147(); //#147 +24c .rdata:0076e558
		virtual void Function_0148(); //#148 +250 .rdata:0076e55c
		virtual void Function_0149(); //#149 +254 .rdata:0076e560
		virtual void Function_0150(); //#150 +258 .rdata:0076e564
		virtual void Function_0151(); //#151 +25c .rdata:0076e568
		virtual void Function_0152(); //#152 +260 .rdata:0076e56c
		virtual void Function_0153(); //#153 +264 .rdata:0076e570
		virtual void Function_0154(); //#154 +268 .rdata:0076e574
		virtual void Function_0155(); //#155 +26c .rdata:0076e578
		virtual void Function_0156(); //#156 +270 .rdata:0076e57c
		virtual void Function_0157(); //#157 +274 .rdata:0076e580
		virtual void Function_0158(); //#158 +278 .rdata:0076e584
		virtual void Function_0159(); //#159 +27c .rdata:0076e588
		virtual void Function_0160(); //#160 +280 .rdata:0076e58c
		virtual void Function_0161(); //#161 +284 .rdata:0076e590
		virtual void Function_0162(); //#162 +288 .rdata:0076e594
		virtual void Function_0163(); //#163 +28c .rdata:0076e598
		virtual void Function_0164(); //#164 +290 .rdata:0076e59c
		virtual void Function_0165(); //#165 +294 .rdata:0076e5a0
		virtual void Function_0166(); //#166 +298 .rdata:0076e5a4
		virtual void Function_0167(); //#167 +29c .rdata:0076e5a8
		virtual void Function_0168(); //#168 +2a0 .rdata:0076e5ac
		virtual void Function_0169(); //#169 +2a4 .rdata:0076e5b0
		virtual void Function_0170(); //#170 +2a8 .rdata:0076e5b4
		virtual void Function_0171(); //#171 +2ac .rdata:0076e5b8
		virtual void Function_0172(); //#172 +2b0 .rdata:0076e5bc
		virtual void Function_0173(); //#173 +2b4 .rdata:0076e5c0
		virtual void Function_0174(); //#174 +2b8 .rdata:0076e5c4
		virtual void Function_0175(); //#175 +2bc .rdata:0076e5c8
		virtual void Function_0176(); //#176 +2c0 .rdata:0076e5cc
		virtual void Function_0177(); //#177 +2c4 .rdata:0076e5d0
		virtual void Function_0178(); //#178 +2c8 .rdata:0076e5d4
		virtual void Function_0179(); //#179 +2cc .rdata:0076e5d8
		virtual void Function_0180(); //#180 +2d0 .rdata:0076e5dc
		virtual void Function_0181(); //#181 +2d4 .rdata:0076e5e0
		virtual void Function_0182(); //#182 +2d8 .rdata:0076e5e4
		virtual void Function_0183(); //#183 +2dc .rdata:0076e5e8
		virtual void Function_0184(); //#184 +2e0 .rdata:0076e5ec
		virtual void Function_0185(); //#185 +2e4 .rdata:0076e5f0
		virtual void Function_0186(); //#186 +2e8 .rdata:0076e5f4
		virtual void Function_0187(); //#187 +2ec .rdata:0076e5f8
		virtual void Function_0188(); //#188 +2f0 .rdata:0076e5fc
		virtual void Function_0189(); //#189 +2f4 .rdata:0076e600
		virtual void Function_0190(); //#190 +2f8 .rdata:0076e604

		/// === customs ===
		static ZROOM* getRoomByEntityLocator(ZEntityLocator* _entity);
	};

	class ZROOMPOOL
	{
	public:
		int32_t m_count; //0x0000
		ZROOM* m_pool[417]; //0x0004
	};

}}