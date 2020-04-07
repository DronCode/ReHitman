#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {

	class ZHM3ItemBomb
	{
	public:
		/// === members ===
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[164]; //0x0008
		REFTAB* m_reftab; //0x00AC
		char pad_00B0[28]; //0x00B0

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007991e4
		virtual void Function_0001(); //#1 +4 .rdata:007991e8
		virtual void Function_0002(); //#2 +8 .rdata:007991ec
		virtual void Function_0003(); //#3 +c .rdata:007991f0
		virtual void Function_0004(); //#4 +10 .rdata:007991f4
		virtual void Function_0005(); //#5 +14 .rdata:007991f8
		virtual void Function_0006(); //#6 +18 .rdata:007991fc
		virtual void Function_0007(); //#7 +1c .rdata:00799200
		virtual void Function_0008(); //#8 +20 .rdata:00799204
		virtual void Function_0009(); //#9 +24 .rdata:00799208
		virtual void Function_0010(); //#10 +28 .rdata:0079920c
		virtual void Function_0011(); //#11 +2c .rdata:00799210
		virtual void Function_0012(); //#12 +30 .rdata:00799214
		virtual void Function_0013(); //#13 +34 .rdata:00799218
		virtual void Function_0014(); //#14 +38 .rdata:0079921c
		virtual void Function_0015(); //#15 +3c .rdata:00799220
		virtual void Function_0016(); //#16 +40 .rdata:00799224
		virtual void Function_0017(); //#17 +44 .rdata:00799228
		virtual void Function_0018(); //#18 +48 .rdata:0079922c
		virtual void Function_0019(); //#19 +4c .rdata:00799230
		virtual void Function_0020(); //#20 +50 .rdata:00799234
		virtual void Function_0021(); //#21 +54 .rdata:00799238
		virtual void Function_0022(); //#22 +58 .rdata:0079923c
		virtual void Function_0023(); //#23 +5c .rdata:00799240
		virtual void Function_0024(); //#24 +60 .rdata:00799244
		virtual void Function_0025(); //#25 +64 .rdata:00799248
		virtual void Function_0026(); //#26 +68 .rdata:0079924c
		virtual void Function_0027(); //#27 +6c .rdata:00799250
		virtual void Function_0028(); //#28 +70 .rdata:00799254
		virtual void Function_0029(); //#29 +74 .rdata:00799258
		virtual void Function_0030(); //#30 +78 .rdata:0079925c
		virtual void Function_0031(); //#31 +7c .rdata:00799260
		virtual void Function_0032(); //#32 +80 .rdata:00799264
		virtual void Function_0033(); //#33 +84 .rdata:00799268
		virtual void Function_0034(); //#34 +88 .rdata:0079926c
		virtual void Function_0035(); //#35 +8c .rdata:00799270
		virtual void Function_0036(); //#36 +90 .rdata:00799274
		virtual void Function_0037(); //#37 +94 .rdata:00799278
		virtual void Function_0038(); //#38 +98 .rdata:0079927c
		virtual void Function_0039(); //#39 +9c .rdata:00799280
		virtual void Function_0040(); //#40 +a0 .rdata:00799284
		virtual void Function_0041(); //#41 +a4 .rdata:00799288
		virtual void Function_0042(); //#42 +a8 .rdata:0079928c
		virtual void Function_0043(); //#43 +ac .rdata:00799290
		virtual void Function_0044(); //#44 +b0 .rdata:00799294
		virtual void Function_0045(); //#45 +b4 .rdata:00799298
		virtual void Function_0046(); //#46 +b8 .rdata:0079929c
		virtual void Function_0047(); //#47 +bc .rdata:007992a0
		virtual void Function_0048(); //#48 +c0 .rdata:007992a4
		virtual void Function_0049(); //#49 +c4 .rdata:007992a8
		virtual void Function_0050(); //#50 +c8 .rdata:007992ac
		virtual void Function_0051(); //#51 +cc .rdata:007992b0
		virtual void Function_0052(); //#52 +d0 .rdata:007992b4
		virtual void Function_0053(); //#53 +d4 .rdata:007992b8
		virtual void Function_0054(); //#54 +d8 .rdata:007992bc
		virtual void Function_0055(); //#55 +dc .rdata:007992c0
		virtual void Function_0056(); //#56 +e0 .rdata:007992c4
		virtual void Function_0057(); //#57 +e4 .rdata:007992c8
		virtual void Function_0058(); //#58 +e8 .rdata:007992cc
		virtual void Function_0059(); //#59 +ec .rdata:007992d0
		virtual void Function_0060(); //#60 +f0 .rdata:007992d4
		virtual void Function_0061(); //#61 +f4 .rdata:007992d8
		virtual void Function_0062(); //#62 +f8 .rdata:007992dc
		virtual void Function_0063(); //#63 +fc .rdata:007992e0
		virtual void Function_0064(); //#64 +100 .rdata:007992e4
		virtual void Function_0065(); //#65 +104 .rdata:007992e8
		virtual void Function_0066(); //#66 +108 .rdata:007992ec
		virtual void Function_0067(); //#67 +10c .rdata:007992f0
		virtual void Function_0068(); //#68 +110 .rdata:007992f4
		virtual void Function_0069(); //#69 +114 .rdata:007992f8
		virtual void Function_0070(); //#70 +118 .rdata:007992fc
		virtual void Function_0071(); //#71 +11c .rdata:00799300
		virtual void Function_0072(); //#72 +120 .rdata:00799304
		virtual void Function_0073(); //#73 +124 .rdata:00799308
		virtual void Function_0074(); //#74 +128 .rdata:0079930c
		virtual void Function_0075(); //#75 +12c .rdata:00799310
		virtual void Function_0076(); //#76 +130 .rdata:00799314
		virtual void Function_0077(); //#77 +134 .rdata:00799318
		virtual void Function_0078(); //#78 +138 .rdata:0079931c
		virtual void Function_0079(); //#79 +13c .rdata:00799320
		virtual void Function_0080(); //#80 +140 .rdata:00799324
		virtual void Function_0081(); //#81 +144 .rdata:00799328
		virtual void Function_0082(); //#82 +148 .rdata:0079932c
		virtual void Function_0083(); //#83 +14c .rdata:00799330
		virtual void Function_0084(); //#84 +150 .rdata:00799334
		virtual void Function_0085(); //#85 +154 .rdata:00799338
		virtual void Function_0086(); //#86 +158 .rdata:0079933c
		virtual void Function_0087(); //#87 +15c .rdata:00799340
		virtual void Function_0088(); //#88 +160 .rdata:00799344
		virtual void Function_0089(); //#89 +164 .rdata:00799348
		virtual void Function_0090(); //#90 +168 .rdata:0079934c
		virtual void Function_0091(); //#91 +16c .rdata:00799350
		virtual void Function_0092(); //#92 +170 .rdata:00799354
		virtual void Function_0093(); //#93 +174 .rdata:00799358
		virtual void Function_0094(); //#94 +178 .rdata:0079935c
		virtual void Function_0095(); //#95 +17c .rdata:00799360
		virtual void Function_0096(); //#96 +180 .rdata:00799364
		virtual void Function_0097(); //#97 +184 .rdata:00799368
		virtual void Function_0098(); //#98 +188 .rdata:0079936c
		virtual void Function_0099(); //#99 +18c .rdata:00799370
		virtual void Function_0100(); //#100 +190 .rdata:00799374
		virtual void Function_0101(); //#101 +194 .rdata:00799378
		virtual void Function_0102(); //#102 +198 .rdata:0079937c
		virtual void Function_0103(); //#103 +19c .rdata:00799380
		virtual void Function_0104(); //#104 +1a0 .rdata:00799384
		virtual void Function_0105(); //#105 +1a4 .rdata:00799388
		virtual void Function_0106(); //#106 +1a8 .rdata:0079938c
		virtual void Function_0107(); //#107 +1ac .rdata:00799390
		virtual void Function_0108(); //#108 +1b0 .rdata:00799394
		virtual void Function_0109(); //#109 +1b4 .rdata:00799398
		virtual void Function_0110(); //#110 +1b8 .rdata:0079939c
		virtual void Function_0111(); //#111 +1bc .rdata:007993a0
		virtual void Function_0112(); //#112 +1c0 .rdata:007993a4
		virtual void Function_0113(); //#113 +1c4 .rdata:007993a8
		virtual void Function_0114(); //#114 +1c8 .rdata:007993ac
		virtual void Function_0115(); //#115 +1cc .rdata:007993b0
		virtual void Function_0116(); //#116 +1d0 .rdata:007993b4
		virtual void Function_0117(); //#117 +1d4 .rdata:007993b8
		virtual void Function_0118(); //#118 +1d8 .rdata:007993bc
		virtual void Function_0119(); //#119 +1dc .rdata:007993c0
		virtual void Function_0120(); //#120 +1e0 .rdata:007993c4
		virtual void Function_0121(); //#121 +1e4 .rdata:007993c8
		virtual void Function_0122(); //#122 +1e8 .rdata:007993cc
		virtual void Function_0123(); //#123 +1ec .rdata:007993d0
		virtual void Function_0124(); //#124 +1f0 .rdata:007993d4
		virtual void Function_0125(); //#125 +1f4 .rdata:007993d8
		virtual void Function_0126(); //#126 +1f8 .rdata:007993dc
		virtual void Function_0127(); //#127 +1fc .rdata:007993e0
		virtual void Function_0128(); //#128 +200 .rdata:007993e4
		virtual void Function_0129(); //#129 +204 .rdata:007993e8
		virtual void Function_0130(); //#130 +208 .rdata:007993ec
		virtual void Function_0131(); //#131 +20c .rdata:007993f0
		virtual void Function_0132(); //#132 +210 .rdata:007993f4
		virtual void Function_0133(); //#133 +214 .rdata:007993f8
		virtual void Function_0134(); //#134 +218 .rdata:007993fc
		virtual void Function_0135(); //#135 +21c .rdata:00799400
		virtual void Function_0136(); //#136 +220 .rdata:00799404
		virtual void Function_0137(); //#137 +224 .rdata:00799408
		virtual void Function_0138(); //#138 +228 .rdata:0079940c
		virtual void Function_0139(); //#139 +22c .rdata:00799410
		virtual void Function_0140(); //#140 +230 .rdata:00799414
		virtual void Function_0141(); //#141 +234 .rdata:00799418
		virtual void Function_0142(); //#142 +238 .rdata:0079941c
		virtual void Function_0143(); //#143 +23c .rdata:00799420
		virtual void Function_0144(); //#144 +240 .rdata:00799424
		virtual void Function_0145(); //#145 +244 .rdata:00799428
		virtual void Function_0146(); //#146 +248 .rdata:0079942c
		virtual void Function_0147(); //#147 +24c .rdata:00799430
		virtual void Function_0148(); //#148 +250 .rdata:00799434
		virtual void Function_0149(); //#149 +254 .rdata:00799438
		virtual void Function_0150(); //#150 +258 .rdata:0079943c
		virtual void Function_0151(); //#151 +25c .rdata:00799440
		virtual void Function_0152(); //#152 +260 .rdata:00799444
		virtual void Function_0153(); //#153 +264 .rdata:00799448
		virtual void Function_0154(); //#154 +268 .rdata:0079944c
		virtual void Function_0155(); //#155 +26c .rdata:00799450
		virtual void Function_0156(); //#156 +270 .rdata:00799454
		virtual void Function_0157(); //#157 +274 .rdata:00799458
		virtual void Function_0158(); //#158 +278 .rdata:0079945c
		virtual void Function_0159(); //#159 +27c .rdata:00799460
		virtual void Function_0160(); //#160 +280 .rdata:00799464
		virtual void Function_0161(); //#161 +284 .rdata:00799468
		virtual void Function_0162(); //#162 +288 .rdata:0079946c
		virtual void Function_0163(); //#163 +28c .rdata:00799470
		virtual void Function_0164(); //#164 +290 .rdata:00799474
		virtual void Function_0165(); //#165 +294 .rdata:00799478
		virtual void Function_0166(); //#166 +298 .rdata:0079947c
		virtual void Function_0167(); //#167 +29c .rdata:00799480
		virtual void Function_0168(); //#168 +2a0 .rdata:00799484
		virtual void Function_0169(); //#169 +2a4 .rdata:00799488
		virtual void Function_0170(); //#170 +2a8 .rdata:0079948c
		virtual void Function_0171(); //#171 +2ac .rdata:00799490
		virtual void Function_0172(); //#172 +2b0 .rdata:00799494
		virtual void Function_0173(); //#173 +2b4 .rdata:00799498
		virtual void Function_0174(); //#174 +2b8 .rdata:0079949c
		virtual void Function_0175(); //#175 +2bc .rdata:007994a0
		virtual void Function_0176(); //#176 +2c0 .rdata:007994a4
		virtual void Function_0177(); //#177 +2c4 .rdata:007994a8
		virtual void Function_0178(); //#178 +2c8 .rdata:007994ac
		virtual void Function_0179(); //#179 +2cc .rdata:007994b0
		virtual void Function_0180(); //#180 +2d0 .rdata:007994b4
		virtual void Function_0181(); //#181 +2d4 .rdata:007994b8
		virtual void Function_0182(); //#182 +2d8 .rdata:007994bc
		virtual void Function_0183(); //#183 +2dc .rdata:007994c0
		virtual void Function_0184(); //#184 +2e0 .rdata:007994c4
		virtual void Function_0185(); //#185 +2e4 .rdata:007994c8
		virtual void Function_0186(); //#186 +2e8 .rdata:007994cc
		virtual void Function_0187(); //#187 +2ec .rdata:007994d0
		virtual void Function_0188(); //#188 +2f0 .rdata:007994d4
		virtual void Function_0189(); //#189 +2f4 .rdata:007994d8
		virtual void Function_0190(); //#190 +2f8 .rdata:007994dc
		virtual void Function_0191(); //#191 +2fc .rdata:007994e0
		virtual void Function_0192(); //#192 +300 .rdata:007994e4
		virtual void Function_0193(); //#193 +304 .rdata:007994e8
		virtual void Function_0194(); //#194 +308 .rdata:007994ec
		virtual void Function_0195(); //#195 +30c .rdata:007994f0
		virtual void Function_0196(); //#196 +310 .rdata:007994f4
		virtual void Function_0197(); //#197 +314 .rdata:007994f8
		virtual void Function_0198(); //#198 +318 .rdata:007994fc
		virtual void Function_0199(); //#199 +31c .rdata:00799500
		virtual void Function_0200(); //#200 +320 .rdata:00799504
		virtual void Function_0201(); //#201 +324 .rdata:00799508
		virtual void Function_0202(); //#202 +328 .rdata:0079950c
		virtual void Function_0203(); //#203 +32c .rdata:00799510
		virtual void Function_0204(); //#204 +330 .rdata:00799514
		virtual void Function_0205(); //#205 +334 .rdata:00799518
		virtual void Function_0206(); //#206 +338 .rdata:0079951c
		virtual void Function_0207(); //#207 +33c .rdata:00799520
		virtual void Function_0208(); //#208 +340 .rdata:00799524
		virtual void Function_0209(); //#209 +344 .rdata:00799528
		virtual void Function_0210(); //#210 +348 .rdata:0079952c
		virtual void Function_0211(); //#211 +34c .rdata:00799530
		virtual void Function_0212(); //#212 +350 .rdata:00799534
		virtual void Function_0213(); //#213 +354 .rdata:00799538
		virtual void Function_0214(); //#214 +358 .rdata:0079953c
		virtual void Function_0215(); //#215 +35c .rdata:00799540
		virtual void Function_0216(); //#216 +360 .rdata:00799544
		virtual void Function_0217(); //#217 +364 .rdata:00799548
	}; //Size: 0x00CC

} }