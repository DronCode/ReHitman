#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {


	class ZHM3ItemTemplate
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[4]; //0x0008
		uint32_t __MEMCHECK__; //0x000C
		char pad_0010[48]; //0x0010

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
	}; //Size: 0x0040

} }