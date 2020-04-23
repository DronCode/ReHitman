#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZWeaponStorage : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_STDOBJ; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[64]; //0x0030
		int32_t m_itemsCount; //0x0070
		ZHM3Item* m_items[28]; //0x0074
		char pad_00E4[12]; //0x00E4

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079dcc4
		virtual void Function_0001(); //#1 +4 .rdata:0079dcc8
		virtual void Function_0002(); //#2 +8 .rdata:0079dccc
		virtual void Function_0003(); //#3 +c .rdata:0079dcd0
		virtual void Function_0004(); //#4 +10 .rdata:0079dcd4
		virtual void Function_0005(); //#5 +14 .rdata:0079dcd8
		virtual void Function_0006(); //#6 +18 .rdata:0079dcdc
		virtual void Function_0007(); //#7 +1c .rdata:0079dce0
		virtual void Function_0008(); //#8 +20 .rdata:0079dce4
		virtual void Function_0009(); //#9 +24 .rdata:0079dce8
		virtual void Function_0010(); //#10 +28 .rdata:0079dcec
		virtual void Function_0011(); //#11 +2c .rdata:0079dcf0
		virtual void Function_0012(); //#12 +30 .rdata:0079dcf4
		virtual void Function_0013(); //#13 +34 .rdata:0079dcf8
		virtual void Function_0014(); //#14 +38 .rdata:0079dcfc
		virtual void Function_0015(); //#15 +3c .rdata:0079dd00
		virtual void Function_0016(); //#16 +40 .rdata:0079dd04
		virtual void Function_0017(); //#17 +44 .rdata:0079dd08
		virtual void Function_0018(); //#18 +48 .rdata:0079dd0c
		virtual void Function_0019(); //#19 +4c .rdata:0079dd10
		virtual void Function_0020(); //#20 +50 .rdata:0079dd14
		virtual void Function_0021(); //#21 +54 .rdata:0079dd18
		virtual void Function_0022(); //#22 +58 .rdata:0079dd1c
		virtual void Function_0023(); //#23 +5c .rdata:0079dd20
		virtual void Function_0024(); //#24 +60 .rdata:0079dd24
		virtual void Function_0025(); //#25 +64 .rdata:0079dd28
		virtual void Function_0026(); //#26 +68 .rdata:0079dd2c
		virtual void Function_0027(); //#27 +6c .rdata:0079dd30
		virtual void Function_0028(); //#28 +70 .rdata:0079dd34
		virtual void Function_0029(); //#29 +74 .rdata:0079dd38
		virtual void Function_0030(); //#30 +78 .rdata:0079dd3c
		virtual void Function_0031(); //#31 +7c .rdata:0079dd40
		virtual void Function_0032(); //#32 +80 .rdata:0079dd44
		virtual void Function_0033(); //#33 +84 .rdata:0079dd48
		virtual void Function_0034(); //#34 +88 .rdata:0079dd4c
		virtual void Function_0035(); //#35 +8c .rdata:0079dd50
	}; //Size: 0x00F0

} }