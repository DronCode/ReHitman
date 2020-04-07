#pragma once

#include <cstdint>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZWINDOWS.h>
#include <sdk/ZWINDOW.h>
#include <sdk/ZGROUP.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class ZXMLGUISystem : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZWINDOW* m_window; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		int m_unkInt0; //0x0030
		ZGROUP* m_windowGroups[18]; //0x0034

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00781244
		virtual void Function_0001(); //#1 +4 .rdata:00781248
		virtual void Function_0002(); //#2 +8 .rdata:0078124c
		virtual void Function_0003(); //#3 +c .rdata:00781250
		virtual void Function_0004(); //#4 +10 .rdata:00781254
		virtual void Function_0005(); //#5 +14 .rdata:00781258
		virtual void Function_0006(); //#6 +18 .rdata:0078125c
		virtual void Function_0007(); //#7 +1c .rdata:00781260
		virtual void Function_0008(); //#8 +20 .rdata:00781264
		virtual void Function_0009(); //#9 +24 .rdata:00781268
		virtual void Function_0010(); //#10 +28 .rdata:0078126c
		virtual void Function_0011(); //#11 +2c .rdata:00781270
		virtual void Function_0012(); //#12 +30 .rdata:00781274
		virtual void Function_0013(); //#13 +34 .rdata:00781278
		virtual void Function_0014(); //#14 +38 .rdata:0078127c
		virtual void Function_0015(); //#15 +3c .rdata:00781280
		virtual void Function_0016(); //#16 +40 .rdata:00781284
		virtual void Function_0017(); //#17 +44 .rdata:00781288
		virtual void Function_0018(); //#18 +48 .rdata:0078128c
		virtual void Function_0019(); //#19 +4c .rdata:00781290
		virtual void Function_0020(); //#20 +50 .rdata:00781294
		virtual void Function_0021(); //#21 +54 .rdata:00781298
		virtual void Function_0022(); //#22 +58 .rdata:0078129c
		virtual void Function_0023(); //#23 +5c .rdata:007812a0
		virtual void Function_0024(); //#24 +60 .rdata:007812a4
		virtual void Function_0025(); //#25 +64 .rdata:007812a8
		virtual void Function_0026(); //#26 +68 .rdata:007812ac
		virtual void Function_0027(); //#27 +6c .rdata:007812b0
		virtual void Function_0028(); //#28 +70 .rdata:007812b4
		virtual void Function_0029(); //#29 +74 .rdata:007812b8
		virtual void Function_0030(); //#30 +78 .rdata:007812bc
		virtual void Function_0031(); //#31 +7c .rdata:007812c0
		virtual void Function_0032(); //#32 +80 .rdata:007812c4
		virtual void Function_0033(); //#33 +84 .rdata:007812c8
		virtual void Function_0034(); //#34 +88 .rdata:007812cc
		virtual void Function_0035(); //#35 +8c .rdata:007812d0
		virtual ZWINDOWS* getZWindowsSubsystem(); //#36 +90 .rdata:007812d4
		virtual void Function_0037(); //#37 +94 .rdata:007812d8
		virtual void Function_0038(); //#38 +98 .rdata:007812dc
		virtual void Function_0039(); //#39 +9c .rdata:007812e0
		virtual void Function_0040(); //#40 +a0 .rdata:007812e4
		virtual void Function_0041(); //#41 +a4 .rdata:007812e8
		virtual void Function_0042(); //#42 +a8 .rdata:007812ec
		virtual void Function_0043(); //#43 +ac .rdata:007812f0
		virtual void Function_0044(); //#44 +b0 .rdata:007812f4
		virtual void Function_0045(); //#45 +b4 .rdata:007812f8
		virtual void Function_0046(); //#46 +b8 .rdata:007812fc
		virtual void Function_0047(); //#47 +bc .rdata:00781300
		virtual void Function_0048(); //#48 +c0 .rdata:00781304
		virtual void Function_0049(); //#49 +c4 .rdata:00781308
		virtual int Function_0050(); //#50 +c8 .rdata:0078130c
		virtual void Function_0051(); //#51 +cc .rdata:00781310 
	};

} }