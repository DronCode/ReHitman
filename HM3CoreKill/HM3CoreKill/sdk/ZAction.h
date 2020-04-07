#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZAction : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZSTDOBJ* m_entity; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		char pad_0030[68]; //0x0030
		ZAction* m_nextAction; //0x0074
		char pad_0078[8]; //0x0078

		/// === vftable ===
		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
	}; //Size: 0x0080

}}