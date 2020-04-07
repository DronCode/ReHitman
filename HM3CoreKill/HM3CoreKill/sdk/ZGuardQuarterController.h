#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/REFTAB32.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZWeaponStorage.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZGuardQuarterController : public ZLinkedListNodeBase 
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_STDOBJ; //0x0024
		char pad_0028[4]; //0x0028
		uint32_t m_RTTI; //0x002C
		REFTAB32 m_REFTAB32; //0x0030
		int32_t m_STDOBJID; //0x00E0
		ZWeaponStorage* m_weaponStorage; //0x00E4
		char pad_00E8[8]; //0x00E8

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079dd8c
		virtual void Function_0001(); //#1 +4 .rdata:0079dd90
		virtual void Function_0002(); //#2 +8 .rdata:0079dd94
		virtual void Function_0003(); //#3 +c .rdata:0079dd98
		virtual void Function_0004(); //#4 +10 .rdata:0079dd9c
		virtual void Function_0005(); //#5 +14 .rdata:0079dda0
		virtual void Function_0006(); //#6 +18 .rdata:0079dda4
		virtual void Function_0007(); //#7 +1c .rdata:0079dda8
		virtual void Function_0008(); //#8 +20 .rdata:0079ddac
		virtual void Function_0009(); //#9 +24 .rdata:0079ddb0
		virtual void Function_0010(); //#10 +28 .rdata:0079ddb4
		virtual void Function_0011(); //#11 +2c .rdata:0079ddb8
		virtual void Function_0012(); //#12 +30 .rdata:0079ddbc
		virtual void Function_0013(); //#13 +34 .rdata:0079ddc0
		virtual void Function_0014(); //#14 +38 .rdata:0079ddc4
		virtual void Function_0015(); //#15 +3c .rdata:0079ddc8
		virtual void Function_0016(); //#16 +40 .rdata:0079ddcc
		virtual void Function_0017(); //#17 +44 .rdata:0079ddd0
		virtual void Function_0018(); //#18 +48 .rdata:0079ddd4
		virtual void Function_0019(); //#19 +4c .rdata:0079ddd8
		virtual void Function_0020(); //#20 +50 .rdata:0079dddc
		virtual void Function_0021(); //#21 +54 .rdata:0079dde0
		virtual void Function_0022(); //#22 +58 .rdata:0079dde4
		virtual void Function_0023(); //#23 +5c .rdata:0079dde8
		virtual void Function_0024(); //#24 +60 .rdata:0079ddec
		virtual void Function_0025(); //#25 +64 .rdata:0079ddf0
		virtual void Function_0026(); //#26 +68 .rdata:0079ddf4
		virtual void Function_0027(); //#27 +6c .rdata:0079ddf8
		virtual void Function_0028(); //#28 +70 .rdata:0079ddfc
		virtual void Function_0029(); //#29 +74 .rdata:0079de00
		virtual void Function_0030(); //#30 +78 .rdata:0079de04
		virtual void Function_0031(); //#31 +7c .rdata:0079de08
		virtual void Function_0032(); //#32 +80 .rdata:0079de0c
		virtual void Function_0033(); //#33 +84 .rdata:0079de10
		virtual void Function_0034(); //#34 +88 .rdata:0079de14
		virtual void Function_0035(); //#35 +8c .rdata:0079de18
	}; //Size: 0x00F0


} }