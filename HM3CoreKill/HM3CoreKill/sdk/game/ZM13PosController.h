#pragma once

#include <cstdint>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZM13PosController : public ZLinkedListNodeBase
	{
	public:
		int32_t m_unkInt0;		//0x0014
		char pad_0018[8];		//0x0018
		int8_t m_unkFlag0;		//0x0020
		int8_t m_unkFlag1;		//0x0021
		int8_t m_unkFlag2;		//0x0022
		int8_t m_unkFlag3;		//0x0023
		ZHM3Actor* m_actor;		//0x0024
		char pad_0028[4];		//0x0028
		ZGlacierRTTI* m_RTTI;	//0x002C
		char pad_0030[48];		//0x0030

		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0078c344
		virtual void Function_0001(); //#1 +4 .rdata:0078c348
		virtual void Function_0002(); //#2 +8 .rdata:0078c34c
		virtual void Function_0003(); //#3 +c .rdata:0078c350
		virtual void Function_0004(); //#4 +10 .rdata:0078c354
		virtual void Function_0005(); //#5 +14 .rdata:0078c358
		virtual void Function_0006(); //#6 +18 .rdata:0078c35c
		virtual void Function_0007(); //#7 +1c .rdata:0078c360
		virtual void Function_0008(); //#8 +20 .rdata:0078c364
		virtual void Function_0009(); //#9 +24 .rdata:0078c368
		virtual void Function_0010(); //#10 +28 .rdata:0078c36c
		virtual void Function_0011(); //#11 +2c .rdata:0078c370
		virtual void Function_0012(); //#12 +30 .rdata:0078c374
		virtual void Function_0013(); //#13 +34 .rdata:0078c378
		virtual void Function_0014(); //#14 +38 .rdata:0078c37c
		virtual void Function_0015(); //#15 +3c .rdata:0078c380
		virtual void Function_0016(); //#16 +40 .rdata:0078c384
		virtual void Function_0017(); //#17 +44 .rdata:0078c388
		virtual void Function_0018(); //#18 +48 .rdata:0078c38c
		virtual const char* getTypeName(); //#19 +4c .rdata:0078c390
		virtual void Function_0020(); //#20 +50 .rdata:0078c394
		virtual void Function_0021(); //#21 +54 .rdata:0078c398
		virtual void Function_0022(); //#22 +58 .rdata:0078c39c
		virtual void Function_0023(); //#23 +5c .rdata:0078c3a0
		virtual void Function_0024(); //#24 +60 .rdata:0078c3a4
		virtual void Function_0025(); //#25 +64 .rdata:0078c3a8
		virtual void Function_0026(); //#26 +68 .rdata:0078c3ac
		virtual void Function_0027(); //#27 +6c .rdata:0078c3b0
		virtual void Function_0028(); //#28 +70 .rdata:0078c3b4
		virtual void Function_0029(); //#29 +74 .rdata:0078c3b8
		virtual void Function_0030(); //#30 +78 .rdata:0078c3bc
		virtual void Function_0031(); //#31 +7c .rdata:0078c3c0
		virtual unsigned int processState(); //#32 +80 .rdata:0078c3c4
		virtual void Function_0033(); //#33 +84 .rdata:0078c3c8
		virtual ZGlacierRTTI* setRuntimeTypeInformation(ZGlacierRTTI* rtti); //#34 +88 .rdata:0078c3cc
		virtual void Function_0034(); //#34 +88 .rdata:0078C3D0
	}; //Size: 0x0060

} }