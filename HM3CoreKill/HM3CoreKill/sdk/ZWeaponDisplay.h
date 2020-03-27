#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZCHAROBJ.h>
#include <sdk/ZWINDOW.h>

namespace ioi { namespace hm3 {

	class ZWeaponDisplay : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZWINDOW* m_window; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		ZCHAROBJ* m_textField0; //0x0030
		ZCHAROBJ* m_textField1; //0x0034
		char pad_0038[84]; //0x0038
		ZCHAROBJ* m_textField2; //0x008C
		ZCHAROBJ* m_textField3; //0x0090
		uint32_t m_WINPIC; //0x0094
		char pad_0098[24]; //0x0098

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007a166c
		virtual void Function_0001(); //#1 +4 .rdata:007a1670
		virtual void Function_0002(); //#2 +8 .rdata:007a1674
		virtual void Function_0003(); //#3 +c .rdata:007a1678
		virtual void Function_0004(); //#4 +10 .rdata:007a167c
		virtual void Function_0005(); //#5 +14 .rdata:007a1680
		virtual void Function_0006(); //#6 +18 .rdata:007a1684
		virtual void Function_0007(); //#7 +1c .rdata:007a1688
		virtual void Function_0008(); //#8 +20 .rdata:007a168c
		virtual void Function_0009(); //#9 +24 .rdata:007a1690
		virtual void Function_0010(); //#10 +28 .rdata:007a1694
		virtual void Function_0011(); //#11 +2c .rdata:007a1698
		virtual void Function_0012(); //#12 +30 .rdata:007a169c
		virtual void Function_0013(); //#13 +34 .rdata:007a16a0
		virtual void Function_0014(); //#14 +38 .rdata:007a16a4
		virtual void Function_0015(); //#15 +3c .rdata:007a16a8
		virtual void Function_0016(); //#16 +40 .rdata:007a16ac
		virtual void Function_0017(); //#17 +44 .rdata:007a16b0
		virtual void Function_0018(); //#18 +48 .rdata:007a16b4
		virtual void Function_0019(); //#19 +4c .rdata:007a16b8
		virtual void Function_0020(); //#20 +50 .rdata:007a16bc
		virtual void Function_0021(); //#21 +54 .rdata:007a16c0
		virtual void Function_0022(); //#22 +58 .rdata:007a16c4
		virtual void Function_0023(); //#23 +5c .rdata:007a16c8
		virtual void Function_0024(); //#24 +60 .rdata:007a16cc
		virtual void Function_0025(); //#25 +64 .rdata:007a16d0
		virtual void Function_0026(); //#26 +68 .rdata:007a16d4
		virtual void Function_0027(); //#27 +6c .rdata:007a16d8
		virtual void Function_0028(); //#28 +70 .rdata:007a16dc
		virtual void Function_0029(); //#29 +74 .rdata:007a16e0
		virtual void Function_0030(); //#30 +78 .rdata:007a16e4
		virtual void Function_0031(); //#31 +7c .rdata:007a16e8
		virtual void Function_0032(); //#32 +80 .rdata:007a16ec
		virtual void Function_0033(); //#33 +84 .rdata:007a16f0
		virtual void Function_0034(); //#34 +88 .rdata:007a16f4
		virtual void Function_0035(); //#35 +8c .rdata:007a16f8
		virtual void Function_0036(); //#36 +90 .rdata:007a16fc
		virtual void Function_0037(); //#37 +94 .rdata:007a1700
		virtual void Function_0038(); //#38 +98 .rdata:007a1704
		virtual void Function_0039(); //#39 +9c .rdata:007a1708
		virtual void Function_0040(); //#40 +a0 .rdata:007a170c
		virtual void Function_0041(); //#41 +a4 .rdata:007a1710
		virtual void Function_0042(); //#42 +a8 .rdata:007a1714
		virtual void Function_0043(); //#43 +ac .rdata:007a1718
		virtual void Function_0044(); //#44 +b0 .rdata:007a171c
		virtual void Function_0045(); //#45 +b4 .rdata:007a1720
		virtual void Function_0046(); //#46 +b8 .rdata:007a1724
		virtual void Function_0047(); //#47 +bc .rdata:007a1728
		virtual void Function_0048(); //#48 +c0 .rdata:007a172c
		virtual void Function_0049(); //#49 +c4 .rdata:007a1730
		virtual void Function_0050(); //#50 +c8 .rdata:007a1734
		virtual void Function_0051(); //#51 +cc .rdata:007a1738
		virtual void Function_0052(); //#52 +d0 .rdata:007a173c
	};

} }