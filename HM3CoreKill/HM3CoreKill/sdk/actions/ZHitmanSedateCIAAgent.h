#pragma once

#include <cstdint>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/actions/ZLnkAction.h>

namespace ioi { namespace hm3 {

	class ZHitmanSedateCIAAgent
	{
	public:
		/// === members ===
		ZLnkActionType m_actionType; //0x0004
		ZHM3Actor* m_observerActor; //0x0008
		ZHM3Hitman3* m_hitman3; //0x000C
		ZAnimationInfo* m_animSedate; //0x0010
		ZHM3Actor* m_targetActor; //0x0014
		char pad_0018[4]; //0x0018

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079287c
		virtual void Function_0001(); //#1 +4 .rdata:00792880
		virtual void execute(); //#2 +8 .rdata:00792884
		virtual void Function_0003(); //#3 +c .rdata:00792888
		virtual void Function_0004(); //#4 +10 .rdata:0079288c
		virtual void Function_0005(); //#5 +14 .rdata:00792890
		virtual void Function_0006(); //#6 +18 .rdata:00792894
		virtual void Function_0007(); //#7 +1c .rdata:00792898
		virtual void Function_0008(); //#8 +20 .rdata:0079289c
		virtual void Function_0009(); //#9 +24 .rdata:007928a0
		virtual void Function_0010(); //#10 +28 .rdata:007928a4
		virtual void Function_0011(); //#11 +2c .rdata:007928a8
		virtual void Function_0012(); //#12 +30 .rdata:007928ac
		virtual void Function_0013(); //#13 +34 .rdata:007928b0
		virtual void Function_0014(); //#14 +38 .rdata:007928b4
		virtual void Function_0015(); //#15 +3c .rdata:007928b8
		virtual void Function_0016(); //#16 +40 .rdata:007928bc
		virtual void Function_0017(); //#17 +44 .rdata:007928c0
	}; //Size: 0x001C

}}