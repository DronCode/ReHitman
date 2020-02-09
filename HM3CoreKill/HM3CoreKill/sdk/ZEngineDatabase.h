#pragma once

#include <cstdint>
#include <sdk/ZGeomBuffer.h>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZEngineDatabase
	{
	public:
		char pad_0004[12]; //0x0004
		ZGeomBuffer* m_geomBuffer; //0x0010

		virtual void Function0();	//+0x0
		virtual void Function1();	//+0x4
		virtual void Function2();	//+0x8
		virtual void Function3();	//+0xC
		virtual void Function4();	//+0x10
		virtual void Function5();	//+0x14
		virtual void Function6();	//+0x18
		virtual void Function7();	//+0x1C
		virtual void Function8();	//+0x20
		virtual void Function9();	//+0x24
		virtual void Function10();	//+0x28
		virtual void Function11();	//+0x2C
		virtual void Function12();	//+0x30
		virtual void Function13();	//+0x34
		virtual void Function14();	//+0x38
		virtual void Function15();	//+0x3C
		virtual void Function16();	//+0x40
		virtual void Function17();	//+0x44
		virtual void Function18();	//+0x48
		virtual void Function19();	//+0x4C
		virtual void Function20();	//+0x50
		virtual void Function21();	//+0x54
		virtual void Function22();	//+0x58
		virtual void Function23();	//+0x5C
		virtual void Function24();	//+0x60
		virtual void Function25();	//+0x64
		virtual void Function26();	//+0x68
		virtual void Function27();	//+0x6C
		virtual void Function28();	//+0x70
		virtual void Function29();	//+0x74
		virtual void Function30();	//+0x78
		virtual void Function31();	//+0x7C
		virtual void Function32();	//+0x80
		virtual void Function33();	//+0x84
		virtual void Function34();	//+0x88
		virtual void Function35();	//+0x8C
		virtual void Function36();	//+0x90
		virtual void Function37();	//+0x94
		virtual bool Function38();	//+0x98
		virtual void Function39();	//+0x9C
		virtual void Function40();	//+0x100
		virtual void Function41();	//+0x100
		virtual void Function42();	//+0x104
		virtual void Function43();	//+0x108
		virtual void Function44();	//+0x10C
		virtual void Function45();	//+0x110
		virtual void Function46();	//+0x114
		virtual void Function47();	//+0x118
		virtual void Function48();	//+0x11C
		virtual void Function49();	//+0x120
		virtual void Function50();	//+0x124
		virtual void Function51();	//+0x128
		virtual void Function52();	//+0x12C
		virtual void Function53();	//+0x130
		virtual void Function54();	//+0x134
		virtual void Function55();	//+0x138
		virtual void Function56();	//+0x13C
		virtual void Function57();	//+0x140
		virtual void Function58();	//+0x144
		virtual void Function59();	//+0x148
		virtual void Function60();	//+0x14C
		virtual void Function61();	//+0x150
		virtual void Function62();	//+0x154
		virtual void Function63();	//+0x158
		virtual void Function64();	//+0x15C
		virtual void Function65();	//+0x160
		virtual void Function66();	//+0x164
		virtual void Function67();	//+0x168
		virtual void Function68();	//+0x16C
		virtual void Function69();	//+0x170
		virtual void Function70();	//+0x174
		virtual void Function71();	//+0x178
		virtual void Function72();	//+0x17C
		virtual void Function73();	//+0x180
		virtual void Function74();	//+0x184
		virtual void Function75();	//+0x188
		virtual void Function76();	//+0x18C
		virtual void Function77();	//+0x190
		virtual void Function78();	//+0x194
		virtual void Function79();	//+0x198
		virtual void Function80();	//+0x19C
	}; //Size: 0x0014


	class CCOM
	{
	public:
	};

	CCOM* getCCOMObjectFromEngineDB(ZEngineDatabase* instance);
}}