#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	class ZHM3HmAs
	{
	public:
		uint32_t m_currentRoleInfo; //0x0004
		char pad_0008[52]; //0x0008
		ZSTDOBJ* m_STDOBJ0; //0x003C
		ZSTDOBJ* m_STDOBJ1; //0x0040
		char pad_0044[100]; //0x0044

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
	}; //Size: 0x00A8

}}