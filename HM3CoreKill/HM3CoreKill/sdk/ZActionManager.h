#pragma once

#include <cstdint>

namespace ioi { namespace hm3 { 
	class ZActionMapTree
	{
	public:
		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0075E878 .func:44B460

		/// === members ===
		ZActionMapTree* m_parent; //0x0004
		ZActionMapTree* m_leftBranch; //0x0008
		ZActionMapTree* m_rightBranch; //0x000C
		ZActionMapTree* m_unusedBranch0; //0x0010
		ZActionMapTree* m_unusedBranch1; //0x0014
		ZActionMapTree* m_unusedBranch2; //0x0018
		char m_name[24]; //0x001C
		uint32_t m_unk0; //0x0034
		char pad_0038[8]; //0x0038
	};

	class ZActionManager
	{
	public:
		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0075e8ac
		virtual void Function_0001(); //#1 +4 .rdata:0075e8b0
		virtual bool getFlag4CState(); //#2 +8 .rdata:0075e8b4
		virtual void Function_0003(); //#3 +c .rdata:0075e8b8
		virtual void Function_0004(); //#4 +10 .rdata:0075e8bc
		virtual char* getHotkeyForAction(const char* actionName); //#5 +14 .rdata:0075e8c0
		virtual void Function_0006(); //#6 +18 .rdata:0075e8c4
		virtual void Function_0007(); //#7 +1c .rdata:0075e8c8
		virtual void Function_0008(); //#8 +20 .rdata:0075e8cc
		virtual void Function_0009(); //#9 +24 .rdata:0075e8d0
		virtual void Function_0010(); //#10 +28 .rdata:0075e8d4
		virtual void Function_0011(); //#11 +2c .rdata:0075e8d8
		virtual void Function_0012(); //#12 +30 .rdata:0075e8dc
		virtual void Function_0013(); //#13 +34 .rdata:0075e8e0
		virtual void Function_0014(); //#14 +38 .rdata:0075e8e4

		/// === members ===
		ZActionMapTree m_tree; //0x0004
	};
} }