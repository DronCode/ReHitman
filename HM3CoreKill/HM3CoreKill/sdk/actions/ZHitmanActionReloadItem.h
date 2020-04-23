#pragma once

#include <cstdint>
#include <sdk/ZIKHAND.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/actions/ZLnkAction.h>

namespace ioi { namespace hm3 {
	
	class ZHitmanActionReloadItem
	{
	public:
		ZLnkActionType	m_actionType; //0x0004
		ZHM3Hitman3*	m_hitman3; //0x0008
		ZIKHAND*		m_hand_1; //0x000C
		char			pad_0010[28]; //0x0010
		ZAnimationInfo* m_animReloadHardballer; //0x002C
		ZHM3Item*		m_item; //0x0030
		ZHM3Actor*		m_actor; //0x0034
		ZIKHAND*		m_hand_2; //0x0038
		int32_t			m_flag; //0x003C
		uint32_t		m_pose; //0x0040
		ZAnimationInfo* m_animPullGunRight; //0x0044
		int32_t			m_flag_2; //0x0048
		char			pad_004C[52]; //0x004C

		virtual void Function_0000(); //#0 +0 .rdata:007936d4
		virtual void Function_0001(); //#1 +4 .rdata:007936d8
		virtual void Function_0002(); //#2 +8 .rdata:007936dc
		virtual void Function_0003(); //#3 +c .rdata:007936e0
		virtual void Function_0004(); //#4 +10 .rdata:007936e4
		virtual void Function_0005(); //#5 +14 .rdata:007936e8
		virtual void Function_0006(); //#6 +18 .rdata:007936ec
		virtual void Function_0007(); //#7 +1c .rdata:007936f0
		virtual const char* getActionName(); //#8 +20 .rdata:007936f4
		virtual void Function_0009(); //#9 +24 .rdata:007936f8
		virtual void Function_0010(); //#10 +28 .rdata:007936fc
		virtual void Function_0011(); //#11 +2c .rdata:00793700
		virtual void Function_0012(); //#12 +30 .rdata:00793704
		virtual void Function_0013(); //#13 +34 .rdata:00793708
		virtual void Function_0014(); //#14 +38 .rdata:0079370c
		virtual void Function_0015(); //#15 +3c .rdata:00793710
		virtual void Function_0016(); //#16 +40 .rdata:00793714
		virtual void Function_0017(); //#17 +44 .rdata:00793718
		virtual void Function_0018(); //#18 +48 .rdata:0079371c
		virtual void Function_0019(); //#19 +4c .rdata:00793720
	}; //Size: 0x0080
}}