#pragma once

#include <cstdint>
#include <sdk/CRagdoll2.h>

namespace ioi { namespace hm3 { 
	class ZBodyInfo
	{
	public:
		char pad_0000[8]; //0x0000
		int32_t m_id; //0x0008
		int32_t m_unk0; //0x000C
		int32_t m_unk1; //0x0010
		char pad_0014[4]; //0x0014
		int32_t m_unk2; //0x0018
		int32_t m_unk3; //0x001C
		char pad_0020[744]; //0x0020
		CRagdoll2* m_radgoll2; //0x0308
		char pad_030C[48]; //0x030C
	}; //Size: 0x033C
} }