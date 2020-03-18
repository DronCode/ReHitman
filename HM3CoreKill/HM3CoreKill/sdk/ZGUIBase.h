#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>

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

		char m_name[64];	//0x0004
		Vector2 m_position; //0x0044
	};
}}