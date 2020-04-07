#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {

	class ZGROUP
	{
	public:
		/// === members ===
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[52]; //0x0008
		ZEntityLocator* m_leftBranch; //0x003C
		ZEntityLocator* m_rightBranch; //0x0040
		char pad_0044[8]; //0x0044

		/// === vftable ===s
		virtual void Function_0000(); //#0 +0 .rdata:0076a4c4
		virtual void Function_0001(); //#1 +4 .rdata:0076a4c8
		virtual void Function_0002(); //#2 +8 .rdata:0076a4cc
		virtual void Function_0003(); //#3 +c .rdata:0076a4d0
		virtual void Function_0004(); //#4 +10 .rdata:0076a4d4
		virtual void Function_0005(); //#5 +14 .rdata:0076a4d8
		virtual void Function_0006(); //#6 +18 .rdata:0076a4dc
		virtual void Function_0007(); //#7 +1c .rdata:0076a4e0
		virtual void Function_0008(); //#8 +20 .rdata:0076a4e4
		virtual void Function_0009(); //#9 +24 .rdata:0076a4e8
		virtual void Function_0010(); //#10 +28 .rdata:0076a4ec
		virtual void Function_0011(); //#11 +2c .rdata:0076a4f0
		virtual void Function_0012(); //#12 +30 .rdata:0076a4f4
		virtual void Function_0013(); //#13 +34 .rdata:0076a4f8
		virtual void Function_0014(); //#14 +38 .rdata:0076a4fc
		virtual void Function_0015(); //#15 +3c .rdata:0076a500
		virtual void Function_0016(); //#16 +40 .rdata:0076a504
		virtual void Function_0017(); //#17 +44 .rdata:0076a508
		virtual void Function_0018(); //#18 +48 .rdata:0076a50c
		virtual void Function_0019(); //#19 +4c .rdata:0076a510
		virtual void Function_0020(); //#20 +50 .rdata:0076a514
		virtual void Function_0021(); //#21 +54 .rdata:0076a518
		virtual void Function_0022(); //#22 +58 .rdata:0076a51c
		virtual void Function_0023(); //#23 +5c .rdata:0076a520
		virtual void Function_0024(); //#24 +60 .rdata:0076a524
		virtual void Function_0025(); //#25 +64 .rdata:0076a528
		virtual void Function_0026(); //#26 +68 .rdata:0076a52c
		virtual void Function_0027(); //#27 +6c .rdata:0076a530
		virtual void Function_0028(); //#28 +70 .rdata:0076a534
		virtual void Function_0029(); //#29 +74 .rdata:0076a538
		virtual void Function_0030(); //#30 +78 .rdata:0076a53c
		virtual void Function_0031(); //#31 +7c .rdata:0076a540
		virtual void Function_0032(); //#32 +80 .rdata:0076a544
		virtual void Function_0033(); //#33 +84 .rdata:0076a548
		virtual void Function_0034(); //#34 +88 .rdata:0076a54c
		virtual void Function_0035(); //#35 +8c .rdata:0076a550
		virtual void Function_0036(); //#36 +90 .rdata:0076a554
		virtual void Function_0037(); //#37 +94 .rdata:0076a558
		virtual void Function_0038(); //#38 +98 .rdata:0076a55c
		virtual void Function_0039(); //#39 +9c .rdata:0076a560
		virtual void Function_0040(); //#40 +a0 .rdata:0076a564
		virtual void Function_0041(); //#41 +a4 .rdata:0076a568
		virtual void Function_0042(); //#42 +a8 .rdata:0076a56c
		virtual void Function_0043(); //#43 +ac .rdata:0076a570
		virtual void Function_0044(); //#44 +b0 .rdata:0076a574
		virtual void Function_0045(); //#45 +b4 .rdata:0076a578
		virtual void Function_0046(); //#46 +b8 .rdata:0076a57c
		virtual void Function_0047(); //#47 +bc .rdata:0076a580
		virtual void Function_0048(); //#48 +c0 .rdata:0076a584
		virtual void Function_0049(); //#49 +c4 .rdata:0076a588
		virtual void Function_0050(); //#50 +c8 .rdata:0076a58c
		virtual void Function_0051(); //#51 +cc .rdata:0076a590
		virtual void Function_0052(); //#52 +d0 .rdata:0076a594
		virtual void Function_0053(); //#53 +d4 .rdata:0076a598
		virtual void Function_0054(); //#54 +d8 .rdata:0076a59c
		virtual void Function_0055(); //#55 +dc .rdata:0076a5a0
		virtual void Function_0056(); //#56 +e0 .rdata:0076a5a4
		virtual void Function_0057(); //#57 +e4 .rdata:0076a5a8
		virtual void Function_0058(); //#58 +e8 .rdata:0076a5ac
		virtual void Function_0059(); //#59 +ec .rdata:0076a5b0
		virtual void Function_0060(); //#60 +f0 .rdata:0076a5b4
		virtual void Function_0061(); //#61 +f4 .rdata:0076a5b8
		virtual void Function_0062(); //#62 +f8 .rdata:0076a5bc
		virtual void Function_0063(); //#63 +fc .rdata:0076a5c0
		virtual void Function_0064(); //#64 +100 .rdata:0076a5c4
		virtual void Function_0065(); //#65 +104 .rdata:0076a5c8
		virtual void Function_0066(); //#66 +108 .rdata:0076a5cc
		virtual void Function_0067(); //#67 +10c .rdata:0076a5d0
		virtual void Function_0068(); //#68 +110 .rdata:0076a5d4
		virtual void Function_0069(); //#69 +114 .rdata:0076a5d8
		virtual void Function_0070(); //#70 +118 .rdata:0076a5dc
		virtual void Function_0071(); //#71 +11c .rdata:0076a5e0
		virtual void Function_0072(); //#72 +120 .rdata:0076a5e4
		virtual void Function_0073(); //#73 +124 .rdata:0076a5e8
		virtual void Function_0074(); //#74 +128 .rdata:0076a5ec
		virtual void Function_0075(); //#75 +12c .rdata:0076a5f0
		virtual void Function_0076(); //#76 +130 .rdata:0076a5f4
		virtual void Function_0077(); //#77 +134 .rdata:0076a5f8
		virtual void Function_0078(); //#78 +138 .rdata:0076a5fc
		virtual void Function_0079(); //#79 +13c .rdata:0076a600
		virtual void Function_0080(); //#80 +140 .rdata:0076a604
		virtual void Function_0081(); //#81 +144 .rdata:0076a608
		virtual void Function_0082(); //#82 +148 .rdata:0076a60c
		virtual void Function_0083(); //#83 +14c .rdata:0076a610
		virtual void Function_0084(); //#84 +150 .rdata:0076a614
		virtual void Function_0085(); //#85 +154 .rdata:0076a618
		virtual void Function_0086(); //#86 +158 .rdata:0076a61c
		virtual void Function_0087(); //#87 +15c .rdata:0076a620
		virtual void Function_0088(); //#88 +160 .rdata:0076a624
		virtual void Function_0089(); //#89 +164 .rdata:0076a628
		virtual void Function_0090(); //#90 +168 .rdata:0076a62c
		virtual void Function_0091(); //#91 +16c .rdata:0076a630
		virtual void Function_0092(); //#92 +170 .rdata:0076a634
		virtual void Function_0093(); //#93 +174 .rdata:0076a638
		virtual void Function_0094(); //#94 +178 .rdata:0076a63c
		virtual void Function_0095(); //#95 +17c .rdata:0076a640
		virtual void Function_0096(); //#96 +180 .rdata:0076a644
		virtual void Function_0097(); //#97 +184 .rdata:0076a648
		virtual void Function_0098(); //#98 +188 .rdata:0076a64c
		virtual void Function_0099(); //#99 +18c .rdata:0076a650
		virtual void Function_0100(); //#100 +190 .rdata:0076a654
		virtual void Function_0101(); //#101 +194 .rdata:0076a658
		virtual void Function_0102(); //#102 +198 .rdata:0076a65c
		virtual void Function_0103(); //#103 +19c .rdata:0076a660
		virtual void Function_0104(); //#104 +1a0 .rdata:0076a664
		virtual void Function_0105(); //#105 +1a4 .rdata:0076a668
		virtual void Function_0106(); //#106 +1a8 .rdata:0076a66c
		virtual void Function_0107(); //#107 +1ac .rdata:0076a670
		virtual void Function_0108(); //#108 +1b0 .rdata:0076a674
		virtual void Function_0109(); //#109 +1b4 .rdata:0076a678
		virtual void Function_0110(); //#110 +1b8 .rdata:0076a67c
		virtual void Function_0111(); //#111 +1bc .rdata:0076a680
		virtual void Function_0112(); //#112 +1c0 .rdata:0076a684
		virtual void Function_0113(); //#113 +1c4 .rdata:0076a688
		virtual void Function_0114(); //#114 +1c8 .rdata:0076a68c
		virtual void Function_0115(); //#115 +1cc .rdata:0076a690
		virtual void Function_0116(); //#116 +1d0 .rdata:0076a694
		virtual void Function_0117(); //#117 +1d4 .rdata:0076a698
		virtual void Function_0118(); //#118 +1d8 .rdata:0076a69c
		virtual void Function_0119(); //#119 +1dc .rdata:0076a6a0
		virtual void Function_0120(); //#120 +1e0 .rdata:0076a6a4
		virtual void Function_0121(); //#121 +1e4 .rdata:0076a6a8
		virtual void Function_0122(); //#122 +1e8 .rdata:0076a6ac
		virtual void Function_0123(); //#123 +1ec .rdata:0076a6b0
		virtual void Function_0124(); //#124 +1f0 .rdata:0076a6b4
		virtual void Function_0125(); //#125 +1f4 .rdata:0076a6b8
		virtual void Function_0126(); //#126 +1f8 .rdata:0076a6bc
		virtual void Function_0127(); //#127 +1fc .rdata:0076a6c0
		virtual void Function_0128(); //#128 +200 .rdata:0076a6c4
		virtual void Function_0129(); //#129 +204 .rdata:0076a6c8
		virtual void Function_0130(); //#130 +208 .rdata:0076a6cc
		virtual void Function_0131(); //#131 +20c .rdata:0076a6d0
		virtual void Function_0132(); //#132 +210 .rdata:0076a6d4
		virtual void Function_0133(); //#133 +214 .rdata:0076a6d8
		virtual void Function_0134(); //#134 +218 .rdata:0076a6dc
		virtual void Function_0135(); //#135 +21c .rdata:0076a6e0
		virtual void Function_0136(); //#136 +220 .rdata:0076a6e4
		virtual void Function_0137(); //#137 +224 .rdata:0076a6e8
		virtual void Function_0138(); //#138 +228 .rdata:0076a6ec
		virtual void Function_0139(); //#139 +22c .rdata:0076a6f0
		virtual void Function_0140(); //#140 +230 .rdata:0076a6f4
		virtual void Function_0141(); //#141 +234 .rdata:0076a6f8
		virtual void Function_0142(); //#142 +238 .rdata:0076a6fc
		virtual void Function_0143(); //#143 +23c .rdata:0076a700
		virtual void Function_0144(); //#144 +240 .rdata:0076a704
		virtual void Function_0145(); //#145 +244 .rdata:0076a708
		virtual void Function_0146(); //#146 +248 .rdata:0076a70c

		static ZGROUP* getGroupByEntityLocator(ioi::hm3::ZEntityLocator* _entity);
	}; //Size: 0x004C

}}