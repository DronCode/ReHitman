#pragma once

#include <sdk/ZAnimationInfo.h>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	class ZHM3ItemWeapon
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[164]; //0x0008
		REFTAB* m_REFTAB; //0x00AC
		char pad_00B0[76]; //0x00B0
		ZAnimationInfo* m_animReload; //0x00FC
		ZAnimationInfo* m_animFire; //0x0100
		char pad_0104[32]; //0x0104
		uint32_t m_LNKOBJ; //0x0124
		char pad_0128[52]; //0x0128

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
	}; //Size: 0x015C

} }