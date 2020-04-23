#pragma once

#include <cstdint>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZCHAROBJ.h>
#include <sdk/ZWINDOW.h>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	class ZCheatMenu : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZWINDOW* m_window; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[20]; //0x0030
		ZCHAROBJ* m_textField0; //0x0044
		char pad_0048[20]; //0x0048
		REFTAB m_reftab; //0x005C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079e9e8
		virtual void Function_0001(); //#1 +4 .rdata:0079e9ec
		virtual void Function_0002(); //#2 +8 .rdata:0079e9f0
		virtual void Function_0003(); //#3 +c .rdata:0079e9f4
		virtual void Function_0004(); //#4 +10 .rdata:0079e9f8
		virtual void Function_0005(); //#5 +14 .rdata:0079e9fc
		virtual void Function_0006(); //#6 +18 .rdata:0079ea00
		virtual void Function_0007(); //#7 +1c .rdata:0079ea04
		virtual void Function_0008(); //#8 +20 .rdata:0079ea08
		virtual void Function_0009(); //#9 +24 .rdata:0079ea0c
		virtual void Function_0010(); //#10 +28 .rdata:0079ea10
		virtual void Function_0011(); //#11 +2c .rdata:0079ea14
		virtual void Function_0012(); //#12 +30 .rdata:0079ea18
		virtual void Function_0013(); //#13 +34 .rdata:0079ea1c
		virtual void Function_0014(); //#14 +38 .rdata:0079ea20
		virtual void Function_0015(); //#15 +3c .rdata:0079ea24
		virtual void Function_0016(); //#16 +40 .rdata:0079ea28
		virtual void Function_0017(); //#17 +44 .rdata:0079ea2c
		virtual void Function_0018(); //#18 +48 .rdata:0079ea30
		virtual void Function_0019(); //#19 +4c .rdata:0079ea34
		virtual void Function_0020(); //#20 +50 .rdata:0079ea38
		virtual void Function_0021(); //#21 +54 .rdata:0079ea3c
		virtual void Function_0022(); //#22 +58 .rdata:0079ea40
		virtual void Function_0023(); //#23 +5c .rdata:0079ea44
		virtual void Function_0024(); //#24 +60 .rdata:0079ea48
		virtual void Function_0025(); //#25 +64 .rdata:0079ea4c
		virtual void Function_0026(); //#26 +68 .rdata:0079ea50
		virtual void Function_0027(); //#27 +6c .rdata:0079ea54
		virtual void Function_0028(); //#28 +70 .rdata:0079ea58
		virtual void Function_0029(); //#29 +74 .rdata:0079ea5c
		virtual void Function_0030(); //#30 +78 .rdata:0079ea60
		virtual void Function_0031(); //#31 +7c .rdata:0079ea64
		virtual void Function_0032(); //#32 +80 .rdata:0079ea68
		virtual void Function_0033(); //#33 +84 .rdata:0079ea6c
		virtual void Function_0034(); //#34 +88 .rdata:0079ea70
		virtual void Function_0035(); //#35 +8c .rdata:0079ea74
		virtual void Function_0036(); //#36 +90 .rdata:0079ea78
		virtual void Function_0037(); //#37 +94 .rdata:0079ea7c
		virtual void Function_0038(); //#38 +98 .rdata:0079ea80
		virtual void Function_0039(); //#39 +9c .rdata:0079ea84
		virtual void Function_0040(); //#40 +a0 .rdata:0079ea88
		virtual void Function_0041(); //#41 +a4 .rdata:0079ea8c
		virtual void Function_0042(); //#42 +a8 .rdata:0079ea90
		virtual void Function_0043(); //#43 +ac .rdata:0079ea94
		virtual void Function_0044(); //#44 +b0 .rdata:0079ea98
		virtual void Function_0045(); //#45 +b4 .rdata:0079ea9c
		virtual void Function_0046(); //#46 +b8 .rdata:0079eaa0
		virtual void Function_0047(); //#47 +bc .rdata:0079eaa4
		virtual void Function_0048(); //#48 +c0 .rdata:0079eaa8
	}; //Size: 0x0080

} }