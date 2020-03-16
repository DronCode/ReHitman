#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>
#include <sdk/ZHM3BriefingControl.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class ZHM3LevelControl
	{
	public:
		char pad_0004[32]; //0x0004
		uint32_t m_startPoint; //0x0024
		char pad_0028[124]; //0x0028

		virtual void Function_0000(); //#0 +0 .rdata:007ac9b4
		virtual void Function_0001(); //#1 +4 .rdata:007ac9b8
		virtual void Function_0002(); //#2 +8 .rdata:007ac9bc
		virtual void Function_0003(); //#3 +c .rdata:007ac9c0
		virtual void Function_0004(); //#4 +10 .rdata:007ac9c4
		virtual void Function_0005(); //#5 +14 .rdata:007ac9c8
		virtual void Function_0006(); //#6 +18 .rdata:007ac9cc
		virtual void Function_0007(); //#7 +1c .rdata:007ac9d0
		virtual void Function_0008(); //#8 +20 .rdata:007ac9d4
		virtual void Function_0009(); //#9 +24 .rdata:007ac9d8
		virtual void Function_0010(); //#10 +28 .rdata:007ac9dc
		virtual void Function_0011(); //#11 +2c .rdata:007ac9e0
		virtual void Function_0012(); //#12 +30 .rdata:007ac9e4
		virtual void Function_0013(); //#13 +34 .rdata:007ac9e8
		virtual void Function_0014(); //#14 +38 .rdata:007ac9ec
		virtual void Function_0015(); //#15 +3c .rdata:007ac9f0
		virtual void Function_0016(); //#16 +40 .rdata:007ac9f4
		virtual void Function_0017(); //#17 +44 .rdata:007ac9f8
		virtual void Function_0018(); //#18 +48 .rdata:007ac9fc
		virtual const char* getTypeName(); //#19 +4c .rdata:007aca00
		virtual void Function_0020(); //#20 +50 .rdata:007aca04
		virtual void Function_0021(); //#21 +54 .rdata:007aca08
		virtual void Function_0022(); //#22 +58 .rdata:007aca0c
		virtual void Function_0023(); //#23 +5c .rdata:007aca10
		virtual void Function_0024(); //#24 +60 .rdata:007aca14
		virtual void Function_0025(); //#25 +64 .rdata:007aca18
		virtual void Function_0026(); //#26 +68 .rdata:007aca1c
		virtual void Function_0027(); //#27 +6c .rdata:007aca20
		virtual void Function_0028(); //#28 +70 .rdata:007aca24
		virtual void Function_0029(); //#29 +74 .rdata:007aca28
		virtual void Function_0030(); //#30 +78 .rdata:007aca2c
		virtual void Function_0031(); //#31 +7c .rdata:007aca30
		virtual void Function_0032(); //#32 +80 .rdata:007aca34
		virtual void Function_0033(); //#33 +84 .rdata:007aca38
		virtual void Function_0034(); //#34 +88 .rdata:007aca3c
		virtual void Function_0035(); //#35 +8c .rdata:007aca40
		virtual void Function_0036(); //#36 +90 .rdata:007aca44
		virtual void Function_0037(); //#37 +94 .rdata:007aca48
		virtual void Function_0038(); //#38 +98 .rdata:007aca4c
		virtual void Function_0039(); //#39 +9c .rdata:007aca50
		virtual void Function_0040(); //#40 +a0 .rdata:007aca54
		virtual void Function_0041(); //#41 +a4 .rdata:007aca58
		virtual void Function_0042(); //#42 +a8 .rdata:007aca5c
		virtual void Function_0043(); //#43 +ac .rdata:007aca60
		virtual void Function_0044(); //#44 +b0 .rdata:007aca64
		virtual void Function_0045(); //#45 +b4 .rdata:007aca68
		virtual void Function_0046(); //#46 +b8 .rdata:007aca6c
		virtual void Function_0047(); //#47 +bc .rdata:007aca70
		virtual void Function_0048(); //#48 +c0 .rdata:007aca74
		virtual void Function_0049(); //#49 +c4 .rdata:007aca78
		virtual void Function_0050(); //#50 +c8 .rdata:007aca7c
		virtual void Function_0051(); //#51 +cc .rdata:007aca80
		virtual void Function_0052(); //#52 +d0 .rdata:007aca84
		virtual void Function_0053(); //#53 +d4 .rdata:007aca88
		virtual void Function_0054(); //#54 +d8 .rdata:007aca8c
		virtual void Function_0055(); //#55 +dc .rdata:007aca90
		virtual void Function_0056(); //#56 +e0 .rdata:007aca94
		virtual void Function_0057(); //#57 +e4 .rdata:007aca98
		virtual void Function_0058(); //#58 +e8 .rdata:007aca9c
		virtual void Function_0059(); //#59 +ec .rdata:007acaa0
		virtual void failMissionWithMessage(const char* dialogName); //#60 +f0 .rdata:007acaa4
		virtual void Function_0061(); //#61 +f4 .rdata:007acaa8
		virtual void Function_0062(); //#62 +f8 .rdata:007acaac
		virtual void completeLevelRequest(); //#63 +fc .rdata:007acab0
		virtual void Function_0064(); //#64 +100 .rdata:007acab4
		virtual void Function_0065(); //#65 +104 .rdata:007acab8
		virtual ZHM3BriefingControl* getBriefingControl(int a2); //#66 +108 .rdata:007acabc
		virtual void Function_0067(); //#67 +10c .rdata:007acac0
		virtual void Function_0068(); //#68 +110 .rdata:007acac4
		virtual void Function_0069(); //#69 +114 .rdata:007acac8
		virtual void Function_0070(); //#70 +118 .rdata:007acacc
		virtual void Function_0071(); //#71 +11c .rdata:007acad0
		virtual void sendEvent(std::uintptr_t evId, int unk1, int unk2); //#72 +120 .rdata:007acad4
		virtual void Function_0073(); //#73 +124 .rdata:007acad8
		virtual void sendEventWithSTDOBJ(ZSTDOBJ* stdObj, std::intptr_t ev, int* pResult); //#74 +128 .rdata:007acadc
		virtual void Function_0075(); //#75 +12c .rdata:007acae0
		virtual void Function_0076(); //#76 +130 .rdata:007acae4
		virtual void Function_0077(); //#77 +134 .rdata:007acae8
		virtual void Function_0078(); //#78 +138 .rdata:007acaec
		virtual void Function_0079(); //#79 +13c .rdata:007acaf0
		virtual void Function_0080(); //#80 +140 .rdata:007acaf4
		virtual void Function_0081(); //#81 +144 .rdata:007acaf8
		virtual void Function_0082(); //#82 +148 .rdata:007acafc
		virtual void Function_0083(); //#83 +14c .rdata:007acb00
		virtual void Function_0084(); //#84 +150 .rdata:007acb04
		virtual void Function_0085(); //#85 +154 .rdata:007acb08
		virtual void Function_0086(); //#86 +158 .rdata:007acb0c
		virtual void Function_0087(); //#87 +15c .rdata:007acb10
		virtual void Function_0088(); //#88 +160 .rdata:007acb14
		virtual void Function_0089(); //#89 +164 .rdata:007acb18
		virtual void Function_0090(); //#90 +168 .rdata:007acb1c
		virtual void Function_0091(); //#91 +16c .rdata:007acb20
		virtual void Function_0092(); //#92 +170 .rdata:007acb24
		virtual void Function_0093(); //#93 +174 .rdata:007acb28
		virtual void Function_0094(); //#94 +178 .rdata:007acb2c
		virtual void Function_0095(); //#95 +17c .rdata:007acb30
		virtual void Function_0096(); //#96 +180 .rdata:007acb34
		virtual void Function_0097(); //#97 +184 .rdata:007acb38
		virtual void Function_0098(); //#98 +188 .rdata:007acb3c
		virtual void Function_0099(); //#99 +18c .rdata:007acb40
		virtual void Function_0100(); //#100 +190 .rdata:007acb44
	};

}}