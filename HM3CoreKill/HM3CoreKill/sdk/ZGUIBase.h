#pragma once

#include <cstdint>

namespace ioi {
namespace hm3 {
	/****
		@class: ZGUIBase

		+------(ZGUIBase)-----
	0x0 | {vfptr}
	0x4 | char		Name[64];
	0x68| int32_t	X
	0x72| int32_t	Y
		+---------------------
	****/

	class ZGUIBase
	{
	public:
		//2 METHODS
		virtual int  sub_563D20(int, int);
		virtual void RESERVED_0();

		char			Name[64];	//+ 0x04
		int32_t			X;			//+ 0x68
		int32_t			Y;			//+ 0x72
	};

	/****

		 +------(IGUIElement)----
		 |+------(ZGUIBase)-----
	0x0  || {vfptr}
	0x4  || char		Name[64];
	0x68 || int32_t	X
	0x72 || int32_t	Y
		 |+---------------------
	0x76 | {vfptr}
	0x7A | int32_t unk0;
	0x7E | int32_t unk1;
	0x82 | int32_t unk2;
	0x86 | int32_t unk3;
	0x8A | int32_t unk4;
	0x8E | int32_t unk5;
	0x92 | bool    unk6;
		 +-----------------------
	****/
	class IGUIElement : public ZGUIBase
	{
	public:
		//14 METHODS
		virtual  int sub_55E230(int, int);
		virtual void RESERVED_0();
		virtual void RESERVED_1();
		virtual void RESERVED_2();
		virtual void RESERVED_3();
		virtual void sub_580400();
		virtual void RESERVED_4();
		virtual void sub_55E4B0();
		virtual void RESERVED_5();
		virtual void sub_6F7FC0();
		virtual void RESERVED_6();
		virtual void RESERVED_7();
		virtual void RESERVED_8();

		// TODO: RECONSTRUCT INLINE STRUCTURE
		int32_t Unknown_0;
		int32_t Unknown_1;
		int32_t Unknown_2;
		int32_t Unknown_3;
		int32_t Unknown_4;
		int32_t Unknown_5;
		bool    Unknown_6;
	};

	class ZNavigator : public IGUIElement, public ZGUIBase
	{
	public:
		//16 METHODS

	};

	class ZNavigatorGeneric : public ZNavigator
	{
	public:
		//16 METHODS
	};
}}