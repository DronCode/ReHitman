#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZHM3Actor.h>

namespace ioi { namespace hm3 { 
	
	class ConstrainedParticleSystem
	{
	public:
		int m_unkPtr0; //0x0004
		int m_unkPtr1; //0x0008
		int m_unkPtr2; //0x000C
		char pad_0010[8]; //0x0010
		int m_size; //0x0018
		char pad_001C[20]; //0x001C
		ZHM3Actor* m_actor; //0x0030
		char pad_0034[12]; //0x0034
		ZEntityLocator* m_entityLocator; //0x0040
		char pad_0044[52]; //0x0044
		ZEntityLocator* m_entityLocator1; //0x0078
		char pad_007C[52]; //0x007C
		ZEntityLocator* m_entityLocator2; //0x00B0
		char pad_00B4[16]; //0x00B4
		void* m_unkFunc0; //0x00C4
		char pad_00C8[4]; //0x00C8
		void* m_unkFunc1; //0x00CC
		char pad_00D0[24]; //0x00D0
		ZEntityLocator* m_entityLocator3; //0x00E8
		char pad_00EC[44]; //0x00EC

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
	}; //Size: 0x0118

}}