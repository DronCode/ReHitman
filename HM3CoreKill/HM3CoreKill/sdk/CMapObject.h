#pragma once

#include <sdk/ZGlacierRTTI.h>
#include <cstdint>

namespace ioi { namespace hm3 {

	class CMapObject
	{
	public:
		virtual void Function_0();  //+0000 [rdata base at 0x0076CB0C]
		virtual void Function_1();  //+0001 [rdata base at 0x0076CB10]
		virtual void Function_2();  //+0002 [rdata base at 0x0076CB14]
		virtual void Function_3();  //+0003 [rdata base at 0x0076CB18]
		virtual void Function_4();  //+0004 [rdata base at 0x0076CB1C]
		virtual void Function_5();  //+0005 [rdata base at 0x0076CB20]
		virtual void Function_6();  //+0006 [rdata base at 0x0076CB24]
		virtual void Function_7();  //+0007 [rdata base at 0x0076CB28]
		virtual void Function_8();  //+0008 [rdata base at 0x0076CB2C]
		virtual void Function_9();  //+0009 [rdata base at 0x0076CB30]
		virtual void Function_10(); //+000A [rdata base at 0x0076CB34]
		virtual void Function_11(); //+000B [rdata base at 0x0076CB38]
		virtual void Function_12(); //+000C [rdata base at 0x0076CB3C]
		virtual void Function_13(); //+000D [rdata base at 0x0076CB40]
		virtual void Function_14(); //+000E [rdata base at 0x0076CB44]
		virtual void Function_15(); //+000F [rdata base at 0x0076CB48]
		virtual void Function_16(); //+0010 [rdata base at 0x0076CB4C]
		virtual void Function_17(); //+0011 [rdata base at 0x0076CB50]
		virtual void Function_18(); //+0012 [rdata base at 0x0076CB54]
		virtual void Function_19(); //+0013 [rdata base at 0x0076CB58]
		virtual void Function_20(); //+0014 [rdata base at 0x0076CB5C]
		virtual void Function_21(); //+0015 [rdata base at 0x0076CB60]
		virtual void Function_22(); //+0016 [rdata base at 0x0076CB64]
		virtual void Function_23(); //+0017 [rdata base at 0x0076CB68]
		virtual void Function_24(); //+0018 [rdata base at 0x0076CB6C]
		virtual void Function_25(); //+0019 [rdata base at 0x0076CB70]
		virtual void Function_26(); //+001A [rdata base at 0x0076CB74]
		virtual void Function_27(); //+001B [rdata base at 0x0076CB78]
		virtual void Function_28(); //+001C [rdata base at 0x0076CB7C]
		virtual void Function_29(); //+001D [rdata base at 0x0076CB80] <onEvent proxy>
		virtual void Function_30(); //+001E [rdata base at 0x0076CB84]
		virtual void Function_31(); //+001F [rdata base at 0x0076CB88]
		virtual void Function_32(); //+0020 [rdata base at 0x0076CB8C]
		virtual void Function_33(); //+0021 [rdata base at 0x0076CB90]
		virtual void Function_34(); //+0022 [rdata base at 0x0076CB94]
		virtual void Function_35(); //+0023 [rdata base at 0x0076CB98]

		// --- MEMBERS ---
		char pad_0004[32];							//0x0004
		std::uintptr_t m_objectToLookup;						//0x0024
		char pad_0028[4];							//0x0028
		ioi::hm3::ZGlacierRTTI* m_runtimeTypeInfo;  //0x002C
		char pad_0030[16];							//0x0030
	};

}}