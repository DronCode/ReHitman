#pragma once

#include <cstdint>
#include <sdk/ConstrainedParticleSystem.h>

namespace ioi { namespace hm3 { 
	class CRagdoll2
	{
	public:
		char pad_0004[324]; //0x0004
		ConstrainedParticleSystem* m_constrainedParticleSystem; //0x0148
		char pad_014C[116]; //0x014C

		virtual void Function0(); ///#0, .rdata:00781CC0
	}; //Size: 0x01C0
}}