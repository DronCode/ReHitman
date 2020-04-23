#pragma once

#include <cstdint>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZHM3ItemTemplate.h>
#include <sdk/actions/ZLnkAction.h>

namespace ioi { namespace hm3 {

	class ZHitmanActionDestroyDualWeapons
	{
	public:
		ZLnkActionType		m_actionType; //0x0004
		char				pad_0008[4]; //0x0008
		ZHM3Hitman3*		m_hitman3; //0x000C
		ZHM3ItemTemplate*	m_itemTemplate; //0x0010
		ZHM3Hitman3*		m_hitman3_2; //0x0014
		bool				m_flag : 4; //0x0018

		virtual void Function_0000(); //#0 +0 .rdata:00792374
		virtual void Function_0001(); //#1 +4 .rdata:00792378
		virtual void Function_0002(); //#2 +8 .rdata:0079237c
		virtual void Function_0003(); //#3 +c .rdata:00792380
		virtual void Function_0004(); //#4 +10 .rdata:00792384
		virtual void Function_0005(); //#5 +14 .rdata:00792388
		virtual void Function_0006(); //#6 +18 .rdata:0079238c
		virtual void Function_0007(); //#7 +1c .rdata:00792390
		virtual void Function_0008(); //#8 +20 .rdata:00792394
		virtual void Function_0009(); //#9 +24 .rdata:00792398
		virtual void Function_0010(); //#10 +28 .rdata:0079239c
		virtual void Function_0011(); //#11 +2c .rdata:007923a0
		virtual void Function_0012(); //#12 +30 .rdata:007923a4
		virtual void Function_0013(); //#13 +34 .rdata:007923a8
		virtual void Function_0014(); //#14 +38 .rdata:007923ac
		virtual void Function_0015(); //#15 +3c .rdata:007923b0
		virtual void Function_0016(); //#16 +40 .rdata:007923b4
		virtual void Function_0017(); //#17 +44 .rdata:007923b8
	}; //Size: 0x001C

} }