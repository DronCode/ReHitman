#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	template <typename _T> struct ZLinkedListHeader
	{
		/// === types ===
		using ItemType = _T;

		/// === members ===
		ItemType* m_prev;
		ItemType* m_next;

		/// === helpers ===
		ItemType* begin() { return reinterpret_cast<_T*>(reinterpret_cast<std::intptr_t*>(m_next) - 1); }
		ItemType* end() { return reinterpret_cast<_T*>(reinterpret_cast<std::intptr_t*>(m_prev) - 1); }
	};

	struct ZLinkedListNodeBase
	{
		ZLinkedListNodeBase* pNext;     // +0
		ZLinkedListNodeBase* pPrev;     // +4
		int32_t mId;					// +8
		char pad_0010[4];				// +C
	};

} }