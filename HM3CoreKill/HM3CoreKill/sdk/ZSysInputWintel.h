#pragma once

#include <cstdint>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZKeyboardWintel.h>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZSysInputWintel
	{
	public:
		char pad_0004[12]; //0x0004
		ZMouseWintel* m_mouseDevice; //0x0010
		ZKeyboardWintel* m_keyboardDevice; //0x0014

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
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual void Function13();
		virtual void Function14();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
	}; //Size: 0x0018

}}