#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class CIngameMap;
	class CMapIconDraw;
	class CInGameMapViews;
	class MapView_t;
	class ZGlacierRTTI;

	class MapAction
	{
	public:
		char* name; //0x0000 
		std::uintptr_t* action; //0x0004 
		char pad_0x0008[0x4]; //0x0008
	}; //Size=0x000C

	class CIngameMap
	{
	public:
		char pad_0x0000[0x18]; //0x0000
		int32_t m_flags; //0x0018 
		int32_t m_showed; //0x001C 
		char pad_0x0020[0xC]; //0x0020
		ZGlacierRTTI* m_RTTI; //0x002C 
		MapAction m_actions[12]; //0x0030 
		char pad_0x00C0[0xE8]; //0x00C0
		CInGameMapViews* m_views; //0x01A8 
		char pad_0x01AC[0x24]; //0x01AC
		CMapIconDraw* m_iconRenderer; //0x01D0 
		char pad_0x01D4[0x38]; //0x01D4
		Vector4 m_drawPosition; //0x020C 
		char pad_0x021C[0x90]; //0x021C
		MapView_t* m_activeMap; //0x02AC 
		char pad_0x02B0[0x20]; //0x02B0

	}; //Size=0x02D0

	class CMapIconDraw
	{
	public:
		char pad_0x0000[0x1C]; //0x0000
		Vector3 m_position; //0x001C 
		char pad_0x0028[0x5C]; //0x0028

	}; //Size=0x0084

	class MapView_t
	{
	public:
		int32_t m_unknown; //0x0000 
		int32_t m_flags; //0x0004 
		char* m_viewName; //0x0008 
		int32_t m_viewId; //0x000C 
		char pad_0x0010[0x4]; //0x0010

	}; //Size=0x0014

	class CInGameMapViews
	{
	public:
		MapView_t viewsPool[5]; //0x0000 
		char pad_0x0064[0x10]; //0x0064
		ZGlacierRTTI* m_RTTI; //0x0074 

	}; //Size=0x0078
}}