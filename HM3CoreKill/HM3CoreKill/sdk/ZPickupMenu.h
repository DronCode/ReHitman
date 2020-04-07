#pragma once

#include <cstdint>
#include <sdk/ZWINDOW.h>
#include <sdk/MathCommon.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZAction.h>

namespace ioi { namespace hm3 {

	class ZPickupMenu : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZWINDOW* m_window; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		std::uintptr_t* m_winObjPool[6]; //0x0030
		int32_t m_unk0; //0x0048
		char pad_004C[20]; //0x004C
		int32_t m_availableActionsCount; //0x0060
		uint32_t m_lineObj_0; //0x0064
		uint32_t m_lineObj_1; //0x0068
		char pad_006C[4]; //0x006C
		Vector2 m_unkVec2F; //0x0070
		char pad_0078[4]; //0x0078
		ZAction* m_rootAction; //0x007C
		int32_t m_unkInt; //0x0080
		char pad_0084[72]; //0x0084

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007a12d4
		virtual void Function_0001(); //#1 +4 .rdata:007a12d8
		virtual void Function_0002(); //#2 +8 .rdata:007a12dc
		virtual void Function_0003(); //#3 +c .rdata:007a12e0
		virtual void Function_0004(); //#4 +10 .rdata:007a12e4
		virtual void Function_0005(); //#5 +14 .rdata:007a12e8
		virtual void Function_0006(); //#6 +18 .rdata:007a12ec
		virtual void Function_0007(); //#7 +1c .rdata:007a12f0
		virtual void Function_0008(); //#8 +20 .rdata:007a12f4
		virtual void Function_0009(); //#9 +24 .rdata:007a12f8
		virtual void Function_0010(); //#10 +28 .rdata:007a12fc
		virtual void Function_0011(); //#11 +2c .rdata:007a1300
		virtual void Function_0012(); //#12 +30 .rdata:007a1304
		virtual void Function_0013(); //#13 +34 .rdata:007a1308
		virtual void Function_0014(); //#14 +38 .rdata:007a130c
		virtual void Function_0015(); //#15 +3c .rdata:007a1310
		virtual void Function_0016(); //#16 +40 .rdata:007a1314
		virtual void Function_0017(); //#17 +44 .rdata:007a1318
		virtual void Function_0018(); //#18 +48 .rdata:007a131c
		virtual void Function_0019(); //#19 +4c .rdata:007a1320
		virtual void Function_0020(); //#20 +50 .rdata:007a1324
		virtual void Function_0021(); //#21 +54 .rdata:007a1328
		virtual void Function_0022(); //#22 +58 .rdata:007a132c
		virtual void Function_0023(); //#23 +5c .rdata:007a1330
		virtual void Function_0024(); //#24 +60 .rdata:007a1334
		virtual void Function_0025(); //#25 +64 .rdata:007a1338
		virtual void Function_0026(); //#26 +68 .rdata:007a133c
		virtual void Function_0027(); //#27 +6c .rdata:007a1340
		virtual void Function_0028(); //#28 +70 .rdata:007a1344
		virtual void Function_0029(); //#29 +74 .rdata:007a1348
		virtual void Function_0030(); //#30 +78 .rdata:007a134c
		virtual void Function_0031(); //#31 +7c .rdata:007a1350
		virtual void Function_0032(); //#32 +80 .rdata:007a1354
		virtual void Function_0033(); //#33 +84 .rdata:007a1358
		virtual void Function_0034(); //#34 +88 .rdata:007a135c
		virtual void Function_0035(); //#35 +8c .rdata:007a1360
		virtual void Function_0036(); //#36 +90 .rdata:007a1364
		virtual void Function_0037(); //#37 +94 .rdata:007a1368
		virtual void Function_0038(); //#38 +98 .rdata:007a136c
		virtual void Function_0039(); //#39 +9c .rdata:007a1370
		virtual void Function_0040(); //#40 +a0 .rdata:007a1374
		virtual void Function_0041(); //#41 +a4 .rdata:007a1378
		virtual void Function_0042(); //#42 +a8 .rdata:007a137c
		virtual void Function_0043(); //#43 +ac .rdata:007a1380
		virtual void Function_0044(); //#44 +b0 .rdata:007a1384
		virtual void Function_0045(); //#45 +b4 .rdata:007a1388
		virtual void Function_0046(); //#46 +b8 .rdata:007a138c
		virtual void Function_0047(); //#47 +bc .rdata:007a1390
		virtual void Function_0048(); //#48 +c0 .rdata:007a1394
		virtual void Function_0049(); //#49 +c4 .rdata:007a1398
		virtual void Function_0050(); //#50 +c8 .rdata:007a139c
		virtual void Function_0051(); //#51 +cc .rdata:007a13a0
		virtual void Function_0052(); //#52 +d0 .rdata:007a13a4
		virtual int getAvailableActionsCount(); //#53 +d4 .rdata:007a13a8
		virtual void Function_0054(); //#54 +d8 .rdata:007a13ac
	}; //Size: 0x00CC

}}