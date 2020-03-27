#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 { 
	class ZROOMPOOL;

	class ZROOM
	{
	public:
		char pad_0004[104]; //0x0004
		ZROOMPOOL* m_data; //0x006C
		char pad_0070[16]; //0x0070

		virtual void Function0();
	};

	class ZROOMPOOL
	{
	public:
		int32_t m_count; //0x0000
		ZROOM* m_pool[417]; //0x0004
	};

}}