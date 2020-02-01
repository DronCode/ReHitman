#pragma once

#include <cstdint>

namespace ioi { namespace hm3 { namespace sysinput {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZKeyboardStorage
	{
	public:
		char pad_0000[12];				//0x0000
		int32_t isBackspacePressed;		//0x000C
		char pad_0010[12];				//0x0010
		int32_t isCtrlPressed;			//0x001C
		char pad_0020[8];				//0x0020
		int32_t isShiftPressed;			//0x0028
		char pad_002C[8];				//0x002C
		int32_t isRightShiftPressed;	//0x0034
		int32_t isAltPressed;			//0x0038
		char pad_003C[96];				//0x003C
		int32_t isRightCtrlPressed;		//0x009C
		char pad_00A0[24];				//0x00A0
		int32_t isRightAltPressed;		//0x00B8
		char pad_00BC[68];				//0x00BC
	}; //Size: 0x0100

}}}