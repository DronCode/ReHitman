#pragma once

#include <sdk/MathCommon.h>
#include <sdk/ZGUIBase.h>
#include <sdk/ZWINDOW.h>

namespace ioi { namespace hm3 {

	class ZHM3InventoryMenu
	{
	public:
		/// === members ===
		char m_name[64]; //0x0004
		Vector2 m_position; //0x0044
		ZGUIBase* m_colorSet; //0x004C
		char pad_0050[300]; //0x0050
		uint32_t m_winGroup; //0x017C
		ZWINDOW* m_window; //0x0180
		char pad_0184[124]; //0x0184

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007a3e9c
		virtual void Function_0001(); //#1 +4 .rdata:007a3ea0
		virtual void Function_0002(); //#2 +8 .rdata:007a3ea4
		virtual void Function_0003(); //#3 +c .rdata:007a3ea8
		virtual void Function_0004(); //#4 +10 .rdata:007a3eac
		virtual void Function_0005(); //#5 +14 .rdata:007a3eb0
		virtual void Function_0006(); //#6 +18 .rdata:007a3eb4
		virtual void Function_0007(); //#7 +1c .rdata:007a3eb8
		virtual void Function_0008(); //#8 +20 .rdata:007a3ebc
		virtual void Function_0009(); //#9 +24 .rdata:007a3ec0
		virtual void Function_0010(); //#10 +28 .rdata:007a3ec4
		virtual void Function_0011(); //#11 +2c .rdata:007a3ec8
		virtual void Function_0012(); //#12 +30 .rdata:007a3ecc
		virtual void Function_0013(); //#13 +34 .rdata:007a3ed0
		virtual void Function_0014(); //#14 +38 .rdata:007a3ed4
		virtual void Function_0015(); //#15 +3c .rdata:007a3ed8
	}; //Size: 0x0200

} }