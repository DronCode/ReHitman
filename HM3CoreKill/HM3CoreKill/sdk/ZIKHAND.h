#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {
	
	enum class HandType { 
		LeftHand	= 32, 
		RightHand	= 31,
		RatUnk0		= 20,
		RatUnk1		= 25 
	};

	class ZIKHAND
	{
	public:
		char pad_0004[92]; //0x0004
		int32_t m_itemID; //0x0060
		bool m_hasItem; //0x0064
		char pad_0065[3]; //0x0065
		HandType m_handType; //0x0068
		char pad_006C[20]; //0x006C

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

} }