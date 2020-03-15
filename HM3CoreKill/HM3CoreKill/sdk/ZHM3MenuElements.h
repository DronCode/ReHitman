#pragma once

namespace ioi { namespace hm3 {

	class ZHM3MenuElements
	{
	public:
		/// === members ===
		uint32_t m_XMLGUISystem; //0x0004
		char pad_0008[56]; //0x0008

		/// === vftable ===
		virtual void Function_0();
		virtual void Function_1();
		virtual void Function_2();
		virtual void Function_3(const char* menuName);
		virtual void Function_4();
		virtual void Function_5();
	};

}}