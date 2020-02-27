#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi { namespace hm3 {

	class ZHM3ItemTemplateAmmo
	{
	public:
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[160]; //0x0008

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

} }