#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {

	class ZCar
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[520]; //0x0008
		int32_t m_carShouldMove; //0x0210
		char pad_0214[356]; //0x0214
		int32_t unk0; //0x0378
		char pad_037C[452]; //0x037C


		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0078411c
		virtual void Function_0001(); //#1 +4 .rdata:00784120
		virtual void Function_0002(); //#2 +8 .rdata:00784124
		virtual void Function_0003(); //#3 +c .rdata:00784128
		virtual void Function_0004(); //#4 +10 .rdata:0078412c
		virtual void Function_0005(); //#5 +14 .rdata:00784130
		virtual void Function_0006(); //#6 +18 .rdata:00784134
		virtual void Function_0007(); //#7 +1c .rdata:00784138
		virtual void Function_0008(); //#8 +20 .rdata:0078413c
		virtual void Function_0009(); //#9 +24 .rdata:00784140
		virtual void Function_0010(); //#10 +28 .rdata:00784144
		virtual void Function_0011(); //#11 +2c .rdata:00784148
		virtual void Function_0012(); //#12 +30 .rdata:0078414c
		virtual void Function_0013(); //#13 +34 .rdata:00784150
		virtual void Function_0014(); //#14 +38 .rdata:00784154
		virtual void Function_0015(); //#15 +3c .rdata:00784158
		virtual void Function_0016(); //#16 +40 .rdata:0078415c
		virtual void Function_0017(); //#17 +44 .rdata:00784160
		virtual void Function_0018(); //#18 +48 .rdata:00784164
		virtual void Function_0019(); //#19 +4c .rdata:00784168
		virtual void Function_0020(); //#20 +50 .rdata:0078416c
		virtual void Function_0021(); //#21 +54 .rdata:00784170
		virtual void Function_0022(); //#22 +58 .rdata:00784174
		virtual void Function_0023(); //#23 +5c .rdata:00784178
		virtual void Function_0024(); //#24 +60 .rdata:0078417c
		virtual void Function_0025(); //#25 +64 .rdata:00784180
		virtual void Function_0026(); //#26 +68 .rdata:00784184
		virtual void Function_0027(); //#27 +6c .rdata:00784188
		virtual void Function_0028(); //#28 +70 .rdata:0078418c
		virtual void Function_0029(); //#29 +74 .rdata:00784190
		virtual void Function_0030(); //#30 +78 .rdata:00784194
		virtual void Function_0031(); //#31 +7c .rdata:00784198
		virtual void Function_0032(); //#32 +80 .rdata:0078419c
		virtual void Function_0033(); //#33 +84 .rdata:007841a0
		virtual void Function_0034(); //#34 +88 .rdata:007841a4
		virtual void Function_0035(); //#35 +8c .rdata:007841a8
		virtual void Function_0036(); //#36 +90 .rdata:007841ac
		virtual void Function_0037(); //#37 +94 .rdata:007841b0
		virtual void Function_0038(); //#38 +98 .rdata:007841b4
		virtual void Function_0039(); //#39 +9c .rdata:007841b8
		virtual void Function_0040(); //#40 +a0 .rdata:007841bc
		virtual void Function_0041(); //#41 +a4 .rdata:007841c0
		virtual void Function_0042(); //#42 +a8 .rdata:007841c4
		virtual void Function_0043(); //#43 +ac .rdata:007841c8
		virtual void Function_0044(); //#44 +b0 .rdata:007841cc
		virtual void Function_0045(); //#45 +b4 .rdata:007841d0
		virtual void Function_0046(); //#46 +b8 .rdata:007841d4
		virtual void Function_0047(); //#47 +bc .rdata:007841d8
		virtual void Function_0048(); //#48 +c0 .rdata:007841dc
		virtual void Function_0049(); //#49 +c4 .rdata:007841e0
		virtual void Function_0050(); //#50 +c8 .rdata:007841e4
		virtual void Function_0051(); //#51 +cc .rdata:007841e8
		virtual void Function_0052(); //#52 +d0 .rdata:007841ec
		virtual void Function_0053(); //#53 +d4 .rdata:007841f0
		virtual void Function_0054(); //#54 +d8 .rdata:007841f4
		virtual void Function_0055(); //#55 +dc .rdata:007841f8
		virtual void Function_0056(); //#56 +e0 .rdata:007841fc
		virtual void Function_0057(); //#57 +e4 .rdata:00784200
		virtual void Function_0058(); //#58 +e8 .rdata:00784204
		virtual void Function_0059(); //#59 +ec .rdata:00784208
		virtual void Function_0060(); //#60 +f0 .rdata:0078420c
		virtual void Function_0061(); //#61 +f4 .rdata:00784210
		virtual void Function_0062(); //#62 +f8 .rdata:00784214
		virtual void Function_0063(); //#63 +fc .rdata:00784218
		virtual void Function_0064(); //#64 +100 .rdata:0078421c
		virtual void Function_0065(); //#65 +104 .rdata:00784220
		virtual void Function_0066(); //#66 +108 .rdata:00784224
		virtual void Function_0067(); //#67 +10c .rdata:00784228
		virtual void Function_0068(); //#68 +110 .rdata:0078422c
		virtual void Function_0069(); //#69 +114 .rdata:00784230
		virtual void Function_0070(); //#70 +118 .rdata:00784234
		virtual void Function_0071(); //#71 +11c .rdata:00784238
		virtual void Function_0072(); //#72 +120 .rdata:0078423c
		virtual void Function_0073(); //#73 +124 .rdata:00784240
		virtual void Function_0074(); //#74 +128 .rdata:00784244
		virtual void Function_0075(); //#75 +12c .rdata:00784248
		virtual void Function_0076(); //#76 +130 .rdata:0078424c
		virtual void Function_0077(); //#77 +134 .rdata:00784250
		virtual void Function_0078(); //#78 +138 .rdata:00784254
		virtual void Function_0079(); //#79 +13c .rdata:00784258
		virtual void Function_0080(); //#80 +140 .rdata:0078425c
		virtual void Function_0081(); //#81 +144 .rdata:00784260
		virtual void Function_0082(); //#82 +148 .rdata:00784264
		virtual void Function_0083(); //#83 +14c .rdata:00784268
		virtual void Function_0084(); //#84 +150 .rdata:0078426c
		virtual void Function_0085(); //#85 +154 .rdata:00784270
		virtual void Function_0086(); //#86 +158 .rdata:00784274
		virtual void Function_0087(); //#87 +15c .rdata:00784278
		virtual void Function_0088(); //#88 +160 .rdata:0078427c
		virtual void Function_0089(); //#89 +164 .rdata:00784280
		virtual void Function_0090(); //#90 +168 .rdata:00784284
		virtual void Function_0091(); //#91 +16c .rdata:00784288
		virtual void Function_0092(); //#92 +170 .rdata:0078428c
		virtual void Function_0093(); //#93 +174 .rdata:00784290
		virtual void Function_0094(); //#94 +178 .rdata:00784294
		virtual void Function_0095(); //#95 +17c .rdata:00784298
		virtual void Function_0096(); //#96 +180 .rdata:0078429c
		virtual void Function_0097(); //#97 +184 .rdata:007842a0
		virtual void Function_0098(); //#98 +188 .rdata:007842a4
		virtual void Function_0099(); //#99 +18c .rdata:007842a8
		virtual void Function_0100(); //#100 +190 .rdata:007842ac
		virtual void Function_0101(); //#101 +194 .rdata:007842b0
		virtual void Function_0102(); //#102 +198 .rdata:007842b4
		virtual void Function_0103(); //#103 +19c .rdata:007842b8
		virtual void Function_0104(); //#104 +1a0 .rdata:007842bc
		virtual void Function_0105(); //#105 +1a4 .rdata:007842c0
		virtual void Function_0106(); //#106 +1a8 .rdata:007842c4
		virtual void Function_0107(); //#107 +1ac .rdata:007842c8
		virtual void Function_0108(); //#108 +1b0 .rdata:007842cc
		virtual void Function_0109(); //#109 +1b4 .rdata:007842d0
		virtual void Function_0110(); //#110 +1b8 .rdata:007842d4
		virtual void Function_0111(); //#111 +1bc .rdata:007842d8
		virtual void Function_0112(); //#112 +1c0 .rdata:007842dc
		virtual void Function_0113(); //#113 +1c4 .rdata:007842e0
		virtual void Function_0114(); //#114 +1c8 .rdata:007842e4
		virtual void Function_0115(); //#115 +1cc .rdata:007842e8
		virtual void Function_0116(); //#116 +1d0 .rdata:007842ec
		virtual void Function_0117(); //#117 +1d4 .rdata:007842f0
		virtual void Function_0118(); //#118 +1d8 .rdata:007842f4
		virtual void Function_0119(); //#119 +1dc .rdata:007842f8
		virtual void Function_0120(); //#120 +1e0 .rdata:007842fc
		virtual void Function_0121(); //#121 +1e4 .rdata:00784300
		virtual void Function_0122(); //#122 +1e8 .rdata:00784304
		virtual void Function_0123(); //#123 +1ec .rdata:00784308
		virtual void Function_0124(); //#124 +1f0 .rdata:0078430c
		virtual void Function_0125(); //#125 +1f4 .rdata:00784310
		virtual void Function_0126(); //#126 +1f8 .rdata:00784314
		virtual void Function_0127(); //#127 +1fc .rdata:00784318
		virtual void Function_0128(); //#128 +200 .rdata:0078431c
		virtual void Function_0129(); //#129 +204 .rdata:00784320
		virtual void Function_0130(); //#130 +208 .rdata:00784324
		virtual void Function_0131(); //#131 +20c .rdata:00784328
		virtual void Function_0132(); //#132 +210 .rdata:0078432c
		virtual void Function_0133(); //#133 +214 .rdata:00784330
		virtual void Function_0134(); //#134 +218 .rdata:00784334
		virtual void Function_0135(); //#135 +21c .rdata:00784338
		virtual void Function_0136(); //#136 +220 .rdata:0078433c
		virtual void Function_0137(); //#137 +224 .rdata:00784340
		virtual void Function_0138(); //#138 +228 .rdata:00784344
		virtual void Function_0139(); //#139 +22c .rdata:00784348
		virtual void Function_0140(); //#140 +230 .rdata:0078434c
		virtual void Function_0141(); //#141 +234 .rdata:00784350
		virtual void Function_0142(); //#142 +238 .rdata:00784354
		virtual void Function_0143(); //#143 +23c .rdata:00784358
		virtual void Function_0144(); //#144 +240 .rdata:0078435c
		virtual void Function_0145(); //#145 +244 .rdata:00784360
		virtual void Function_0146(); //#146 +248 .rdata:00784364
		virtual void Function_0147(); //#147 +24c .rdata:00784368
		virtual void Function_0148(); //#148 +250 .rdata:0078436c
		virtual void Function_0149(); //#149 +254 .rdata:00784370
		virtual void Function_0150(); //#150 +258 .rdata:00784374
		virtual void Function_0151(); //#151 +25c .rdata:00784378
		virtual void Function_0152(); //#152 +260 .rdata:0078437c
		virtual void Function_0153(); //#153 +264 .rdata:00784380
		virtual void Function_0154(); //#154 +268 .rdata:00784384
		virtual void Function_0155(); //#155 +26c .rdata:00784388
		virtual void Function_0156(); //#156 +270 .rdata:0078438c
		virtual void Function_0157(); //#157 +274 .rdata:00784390
		virtual void Function_0158(); //#158 +278 .rdata:00784394
		virtual void Function_0159(); //#159 +27c .rdata:00784398
		virtual void Function_0160(); //#160 +280 .rdata:0078439c
		virtual void Function_0161(); //#161 +284 .rdata:007843a0
		virtual void Function_0162(); //#162 +288 .rdata:007843a4
		virtual void Function_0163(); //#163 +28c .rdata:007843a8
		virtual void Function_0164(); //#164 +290 .rdata:007843ac
		virtual void Function_0165(); //#165 +294 .rdata:007843b0
		virtual void Function_0166(); //#166 +298 .rdata:007843b4
		virtual void Function_0167(); //#167 +29c .rdata:007843b8
		virtual void Function_0168(); //#168 +2a0 .rdata:007843bc
		virtual void Function_0169(); //#169 +2a4 .rdata:007843c0
		virtual void Function_0170(); //#170 +2a8 .rdata:007843c4
		virtual void Function_0171(); //#171 +2ac .rdata:007843c8
		virtual void Function_0172(); //#172 +2b0 .rdata:007843cc
		virtual void Function_0173(); //#173 +2b4 .rdata:007843d0
		virtual void Function_0174(); //#174 +2b8 .rdata:007843d4
		virtual void Function_0175(); //#175 +2bc .rdata:007843d8
		virtual void Function_0176(); //#176 +2c0 .rdata:007843dc
		virtual void Function_0177(); //#177 +2c4 .rdata:007843e0
		virtual void Function_0178(); //#178 +2c8 .rdata:007843e4
		virtual void Function_0179(); //#179 +2cc .rdata:007843e8
		virtual void Function_0180(); //#180 +2d0 .rdata:007843ec
		virtual void Function_0181(); //#181 +2d4 .rdata:007843f0
		virtual void Function_0182(); //#182 +2d8 .rdata:007843f4
		virtual void Function_0183(); //#183 +2dc .rdata:007843f8
		virtual void Function_0184(); //#184 +2e0 .rdata:007843fc
		virtual void Function_0185(); //#185 +2e4 .rdata:00784400
		virtual void Function_0186(); //#186 +2e8 .rdata:00784404
		virtual void Function_0187(); //#187 +2ec .rdata:00784408
		virtual void Function_0188(); //#188 +2f0 .rdata:0078440c
		virtual void Function_0189(); //#189 +2f4 .rdata:00784410
		virtual void Function_0190(); //#190 +2f8 .rdata:00784414
		virtual void Function_0191(); //#191 +2fc .rdata:00784418
		virtual void Function_0192(); //#192 +300 .rdata:0078441c
		virtual void Function_0193(); //#193 +304 .rdata:00784420
		virtual void Function_0194(); //#194 +308 .rdata:00784424
		virtual void Function_0195(); //#195 +30c .rdata:00784428
		virtual void Function_0196(); //#196 +310 .rdata:0078442c
		virtual void Function_0197(); //#197 +314 .rdata:00784430
		virtual void Function_0198(); //#198 +318 .rdata:00784434
		virtual void Function_0199(); //#199 +31c .rdata:00784438
		virtual void Function_0200(); //#200 +320 .rdata:0078443c
		virtual void Function_0201(); //#201 +324 .rdata:00784440
		virtual void Function_0202(); //#202 +328 .rdata:00784444
		virtual void Function_0203(); //#203 +32c .rdata:00784448
		virtual float getUnkFloat(); //#204 +330 .rdata:0078444c
		virtual void Function_0205(); //#205 +334 .rdata:00784450
		virtual void Function_0206(); //#206 +338 .rdata:00784454
		virtual void Function_0207(); //#207 +33c .rdata:00784458
	}; //Size: 0x00F4

}}