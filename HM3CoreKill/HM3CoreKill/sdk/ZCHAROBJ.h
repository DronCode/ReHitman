#pragma once

#include <cstdint>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {

	class ZCHAROBJ
	{
	public:
		/// === members ===
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[4]; //0x0008
		int32_t __MEMCHECK__; //0x000C
		char pad_0010[136]; //0x0010
		uint32_t m_font; //0x0098
		char pad_009C[4]; //0x009C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0077cd34
		virtual void Function_0001(); //#1 +4 .rdata:0077cd38
		virtual void Function_0002(); //#2 +8 .rdata:0077cd3c
		virtual void Function_0003(); //#3 +c .rdata:0077cd40
		virtual void Function_0004(); //#4 +10 .rdata:0077cd44
		virtual void Function_0005(); //#5 +14 .rdata:0077cd48
		virtual void Function_0006(); //#6 +18 .rdata:0077cd4c
		virtual void Function_0007(); //#7 +1c .rdata:0077cd50
		virtual void Function_0008(); //#8 +20 .rdata:0077cd54
		virtual void Function_0009(); //#9 +24 .rdata:0077cd58
		virtual void Function_0010(); //#10 +28 .rdata:0077cd5c
		virtual void Function_0011(); //#11 +2c .rdata:0077cd60
		virtual void Function_0012(); //#12 +30 .rdata:0077cd64
		virtual void Function_0013(); //#13 +34 .rdata:0077cd68
		virtual void Function_0014(); //#14 +38 .rdata:0077cd6c
		virtual void Function_0015(); //#15 +3c .rdata:0077cd70
		virtual void Function_0016(); //#16 +40 .rdata:0077cd74
		virtual void Function_0017(); //#17 +44 .rdata:0077cd78
		virtual void Function_0018(); //#18 +48 .rdata:0077cd7c
		virtual void Function_0019(); //#19 +4c .rdata:0077cd80
		virtual void Function_0020(); //#20 +50 .rdata:0077cd84
		virtual void Function_0021(); //#21 +54 .rdata:0077cd88
		virtual void Function_0022(); //#22 +58 .rdata:0077cd8c
		virtual void Function_0023(); //#23 +5c .rdata:0077cd90
		virtual void Function_0024(); //#24 +60 .rdata:0077cd94
		virtual void Function_0025(); //#25 +64 .rdata:0077cd98
		virtual void Function_0026(); //#26 +68 .rdata:0077cd9c
		virtual void Function_0027(); //#27 +6c .rdata:0077cda0
		virtual void Function_0028(); //#28 +70 .rdata:0077cda4
		virtual void Function_0029(); //#29 +74 .rdata:0077cda8
		virtual void Function_0030(); //#30 +78 .rdata:0077cdac
		virtual void Function_0031(); //#31 +7c .rdata:0077cdb0
		virtual void Function_0032(); //#32 +80 .rdata:0077cdb4
		virtual void Function_0033(); //#33 +84 .rdata:0077cdb8
		virtual void Function_0034(); //#34 +88 .rdata:0077cdbc
		virtual void Function_0035(); //#35 +8c .rdata:0077cdc0
		virtual void Function_0036(); //#36 +90 .rdata:0077cdc4
		virtual void Function_0037(); //#37 +94 .rdata:0077cdc8
		virtual void Function_0038(); //#38 +98 .rdata:0077cdcc
		virtual void Function_0039(); //#39 +9c .rdata:0077cdd0
		virtual void Function_0040(); //#40 +a0 .rdata:0077cdd4
		virtual void Function_0041(); //#41 +a4 .rdata:0077cdd8
		virtual void Function_0042(); //#42 +a8 .rdata:0077cddc
		virtual void Function_0043(); //#43 +ac .rdata:0077cde0
		virtual void Function_0044(); //#44 +b0 .rdata:0077cde4
		virtual void Function_0045(); //#45 +b4 .rdata:0077cde8
		virtual void Function_0046(); //#46 +b8 .rdata:0077cdec
		virtual void Function_0047(); //#47 +bc .rdata:0077cdf0
		virtual void Function_0048(); //#48 +c0 .rdata:0077cdf4
		virtual void Function_0049(); //#49 +c4 .rdata:0077cdf8
		virtual void Function_0050(); //#50 +c8 .rdata:0077cdfc
		virtual void Function_0051(); //#51 +cc .rdata:0077ce00
		virtual void Function_0052(); //#52 +d0 .rdata:0077ce04
		virtual void Function_0053(); //#53 +d4 .rdata:0077ce08
		virtual void Function_0054(); //#54 +d8 .rdata:0077ce0c
		virtual void Function_0055(); //#55 +dc .rdata:0077ce10
		virtual void Function_0056(); //#56 +e0 .rdata:0077ce14
		virtual void Function_0057(); //#57 +e4 .rdata:0077ce18
		virtual void Function_0058(); //#58 +e8 .rdata:0077ce1c
		virtual void Function_0059(); //#59 +ec .rdata:0077ce20
		virtual void Function_0060(); //#60 +f0 .rdata:0077ce24
		virtual void Function_0061(); //#61 +f4 .rdata:0077ce28
		virtual void Function_0062(); //#62 +f8 .rdata:0077ce2c
		virtual void Function_0063(); //#63 +fc .rdata:0077ce30
		virtual void Function_0064(); //#64 +100 .rdata:0077ce34
		virtual void Function_0065(); //#65 +104 .rdata:0077ce38
		virtual void Function_0066(); //#66 +108 .rdata:0077ce3c
		virtual void Function_0067(); //#67 +10c .rdata:0077ce40
		virtual void Function_0068(); //#68 +110 .rdata:0077ce44
		virtual void Function_0069(); //#69 +114 .rdata:0077ce48
		virtual void Function_0070(); //#70 +118 .rdata:0077ce4c
		virtual void Function_0071(); //#71 +11c .rdata:0077ce50
		virtual void Function_0072(); //#72 +120 .rdata:0077ce54
		virtual void Function_0073(); //#73 +124 .rdata:0077ce58
		virtual void Function_0074(); //#74 +128 .rdata:0077ce5c
		virtual void Function_0075(); //#75 +12c .rdata:0077ce60
		virtual void Function_0076(); //#76 +130 .rdata:0077ce64
		virtual void Function_0077(); //#77 +134 .rdata:0077ce68
		virtual void Function_0078(); //#78 +138 .rdata:0077ce6c
		virtual void Function_0079(); //#79 +13c .rdata:0077ce70
		virtual void Function_0080(); //#80 +140 .rdata:0077ce74
		virtual void Function_0081(); //#81 +144 .rdata:0077ce78
		virtual void Function_0082(); //#82 +148 .rdata:0077ce7c
		virtual void Function_0083(); //#83 +14c .rdata:0077ce80
		virtual void Function_0084(); //#84 +150 .rdata:0077ce84
		virtual void Function_0085(); //#85 +154 .rdata:0077ce88
		virtual void Function_0086(); //#86 +158 .rdata:0077ce8c
		virtual void Function_0087(); //#87 +15c .rdata:0077ce90
		virtual void Function_0088(); //#88 +160 .rdata:0077ce94
		virtual void Function_0089(); //#89 +164 .rdata:0077ce98
		virtual void Function_0090(); //#90 +168 .rdata:0077ce9c
		virtual void Function_0091(); //#91 +16c .rdata:0077cea0
		virtual void Function_0092(); //#92 +170 .rdata:0077cea4
		virtual void Function_0093(); //#93 +174 .rdata:0077cea8
		virtual void Function_0094(); //#94 +178 .rdata:0077ceac
		virtual void Function_0095(); //#95 +17c .rdata:0077ceb0
		virtual void Function_0096(); //#96 +180 .rdata:0077ceb4
		virtual void Function_0097(); //#97 +184 .rdata:0077ceb8
		virtual void Function_0098(); //#98 +188 .rdata:0077cebc
		virtual void Function_0099(); //#99 +18c .rdata:0077cec0
		virtual void Function_0100(); //#100 +190 .rdata:0077cec4
		virtual void Function_0101(); //#101 +194 .rdata:0077cec8
		virtual void Function_0102(); //#102 +198 .rdata:0077cecc
		virtual void Function_0103(); //#103 +19c .rdata:0077ced0
		virtual void Function_0104(); //#104 +1a0 .rdata:0077ced4
		virtual void Function_0105(); //#105 +1a4 .rdata:0077ced8
		virtual void Function_0106(); //#106 +1a8 .rdata:0077cedc
		virtual void Function_0107(); //#107 +1ac .rdata:0077cee0
		virtual void Function_0108(); //#108 +1b0 .rdata:0077cee4
		virtual void Function_0109(); //#109 +1b4 .rdata:0077cee8
		virtual void Function_0110(); //#110 +1b8 .rdata:0077ceec
		virtual void Function_0111(); //#111 +1bc .rdata:0077cef0
		virtual void Function_0112(); //#112 +1c0 .rdata:0077cef4
		virtual void Function_0113(); //#113 +1c4 .rdata:0077cef8
		virtual void Function_0114(); //#114 +1c8 .rdata:0077cefc
		virtual void Function_0115(); //#115 +1cc .rdata:0077cf00
		virtual void Function_0116(); //#116 +1d0 .rdata:0077cf04
		virtual void Function_0117(); //#117 +1d4 .rdata:0077cf08
		virtual void Function_0118(); //#118 +1d8 .rdata:0077cf0c
		virtual void Function_0119(); //#119 +1dc .rdata:0077cf10
		virtual void Function_0120(); //#120 +1e0 .rdata:0077cf14
		virtual void Function_0121(); //#121 +1e4 .rdata:0077cf18
		virtual void Function_0122(); //#122 +1e8 .rdata:0077cf1c
		virtual void Function_0123(); //#123 +1ec .rdata:0077cf20
		virtual void Function_0124(); //#124 +1f0 .rdata:0077cf24
		virtual void Function_0125(); //#125 +1f4 .rdata:0077cf28
		virtual void Function_0126(); //#126 +1f8 .rdata:0077cf2c
		virtual void Function_0127(); //#127 +1fc .rdata:0077cf30
		virtual void Function_0128(); //#128 +200 .rdata:0077cf34
		virtual void Function_0129(); //#129 +204 .rdata:0077cf38
		virtual void Function_0130(); //#130 +208 .rdata:0077cf3c
		virtual void Function_0131(); //#131 +20c .rdata:0077cf40
		virtual void Function_0132(); //#132 +210 .rdata:0077cf44
		virtual void Function_0133(); //#133 +214 .rdata:0077cf48
		virtual void Function_0134(); //#134 +218 .rdata:0077cf4c
		virtual void Function_0135(); //#135 +21c .rdata:0077cf50
		virtual void Function_0136(); //#136 +220 .rdata:0077cf54
		virtual void Function_0137(); //#137 +224 .rdata:0077cf58
		virtual void Function_0138(); //#138 +228 .rdata:0077cf5c
		virtual void Function_0139(); //#139 +22c .rdata:0077cf60
		virtual void Function_0140(); //#140 +230 .rdata:0077cf64
		virtual void Function_0141(); //#141 +234 .rdata:0077cf68
		virtual void Function_0142(); //#142 +238 .rdata:0077cf6c
		virtual void Function_0143(); //#143 +23c .rdata:0077cf70
		virtual void setText(const char* text); //#144 +240 .rdata:0077cf74
		virtual void Function_0145(); //#145 +244 .rdata:0077cf78
		virtual void Function_0146(); //#146 +248 .rdata:0077cf7c
		virtual void Function_0147(); //#147 +24c .rdata:0077cf80
	}; //Size: 0x00A0

} }