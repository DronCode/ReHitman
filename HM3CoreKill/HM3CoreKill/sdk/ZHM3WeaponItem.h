#pragma once

#include <sdk/ZAnimationInfo.h>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	class ZHM3ItemWeapon
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[164]; //0x0008
		REFTAB* m_REFTAB; //0x00AC
		char pad_00B0[76]; //0x00B0
		ZAnimationInfo* m_animReload; //0x00FC
		ZAnimationInfo* m_animFire; //0x0100
		char pad_0104[32]; //0x0104
		uint32_t m_LNKOBJ; //0x0124
		char pad_0128[52]; //0x0128

		virtual void Function_0000(); //#0 +0 .rdata:00772b64
		virtual void Function_0001(); //#1 +4 .rdata:00772b68
		virtual void Function_0002(); //#2 +8 .rdata:00772b6c
		virtual void Function_0003(); //#3 +c .rdata:00772b70
		virtual void Function_0004(); //#4 +10 .rdata:00772b74
		virtual void Function_0005(); //#5 +14 .rdata:00772b78
		virtual void Function_0006(); //#6 +18 .rdata:00772b7c
		virtual void Function_0007(); //#7 +1c .rdata:00772b80
		virtual void Function_0008(); //#8 +20 .rdata:00772b84
		virtual void Function_0009(); //#9 +24 .rdata:00772b88
		virtual void Function_0010(); //#10 +28 .rdata:00772b8c
		virtual void Function_0011(); //#11 +2c .rdata:00772b90
		virtual void Function_0012(); //#12 +30 .rdata:00772b94
		virtual void Function_0013(); //#13 +34 .rdata:00772b98
		virtual void Function_0014(); //#14 +38 .rdata:00772b9c
		virtual void Function_0015(); //#15 +3c .rdata:00772ba0
		virtual void Function_0016(); //#16 +40 .rdata:00772ba4
		virtual void Function_0017(); //#17 +44 .rdata:00772ba8
		virtual void Function_0018(); //#18 +48 .rdata:00772bac
		virtual void Function_0019(); //#19 +4c .rdata:00772bb0
		virtual void Function_0020(); //#20 +50 .rdata:00772bb4
		virtual void Function_0021(); //#21 +54 .rdata:00772bb8
		virtual void Function_0022(); //#22 +58 .rdata:00772bbc
		virtual void Function_0023(); //#23 +5c .rdata:00772bc0
		virtual void Function_0024(); //#24 +60 .rdata:00772bc4
		virtual void Function_0025(); //#25 +64 .rdata:00772bc8
		virtual void Function_0026(); //#26 +68 .rdata:00772bcc
		virtual void Function_0027(); //#27 +6c .rdata:00772bd0
		virtual void Function_0028(); //#28 +70 .rdata:00772bd4
		virtual void Function_0029(); //#29 +74 .rdata:00772bd8
		virtual void Function_0030(); //#30 +78 .rdata:00772bdc
		virtual void Function_0031(); //#31 +7c .rdata:00772be0
		virtual void Function_0032(); //#32 +80 .rdata:00772be4
		virtual void Function_0033(); //#33 +84 .rdata:00772be8
		virtual void Function_0034(); //#34 +88 .rdata:00772bec
		virtual void Function_0035(); //#35 +8c .rdata:00772bf0
		virtual void Function_0036(); //#36 +90 .rdata:00772bf4
		virtual void Function_0037(); //#37 +94 .rdata:00772bf8
		virtual void Function_0038(); //#38 +98 .rdata:00772bfc
		virtual void Function_0039(); //#39 +9c .rdata:00772c00
		virtual void Function_0040(); //#40 +a0 .rdata:00772c04
		virtual void Function_0041(); //#41 +a4 .rdata:00772c08
		virtual void Function_0042(); //#42 +a8 .rdata:00772c0c
		virtual void Function_0043(); //#43 +ac .rdata:00772c10
		virtual void Function_0044(); //#44 +b0 .rdata:00772c14
		virtual void Function_0045(); //#45 +b4 .rdata:00772c18
		virtual void Function_0046(); //#46 +b8 .rdata:00772c1c
		virtual void Function_0047(); //#47 +bc .rdata:00772c20
		virtual void Function_0048(); //#48 +c0 .rdata:00772c24
		virtual void Function_0049(); //#49 +c4 .rdata:00772c28
		virtual void Function_0050(); //#50 +c8 .rdata:00772c2c
		virtual void Function_0051(); //#51 +cc .rdata:00772c30
		virtual void Function_0052(); //#52 +d0 .rdata:00772c34
		virtual void Function_0053(); //#53 +d4 .rdata:00772c38
		virtual void Function_0054(); //#54 +d8 .rdata:00772c3c
		virtual void Function_0055(); //#55 +dc .rdata:00772c40
		virtual void Function_0056(); //#56 +e0 .rdata:00772c44
		virtual void Function_0057(); //#57 +e4 .rdata:00772c48
		virtual void Function_0058(); //#58 +e8 .rdata:00772c4c
		virtual void Function_0059(); //#59 +ec .rdata:00772c50
		virtual void Function_0060(); //#60 +f0 .rdata:00772c54
		virtual void Function_0061(); //#61 +f4 .rdata:00772c58
		virtual void Function_0062(); //#62 +f8 .rdata:00772c5c
		virtual void Function_0063(); //#63 +fc .rdata:00772c60
		virtual void Function_0064(); //#64 +100 .rdata:00772c64
		virtual void Function_0065(); //#65 +104 .rdata:00772c68
		virtual void Function_0066(); //#66 +108 .rdata:00772c6c
		virtual void Function_0067(); //#67 +10c .rdata:00772c70
		virtual void Function_0068(); //#68 +110 .rdata:00772c74
		virtual void Function_0069(); //#69 +114 .rdata:00772c78
		virtual void Function_0070(); //#70 +118 .rdata:00772c7c
		virtual void Function_0071(); //#71 +11c .rdata:00772c80
		virtual void Function_0072(); //#72 +120 .rdata:00772c84
		virtual void Function_0073(); //#73 +124 .rdata:00772c88
		virtual void Function_0074(); //#74 +128 .rdata:00772c8c
		virtual void Function_0075(); //#75 +12c .rdata:00772c90
		virtual void Function_0076(); //#76 +130 .rdata:00772c94
		virtual void Function_0077(); //#77 +134 .rdata:00772c98
		virtual void Function_0078(); //#78 +138 .rdata:00772c9c
		virtual void Function_0079(); //#79 +13c .rdata:00772ca0
		virtual void Function_0080(); //#80 +140 .rdata:00772ca4
		virtual void Function_0081(); //#81 +144 .rdata:00772ca8
		virtual void Function_0082(); //#82 +148 .rdata:00772cac
		virtual void Function_0083(); //#83 +14c .rdata:00772cb0
		virtual void Function_0084(); //#84 +150 .rdata:00772cb4
		virtual void Function_0085(); //#85 +154 .rdata:00772cb8
		virtual void Function_0086(); //#86 +158 .rdata:00772cbc
		virtual void Function_0087(); //#87 +15c .rdata:00772cc0
		virtual void Function_0088(); //#88 +160 .rdata:00772cc4
		virtual void Function_0089(); //#89 +164 .rdata:00772cc8
		virtual void Function_0090(); //#90 +168 .rdata:00772ccc
		virtual void Function_0091(); //#91 +16c .rdata:00772cd0
		virtual void Function_0092(); //#92 +170 .rdata:00772cd4
		virtual void Function_0093(); //#93 +174 .rdata:00772cd8
		virtual void Function_0094(); //#94 +178 .rdata:00772cdc
		virtual void Function_0095(); //#95 +17c .rdata:00772ce0
		virtual void Function_0096(); //#96 +180 .rdata:00772ce4
		virtual void Function_0097(); //#97 +184 .rdata:00772ce8
		virtual void Function_0098(); //#98 +188 .rdata:00772cec
		virtual void Function_0099(); //#99 +18c .rdata:00772cf0
		virtual void Function_0100(); //#100 +190 .rdata:00772cf4
		virtual void Function_0101(); //#101 +194 .rdata:00772cf8
		virtual void Function_0102(); //#102 +198 .rdata:00772cfc
		virtual void Function_0103(); //#103 +19c .rdata:00772d00
		virtual void Function_0104(); //#104 +1a0 .rdata:00772d04
		virtual void Function_0105(); //#105 +1a4 .rdata:00772d08
		virtual void Function_0106(); //#106 +1a8 .rdata:00772d0c
		virtual void Function_0107(); //#107 +1ac .rdata:00772d10
		virtual void Function_0108(); //#108 +1b0 .rdata:00772d14
		virtual void Function_0109(); //#109 +1b4 .rdata:00772d18
		virtual void Function_0110(); //#110 +1b8 .rdata:00772d1c
		virtual void Function_0111(); //#111 +1bc .rdata:00772d20
		virtual void Function_0112(); //#112 +1c0 .rdata:00772d24
		virtual void Function_0113(); //#113 +1c4 .rdata:00772d28
		virtual void Function_0114(); //#114 +1c8 .rdata:00772d2c
		virtual void Function_0115(); //#115 +1cc .rdata:00772d30
		virtual void Function_0116(); //#116 +1d0 .rdata:00772d34
		virtual void Function_0117(); //#117 +1d4 .rdata:00772d38
		virtual void Function_0118(); //#118 +1d8 .rdata:00772d3c
		virtual void Function_0119(); //#119 +1dc .rdata:00772d40
		virtual void Function_0120(); //#120 +1e0 .rdata:00772d44
		virtual void Function_0121(); //#121 +1e4 .rdata:00772d48
		virtual void Function_0122(); //#122 +1e8 .rdata:00772d4c
		virtual void Function_0123(); //#123 +1ec .rdata:00772d50
		virtual void Function_0124(); //#124 +1f0 .rdata:00772d54
		virtual void Function_0125(); //#125 +1f4 .rdata:00772d58
		virtual void Function_0126(); //#126 +1f8 .rdata:00772d5c
		virtual void Function_0127(); //#127 +1fc .rdata:00772d60
		virtual void Function_0128(); //#128 +200 .rdata:00772d64
		virtual void Function_0129(); //#129 +204 .rdata:00772d68
		virtual void Function_0130(); //#130 +208 .rdata:00772d6c
		virtual void Function_0131(); //#131 +20c .rdata:00772d70
		virtual void Function_0132(); //#132 +210 .rdata:00772d74
		virtual void Function_0133(); //#133 +214 .rdata:00772d78
		virtual void Function_0134(); //#134 +218 .rdata:00772d7c
		virtual void Function_0135(); //#135 +21c .rdata:00772d80
		virtual void Function_0136(); //#136 +220 .rdata:00772d84
		virtual void Function_0137(); //#137 +224 .rdata:00772d88
		virtual void Function_0138(); //#138 +228 .rdata:00772d8c
		virtual void Function_0139(); //#139 +22c .rdata:00772d90
		virtual void Function_0140(); //#140 +230 .rdata:00772d94
		virtual void Function_0141(); //#141 +234 .rdata:00772d98
		virtual void Function_0142(); //#142 +238 .rdata:00772d9c
		virtual void Function_0143(); //#143 +23c .rdata:00772da0
		virtual void Function_0144(); //#144 +240 .rdata:00772da4
		virtual void Function_0145(); //#145 +244 .rdata:00772da8
		virtual void Function_0146(); //#146 +248 .rdata:00772dac
		virtual void Function_0147(); //#147 +24c .rdata:00772db0
		virtual void Function_0148(); //#148 +250 .rdata:00772db4
		virtual void Function_0149(); //#149 +254 .rdata:00772db8
		virtual void Function_0150(); //#150 +258 .rdata:00772dbc
		virtual void Function_0151(); //#151 +25c .rdata:00772dc0
		virtual void Function_0152(); //#152 +260 .rdata:00772dc4
		virtual void Function_0153(); //#153 +264 .rdata:00772dc8
		virtual void Function_0154(); //#154 +268 .rdata:00772dcc
		virtual void Function_0155(); //#155 +26c .rdata:00772dd0
		virtual void Function_0156(); //#156 +270 .rdata:00772dd4
		virtual void Function_0157(); //#157 +274 .rdata:00772dd8
		virtual void Function_0158(); //#158 +278 .rdata:00772ddc
		virtual void Function_0159(); //#159 +27c .rdata:00772de0
		virtual void Function_0160(); //#160 +280 .rdata:00772de4
		virtual void Function_0161(); //#161 +284 .rdata:00772de8
		virtual void Function_0162(); //#162 +288 .rdata:00772dec
		virtual void Function_0163(); //#163 +28c .rdata:00772df0
		virtual void Function_0164(); //#164 +290 .rdata:00772df4
		virtual void Function_0165(); //#165 +294 .rdata:00772df8
		virtual void Function_0166(); //#166 +298 .rdata:00772dfc
		virtual void Function_0167(); //#167 +29c .rdata:00772e00
		virtual void Function_0168(); //#168 +2a0 .rdata:00772e04
		virtual void Function_0169(); //#169 +2a4 .rdata:00772e08
		virtual void Function_0170(); //#170 +2a8 .rdata:00772e0c
		virtual void Function_0171(); //#171 +2ac .rdata:00772e10
		virtual void Function_0172(); //#172 +2b0 .rdata:00772e14
		virtual void Function_0173(); //#173 +2b4 .rdata:00772e18
		virtual void Function_0174(); //#174 +2b8 .rdata:00772e1c
		virtual void Function_0175(); //#175 +2bc .rdata:00772e20
		virtual void Function_0176(); //#176 +2c0 .rdata:00772e24
		virtual void Function_0177(); //#177 +2c4 .rdata:00772e28
		virtual void Function_0178(); //#178 +2c8 .rdata:00772e2c
		virtual void Function_0179(); //#179 +2cc .rdata:00772e30
		virtual void Function_0180(); //#180 +2d0 .rdata:00772e34
		virtual void Function_0181(); //#181 +2d4 .rdata:00772e38
		virtual void Function_0182(); //#182 +2d8 .rdata:00772e3c
		virtual void Function_0183(); //#183 +2dc .rdata:00772e40
		virtual void Function_0184(); //#184 +2e0 .rdata:00772e44
		virtual void Function_0185(); //#185 +2e4 .rdata:00772e48
		virtual void Function_0186(); //#186 +2e8 .rdata:00772e4c
		virtual void Function_0187(); //#187 +2ec .rdata:00772e50
		virtual int getClipCapacity(); //#188 +2f0 .rdata:00772e54
		virtual void Function_0189(); //#189 +2f4 .rdata:00772e58
		virtual void Function_0190(); //#190 +2f8 .rdata:00772e5c
		virtual void Function_0191(); //#191 +2fc .rdata:00772e60
		virtual void Function_0192(); //#192 +300 .rdata:00772e64
		virtual void Function_0193(); //#193 +304 .rdata:00772e68
		virtual void Function_0194(); //#194 +308 .rdata:00772e6c
		virtual void Function_0195(); //#195 +30c .rdata:00772e70
		virtual void Function_0196(); //#196 +310 .rdata:00772e74
		virtual void Function_0197(); //#197 +314 .rdata:00772e78
		virtual void Function_0198(); //#198 +318 .rdata:00772e7c
		virtual void Function_0199(); //#199 +31c .rdata:00772e80
		virtual void Function_0200(); //#200 +320 .rdata:00772e84
		virtual void Function_0201(); //#201 +324 .rdata:00772e88
		virtual void Function_0202(); //#202 +328 .rdata:00772e8c
		virtual void Function_0203(); //#203 +32c .rdata:00772e90
		virtual void Function_0204(); //#204 +330 .rdata:00772e94
		virtual void Function_0205(); //#205 +334 .rdata:00772e98
	}; //Size: 0x015C

} }