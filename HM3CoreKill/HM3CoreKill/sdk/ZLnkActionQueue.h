#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	class ZLnkAction;
	class ZHM3Hitman3;

	class ZLnkActionQueue
	{
	public:
		ZLnkAction*		m_currentAction; //0x0004
		ZHM3Hitman3*	m_hitman3; //0x0008
		ZLINKREFTAB*	m_lnkRefTab; //0x000C
		char			pad_0010[1164]; //0x0010

		virtual void Function_0000(); //#0 +0 .rdata:0079d988
		virtual void pushAction(ZLnkAction* action); //#1 +4 .rdata:0079d98c
		virtual void Function_0002(); //#2 +8 .rdata:0079d990 [execute action]
		virtual void Function_0003(); //#3 +c .rdata:0079d994
		virtual void Function_0004(); //#4 +10 .rdata:0079d998
		virtual void Function_0005(); //#5 +14 .rdata:0079d99c
		virtual ZLnkAction* popTopAction(); //#6 +18 .rdata:0079d9a0
		virtual void Function_0007(); //#7 +1c .rdata:0079d9a4
		virtual void Function_0008(); //#8 +20 .rdata:0079d9a8
		virtual void Function_0009(); //#9 +24 .rdata:0079d9ac
	}; //Size: 0x049C

} }