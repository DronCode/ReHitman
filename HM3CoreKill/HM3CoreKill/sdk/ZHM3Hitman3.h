#pragma once

#include <sdk/actions/ZLnkAction.h>
#include <sdk/game/ZHM3MovementGuideToMatPos.h>
#include <sdk/ZLnkActionQueue.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ZBoxPrimitive.h>
#include <sdk/CInventory.h>
#include <sdk/ZHumanBoid.h>
#include <sdk/ZHM3Camera.h>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZHM3HmAs.h>
#include <sdk/ZIKHAND.h>
#include <sdk/ZROOM.h>

namespace ioi { namespace hm3 {

	struct NearActorRef
	{
		ZHM3Actor* actor;	//+ 00
		float distance;		//+ 04
		float unk0;			//+ 08
		float unk1;			//+ 0C
	};

	class ZHM3Hitman3
	{
	public:
		// === vftable ===
		virtual void Function_0000(); // [0000] +0000 [.rdata at 0x00790E8C]
		virtual void Function_0001(); // [0001] +0004 [.rdata at 0x00790E90]
		virtual void Function_0002(); // [0002] +0008 [.rdata at 0x00790E94]
		virtual void Function_0003(); // [0003] +000C [.rdata at 0x00790E98]
		virtual void Function_0004(); // [0004] +0010 [.rdata at 0x00790E9C]
		virtual void Function_0005(); // [0005] +0014 [.rdata at 0x00790EA0]
		virtual void Function_0006(); // [0006] +0018 [.rdata at 0x00790EA4]
		virtual void Function_0007(); // [0007] +001C [.rdata at 0x00790EA8]
		virtual void Function_0008(); // [0008] +0020 [.rdata at 0x00790EAC]
		virtual void Function_0009(); // [0009] +0024 [.rdata at 0x00790EB0]
		virtual void Function_0010(); // [0010] +0028 [.rdata at 0x00790EB4]
		virtual void Function_0011(); // [0011] +002C [.rdata at 0x00790EB8]
		virtual void Function_0012(); // [0012] +0030 [.rdata at 0x00790EBC]
		virtual void Function_0013(); // [0013] +0034 [.rdata at 0x00790EC0]
		virtual void Function_0014(); // [0014] +0038 [.rdata at 0x00790EC4]
		virtual void Function_0015(); // [0015] +003C [.rdata at 0x00790EC8]
		virtual void Function_0016(); // [0016] +0040 [.rdata at 0x00790ECC]
		virtual void Function_0017(); // [0017] +0044 [.rdata at 0x00790ED0]
		virtual void Function_0018(); // [0018] +0048 [.rdata at 0x00790ED4]
		virtual void Function_0019(); // [0019] +004C [.rdata at 0x00790ED8]
		virtual void Function_0020(); // [0020] +0050 [.rdata at 0x00790EDC]
		virtual void Function_0021(); // [0021] +0054 [.rdata at 0x00790EE0]
		virtual void Function_0022(); // [0022] +0058 [.rdata at 0x00790EE4]
		virtual void Function_0023(); // [0023] +005C [.rdata at 0x00790EE8]
		virtual void Function_0024(); // [0024] +0060 [.rdata at 0x00790EEC]
		virtual void Function_0025(); // [0025] +0064 [.rdata at 0x00790EF0]
		virtual void Function_0026(); // [0026] +0068 [.rdata at 0x00790EF4]
		virtual void Function_0027(); // [0027] +006C [.rdata at 0x00790EF8]
		virtual void Function_0028(); // [0028] +0070 [.rdata at 0x00790EFC]
		virtual void Function_0029(); // [0029] +0074 [.rdata at 0x00790F00]
		virtual void Function_0030(); // [0030] +0078 [.rdata at 0x00790F04]
		virtual void Function_0031(); // [0031] +007C [.rdata at 0x00790F08]
		virtual void Function_0032(); // [0032] +0080 [.rdata at 0x00790F0C]
		virtual void Function_0033(); // [0033] +0084 [.rdata at 0x00790F10]
		virtual void Function_0034(); // [0034] +0088 [.rdata at 0x00790F14]
		virtual void Function_0035(); // [0035] +008C [.rdata at 0x00790F18]
		virtual void Function_0036(); // [0036] +0090 [.rdata at 0x00790F1C]
		virtual void Function_0037(); // [0037] +0094 [.rdata at 0x00790F20]
		virtual void Function_0038(); // [0038] +0098 [.rdata at 0x00790F24]
		virtual void Function_0039(); // [0039] +009C [.rdata at 0x00790F28]
		virtual void Function_0040(); // [0040] +00A0 [.rdata at 0x00790F2C]
		virtual void Function_0041(); // [0041] +00A4 [.rdata at 0x00790F30]
		virtual void Function_0042(); // [0042] +00A8 [.rdata at 0x00790F34]
		virtual void Function_0043(); // [0043] +00AC [.rdata at 0x00790F38]
		virtual void Function_0044(); // [0044] +00B0 [.rdata at 0x00790F3C]
		virtual void Function_0045(); // [0045] +00B4 [.rdata at 0x00790F40]
		virtual void Function_0046(); // [0046] +00B8 [.rdata at 0x00790F44]
		virtual void Function_0047(); // [0047] +00BC [.rdata at 0x00790F48]
		virtual void Function_0048(); // [0048] +00C0 [.rdata at 0x00790F4C]
		virtual void Function_0049(); // [0049] +00C4 [.rdata at 0x00790F50]
		virtual void Function_0050(); // [0050] +00C8 [.rdata at 0x00790F54]
		virtual void Function_0051(); // [0051] +00CC [.rdata at 0x00790F58]
		virtual void Function_0052(); // [0052] +00D0 [.rdata at 0x00790F5C]
		virtual void Function_0053(); // [0053] +00D4 [.rdata at 0x00790F60]
		virtual void Function_0054(); // [0054] +00D8 [.rdata at 0x00790F64]
		virtual void Function_0055(); // [0055] +00DC [.rdata at 0x00790F68]
		virtual void Function_0056(); // [0056] +00E0 [.rdata at 0x00790F6C]
		virtual void Function_0057(); // [0057] +00E4 [.rdata at 0x00790F70]
		virtual void Function_0058(); // [0058] +00E8 [.rdata at 0x00790F74]
		virtual void Function_0059(); // [0059] +00EC [.rdata at 0x00790F78]
		virtual void Function_0060(); // [0060] +00F0 [.rdata at 0x00790F7C]
		virtual void Function_0061(); // [0061] +00F4 [.rdata at 0x00790F80]
		virtual void Function_0062(); // [0062] +00F8 [.rdata at 0x00790F84]
		virtual void Function_0063(); // [0063] +00FC [.rdata at 0x00790F88]
		virtual int  getComponent(const char* componentName); // [0064] +0100 [.rdata at 0x00790F8C]
		virtual void Function_0065(); // [0065] +0104 [.rdata at 0x00790F90]
		virtual void Function_0066(); // [0066] +0108 [.rdata at 0x00790F94]
		virtual void Function_0067(); // [0067] +010C [.rdata at 0x00790F98]
		virtual void Function_0068(); // [0068] +0110 [.rdata at 0x00790F9C]
		virtual void Function_0069(); // [0069] +0114 [.rdata at 0x00790FA0]
		virtual void Function_0070(); // [0070] +0118 [.rdata at 0x00790FA4]
		virtual void Function_0071(); // [0071] +011C [.rdata at 0x00790FA8]
		virtual void sendEvent(std::uintptr_t evId, int* unk1, int unk2); // [0072] +0120 [.rdata at 0x00790FAC]
		virtual void sendEventWithNonSTDOBJ(int a1, std::intptr_t ev, int a3); // [0073] +0124 [.rdata at 0x00790FB0]
		virtual void sendEventWithSTDOBJ(ZSTDOBJ* stdObj, std::intptr_t ev, int* pResult); // [0074] +0128 [.rdata at 0x00790FB4]
		virtual int  sendEventWithEntityID(int entityID, std::intptr_t ev, int* pUnk = 0); // [0075] +012C [.rdata at 0x00790FB8]
		virtual void Function_0076(); // [0076] +0130 [.rdata at 0x00790FBC]
		virtual void Function_0077(); // [0077] +0134 [.rdata at 0x00790FC0]
		virtual void Function_0078(); // [0078] +0138 [.rdata at 0x00790FC4]
		virtual void Function_0079(); // [0079] +013C [.rdata at 0x00790FC8]
		virtual void Function_0080(); // [0080] +0140 [.rdata at 0x00790FCC]
		virtual void Function_0081(); // [0081] +0144 [.rdata at 0x00790FD0]
		virtual void Function_0082(); // [0082] +0148 [.rdata at 0x00790FD4]
		virtual void Function_0083(); // [0083] +014C [.rdata at 0x00790FD8]
		virtual void Function_0084(); // [0084] +0150 [.rdata at 0x00790FDC]
		virtual void Function_0085(); // [0085] +0154 [.rdata at 0x00790FE0]
		virtual void Function_0086(); // [0086] +0158 [.rdata at 0x00790FE4]
		virtual void Function_0087(); // [0087] +015C [.rdata at 0x00790FE8]
		virtual void Function_0088(); // [0088] +0160 [.rdata at 0x00790FEC]
		virtual void Function_0089(); // [0089] +0164 [.rdata at 0x00790FF0]
		virtual void Function_0090(); // [0090] +0168 [.rdata at 0x00790FF4]
		virtual void Function_0091(); // [0091] +016C [.rdata at 0x00790FF8]
		virtual void Function_0092(); // [0092] +0170 [.rdata at 0x00790FFC]
		virtual void Function_0093(); // [0093] +0174 [.rdata at 0x00791000]
		virtual void Function_0094(); // [0094] +0178 [.rdata at 0x00791004]
		virtual void Function_0095(); // [0095] +017C [.rdata at 0x00791008]
		virtual void Function_0096(); // [0096] +0180 [.rdata at 0x0079100C]
		virtual void Function_0097(); // [0097] +0184 [.rdata at 0x00791010]
		virtual void Function_0098(); // [0098] +0188 [.rdata at 0x00791014]
		virtual void Function_0099(); // [0099] +018C [.rdata at 0x00791018]
		virtual void Function_0100(); // [0100] +0190 [.rdata at 0x0079101C]
		virtual void Function_0101(); // [0101] +0194 [.rdata at 0x00791020]
		virtual void Function_0102(); // [0102] +0198 [.rdata at 0x00791024]
		virtual void Function_0103(); // [0103] +019C [.rdata at 0x00791028]
		virtual void Function_0104(); // [0104] +01A0 [.rdata at 0x0079102C]
		virtual void Function_0105(); // [0105] +01A4 [.rdata at 0x00791030]
		virtual void Function_0106(); // [0106] +01A8 [.rdata at 0x00791034]
		virtual void Function_0107(); // [0107] +01AC [.rdata at 0x00791038]
		virtual void Function_0108(); // [0108] +01B0 [.rdata at 0x0079103C]
		virtual void Function_0109(); // [0109] +01B4 [.rdata at 0x00791040]
		virtual void Function_0110(); // [0110] +01B8 [.rdata at 0x00791044]
		virtual void Function_0111(); // [0111] +01BC [.rdata at 0x00791048]
		virtual void Function_0112(); // [0112] +01C0 [.rdata at 0x0079104C]
		virtual void Function_0113(); // [0113] +01C4 [.rdata at 0x00791050]
		virtual void Function_0114(); // [0114] +01C8 [.rdata at 0x00791054]
		virtual void Function_0115(); // [0115] +01CC [.rdata at 0x00791058]
		virtual void Function_0116(); // [0116] +01D0 [.rdata at 0x0079105C]
		virtual void Function_0117(); // [0117] +01D4 [.rdata at 0x00791060]
		virtual void Function_0118(); // [0118] +01D8 [.rdata at 0x00791064]
		virtual void Function_0119(); // [0119] +01DC [.rdata at 0x00791068]
		virtual void Function_0120(); // [0120] +01E0 [.rdata at 0x0079106C]
		virtual void dropCurrentAnimation(int unknown0 = 0); // [0121] +01E4 [.rdata at 0x00791070]
		virtual void Function_0122(); // [0122] +01E8 [.rdata at 0x00791074]
		virtual void Function_0123(); // [0123] +01EC [.rdata at 0x00791078]
		virtual void Function_0124(); // [0124] +01F0 [.rdata at 0x0079107C]
		virtual void Function_0125(); // [0125] +01F4 [.rdata at 0x00791080]
		virtual ioi::hm3::ZAnimationInfo** setAnimation(ioi::hm3::ZAnimationInfo* animation, int unknown0 = 1); // [0126] +01F8 [.rdata at 0x00791084]
		virtual void Function_0127(); // [0127] +01FC [.rdata at 0x00791088]
		virtual void Function_0128(); // [0128] +0200 [.rdata at 0x0079108C]
		virtual void Function_0129(); // [0129] +0204 [.rdata at 0x00791090]
		virtual void Function_0130(); // [0130] +0208 [.rdata at 0x00791094]
		virtual void Function_0131(); // [0131] +020C [.rdata at 0x00791098]
		virtual void Function_0132(); // [0132] +0210 [.rdata at 0x0079109C]
		virtual void Function_0133(); // [0133] +0214 [.rdata at 0x007910A0]
		virtual void Function_0134(); // [0134] +0218 [.rdata at 0x007910A4]
		virtual void Function_0135(); // [0135] +021C [.rdata at 0x007910A8]
		virtual void Function_0136(); // [0136] +0220 [.rdata at 0x007910AC]
		virtual void Function_0137(); // [0137] +0224 [.rdata at 0x007910B0]
		virtual void Function_0138(); // [0138] +0228 [.rdata at 0x007910B4]
		virtual void Function_0139(); // [0139] +022C [.rdata at 0x007910B8]
		virtual void Function_0140(); // [0140] +0230 [.rdata at 0x007910BC]
		virtual void Function_0141(); // [0141] +0234 [.rdata at 0x007910C0]
		virtual void Function_0142(); // [0142] +0238 [.rdata at 0x007910C4]
		virtual void Function_0143(); // [0143] +023C [.rdata at 0x007910C8]
		virtual void Function_0144(); // [0144] +0240 [.rdata at 0x007910CC]
		virtual void Function_0145(); // [0145] +0244 [.rdata at 0x007910D0]
		virtual void Function_0146(); // [0146] +0248 [.rdata at 0x007910D4]
		virtual void Function_0147(); // [0147] +024C [.rdata at 0x007910D8]
		virtual void Function_0148(); // [0148] +0250 [.rdata at 0x007910DC]
		virtual void Function_0149(); // [0149] +0254 [.rdata at 0x007910E0]
		virtual void Function_0150(); // [0150] +0258 [.rdata at 0x007910E4]
		virtual void Function_0151(); // [0151] +025C [.rdata at 0x007910E8]
		virtual void Function_0152(); // [0152] +0260 [.rdata at 0x007910EC]
		virtual void Function_0153(); // [0153] +0264 [.rdata at 0x007910F0]
		virtual void Function_0154(); // [0154] +0268 [.rdata at 0x007910F4]
		virtual void Function_0155(); // [0155] +026C [.rdata at 0x007910F8]
		virtual void Function_0156(); // [0156] +0270 [.rdata at 0x007910FC]
		virtual void Function_0157(); // [0157] +0274 [.rdata at 0x00791100]
		virtual void Function_0158(); // [0158] +0278 [.rdata at 0x00791104]
		virtual void Function_0159(); // [0159] +027C [.rdata at 0x00791108]
		virtual void Function_0160(); // [0160] +0280 [.rdata at 0x0079110C]
		virtual void Function_0161(); // [0161] +0284 [.rdata at 0x00791110]
		virtual void Function_0162(); // [0162] +0288 [.rdata at 0x00791114]
		virtual void Function_0163(); // [0163] +028C [.rdata at 0x00791118]
		virtual void Function_0164(); // [0164] +0290 [.rdata at 0x0079111C]
		virtual void Function_0165(); // [0165] +0294 [.rdata at 0x00791120]
		virtual void Function_0166(); // [0166] +0298 [.rdata at 0x00791124]
		virtual void Function_0167(); // [0167] +029C [.rdata at 0x00791128]
		virtual void Function_0168(); // [0168] +02A0 [.rdata at 0x0079112C]
		virtual void Function_0169(); // [0169] +02A4 [.rdata at 0x00791130]
		virtual void Function_0170(); // [0170] +02A8 [.rdata at 0x00791134]
		virtual void Function_0171(); // [0171] +02AC [.rdata at 0x00791138]
		virtual void Function_0172(); // [0172] +02B0 [.rdata at 0x0079113C]
		virtual void Function_0173(); // [0173] +02B4 [.rdata at 0x00791140]
		virtual void Function_0174(); // [0174] +02B8 [.rdata at 0x00791144]
		virtual void Function_0175(); // [0175] +02BC [.rdata at 0x00791148]
		virtual void Function_0176(); // [0176] +02C0 [.rdata at 0x0079114C]
		virtual void Function_0177(); // [0177] +02C4 [.rdata at 0x00791150]
		virtual void Function_0178(); // [0178] +02C8 [.rdata at 0x00791154]
		virtual void Function_0179(); // [0179] +02CC [.rdata at 0x00791158]
		virtual void Function_0180(); // [0180] +02D0 [.rdata at 0x0079115C]
		virtual void Function_0181(); // [0181] +02D4 [.rdata at 0x00791160]
		virtual void Function_0182(); // [0182] +02D8 [.rdata at 0x00791164]
		virtual void Function_0183(); // [0183] +02DC [.rdata at 0x00791168]
		virtual void Function_0184(); // [0184] +02E0 [.rdata at 0x0079116C]
		virtual void Function_0185(); // [0185] +02E4 [.rdata at 0x00791170]
		virtual void Function_0186(); // [0186] +02E8 [.rdata at 0x00791174]
		virtual void Function_0187(); // [0187] +02EC [.rdata at 0x00791178]
		virtual void Function_0188(); // [0188] +02F0 [.rdata at 0x0079117C]
		virtual void Function_0189(); // [0189] +02F4 [.rdata at 0x00791180]
		virtual void Function_0190(); // [0190] +02F8 [.rdata at 0x00791184]
		virtual void Function_0191(); // [0191] +02FC [.rdata at 0x00791188]
		virtual void Function_0192(); // [0192] +0300 [.rdata at 0x0079118C]
		virtual void Function_0193(); // [0193] +0304 [.rdata at 0x00791190]
		virtual void Function_0194(); // [0194] +0308 [.rdata at 0x00791194]
		virtual void Function_0195(); // [0195] +030C [.rdata at 0x00791198]
		virtual void Function_0196(); // [0196] +0310 [.rdata at 0x0079119C]
		virtual void Function_0197(); // [0197] +0314 [.rdata at 0x007911A0]
		virtual void Function_0198(); // [0198] +0318 [.rdata at 0x007911A4]
		virtual void Function_0199(); // [0199] +031C [.rdata at 0x007911A8]
		virtual void Function_0200(); // [0200] +0320 [.rdata at 0x007911AC]
		virtual void Function_0201(); // [0201] +0324 [.rdata at 0x007911B0]
		virtual void Function_0202(); // [0202] +0328 [.rdata at 0x007911B4]
		virtual void Function_0203(); // [0203] +032C [.rdata at 0x007911B8]
		virtual void Function_0204(); // [0204] +0330 [.rdata at 0x007911BC]
		virtual void Function_0205(); // [0205] +0334 [.rdata at 0x007911C0]
		virtual void Function_0206(); // [0206] +0338 [.rdata at 0x007911C4]
		virtual void Function_0207(); // [0207] +033C [.rdata at 0x007911C8]
		virtual void Function_0208(); // [0208] +0340 [.rdata at 0x007911CC]
		virtual void Function_0209(); // [0209] +0344 [.rdata at 0x007911D0]
		virtual void Function_0210(); // [0210] +0348 [.rdata at 0x007911D4]
		virtual void Function_0211(); // [0211] +034C [.rdata at 0x007911D8]
		virtual void Function_0212(); // [0212] +0350 [.rdata at 0x007911DC]
		virtual void Function_0213(); // [0213] +0354 [.rdata at 0x007911E0]
		virtual void Function_0214(); // [0214] +0358 [.rdata at 0x007911E4]
		virtual void Function_0215(); // [0215] +035C [.rdata at 0x007911E8]
		virtual void Function_0216(); // [0216] +0360 [.rdata at 0x007911EC]
		virtual void Function_0217(); // [0217] +0364 [.rdata at 0x007911F0]
		virtual void Function_0218(); // [0218] +0368 [.rdata at 0x007911F4]
		virtual void Function_0219(); // [0219] +036C [.rdata at 0x007911F8]
		virtual void Function_0220(); // [0220] +0370 [.rdata at 0x007911FC]
		virtual void Function_0221(); // [0221] +0374 [.rdata at 0x00791200]
		virtual void Function_0222(); // [0222] +0378 [.rdata at 0x00791204]
		virtual void Function_0223(); // [0223] +037C [.rdata at 0x00791208]
		virtual void Function_0224(); // [0224] +0380 [.rdata at 0x0079120C]
		virtual void Function_0225(); // [0225] +0384 [.rdata at 0x00791210]
		virtual void Function_0226(); // [0226] +0388 [.rdata at 0x00791214]
		virtual void Function_0227(); // [0227] +038C [.rdata at 0x00791218]
		virtual ZLnkAction* createAction(ZLnkActionType type); // [0228] +0390 [.rdata at 0x0079121C]
		virtual void Function_0229(); // [0229] +0394 [.rdata at 0x00791220]
		virtual void Function_0230(); // [0230] +0398 [.rdata at 0x00791224]
		virtual void Function_0231(); // [0231] +039C [.rdata at 0x00791228]
		virtual void Function_0232(); // [0232] +03A0 [.rdata at 0x0079122C]
		virtual void Function_0233(); // [0233] +03A4 [.rdata at 0x00791230]
		virtual void Function_0234(); // [0234] +03A8 [.rdata at 0x00791234]
		virtual void Function_0235(); // [0235] +03AC [.rdata at 0x00791238]
		virtual void Function_0236(); // [0236] +03B0 [.rdata at 0x0079123C]
		virtual void Function_0237(); // [0237] +03B4 [.rdata at 0x00791240]
		virtual void Function_0238(); // [0238] +03B8 [.rdata at 0x00791244]
		virtual void Function_0239(); // [0239] +03BC [.rdata at 0x00791248]
		virtual void Function_0240(); // [0240] +03C0 [.rdata at 0x0079124C]
		virtual void Function_0241(); // [0241] +03C4 [.rdata at 0x00791250]
		virtual void Function_0242(); // [0242] +03C8 [.rdata at 0x00791254]
		virtual void Function_0243(); // [0243] +03CC [.rdata at 0x00791258]
		virtual void Function_0244(); // [0244] +03D0 [.rdata at 0x0079125C]
		virtual void Function_0245(); // [0245] +03D4 [.rdata at 0x00791260]
		virtual void Function_0246(); // [0246] +03D8 [.rdata at 0x00791264]
		virtual void Function_0247(); // [0247] +03DC [.rdata at 0x00791268]
		virtual void Function_0248(); // [0248] +03E0 [.rdata at 0x0079126C]
		virtual void Function_0249(); // [0249] +03E4 [.rdata at 0x00791270]
		virtual void Function_0250(); // [0250] +03E8 [.rdata at 0x00791274]
		virtual void Function_0251(); // [0251] +03EC [.rdata at 0x00791278]
		virtual void Function_0252(); // [0252] +03F0 [.rdata at 0x0079127C]
		virtual void Function_0253(); // [0253] +03F4 [.rdata at 0x00791280]
		virtual void Function_0254(); // [0254] +03F8 [.rdata at 0x00791284]
		virtual void Function_0255(); // [0255] +03FC [.rdata at 0x00791288]
		virtual void Function_0256(); // [0256] +0400 [.rdata at 0x0079128C]
		virtual void Function_0257(); // [0257] +0404 [.rdata at 0x00791290]
		virtual void Function_0258(); // [0258] +0408 [.rdata at 0x00791294]
		virtual void Function_0259(); // [0259] +040C [.rdata at 0x00791298]
		virtual void Function_0260(); // [0260] +0410 [.rdata at 0x0079129C]
		virtual void Function_0261(); // [0261] +0414 [.rdata at 0x007912A0]
		virtual void Function_0262(); // [0262] +0418 [.rdata at 0x007912A4]
		virtual void Function_0263(); // [0263] +041C [.rdata at 0x007912A8]
		virtual void Function_0264(); // [0264] +0420 [.rdata at 0x007912AC]
		virtual void Function_0265(); // [0265] +0424 [.rdata at 0x007912B0]
		virtual void Function_0266(); // [0266] +0428 [.rdata at 0x007912B4]
		virtual void Function_0267(); // [0267] +042C [.rdata at 0x007912B8]
		virtual void Function_0268(); // [0268] +0430 [.rdata at 0x007912BC]
		virtual void Function_0269(); // [0269] +0434 [.rdata at 0x007912C0]
		virtual void Function_0270(); // [0270] +0438 [.rdata at 0x007912C4]
		virtual void Function_0271(); // [0271] +043C [.rdata at 0x007912C8]
		virtual void Function_0272(); // [0272] +0440 [.rdata at 0x007912CC]
		virtual void Function_0273(); // [0273] +0444 [.rdata at 0x007912D0]
		virtual void Function_0274(); // [0274] +0448 [.rdata at 0x007912D4]
		virtual void Function_0275(); // [0275] +044C [.rdata at 0x007912D8]
		virtual void Function_0276(); // [0276] +0450 [.rdata at 0x007912DC]
		virtual void Function_0277(); // [0277] +0454 [.rdata at 0x007912E0]
		virtual void Function_0278(); // [0278] +0458 [.rdata at 0x007912E4]
		virtual void Function_0279(); // [0279] +045C [.rdata at 0x007912E8]
		virtual void Function_0280(); // [0280] +0460 [.rdata at 0x007912EC]
		virtual void Function_0281(); // [0281] +0464 [.rdata at 0x007912F0]
		virtual void Function_0282(); // [0282] +0468 [.rdata at 0x007912F4]
		virtual void Function_0283(); // [0283] +046C [.rdata at 0x007912F8]
		virtual void Function_0284(); // [0284] +0470 [.rdata at 0x007912FC]
		virtual void Function_0285(); // [0285] +0474 [.rdata at 0x00791300]
		virtual void Function_0286(); // [0286] +0478 [.rdata at 0x00791304]
		virtual void Function_0287(); // [0287] +047C [.rdata at 0x00791308]
		virtual void Function_0288(); // [0288] +0480 [.rdata at 0x0079130C]
		virtual void Function_0289(); // [0289] +0484 [.rdata at 0x00791310]
		virtual void Function_0290(); // [0290] +0488 [.rdata at 0x00791314]
		virtual void Function_0291(); // [0291] +048C [.rdata at 0x00791318]
		virtual void Function_0292(); // [0292] +0490 [.rdata at 0x0079131C]
		virtual void Function_0293(); // [0293] +0494 [.rdata at 0x00791320]
		virtual void Function_0294(); // [0294] +0498 [.rdata at 0x00791324]
		virtual void Function_0295(); // [0295] +049C [.rdata at 0x00791328]
		virtual void Function_0296(); // [0296] +04A0 [.rdata at 0x0079132C]
		virtual void Function_0297(); // [0297] +04A4 [.rdata at 0x00791330]
		virtual void Function_0298(); // [0298] +04A8 [.rdata at 0x00791334]
		virtual void Function_0299(); // [0299] +04AC [.rdata at 0x00791338]
		virtual void Function_0300(); // [0300] +04B0 [.rdata at 0x0079133C]
		virtual void Function_0301(); // [0301] +04B4 [.rdata at 0x00791340]
		virtual void Function_0302(); // [0302] +04B8 [.rdata at 0x00791344]
		virtual void Function_0303(); // [0303] +04BC [.rdata at 0x00791348]
		virtual void Function_0304(); // [0304] +04C0 [.rdata at 0x0079134C]
		virtual void Function_0305(); // [0305] +04C4 [.rdata at 0x00791350]
		virtual void Function_0306(); // [0306] +04C8 [.rdata at 0x00791354]
		virtual ZHM3Item* getCurrentWeapon(); // [0307] +04CC [.rdata at 0x00791358]
		virtual void Function_0308(); // [0308] +04D0 [.rdata at 0x0079135C]
		virtual void Function_0309(); // [0309] +04D4 [.rdata at 0x00791360]
		virtual void Function_0310(); // [0310] +04D8 [.rdata at 0x00791364]
		virtual void Function_0311(); // [0311] +04DC [.rdata at 0x00791368]
		virtual void Function_0312(); // [0312] +04E0 [.rdata at 0x0079136C]
		virtual void Function_0313(); // [0313] +04E4 [.rdata at 0x00791370]
		virtual void Function_0314(); // [0314] +04E8 [.rdata at 0x00791374]
		virtual void Function_0315(); // [0315] +04EC [.rdata at 0x00791378]
		virtual void Function_0316(); // [0316] +04F0 [.rdata at 0x0079137C]
		virtual void Function_0317(); // [0317] +04F4 [.rdata at 0x00791380]
		virtual void Function_0318(); // [0318] +04F8 [.rdata at 0x00791384]
		virtual void Function_0319(); // [0319] +04FC [.rdata at 0x00791388]
		virtual void Function_0320(); // [0320] +0500 [.rdata at 0x0079138C]
		virtual void Function_0321(); // [0321] +0504 [.rdata at 0x00791390]
		virtual void Function_0322(); // [0322] +0508 [.rdata at 0x00791394]
		virtual void Function_0323(); // [0323] +050C [.rdata at 0x00791398]
		virtual void Function_0324(); // [0324] +0510 [.rdata at 0x0079139C]
		virtual void Function_0325(); // [0325] +0514 [.rdata at 0x007913A0]
		virtual void Function_0326(); // [0326] +0518 [.rdata at 0x007913A4]
		virtual void Function_0327(); // [0327] +051C [.rdata at 0x007913A8]
		virtual void Function_0328(); // [0328] +0520 [.rdata at 0x007913AC]
		virtual void Function_0329(); // [0329] +0524 [.rdata at 0x007913B0]
		virtual void Function_0330(); // [0330] +0528 [.rdata at 0x007913B4]
		virtual void Function_0331(); // [0331] +052C [.rdata at 0x007913B8]
		virtual void Function_0332(); // [0332] +0530 [.rdata at 0x007913BC]
		virtual void Function_0333(); // [0333] +0534 [.rdata at 0x007913C0]
		virtual void Function_0334(); // [0334] +0538 [.rdata at 0x007913C4]
		virtual void Function_0335(); // [0335] +053C [.rdata at 0x007913C8]
		virtual void Function_0336(); // [0336] +0540 [.rdata at 0x007913CC]
		virtual void Function_0337(); // [0337] +0544 [.rdata at 0x007913D0]
		virtual void Function_0338(); // [0338] +0548 [.rdata at 0x007913D4]
		virtual void Function_0339(); // [0339] +054C [.rdata at 0x007913D8]
		virtual void Function_0340(); // [0340] +0550 [.rdata at 0x007913DC]
		virtual void Function_0341(); // [0341] +0554 [.rdata at 0x007913E0]
		virtual void Function_0342(); // [0342] +0558 [.rdata at 0x007913E4]
		virtual void Function_0343(); // [0343] +055C [.rdata at 0x007913E8]
		virtual void Function_0344(); // [0344] +0560 [.rdata at 0x007913EC]
		virtual void Function_0345(); // [0345] +0564 [.rdata at 0x007913F0]
		virtual void Function_0346(); // [0346] +0568 [.rdata at 0x007913F4]
		virtual void Function_0347(); // [0347] +056C [.rdata at 0x007913F8]
		virtual void Function_0348(); // [0348] +0570 [.rdata at 0x007913FC]
		virtual void Function_0349(); // [0349] +0574 [.rdata at 0x00791400]
		virtual void Function_0350(); // [0350] +0578 [.rdata at 0x00791404]
		virtual void Function_0351(); // [0351] +057C [.rdata at 0x00791408]
		virtual void Function_0352(); // [0352] +0580 [.rdata at 0x0079140C]
		virtual void Function_0353(); // [0353] +0584 [.rdata at 0x00791410]
		virtual void Function_0354(); // [0354] +0588 [.rdata at 0x00791414]
		virtual void Function_0355(); // [0355] +058C [.rdata at 0x00791418]
		virtual void Function_0356(); // [0356] +0590 [.rdata at 0x0079141C]
		virtual void Function_0357(); // [0357] +0594 [.rdata at 0x00791420]
		virtual void Function_0358(); // [0358] +0598 [.rdata at 0x00791424]
		virtual void Function_0359(); // [0359] +059C [.rdata at 0x00791428]
		virtual void Function_0360(); // [0360] +05A0 [.rdata at 0x0079142C]
		virtual void Function_0361(); // [0361] +05A4 [.rdata at 0x00791430]
		virtual void Function_0362(); // [0362] +05A8 [.rdata at 0x00791434]
		virtual void Function_0363(); // [0363] +05AC [.rdata at 0x00791438]
		virtual void Function_0364(); // [0364] +05B0 [.rdata at 0x0079143C]
		virtual void Function_0365(); // [0365] +05B4 [.rdata at 0x00791440]
		virtual void Function_0366(); // [0366] +05B8 [.rdata at 0x00791444]
		virtual void Function_0367(); // [0367] +05BC [.rdata at 0x00791448]
		virtual void Function_0368(); // [0368] +05C0 [.rdata at 0x0079144C]
		virtual void Function_0369(); // [0369] +05C4 [.rdata at 0x00791450]
		virtual void Function_0370(); // [0370] +05C8 [.rdata at 0x00791454]
		virtual void Function_0371(); // [0371] +05CC [.rdata at 0x00791458]
		virtual int Function_0372(); // [0372] +05D0 [.rdata at 0x0079145C]
		virtual void Function_0373(); // [0373] +05D4 [.rdata at 0x00791460]
		virtual void Function_0374(); // [0374] +05D8 [.rdata at 0x00791464]
		virtual void Function_0375(); // [0375] +05DC [.rdata at 0x00791468]
		virtual void Function_0376(); // [0376] +05E0 [.rdata at 0x0079146C]
		virtual void Function_0377(); // [0377] +05E4 [.rdata at 0x00791470]
		virtual void Function_0378(); // [0378] +05E8 [.rdata at 0x00791474]
		virtual void Function_0379(); // [0379] +05EC [.rdata at 0x00791478]
		virtual void Function_0380(); // [0380] +05F0 [.rdata at 0x0079147C]
		virtual void Function_0381(); // [0381] +05F4 [.rdata at 0x00791480]
		virtual void Function_0382(); // [0382] +05F8 [.rdata at 0x00791484]
		virtual void Function_0383(); // [0383] +05FC [.rdata at 0x00791488]
		virtual void Function_0384(); // [0384] +0600 [.rdata at 0x0079148C]
		virtual void Function_0385(); // [0385] +0604 [.rdata at 0x00791490]
		virtual void Function_0386(); // [0386] +0608 [.rdata at 0x00791494]
		virtual void Function_0387(); // [0387] +060C [.rdata at 0x00791498]
		virtual void Function_0388(); // [0388] +0610 [.rdata at 0x0079149C]
		virtual void Function_0389(); // [0389] +0614 [.rdata at 0x007914A0]
		virtual void Function_0390(); // [0390] +0618 [.rdata at 0x007914A4]
		virtual void Function_0391(); // [0391] +061C [.rdata at 0x007914A8]
		virtual void Function_0392(); // [0392] +0620 [.rdata at 0x007914AC]
		virtual void Function_0393(); // [0393] +0624 [.rdata at 0x007914B0]
		virtual void Function_0394(); // [0394] +0628 [.rdata at 0x007914B4]
		virtual void Function_0395(); // [0395] +062C [.rdata at 0x007914B8]
		virtual void Function_0396(); // [0396] +0630 [.rdata at 0x007914BC]
		virtual void Function_0397(); // [0397] +0634 [.rdata at 0x007914C0]
		virtual void Function_0398(); // [0398] +0638 [.rdata at 0x007914C4]
		virtual void Function_0399(); // [0399] +063C [.rdata at 0x007914C8]
		virtual void Function_0400(); // [0400] +0640 [.rdata at 0x007914CC]
		virtual void Function_0401(); // [0401] +0644 [.rdata at 0x007914D0]
		virtual void Function_0402(); // [0402] +0648 [.rdata at 0x007914D4]
		virtual void Function_0403(); // [0403] +064C [.rdata at 0x007914D8]
		virtual void Function_0404(int); // [0404] +0650 [.rdata at 0x007914DC]
		virtual int Function_0405(); // [0405] +0654 [.rdata at 0x007914E0]
		virtual void Function_0406(); // [0406] +0658 [.rdata at 0x007914E4]
		virtual void Function_0407(); // [0407] +065C [.rdata at 0x007914E8]
		virtual void Function_0408(); // [0408] +0660 [.rdata at 0x007914EC]
		virtual void Function_0409(); // [0409] +0664 [.rdata at 0x007914F0]
		virtual void Function_0410(); // [0410] +0668 [.rdata at 0x007914F4]
		virtual void Function_0411(); // [0411] +066C [.rdata at 0x007914F8]
		virtual void Function_0412(); // [0412] +0670 [.rdata at 0x007914FC]

		// === members ===
		char pad_0004[376]; //0x0004
		ZLnkActionQueue* m_lnkActionQueue; //0x017C
		char pad_0180[597]; //0x0180
		int m_field3D8; //0x03D8
		int m_field3DC; //0x03DC
		int m_field3E0; //0x03E0
		ZHumanBoid* m_humanBoid0; //0x03E4
		int32_t m_pad0; //+3E8
		int32_t m_pad1; //+3EC
		int32_t m_pad2; //+3F0
		int32_t m_pad3; //+3F4
		Vector3 m_position; //+3F8
		int32_t m_pad7; //+404
		int32_t m_pad8; //+408
		int32_t m_pad9; //+40C
		int32_t m_pad10; //+410
		int32_t m_pad11; //+414
		int32_t m_pad12; //+418
		int32_t m_pad13; //+41C
		int32_t m_pad14; //+420
		int32_t m_pad15; //+424
		int32_t m_pad16; //+428
		int32_t m_pad17; //+42C
		int32_t m_pad18; //+430
		int32_t m_pad19; //+434
		int32_t m_pad20; //+438
		int32_t m_pad21; //+43C
		int32_t m_pad22; //+440
		int32_t m_pad23; //+444
		int32_t m_pad24; //+448
		int32_t m_pad25; //+44C
		int32_t m_pad26; //+450
		int32_t m_pad27; //+454

		ZEntityLocator* m_currentZone; //0x0458
		char pad_045C[268]; //0x045C
		ioi::hm3::ZAnimationInfo* m_currentAnim; //0x0568
		char pad_056C[104]; //0x056C
		uint32_t m_zMovementAnimation; //0x05D4
		uint32_t m_zMovementStand; //0x05D8
		uint32_t m_zMovementPrimaryMove; //0x05DC
		char pad_05E0[4]; //0x05E0
		ZHM3MovementGuideToMatPos* m_zMovementGuide; //0x05E4
		char pad_05E8[4]; //0x05E8
		uint32_t m_zMovementFall; //0x05EC
		uint32_t m_zMovementGuideToMatPos; //0x05F0
		uint32_t m_zMovementHumanShield; //0x05F4
		uint32_t m_zMovementClimbWall; //0x05F8
		uint32_t m_zMovementHugWall; //0x05FC
		uint32_t m_zMovementClimbBox; //0x0600
		uint32_t m_zMovementPassObstacle; //0x0604
		uint32_t m_zMovementPassThroughWindow; //0x0608
		uint32_t m_zMovementScaleWall; //0x060C
		char pad_0610[4]; //0x0610
		uint32_t m_zMovementClimbLadder; //0x0614
		uint32_t m_zMovementClimbDrainPipe; //0x0618
		uint32_t m_zMovementDead; //0x061C
		uint32_t m_zMovementKillTargetAnimLineup; //0x0620
		uint32_t m_zMovementCutSequence; //0x0624
		uint32_t m_zMovementDialog; //0x0628
		uint32_t m_zMovementJumpBalcony; //0x062C
		uint32_t m_zMovementOnTable; //0x0630
		char pad_0634[28]; //0x0634
		uint32_t m_movementGuidesPoolEntry; //0x0650
		uint32_t m_currentMovementGuide; //0x0654
		char pad_0658[340]; //0x0658
		uint32_t m_controlMouse; //0x07AC
		uint32_t m_controlMouseStrafe; //0x07B0
		char pad_07B4[20]; //0x07B4
		uint32_t m_easeInOut; //0x07C8
		char pad_07CC[884]; //0x07CC
		CInventory* m_inventory; //0x0B40
		char pad_0B44[4]; //0x0B44
		uint32_t m_group; //0x0B48
		uint32_t m_timeMultEffectControl; //0x0B4C
		ZHM3Camera* m_camera; //0x0B50
		char pad_0B54[8]; //0x0B54
		uint32_t m_zMovementGuideToMatPos2; //0x0B5C
		char pad_0B60[996]; //0x0B60
		uint32_t m_animationsArray5; //0x0F44
		char pad_0F48[28]; //0x0F48
		uint32_t m_bloodTrails; //0x0F64
		char pad_0F68[104]; //0x0F68
		ZHM3HmAs* m_HmAs_0; //0x0FD0
		ZHM3HmAs* m_HmAs; //0x0FD4
		int32_t m_fieldFD8; //0x0FD8
		int32_t m_fieldFDC; //0x0FDC
		int32_t m_fieldFE0; //0x0FE0
		int32_t m_fieldFE4; //0x0FE4
		int32_t m_fieldFE8; //0x0FE8
		int32_t m_fieldFEC; //0x0FEC
		int32_t m_fieldFF0; //0x0FF0
		int32_t m_fieldFF4; //0x0FF4
		int32_t m_fieldFF8; //0x0FF8
		int32_t m_fieldFFC; //0x0FFC
		int32_t m_field1000; //0x1000
		int32_t m_field1004; //0x1004
		int32_t m_field1008; //0x1008
		int32_t m_field100C; //0x100C
		uint32_t m_field1010; //0x1010
		float m_unkFloatAt1014; //0x1014
		int32_t m_field1018; //0x1018
		int32_t m_field101C; //0x101C
		int32_t m_field1020; //0x1020
		int32_t m_field1024; //0x1024
		int8_t m_field1028; //0x1028
		int8_t m_field1029; //0x1029
		int8_t m_field102A; //0x102A
		int8_t m_field102B; //0x102B
		bool m_bChangingClothes; //0x102C
		bool m_bChangingClothesAllowed; //0x102D
		bool m_bSneaking; //0x102E
		bool m_bStrangulating; //0x102F
		bool m_bInjecting; //0x1030
		bool m_bPunching; //0x1031
		bool m_bPushing; //0x1032
		bool m_bClimbingHatch; //0x1033
		float m_fInjectingTime; //0x1034
		bool m_bLockPicking; //0x1038
		int8_t m_field1039; //0x1039
		int8_t m_field103A; //0x103A
		int8_t m_field103B; //0x103B
		bool m_bNightVisionEnabled; //0x103C { controlled by +3D8 & 19, when true - game crashing }
		bool m_bBinocularsEnabled; //0x103D
		bool m_bFacingEnabled; //0x103E
		bool m_bIsInMotion; //0x103F
		bool m_bIsWalking; //0x1040
		bool m_bIsRunning; //0x1041
		bool m_bIsCrouching; //0x1042
		bool m_bIsSneaking; //0x1043
		bool m_bIsCrouchSneaking; //0x1044
		bool m_bIsOnLadder; //0x1045
		bool m_bIsOnDrainPipe; //0x1046
		bool m_bIsOnGuide; //0x1047
		bool m_bForceCrouch; //0x1048
		bool m_bDragPosForced; //0x1049
		int8_t m_field104A; //0x104A
		int8_t m_field104B; //0x104B
		char pad_104C[136]; //0x104C
		int32_t m_nearestActorsPoolCapacity; //0x10D4
		uint32_t m_nearestActorsPoolFirstEntity; //0x10D8
		char pad_10DC[500]; //0x10DC
		ZROOM* m_room; //0x12D0
		int32_t m_eRoomZone; //0x12D4
		int32_t m_eCustomZone; //0x12D8
		int32_t m_field12DC; //0x12DC
		int32_t m_field12E0; //0x12E0
		int32_t m_field12E4; //0x12E4
		ZBoxPrimitive* m_zoneControlBoxPrimitive; //0x12E8
		char pad_12EC[20]; //0x12EC
		ZAnimationInfo* m_animCurrent; //0x1300
		char pad_1304[136]; //0x1304
		uint32_t m_RailInfo_pRailGeom; //0x138C
		Vector3 m_RailInfo_vP1; //0x1390
		Vector3 m_RailInfo_vP2; //0x139C
		Vector3 m_RailInfo_vP3; //0x13A8
		Vector3 m_RailInfo_vColiPt; //0x13B4
		char pad_13C0[140]; //0x13C0
		int32_t		m_availableItemsCount; //0x144C
		ZHM3Item*	m_availableItemsPoolBegin[10]; //0x1450

		/// === custom api ===
		const NearActorRef& getNearActorByTheirIndex(int32_t index);
		ZIKHAND* getHand(HandType type);
	}; //Size: 0x1478


}}