#pragma once

#include <cstdint>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZHM3WeaponItem.h>
#include <sdk/ZIKHAND.h>

namespace ioi { namespace hm3 {

	class ZHM3ActorPunch
	{
	public:
		uint32_t m_unk1; //0x0004
		ZAnimationInfo* m_animPunchGun; //0x0008
		ZHM3Actor* m_actor; //0x000C
		uint32_t m_unk0; //0x0010
		char pad_0014[4]; //0x0014
		ZAnimationInfo* m_animPullGunRight; //0x0018
		ZAnimationInfo* m_animPullGunRight2; //0x001C
		char pad_0020[8]; //0x0020
		ZAnimationInfo* m_animReloadGun; //0x0028
		char pad_002C[20]; //0x002C
		ZHM3Hitman3* m_hitman3; //0x0040
		ZHM3Actor* m_actor2; //0x0044
		ZAnimationInfo* m_animCloseCombat; //0x0048
		ZAnimationInfo* m_animEnemyCloseCombat; //0x004C
		ZHM3Hitman3* m_hitman3_2; //0x0050
		char pad_0054[4]; //0x0054
		char* m_punchType; //0x0058
		char pad_005C[16]; //0x005C
		ZHM3ItemWeapon* m_weapon; //0x006C
		ZHM3Actor* m_actor3; //0x0070
		ZIKHAND* m_hand; //0x0074
		char pad_0078[4]; //0x0078
		ZAnimationInfo* m_animPullGunRight2_1; //0x007C
		ZAnimationInfo* m_animPullGunRight2_2; //0x0080
		char pad_0084[68]; //0x0084

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
	}; //Size: 0x00C8
} }