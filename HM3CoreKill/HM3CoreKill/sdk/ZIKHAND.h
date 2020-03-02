#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZHM3Actor;
	class ZHM3Item;
	class ZHM3ItemTemplate;
	class ZLNKWHANDS;
	
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

		virtual void Function0(); //#0 +0x00 .rdata:00774BEC
		virtual void changeItemInHand(ZLNKWHANDS* actor, int unk1, int _action, int newItemID); //#1 +0x04 .rdata:00774BF0
		virtual void Function2(); //#2 +0x08 .rdata:00774BF4
		virtual ZHM3Item* getItem(); //#3 +0x0C .rdata:00774BF8
		virtual ZHM3ItemTemplate* getItemTemplate(); //#4 +0x10 .rdata:00774BFC
		virtual int resetHands(); //#5 +0x14 .rdata:00774C00
		virtual int takeItem(int _hitman3, int _item, int _item2, float _unk0, int unk1, int _z0, int _z1, int _z2); //#6 +0x18 .rdata:00774C04
	}; //Size: 0x0080

} }