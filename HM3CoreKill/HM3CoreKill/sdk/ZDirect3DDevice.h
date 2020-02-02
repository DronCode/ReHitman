#pragma once

#include <cstdint>
#include <d3d9.h>

namespace ioi { namespace hm3 {
	// Created with ReClass.NET 1.2 by KN4CK3R
	class ZDirect3DDevice
	{
	public:
		IDirect3DDevice9* m_d3dDevice; //0x0004
		int32_t m_unknown; //0x0008

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
	}; //Size: 0x000C
}}