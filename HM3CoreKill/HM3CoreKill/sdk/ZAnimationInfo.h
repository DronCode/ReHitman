#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZAnimationInfo
	{
	public:
		int32_t m_id; //0x0000
		char pad_0004[56]; //0x0004
		char* m_name; //0x003C
	}; //Size: 0x0040

}}