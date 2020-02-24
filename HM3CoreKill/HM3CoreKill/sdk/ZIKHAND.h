#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {
	class ZHM3Hitman3;

	class ZIKHAND
	{
	public:
		char pad_0004[16]; //0x0004
		float m_unkFloat0; //0x0014
		char pad_0018[4]; //0x0018
		float m_unkFloat1; //0x001C
		char pad_0020[4]; //0x0020
		float m_unkFloat2; //0x0024
		char pad_0028[24]; //0x0028
		float m_unkFloat3; //0x0040
		char pad_0044[80]; //0x0044
		ZHM3Hitman3* m_owner; //0x0094
		char pad_0098[4]; //0x0098
		uint32_t m_humanBoid; //0x009C
		char pad_00A0[16]; //0x00A0
		Vector3 m_position; //0x00B0
		char pad_00BC[84]; //0x00BC
		ZEntityLocator* m_currentLevelZone; //0x0110
		char pad_0114[116]; //0x0114

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
	}; //Size: 0x0188

} }