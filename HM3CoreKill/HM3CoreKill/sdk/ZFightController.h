#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZActorCommunication.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {
	
	class ZFightController : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_STDOBJ; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[4]; //0x0030
		ZActorCommunication* m_actorCommunication; //0x0034
		char pad_0038[264]; //0x0038

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079db9c
		virtual void Function_0001(); //#1 +4 .rdata:0079dba0
		virtual void Function_0002(); //#2 +8 .rdata:0079dba4
		virtual void Function_0003(); //#3 +c .rdata:0079dba8
		virtual void Function_0004(); //#4 +10 .rdata:0079dbac
		virtual void Function_0005(); //#5 +14 .rdata:0079dbb0
		virtual void Function_0006(); //#6 +18 .rdata:0079dbb4
		virtual void Function_0007(); //#7 +1c .rdata:0079dbb8
		virtual void Function_0008(); //#8 +20 .rdata:0079dbbc
		virtual void Function_0009(); //#9 +24 .rdata:0079dbc0
		virtual void Function_0010(); //#10 +28 .rdata:0079dbc4
		virtual void Function_0011(); //#11 +2c .rdata:0079dbc8
		virtual void Function_0012(); //#12 +30 .rdata:0079dbcc
		virtual void Function_0013(); //#13 +34 .rdata:0079dbd0
		virtual void Function_0014(); //#14 +38 .rdata:0079dbd4
		virtual void Function_0015(); //#15 +3c .rdata:0079dbd8
		virtual void Function_0016(); //#16 +40 .rdata:0079dbdc
		virtual void Function_0017(); //#17 +44 .rdata:0079dbe0
		virtual void Function_0018(); //#18 +48 .rdata:0079dbe4
		virtual void Function_0019(); //#19 +4c .rdata:0079dbe8
		virtual void Function_0020(); //#20 +50 .rdata:0079dbec
		virtual void Function_0021(); //#21 +54 .rdata:0079dbf0
		virtual void Function_0022(); //#22 +58 .rdata:0079dbf4
		virtual void Function_0023(); //#23 +5c .rdata:0079dbf8
		virtual void Function_0024(); //#24 +60 .rdata:0079dbfc
		virtual void Function_0025(); //#25 +64 .rdata:0079dc00
		virtual void Function_0026(); //#26 +68 .rdata:0079dc04
		virtual void Function_0027(); //#27 +6c .rdata:0079dc08
		virtual void Function_0028(); //#28 +70 .rdata:0079dc0c
		virtual void Function_0029(); //#29 +74 .rdata:0079dc10
		virtual void Function_0030(); //#30 +78 .rdata:0079dc14
		virtual void Function_0031(); //#31 +7c .rdata:0079dc18
		virtual void Function_0032(); //#32 +80 .rdata:0079dc1c
		virtual void Function_0033(); //#33 +84 .rdata:0079dc20
		virtual void Function_0034(); //#34 +88 .rdata:0079dc24
		virtual void Function_0035(); //#35 +8c .rdata:0079dc28
	}; //Size: 0x0140

}}