#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { class REFTAB;  }

namespace ioi { namespace hm3 {
	class ZHM3Item;

	class ZHM3ItemTemplate
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[4]; //0x0008
		uint32_t __MEMCHECK__; //0x000C
		char pad_0010[48]; //0x0010

		virtual void Function_0000(); //#0 +0 .rdata:00799a0c
		virtual void Function_0001(); //#1 +4 .rdata:00799a10
		virtual void Function_0002(); //#2 +8 .rdata:00799a14
		virtual void Function_0003(); //#3 +c .rdata:00799a18
		virtual void Function_0004(); //#4 +10 .rdata:00799a1c
		virtual void Function_0005(); //#5 +14 .rdata:00799a20
		virtual void Function_0006(); //#6 +18 .rdata:00799a24
		virtual void Function_0007(); //#7 +1c .rdata:00799a28
		virtual void Function_0008(); //#8 +20 .rdata:00799a2c
		virtual void Function_0009(); //#9 +24 .rdata:00799a30
		virtual void Function_0010(); //#10 +28 .rdata:00799a34
		virtual void Function_0011(); //#11 +2c .rdata:00799a38
		virtual void Function_0012(); //#12 +30 .rdata:00799a3c
		virtual void Function_0013(); //#13 +34 .rdata:00799a40
		virtual void Function_0014(); //#14 +38 .rdata:00799a44
		virtual void Function_0015(); //#15 +3c .rdata:00799a48
		virtual void Function_0016(); //#16 +40 .rdata:00799a4c
		virtual void Function_0017(); //#17 +44 .rdata:00799a50
		virtual void Function_0018(); //#18 +48 .rdata:00799a54
		virtual void Function_0019(); //#19 +4c .rdata:00799a58
		virtual void Function_0020(); //#20 +50 .rdata:00799a5c
		virtual void Function_0021(); //#21 +54 .rdata:00799a60
		virtual void Function_0022(); //#22 +58 .rdata:00799a64
		virtual void Function_0023(); //#23 +5c .rdata:00799a68
		virtual void Function_0024(); //#24 +60 .rdata:00799a6c
		virtual void Function_0025(); //#25 +64 .rdata:00799a70
		virtual void Function_0026(); //#26 +68 .rdata:00799a74
		virtual void Function_0027(); //#27 +6c .rdata:00799a78
		virtual void Function_0028(); //#28 +70 .rdata:00799a7c
		virtual void Function_0029(); //#29 +74 .rdata:00799a80
		virtual void Function_0030(); //#30 +78 .rdata:00799a84
		virtual void Function_0031(); //#31 +7c .rdata:00799a88
		virtual void Function_0032(); //#32 +80 .rdata:00799a8c
		virtual void Function_0033(); //#33 +84 .rdata:00799a90
		virtual void Function_0034(); //#34 +88 .rdata:00799a94
		virtual void Function_0035(); //#35 +8c .rdata:00799a98
		virtual void Function_0036(); //#36 +90 .rdata:00799a9c
		virtual void Function_0037(); //#37 +94 .rdata:00799aa0
		virtual void Function_0038(); //#38 +98 .rdata:00799aa4
		virtual void Function_0039(); //#39 +9c .rdata:00799aa8
		virtual void Function_0040(); //#40 +a0 .rdata:00799aac
		virtual void Function_0041(); //#41 +a4 .rdata:00799ab0
		virtual void Function_0042(); //#42 +a8 .rdata:00799ab4
		virtual void Function_0043(); //#43 +ac .rdata:00799ab8
		virtual void Function_0044(); //#44 +b0 .rdata:00799abc
		virtual void Function_0045(); //#45 +b4 .rdata:00799ac0
		virtual void Function_0046(); //#46 +b8 .rdata:00799ac4
		virtual void Function_0047(); //#47 +bc .rdata:00799ac8
		virtual void Function_0048(); //#48 +c0 .rdata:00799acc
		virtual void Function_0049(); //#49 +c4 .rdata:00799ad0
		virtual void Function_0050(); //#50 +c8 .rdata:00799ad4
		virtual void Function_0051(); //#51 +cc .rdata:00799ad8
		virtual void Function_0052(); //#52 +d0 .rdata:00799adc
		virtual void Function_0053(); //#53 +d4 .rdata:00799ae0
		virtual void Function_0054(); //#54 +d8 .rdata:00799ae4
		virtual void Function_0055(); //#55 +dc .rdata:00799ae8
		virtual void Function_0056(); //#56 +e0 .rdata:00799aec
		virtual void Function_0057(); //#57 +e4 .rdata:00799af0
		virtual void Function_0058(); //#58 +e8 .rdata:00799af4
		virtual void Function_0059(); //#59 +ec .rdata:00799af8
		virtual void Function_0060(); //#60 +f0 .rdata:00799afc
		virtual void Function_0061(); //#61 +f4 .rdata:00799b00
		virtual void Function_0062(); //#62 +f8 .rdata:00799b04
		virtual void Function_0063(); //#63 +fc .rdata:00799b08
		virtual void Function_0064(); //#64 +100 .rdata:00799b0c
		virtual void Function_0065(); //#65 +104 .rdata:00799b10
		virtual void Function_0066(); //#66 +108 .rdata:00799b14
		virtual void Function_0067(); //#67 +10c .rdata:00799b18
		virtual void Function_0068(); //#68 +110 .rdata:00799b1c
		virtual void Function_0069(); //#69 +114 .rdata:00799b20
		virtual void Function_0070(); //#70 +118 .rdata:00799b24
		virtual void Function_0071(); //#71 +11c .rdata:00799b28
		virtual void Function_0072(); //#72 +120 .rdata:00799b2c
		virtual void Function_0073(); //#73 +124 .rdata:00799b30
		virtual void Function_0074(); //#74 +128 .rdata:00799b34
		virtual void Function_0075(); //#75 +12c .rdata:00799b38
		virtual void Function_0076(); //#76 +130 .rdata:00799b3c
		virtual void Function_0077(); //#77 +134 .rdata:00799b40
		virtual void Function_0078(); //#78 +138 .rdata:00799b44
		virtual void Function_0079(); //#79 +13c .rdata:00799b48
		virtual void Function_0080(); //#80 +140 .rdata:00799b4c
		virtual void Function_0081(); //#81 +144 .rdata:00799b50
		virtual void Function_0082(); //#82 +148 .rdata:00799b54
		virtual void Function_0083(); //#83 +14c .rdata:00799b58
		virtual void Function_0084(); //#84 +150 .rdata:00799b5c
		virtual void Function_0085(); //#85 +154 .rdata:00799b60
		virtual void Function_0086(); //#86 +158 .rdata:00799b64
		virtual void Function_0087(); //#87 +15c .rdata:00799b68
		virtual void Function_0088(); //#88 +160 .rdata:00799b6c
		virtual void Function_0089(); //#89 +164 .rdata:00799b70
		virtual void Function_0090(); //#90 +168 .rdata:00799b74
		virtual void Function_0091(); //#91 +16c .rdata:00799b78
		virtual void Function_0092(); //#92 +170 .rdata:00799b7c
		virtual void Function_0093(); //#93 +174 .rdata:00799b80
		virtual void Function_0094(); //#94 +178 .rdata:00799b84
		virtual void Function_0095(); //#95 +17c .rdata:00799b88
		virtual void Function_0096(); //#96 +180 .rdata:00799b8c
		virtual void Function_0097(); //#97 +184 .rdata:00799b90
		virtual void Function_0098(); //#98 +188 .rdata:00799b94
		virtual void Function_0099(); //#99 +18c .rdata:00799b98
		virtual void Function_0100(); //#100 +190 .rdata:00799b9c
		virtual void Function_0101(); //#101 +194 .rdata:00799ba0
		virtual void Function_0102(); //#102 +198 .rdata:00799ba4
		virtual void Function_0103(); //#103 +19c .rdata:00799ba8
		virtual void Function_0104(); //#104 +1a0 .rdata:00799bac
		virtual void Function_0105(); //#105 +1a4 .rdata:00799bb0
		virtual void Function_0106(); //#106 +1a8 .rdata:00799bb4
		virtual void Function_0107(); //#107 +1ac .rdata:00799bb8
		virtual void Function_0108(); //#108 +1b0 .rdata:00799bbc
		virtual void Function_0109(); //#109 +1b4 .rdata:00799bc0
		virtual void Function_0110(); //#110 +1b8 .rdata:00799bc4
		virtual void Function_0111(); //#111 +1bc .rdata:00799bc8
		virtual void Function_0112(); //#112 +1c0 .rdata:00799bcc
		virtual void Function_0113(); //#113 +1c4 .rdata:00799bd0
		virtual void Function_0114(); //#114 +1c8 .rdata:00799bd4
		virtual void Function_0115(); //#115 +1cc .rdata:00799bd8
		virtual void Function_0116(); //#116 +1d0 .rdata:00799bdc
		virtual void Function_0117(); //#117 +1d4 .rdata:00799be0
		virtual void Function_0118(); //#118 +1d8 .rdata:00799be4
		virtual void Function_0119(); //#119 +1dc .rdata:00799be8
		virtual void Function_0120(); //#120 +1e0 .rdata:00799bec
		virtual void Function_0121(); //#121 +1e4 .rdata:00799bf0
		virtual void Function_0122(); //#122 +1e8 .rdata:00799bf4
		virtual void Function_0123(); //#123 +1ec .rdata:00799bf8
		virtual void Function_0124(); //#124 +1f0 .rdata:00799bfc
		virtual void Function_0125(); //#125 +1f4 .rdata:00799c00
		virtual void Function_0126(); //#126 +1f8 .rdata:00799c04
		virtual void Function_0127(); //#127 +1fc .rdata:00799c08
		virtual void Function_0128(); //#128 +200 .rdata:00799c0c
		virtual void Function_0129(); //#129 +204 .rdata:00799c10
		virtual void Function_0130(); //#130 +208 .rdata:00799c14
		virtual void Function_0131(); //#131 +20c .rdata:00799c18
		virtual void Function_0132(); //#132 +210 .rdata:00799c1c
		virtual void Function_0133(); //#133 +214 .rdata:00799c20
		virtual void Function_0134(); //#134 +218 .rdata:00799c24
		virtual void Function_0135(ZEntityLocator* el); //#135 +21c .rdata:00799c28
		virtual void Function_0136(); //#136 +220 .rdata:00799c2c
		virtual void Function_0137(); //#137 +224 .rdata:00799c30
		virtual void Function_0138(); //#138 +228 .rdata:00799c34
		virtual void Function_0139(); //#139 +22c .rdata:00799c38
		virtual int getValueOf_0x28(); //#140 +230 .rdata:00799c3c
		virtual void Function_0141(); //#141 +234 .rdata:00799c40
		virtual void Function_0142(); //#142 +238 .rdata:00799c44
		virtual void Function_0143(); //#143 +23c .rdata:00799c48
		virtual void Function_0144(); //#144 +240 .rdata:00799c4c
		virtual void Function_0145(); //#145 +244 .rdata:00799c50
		virtual void Function_0146(); //#146 +248 .rdata:00799c54
		virtual void Function_0147(); //#147 +24c .rdata:00799c58
		virtual void Function_0148(); //#148 +250 .rdata:00799c5c ///UNK
		virtual int getConst_0x10042A(); //#149 +254 .rdata:00799c60
		virtual void Function_0150(int _ZLNKOBJ_Instance_, unsigned short a1); //#150 +258 .rdata:00799c64
		virtual int Function_0151(int CCom); //#151 +25c .rdata:00799c68 {something with lState}
		virtual void Function_0152(); //#152 +260 .rdata:00799c6c
		virtual void Function_0153(); //#153 +264 .rdata:00799c70 {something with ItemState*}
		virtual REFTAB* getUnknownREFTAB(); //#154 +268 .rdata:00799c74
		virtual int getValueOf_0x64(); //#155 +26c .rdata:00799c78
		virtual bool Function_0156(int a2, const char* a3); //#156 +270 .rdata:00799c7c
		virtual int Function_0157(int a2, int a3, const char* a4); //#157 +274 .rdata:00799c80
		virtual int Function_0158(int a2, int a3); //#158 +278 .rdata:00799c84
		virtual void getValueOf_0x4C(); //#159 +27c .rdata:00799c88
		virtual int setValueAt_0x4C(int value); //#160 +280 .rdata:00799c8c
		virtual void getValueOf_0x50(); //#161 +284 .rdata:00799c90
		virtual void getPosBoxHand(); //#162 +288 .rdata:00799c94
		virtual int getPosBoxCenter(); //#163 +28c .rdata:00799c98 { return this when PosBox_Center component not found, otherwise pointer to component or smth like that }
		virtual int getPosBoxCamera(); //#164 +290 .rdata:00799c9c
		virtual int getValueOf_0x6C(); //#165 +294 .rdata:00799ca0
		virtual int getValueOf_0x74(); //#166 +298 .rdata:00799ca4
	}; //Size: 0x0040

} }