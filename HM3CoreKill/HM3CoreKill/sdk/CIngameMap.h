#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>

#define DECLARE_UNKNOWN_TYPE_PTR(name) using name = std::uintptr_t;

namespace ioi { namespace hm3 {

	DECLARE_UNKNOWN_TYPE_PTR(ZWINDOW);
	DECLARE_UNKNOWN_TYPE_PTR(ZActionMapTree);

	class CMapIconDraw;

	class CIngameMap
	{
	public:
		char pad_0000[36]; //0x0000
		ZWINDOW* m_UIWindow; //0x0024 [ZWINDOW]
		char pad_0028[144]; //0x0028
		ZActionMapTree* m_actionsTree; //0x00B8 [ZActionMapTree]
		char pad_00BC[276]; //0x00BC
		CMapIconDraw* m_iconDraw; //0x01D0
		char pad_01D4[180]; //0x01D4
		Vector2 m_mapOffset; //0x0288
		char pad_0290[12]; //0x0290
		bool m_isInDragProcess; //0x029C
		char pad_029D[11]; //0x029D
		bool m_isShowing; //0x02A8
		char pad_02A9[3]; //0x02A9
		int32_t m_currentPage; //0x02AC
		char pad_02B0[32]; //0x02B0
	}; //Size: 0x02D0

	class CMapIconDraw
	{
	public:
		char pad_0000[16]; //0x0000
		int8_t N00000981; //0x0010
		char pad_0011[3]; //0x0011
		int8_t N00000982; //0x0014
		char pad_0015[3]; //0x0015
		int8_t N00000983; //0x0018
		char pad_0019[3]; //0x0019
		Vector3 m_position; //0x001C
		char pad_0028[480]; //0x0028
	}; //Size: 0x0208

}}

#undef DECLARE_UNKNOWN_TYPE_PTR