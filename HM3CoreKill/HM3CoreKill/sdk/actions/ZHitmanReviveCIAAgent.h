#pragma once

#include <cstdint>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/actions/ZLnkAction.h>

namespace ioi { namespace hm3 {

	class ZHitmanReviveCIAAgent
	{
	public:
		ZLnkActionType	m_actionType;	//0x0004
		ZHM3Hitman3*	m_hitman3;		//0x0008
		ZHM3Hitman3*	m_hitman3_1;	//0x000C
		ZAnimationInfo*	m_animWakeCIA;	//0x0010
		ZHM3Actor*		m_actor;		//0x0014
		int32_t			m_pad0;			//0x0018
		int32_t			m_pad1;			//0x001C
		int32_t			m_pad2;			//0x0020
		int32_t			m_pad3;			//0x0024
		ZLnkAction		m_lnkAction;	//0x0028

		virtual void Function_0000(); //#0 +0 .rdata:00792a74
		virtual void Function_0001(); //#1 +4 .rdata:00792a78
		virtual void execute(); //#2 +8 .rdata:00792a7c
		virtual void Function_0003(); //#3 +c .rdata:00792a80
		virtual void Function_0004(); //#4 +10 .rdata:00792a84
		virtual void Function_0005(); //#5 +14 .rdata:00792a88
		virtual void Function_0006(); //#6 +18 .rdata:00792a8c
		virtual void Function_0007(); //#7 +1c .rdata:00792a90
		virtual void Function_0008(); //#8 +20 .rdata:00792a94
		virtual void Function_0009(); //#9 +24 .rdata:00792a98
		virtual void Function_0010(); //#10 +28 .rdata:00792a9c
		virtual void Function_0011(); //#11 +2c .rdata:00792aa0
		virtual void Function_0012(); //#12 +30 .rdata:00792aa4
		virtual void Function_0013(); //#13 +34 .rdata:00792aa8
		virtual void Function_0014(); //#14 +38 .rdata:00792aac
		virtual void Function_0015(); //#15 +3c .rdata:00792ab0
		virtual void Function_0016(); //#16 +40 .rdata:00792ab4
		virtual void Function_0017(); //#17 +44 .rdata:00792ab8
	}; //Size: 0x0050

} }