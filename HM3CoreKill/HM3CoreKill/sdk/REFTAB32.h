#pragma once

#include <ck/HM3DebugConsole.h>
#include <cstdint>

namespace ioi {

	class REFTAB32
	{
	public:
		// === members ===
		uint32_t m_pStart; //0x0004
		char pad_0008[28]; //0x0008
		int32_t m_itemsCount; //0x0024
		char pad_0028[4]; //0x0028
		uint32_t m_firstItem; //0x002C
		char pad_0030[80]; //0x0030

		// === vftable ===
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

	template <typename _Type> _Type* get(REFTAB32* reftab, int index)
	{
		HM3_ASSERT(reftab != nullptr, "REFTAB instance must be valid!");
		HM3_ASSERT(index >= 0 && index < reftab->m_itemsCount, "Index is out of bounds!");
		return reinterpret_cast<_Type*>(&reftab->m_firstItem) + index;
	}
}