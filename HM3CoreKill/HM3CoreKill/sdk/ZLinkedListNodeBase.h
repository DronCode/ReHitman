#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	struct ZLinkedListNodeBase
	{
		ZLinkedListNodeBase* pNext;     // +0
		ZLinkedListNodeBase* pPrev;     // +4
		int32_t mId;					// +8
		char pad_0010[4];				// +C
	};

} }