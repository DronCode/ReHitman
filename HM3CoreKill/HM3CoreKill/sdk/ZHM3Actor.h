#pragma once

#include <cstdint>
#include <sdk/ZHumanBoid.h>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ZIKHAND.h>

namespace ioi {
namespace hm3 {

	class ZHM3Actor;

	class ActorInfos
	{
	public:
		char pad_0000[0x50];		//0x0000
		ZEntityLocator* location;	//0x0050
		char pad_0054[12];			//0x0054
		ZHM3Actor* actor;			//0x0060
		char pad_0064[8];			//0x0064
		char* unkType;				//0x006C
		char pad_0070[80];			//0x0070
		uint32_t equipment;			//0x00C0 [ptr]
		char pad_00C4[12];			//0x00C4
		uint32_t group;				//0x00D0 [ptr]
		char pad_00D4[92];			//0x00D4
		uint32_t unk_equ2;			//0x0130 [ptr]
		char pad_0134[12];			//0x0134
	}; //Size: 0x0140

	class ZHM3Actor
	{
	public:
		// === sub types ===
		enum class ActorStatus : int32_t {
			// Pure
			Status_0 = 0,
			Status_1 = 1,
			Status_2 = 2,
			Status_3 = 3,
			Reset = 0xFF,
			// User
			Sleep  = Status_2, ///< Actor will not be dead
			Normal = Status_1,  ///< Actor will be in normal state
			StopAI = Status_0, ///< Actor will not follow by scripts, will stay in inactive mode. Also in this mode actor is in god mode
			ResetAI = Status_3 ///< Actor will be resetted. Any damage, screaming or other stuff will be flushed (not in god mode!)
		};

		enum class SuiteMask : int32_t {
			NoActor					 = 0b0000'0000'0000'0000'0000'0000'0000'0000,	///< This is not an actor (M13, wheelchair gui subactor kind)
			SkinChangerNotSupported	 = 0b0000'0000'0000'0000'0000'0000'0000'0001,	///< This actor does not supports skin changer
			Nude					 = 0b0000'0000'0000'0000'0000'0000'0000'0010,	///< Nude view of model (works only if the actor can share their suit, in other case works as Inivisble)
			Invisible				 = 0b0000'0000'0000'0000'0000'0000'0000'0100,	///< Invisible view of the actor (possible model loading failure, I don't know)
			OriginalView			 = 0b0000'0000'0000'0000'0000'0000'0000'0101,	///< Just original view of actor
			Agent47_WithoutHeaddress = 0b0000'0000'0000'0000'0000'0000'0000'0110,	///< Sometimes works if suit have headdress (in other case will work as invisible)
			Agent47_WithHeaddress	 = 0b0000'0000'0000'0000'0000'0000'0000'0111	///< Works in 99% of situations with actors who can share their suit
		};

		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00796334
		virtual void Function_0001(); //#1 +4 .rdata:00796338
		virtual void Function_0002(); //#2 +8 .rdata:0079633c
		virtual void Function_0003(); //#3 +c .rdata:00796340
		virtual void Function_0004(); //#4 +10 .rdata:00796344
		virtual void Function_0005(); //#5 +14 .rdata:00796348
		virtual void Function_0006(); //#6 +18 .rdata:0079634c
		virtual void Function_0007(); //#7 +1c .rdata:00796350
		virtual void Function_0008(); //#8 +20 .rdata:00796354
		virtual void Function_0009(); //#9 +24 .rdata:00796358
		virtual void Function_0010(); //#10 +28 .rdata:0079635c
		virtual void Function_0011(); //#11 +2c .rdata:00796360
		virtual void Function_0012(); //#12 +30 .rdata:00796364
		virtual void Function_0013(); //#13 +34 .rdata:00796368
		virtual void Function_0014(); //#14 +38 .rdata:0079636c
		virtual void Function_0015(); //#15 +3c .rdata:00796370
		virtual void Function_0016(); //#16 +40 .rdata:00796374
		virtual void Function_0017(); //#17 +44 .rdata:00796378
		virtual void Function_0018(); //#18 +48 .rdata:0079637c
		virtual void Function_0019(); //#19 +4c .rdata:00796380
		virtual void Function_0020(); //#20 +50 .rdata:00796384
		virtual void Function_0021(); //#21 +54 .rdata:00796388
		virtual void Function_0022(); //#22 +58 .rdata:0079638c
		virtual void Function_0023(); //#23 +5c .rdata:00796390
		virtual void Function_0024(); //#24 +60 .rdata:00796394
		virtual void Function_0025(); //#25 +64 .rdata:00796398
		virtual void Function_0026(); //#26 +68 .rdata:0079639c
		virtual void Function_0027(); //#27 +6c .rdata:007963a0
		virtual void Function_0028(); //#28 +70 .rdata:007963a4
		virtual void Function_0029(); //#29 +74 .rdata:007963a8
		virtual void Function_0030(); //#30 +78 .rdata:007963ac
		virtual void Function_0031(); //#31 +7c .rdata:007963b0
		virtual void Function_0032(); //#32 +80 .rdata:007963b4
		virtual void Function_0033(); //#33 +84 .rdata:007963b8
		virtual void Function_0034(); //#34 +88 .rdata:007963bc
		virtual void Function_0035(); //#35 +8c .rdata:007963c0
		virtual void Function_0036(); //#36 +90 .rdata:007963c4
		virtual void Function_0037(); //#37 +94 .rdata:007963c8
		virtual void Function_0038(); //#38 +98 .rdata:007963cc
		virtual void Function_0039(); //#39 +9c .rdata:007963d0
		virtual void Function_0040(); //#40 +a0 .rdata:007963d4
		virtual void Function_0041(); //#41 +a4 .rdata:007963d8
		virtual void Function_0042(); //#42 +a8 .rdata:007963dc
		virtual void Function_0043(); //#43 +ac .rdata:007963e0
		virtual void Function_0044(); //#44 +b0 .rdata:007963e4
		virtual void Function_0045(); //#45 +b4 .rdata:007963e8
		virtual void Function_0046(); //#46 +b8 .rdata:007963ec
		virtual void Function_0047(); //#47 +bc .rdata:007963f0
		virtual void Function_0048(); //#48 +c0 .rdata:007963f4
		virtual void Function_0049(); //#49 +c4 .rdata:007963f8
		virtual void Function_0050(); //#50 +c8 .rdata:007963fc
		virtual void Function_0051(); //#51 +cc .rdata:00796400
		virtual void Function_0052(); //#52 +d0 .rdata:00796404
		virtual void Function_0053(); //#53 +d4 .rdata:00796408
		virtual void Function_0054(); //#54 +d8 .rdata:0079640c
		virtual void Function_0055(); //#55 +dc .rdata:00796410
		virtual void Function_0056(); //#56 +e0 .rdata:00796414
		virtual void Function_0057(); //#57 +e4 .rdata:00796418
		virtual void Function_0058(); //#58 +e8 .rdata:0079641c
		virtual void Function_0059(); //#59 +ec .rdata:00796420
		virtual void Function_0060(); //#60 +f0 .rdata:00796424
		virtual void Function_0061(); //#61 +f4 .rdata:00796428
		virtual void Function_0062(); //#62 +f8 .rdata:0079642c
		virtual void Function_0063(); //#63 +fc .rdata:00796430
		virtual int getComponent(const char* componentName); //#64 +100 .rdata:00796434
		virtual void Function_0065(); //#65 +104 .rdata:00796438
		virtual void Function_0066(); //#66 +108 .rdata:0079643c
		virtual void Function_0067(); //#67 +10c .rdata:00796440
		virtual void Function_0068(); //#68 +110 .rdata:00796444
		virtual void Function_0069(); //#69 +114 .rdata:00796448
		virtual void Function_0070(); //#70 +118 .rdata:0079644c
		virtual void Function_0071(); //#71 +11c .rdata:00796450
		virtual void sendEvent(std::uintptr_t ev, int unk0, int unk1); //#72 +120 .rdata:00796454
		virtual void Function_0073(); //#73 +124 .rdata:00796458
		virtual void Function_0074(); //#74 +128 .rdata:0079645c
		virtual void Function_0075(); //#75 +12c .rdata:00796460
		virtual void Function_0076(); //#76 +130 .rdata:00796464
		virtual void Function_0077(); //#77 +134 .rdata:00796468
		virtual void Function_0078(); //#78 +138 .rdata:0079646c
		virtual void Function_0079(); //#79 +13c .rdata:00796470
		virtual void Function_0080(); //#80 +140 .rdata:00796474
		virtual void Function_0081(); //#81 +144 .rdata:00796478
		virtual void Function_0082(); //#82 +148 .rdata:0079647c
		virtual void Function_0083(); //#83 +14c .rdata:00796480
		virtual void Function_0084(); //#84 +150 .rdata:00796484
		virtual void Function_0085(); //#85 +154 .rdata:00796488
		virtual void Function_0086(); //#86 +158 .rdata:0079648c
		virtual void Function_0087(); //#87 +15c .rdata:00796490
		virtual void Function_0088(); //#88 +160 .rdata:00796494
		virtual void dropAnimation(int, int); //#89 +164 .rdata:00796498
		virtual void Function_0090(); //#90 +168 .rdata:0079649c
		virtual void Function_0091(); //#91 +16c .rdata:007964a0
		virtual void Function_0092(); //#92 +170 .rdata:007964a4
		virtual void Function_0093(); //#93 +174 .rdata:007964a8
		virtual void Function_0094(); //#94 +178 .rdata:007964ac
		virtual void Function_0095(); //#95 +17c .rdata:007964b0
		virtual void Function_0096(); //#96 +180 .rdata:007964b4
		virtual void Function_0097(); //#97 +184 .rdata:007964b8
		virtual void Function_0098(); //#98 +188 .rdata:007964bc
		virtual void Function_0099(); //#99 +18c .rdata:007964c0
		virtual void Function_0100(); //#100 +190 .rdata:007964c4
		virtual void Function_0101(); //#101 +194 .rdata:007964c8
		virtual void Function_0102(); //#102 +198 .rdata:007964cc
		virtual void Function_0103(); //#103 +19c .rdata:007964d0
		virtual void Function_0104(); //#104 +1a0 .rdata:007964d4
		virtual void Function_0105(); //#105 +1a4 .rdata:007964d8
		virtual void Function_0106(); //#106 +1a8 .rdata:007964dc
		virtual void Function_0107(); //#107 +1ac .rdata:007964e0
		virtual void Function_0108(); //#108 +1b0 .rdata:007964e4
		virtual void Function_0109(); //#109 +1b4 .rdata:007964e8
		virtual void Function_0110(); //#110 +1b8 .rdata:007964ec
		virtual void Function_0111(); //#111 +1bc .rdata:007964f0
		virtual void Function_0112(); //#112 +1c0 .rdata:007964f4
		virtual void Function_0113(); //#113 +1c4 .rdata:007964f8
		virtual void Function_0114(); //#114 +1c8 .rdata:007964fc
		virtual void Function_0115(); //#115 +1cc .rdata:00796500
		virtual void Function_0116(); //#116 +1d0 .rdata:00796504
		virtual void Function_0117(); //#117 +1d4 .rdata:00796508
		virtual void Function_0118(); //#118 +1d8 .rdata:0079650c
		virtual void Function_0119(); //#119 +1dc .rdata:00796510
		virtual void Function_0120(); //#120 +1e0 .rdata:00796514
		virtual void Function_0121(); //#121 +1e4 .rdata:00796518
		virtual void Function_0122(); //#122 +1e8 .rdata:0079651c
		virtual void Function_0123(); //#123 +1ec .rdata:00796520
		virtual void Function_0124(); //#124 +1f0 .rdata:00796524
		virtual void Function_0125(); //#125 +1f4 .rdata:00796528
		virtual void setAnimation(ioi::hm3::ZAnimationInfo* animation, int unknown0 = 1); //#126 +1f8 .rdata:0079652c
		virtual void Function_0127(); //#127 +1fc .rdata:00796530
		virtual void Function_0128(); //#128 +200 .rdata:00796534
		virtual void Function_0129(); //#129 +204 .rdata:00796538
		virtual void Function_0130(); //#130 +208 .rdata:0079653c
		virtual void Function_0131(); //#131 +20c .rdata:00796540
		virtual void Function_0132(); //#132 +210 .rdata:00796544
		virtual void Function_0133(); //#133 +214 .rdata:00796548
		virtual void Function_0134(); //#134 +218 .rdata:0079654c
		virtual void Function_0135(); //#135 +21c .rdata:00796550
		virtual void Function_0136(); //#136 +220 .rdata:00796554
		virtual void Function_0137(); //#137 +224 .rdata:00796558
		virtual void Function_0138(); //#138 +228 .rdata:0079655c
		virtual void Function_0139(); //#139 +22c .rdata:00796560
		virtual void Function_0140(); //#140 +230 .rdata:00796564
		virtual void Function_0141(); //#141 +234 .rdata:00796568
		virtual void Function_0142(); //#142 +238 .rdata:0079656c
		virtual void Function_0143(); //#143 +23c .rdata:00796570
		virtual void Function_0144(); //#144 +240 .rdata:00796574
		virtual void Function_0145(); //#145 +244 .rdata:00796578
		virtual void Function_0146(); //#146 +248 .rdata:0079657c
		virtual void Function_0147(); //#147 +24c .rdata:00796580
		virtual void Function_0148(); //#148 +250 .rdata:00796584
		virtual void Function_0149(); //#149 +254 .rdata:00796588
		virtual void Function_0150(); //#150 +258 .rdata:0079658c
		virtual void Function_0151(); //#151 +25c .rdata:00796590
		virtual void Function_0152(); //#152 +260 .rdata:00796594
		virtual void Function_0153(); //#153 +264 .rdata:00796598
		virtual void Function_0154(); //#154 +268 .rdata:0079659c
		virtual void Function_0155(); //#155 +26c .rdata:007965a0
		virtual void Function_0156(); //#156 +270 .rdata:007965a4
		virtual void Function_0157(); //#157 +274 .rdata:007965a8
		virtual void Function_0158(); //#158 +278 .rdata:007965ac
		virtual void Function_0159(); //#159 +27c .rdata:007965b0
		virtual void Function_0160(); //#160 +280 .rdata:007965b4
		virtual void Function_0161(); //#161 +284 .rdata:007965b8
		virtual void Function_0162(); //#162 +288 .rdata:007965bc
		virtual void Function_0163(); //#163 +28c .rdata:007965c0
		virtual void Function_0164(); //#164 +290 .rdata:007965c4
		virtual void Function_0165(); //#165 +294 .rdata:007965c8
		virtual void Function_0166(); //#166 +298 .rdata:007965cc
		virtual void Function_0167(); //#167 +29c .rdata:007965d0
		virtual void Function_0168(); //#168 +2a0 .rdata:007965d4
		virtual void Function_0169(); //#169 +2a4 .rdata:007965d8
		virtual void Function_0170(); //#170 +2a8 .rdata:007965dc
		virtual void Function_0171(); //#171 +2ac .rdata:007965e0
		virtual void Function_0172(); //#172 +2b0 .rdata:007965e4
		virtual void Function_0173(); //#173 +2b4 .rdata:007965e8
		virtual void Function_0174(); //#174 +2b8 .rdata:007965ec
		virtual void Function_0175(); //#175 +2bc .rdata:007965f0
		virtual void Function_0176(); //#176 +2c0 .rdata:007965f4
		virtual void Function_0177(); //#177 +2c4 .rdata:007965f8
		virtual void Function_0178(); //#178 +2c8 .rdata:007965fc
		virtual void Function_0179(); //#179 +2cc .rdata:00796600
		virtual void Function_0180(); //#180 +2d0 .rdata:00796604
		virtual void Function_0181(); //#181 +2d4 .rdata:00796608
		virtual void Function_0182(); //#182 +2d8 .rdata:0079660c
		virtual void Function_0183(); //#183 +2dc .rdata:00796610
		virtual void Function_0184(); //#184 +2e0 .rdata:00796614
		virtual void Function_0185(); //#185 +2e4 .rdata:00796618
		virtual void Function_0186(); //#186 +2e8 .rdata:0079661c
		virtual void Function_0187(); //#187 +2ec .rdata:00796620
		virtual void Function_0188(); //#188 +2f0 .rdata:00796624
		virtual void Function_0189(); //#189 +2f4 .rdata:00796628
		virtual void Function_0190(); //#190 +2f8 .rdata:0079662c
		virtual void Function_0191(); //#191 +2fc .rdata:00796630
		virtual void Function_0192(); //#192 +300 .rdata:00796634
		virtual void Function_0193(); //#193 +304 .rdata:00796638
		virtual void Function_0194(); //#194 +308 .rdata:0079663c
		virtual void Function_0195(); //#195 +30c .rdata:00796640
		virtual void Function_0196(); //#196 +310 .rdata:00796644
		virtual void Function_0197(); //#197 +314 .rdata:00796648
		virtual void Function_0198(); //#198 +318 .rdata:0079664c
		virtual void Function_0199(); //#199 +31c .rdata:00796650
		virtual void Function_0200(); //#200 +320 .rdata:00796654
		virtual void Function_0201(); //#201 +324 .rdata:00796658
		virtual void Function_0202(); //#202 +328 .rdata:0079665c
		virtual void Function_0203(); //#203 +32c .rdata:00796660
		virtual void Function_0204(); //#204 +330 .rdata:00796664
		virtual void Function_0205(); //#205 +334 .rdata:00796668
		virtual void Function_0206(); //#206 +338 .rdata:0079666c
		virtual void Function_0207(); //#207 +33c .rdata:00796670
		virtual void Function_0208(); //#208 +340 .rdata:00796674
		virtual void Function_0209(); //#209 +344 .rdata:00796678
		virtual void Function_0210(); //#210 +348 .rdata:0079667c
		virtual void Function_0211(); //#211 +34c .rdata:00796680
		virtual void Function_0212(); //#212 +350 .rdata:00796684
		virtual void Function_0213(); //#213 +354 .rdata:00796688
		virtual void Function_0214(); //#214 +358 .rdata:0079668c
		virtual void Function_0215(); //#215 +35c .rdata:00796690
		virtual void Function_0216(); //#216 +360 .rdata:00796694
		virtual void Function_0217(); //#217 +364 .rdata:00796698
		virtual void Function_0218(); //#218 +368 .rdata:0079669c
		virtual void Function_0219(); //#219 +36c .rdata:007966a0
		virtual void Function_0220(); //#220 +370 .rdata:007966a4
		virtual void Function_0221(); //#221 +374 .rdata:007966a8
		virtual void Function_0222(); //#222 +378 .rdata:007966ac
		virtual void Function_0223(); //#223 +37c .rdata:007966b0
		virtual void Function_0224(); //#224 +380 .rdata:007966b4
		virtual void Function_0225(); //#225 +384 .rdata:007966b8
		virtual void Function_0226(); //#226 +388 .rdata:007966bc
		virtual void Function_0227(); //#227 +38c .rdata:007966c0
		virtual void Function_0228(); //#228 +390 .rdata:007966c4
		virtual void Function_0229(); //#229 +394 .rdata:007966c8
		virtual void Function_0230(); //#230 +398 .rdata:007966cc
		virtual void Function_0231(); //#231 +39c .rdata:007966d0
		virtual void Function_0232(); //#232 +3a0 .rdata:007966d4
		virtual void Function_0233(); //#233 +3a4 .rdata:007966d8
		virtual void Function_0234(); //#234 +3a8 .rdata:007966dc
		virtual void Function_0235(); //#235 +3ac .rdata:007966e0
		virtual void Function_0236(); //#236 +3b0 .rdata:007966e4
		virtual void Function_0237(); //#237 +3b4 .rdata:007966e8
		virtual void Function_0238(); //#238 +3b8 .rdata:007966ec
		virtual void Function_0239(); //#239 +3bc .rdata:007966f0
		virtual void Function_0240(); //#240 +3c0 .rdata:007966f4
		virtual void Function_0241(); //#241 +3c4 .rdata:007966f8
		virtual void Function_0242(); //#242 +3c8 .rdata:007966fc
		virtual void Function_0243(); //#243 +3cc .rdata:00796700
		virtual void Function_0244(); //#244 +3d0 .rdata:00796704
		virtual void Function_0245(); //#245 +3d4 .rdata:00796708
		virtual void Function_0246(); //#246 +3d8 .rdata:0079670c
		virtual void Function_0247(); //#247 +3dc .rdata:00796710
		virtual void Function_0248(); //#248 +3e0 .rdata:00796714
		virtual void Function_0249(); //#249 +3e4 .rdata:00796718
		virtual void Function_0250(); //#250 +3e8 .rdata:0079671c
		virtual void Function_0251(); //#251 +3ec .rdata:00796720
		virtual void Function_0252(); //#252 +3f0 .rdata:00796724
		virtual void Function_0253(); //#253 +3f4 .rdata:00796728
		virtual void Function_0254(); //#254 +3f8 .rdata:0079672c
		virtual void Function_0255(); //#255 +3fc .rdata:00796730
		virtual void Function_0256(); //#256 +400 .rdata:00796734
		virtual void Function_0257(); //#257 +404 .rdata:00796738
		virtual void Function_0258(); //#258 +408 .rdata:0079673c
		virtual void Function_0259(); //#259 +40c .rdata:00796740
		virtual void Function_0260(); //#260 +410 .rdata:00796744
		virtual const char* Function_0261(); //#261 +414 .rdata:00796748
		virtual void Function_0262(); //#262 +418 .rdata:0079674c
		virtual void Function_0263(); //#263 +41c .rdata:00796750
		virtual void Function_0264(); //#264 +420 .rdata:00796754
		virtual void Function_0265(); //#265 +424 .rdata:00796758
		virtual void Function_0266(); //#266 +428 .rdata:0079675c
		virtual void Function_0267(); //#267 +42c .rdata:00796760
		virtual void Function_0268(); //#268 +430 .rdata:00796764
		virtual void Function_0269(); //#269 +434 .rdata:00796768
		virtual void Function_0270(); //#270 +438 .rdata:0079676c
		virtual void Function_0271(); //#271 +43c .rdata:00796770
		virtual void Function_0272(); //#272 +440 .rdata:00796774
		virtual void Function_0273(); //#273 +444 .rdata:00796778
		virtual void Function_0274(); //#274 +448 .rdata:0079677c
		virtual void Function_0275(); //#275 +44c .rdata:00796780
		virtual void Function_0276(); //#276 +450 .rdata:00796784
		virtual void Function_0277(); //#277 +454 .rdata:00796788
		virtual void Function_0278(); //#278 +458 .rdata:0079678c
		virtual void Function_0279(); //#279 +45c .rdata:00796790
		virtual void Function_0280(); //#280 +460 .rdata:00796794
		virtual void Function_0281(); //#281 +464 .rdata:00796798
		virtual void Function_0282(); //#282 +468 .rdata:0079679c
		virtual void Function_0283(); //#283 +46c .rdata:007967a0
		virtual void Function_0284(); //#284 +470 .rdata:007967a4
		virtual void Function_0285(); //#285 +474 .rdata:007967a8
		virtual void Function_0286(); //#286 +478 .rdata:007967ac
		virtual void Function_0287(); //#287 +47c .rdata:007967b0
		virtual void Function_0288(); //#288 +480 .rdata:007967b4
		virtual void Function_0289(); //#289 +484 .rdata:007967b8
		virtual void Function_0290(); //#290 +488 .rdata:007967bc
		virtual void Function_0291(); //#291 +48c .rdata:007967c0
		virtual void Function_0292(); //#292 +490 .rdata:007967c4
		virtual void Function_0293(); //#293 +494 .rdata:007967c8
		virtual void Function_0294(); //#294 +498 .rdata:007967cc
		virtual void Function_0295(); //#295 +49c .rdata:007967d0
		virtual void Function_0296(); //#296 +4a0 .rdata:007967d4
		virtual void Function_0297(); //#297 +4a4 .rdata:007967d8
		virtual void Function_0298(); //#298 +4a8 .rdata:007967dc
		virtual void Function_0299(); //#299 +4ac .rdata:007967e0
		virtual void Function_0300(); //#300 +4b0 .rdata:007967e4
		virtual void Function_0301(); //#301 +4b4 .rdata:007967e8
		virtual void Function_0302(); //#302 +4b8 .rdata:007967ec
		virtual void Function_0303(); //#303 +4bc .rdata:007967f0
		virtual void Function_0304(); //#304 +4c0 .rdata:007967f4
		virtual void Function_0305(); //#305 +4c4 .rdata:007967f8
		virtual void Function_0306(); //#306 +4c8 .rdata:007967fc
		virtual void Function_0307(); //#307 +4cc .rdata:00796800
		virtual void Function_0308(); //#308 +4d0 .rdata:00796804
		virtual void Function_0309(); //#309 +4d4 .rdata:00796808
		virtual void Function_0310(); //#310 +4d8 .rdata:0079680c
		virtual void Function_0311(); //#311 +4dc .rdata:00796810
		virtual void Function_0312(); //#312 +4e0 .rdata:00796814
		virtual void Function_0313(); //#313 +4e4 .rdata:00796818
		virtual void Function_0314(); //#314 +4e8 .rdata:0079681c
		virtual void Function_0315(); //#315 +4ec .rdata:00796820
		virtual void Function_0316(); //#316 +4f0 .rdata:00796824
		virtual void Function_0317(); //#317 +4f4 .rdata:00796828
		virtual void Function_0318(); //#318 +4f8 .rdata:0079682c
		virtual void Function_0319(); //#319 +4fc .rdata:00796830
		virtual void Function_0320(); //#320 +500 .rdata:00796834
		virtual void Function_0321(); //#321 +504 .rdata:00796838
		virtual void Function_0322(); //#322 +508 .rdata:0079683c
		virtual void Function_0323(); //#323 +50c .rdata:00796840
		virtual void Function_0324(); //#324 +510 .rdata:00796844
		virtual void Function_0325(); //#325 +514 .rdata:00796848
		virtual void Function_0326(); //#326 +518 .rdata:0079684c
		virtual void Function_0327(); //#327 +51c .rdata:00796850
		virtual void Function_0328(); //#328 +520 .rdata:00796854
		virtual void Function_0329(); //#329 +524 .rdata:00796858
		virtual void Function_0330(); //#330 +528 .rdata:0079685c
		virtual void Function_0331(); //#331 +52c .rdata:00796860
		virtual void Function_0332(); //#332 +530 .rdata:00796864
		virtual void Function_0333(); //#333 +534 .rdata:00796868
		virtual void Function_0334(); //#334 +538 .rdata:0079686c
		virtual void Function_0335(); //#335 +53c .rdata:00796870
		virtual void Function_0336(); //#336 +540 .rdata:00796874
		virtual void Function_0337(); //#337 +544 .rdata:00796878
		virtual void Function_0338(); //#338 +548 .rdata:0079687c
		virtual void Function_0339(); //#339 +54c .rdata:00796880
		virtual void Function_0340(); //#340 +550 .rdata:00796884
		virtual void Function_0341(); //#341 +554 .rdata:00796888
		virtual void Function_0342(); //#342 +558 .rdata:0079688c
		virtual void Function_0343(); //#343 +55c .rdata:00796890
		virtual void Function_0344(); //#344 +560 .rdata:00796894
		virtual void Function_0345(); //#345 +564 .rdata:00796898
		virtual void Function_0346(); //#346 +568 .rdata:0079689c
		virtual void Function_0347(); //#347 +56c .rdata:007968a0
		virtual int setStatus(ActorStatus status); //#348 +570 .rdata:007968a4
		virtual void Function_0349(); //#349 +574 .rdata:007968a8
		virtual void Function_0350(); //#350 +578 .rdata:007968ac
		virtual void Function_0351(); //#351 +57c .rdata:007968b0
		virtual void Function_0352(); //#352 +580 .rdata:007968b4
		virtual void Function_0353(); //#353 +584 .rdata:007968b8
		virtual void setPosition__FAKE(float* pThreeFloats); //#354 +588 .rdata:007968bc (it works with coordinates but not world coordinates [-1.0; 1.0])
		virtual const float* getPosition__FAKE(); //#355 +58c .rdata:007968c0
		virtual void Function_0356(); //#356 +590 .rdata:007968c4
		virtual void Function_0357(); //#357 +594 .rdata:007968c8
		virtual void Function_0358(); //#358 +598 .rdata:007968cc
		virtual bool Function_0359(bool arg); //#359 +59c .rdata:007968d0
		virtual bool Function_0360(bool arg); //#360 +5a0 .rdata:007968d4
		virtual void Function_0361(); //#361 +5a4 .rdata:007968d8
		virtual void Function_0362(); //#362 +5a8 .rdata:007968dc
		virtual void Function_0363(); //#363 +5ac .rdata:007968e0
		virtual void Function_0364(); //#364 +5b0 .rdata:007968e4
		virtual int Function_0365(bool arg); //#365 +5b4 .rdata:007968e8
		virtual bool Function_0366(bool); //#366 +5b8 .rdata:007968ec
		virtual void Function_0367(); //#367 +5bc .rdata:007968f0
		virtual void Function_0368(); //#368 +5c0 .rdata:007968f4
		virtual void Function_0369(); //#369 +5c4 .rdata:007968f8
		virtual void Function_0370(); //#370 +5c8 .rdata:007968fc
		virtual void Function_0371(); //#371 +5cc .rdata:00796900
		virtual void Function_0372(); //#372 +5d0 .rdata:00796904
		virtual void Function_0373(); //#373 +5d4 .rdata:00796908
		virtual void Function_0374(); //#374 +5d8 .rdata:0079690c
		virtual void Function_0375(); //#375 +5dc .rdata:00796910
		virtual void Function_0376(); //#376 +5e0 .rdata:00796914
		virtual bool Function_0377(); //#377 +5e4 .rdata:00796918
		virtual void Function_0378(); //#378 +5e8 .rdata:0079691c
		virtual void Function_0379(); //#379 +5ec .rdata:00796920
		virtual void kill(); //#380 +5f0 .rdata:00796924
		virtual void Function_0381(); //#381 +5f4 .rdata:00796928
		virtual int Function_0382(); //#382 +5f8 .rdata:0079692c
		virtual int sedate(); //#383 +5fc .rdata:00796930 (possible not but actor not dies here)
		virtual int Function_0384(); //#384 +600 .rdata:00796934
		virtual void Function_0385(); //#385 +604 .rdata:00796938
		virtual int Function_0386(); //#386 +608 .rdata:0079693c
		virtual void Function_0387(); //#387 +60c .rdata:00796940
		virtual void Function_0388(); //#388 +610 .rdata:00796944
		virtual void Function_0389(); //#389 +614 .rdata:00796948
		virtual void Function_0390(); //#390 +618 .rdata:0079694c
		virtual void Function_0391(); //#391 +61c .rdata:00796950
		virtual void Function_0392(); //#392 +620 .rdata:00796954
		virtual void Function_0393(); //#393 +624 .rdata:00796958
		virtual void Function_0394(); //#394 +628 .rdata:0079695c
		virtual void Function_0395(); //#395 +62c .rdata:00796960 (sync suspicious level with ZOSD)
		virtual void Function_0396(); //#396 +630 .rdata:00796964
		virtual void Function_0397(); //#397 +634 .rdata:00796968
		virtual void Function_0398(); //#398 +638 .rdata:0079696c
		virtual void Function_0399(); //#399 +63c .rdata:00796970
		virtual void Function_0400(); //#400 +640 .rdata:00796974
		virtual void Function_0401(); //#401 +644 .rdata:00796978
		virtual void Function_0402(); //#402 +648 .rdata:0079697c
		virtual void Function_0403(); //#403 +64c .rdata:00796980
		virtual void Function_0404(); //#404 +650 .rdata:00796984
		virtual void Function_0405(); //#405 +654 .rdata:00796988
		virtual void Function_0406(); //#406 +658 .rdata:0079698c
		virtual void Function_0407(); //#407 +65c .rdata:00796990
		virtual void Function_0408(); //#408 +660 .rdata:00796994
		virtual void Function_0409(); //#409 +664 .rdata:00796998
		virtual void Function_0410(); //#410 +668 .rdata:0079699c
		virtual void Function_0411(); //#411 +66c .rdata:007969a0
		virtual void Function_0412(); //#412 +670 .rdata:007969a4
		virtual void Function_0413(); //#413 +674 .rdata:007969a8
		virtual void Function_0414(); //#414 +678 .rdata:007969ac
		virtual void Function_0415(); //#415 +67c .rdata:007969b0
		virtual void Function_0416(); //#416 +680 .rdata:007969b4
		virtual void Function_0417(); //#417 +684 .rdata:007969b8
		virtual void Function_0418(); //#418 +688 .rdata:007969bc (knife thrower check, maybe item hooking here)
		virtual void Function_0419(); //#419 +68c .rdata:007969c0
		virtual void Function_0420(); //#420 +690 .rdata:007969c4
		virtual void Function_0421(); //#421 +694 .rdata:007969c8
		virtual void Function_0422(); //#422 +698 .rdata:007969cc
		virtual void Function_0423(); //#423 +69c .rdata:007969d0
		virtual void Function_0424(); //#424 +6a0 .rdata:007969d4
		virtual void Function_0425(); //#425 +6a4 .rdata:007969d8
		virtual void Function_0426(); //#426 +6a8 .rdata:007969dc
		virtual void Function_0427(); //#427 +6ac .rdata:007969e0
		virtual void Function_0428(); //#428 +6b0 .rdata:007969e4
		virtual void Function_0429(); //#429 +6b4 .rdata:007969e8
		virtual void Function_0430(); //#430 +6b8 .rdata:007969ec
		virtual void Function_0431(); //#431 +6bc .rdata:007969f0
		virtual void Function_0432(); //#432 +6c0 .rdata:007969f4
		virtual void Function_0433(); //#433 +6c4 .rdata:007969f8
		virtual void Function_0434(); //#434 +6c8 .rdata:007969fc
		virtual void Function_0435(); //#435 +6cc .rdata:00796a00
		virtual void Function_0436(); //#436 +6d0 .rdata:00796a04
		virtual void Function_0437(); //#437 +6d4 .rdata:00796a08
		virtual void Function_0438(); //#438 +6d8 .rdata:00796a0c
		virtual void Function_0439(); //#439 +6dc .rdata:00796a10
		virtual void Function_0440(); //#440 +6e0 .rdata:00796a14
		virtual void Function_0441(); //#441 +6e4 .rdata:00796a18
		virtual void Function_0442(); //#442 +6e8 .rdata:00796a1c
		virtual void Function_0443(); //#443 +6ec .rdata:00796a20
		virtual void Function_0444(); //#444 +6f0 .rdata:00796a24 (loadExtendedAnimations)
		virtual void Function_0445(); //#445 +6f4 .rdata:00796a28
		virtual void Function_0446(); //#446 +6f8 .rdata:00796a2c
		virtual void Function_0447(); //#447 +6fc .rdata:00796a30 (actor flags, maybe not used by game)
		virtual void Function_0448(); //#448 +700 .rdata:00796a34

		// === members ===
		ActorInfos* ActorInformation;	//0x0004
		char pad_0008[68]; //0x0008
		SuiteMask m_suitMask; //0x004C
		char pad_0050[932]; //0x0050
		ZHumanBoid* m_boid; //0x03F4
		char pad_03F8[1288]; //0x03F8
		int32_t m_onMapType; //0x0900
		char pad_0904[452]; //0x0904
		uint32_t m_currentZROOM; //0x0AC8
		char pad_0ACC[148]; //0x0ACC


		// === custom ===
		ZIKHAND* getHand(HandType type);

		/**
			Unmapped: 
				+900 - Actor type


			#89 called when actor see us
		
		**/
	}; //Size: 0x0008

	//"THINKER" code sub_504CB0
	//REMOVE GUN FROM HAND OF ACTOR - sub_59E160
	//Called before actor dead sub_59C610 (sometimes)
	//Combat prepare sub_607000
	//.rdata:007964A0                 dd offset sub_4FC030 [ work with physics ]
	//.rdata:007963F4                 dd offset sub_4FBFD0 [ is 5'th bit of +C field inited by 1 ] (in some case set +C |= 0x20u), possible toggle something
	//.rdata:007963F0                 dd offset sub_4E6AC0 [ toggle +2 byte field ]
	//.rdata:007963E8                 dd offset sub_4E69E0 [ +C | add 0x10 or remove 0x10 to mask ]
	//.rdata:00796370                 dd offset sub_6322D0 [ some getter of global ptr, could be useful. Values at pointer looks like messages ]
	// 0051B4F9 - write item id into ZIKHAND when actor wants to use their gun
	// .text:0063E286 (killed here)
}}