#pragma once

#include <cstdint>
#include <sdk/ZAnimationInfo.h>
#include <sdk/MathCommon.h>

namespace ioi { namespace hm3 {

	class ZHM3Actor;
	class ZHM3Item;
	class ZHM3ItemTemplate;
	class ZHM3Hitman3;
	
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

		virtual void Function0(); //#0 +0x00 .rdata:00774BEC [BindVars, unused]
		virtual void changeItemInHand(ZHM3Hitman3* _hitman3, int _itemID); //#1 +0x04 .rdata:00774BF0 (pass zero to _itemID to remove current item)
		virtual void dropItem(ZHM3Hitman3* _hitman3); //#2 +0x08 .rdata:00774BF4
		virtual ZHM3Item* getItem(); //#3 +0x0C .rdata:00774BF8
		virtual ZHM3ItemTemplate* getItemTemplate(); //#4 +0x10 .rdata:00774BFC
		virtual int resetHands(); //#5 +0x14 .rdata:00774C00
		virtual int takeItem(
			ZHM3Hitman3* _hitman3, 
			Matrix4x4* _handTransform, 
			Vector3* _pivotPoint, 
			float _veliocity, 
			ZAnimationCallback_t onAnimationCompletedCallback, 
			int _z0 = 0,
			int _z1 = 0,
			int _z2 = 0
		); //#6 +0x18 .rdata:00774C04
	}; //Size: 0x0080

} }