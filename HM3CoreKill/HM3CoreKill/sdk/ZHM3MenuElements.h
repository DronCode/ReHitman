#pragma once

#include <sdk/ZXMLGUISystem.h>
#include <sdk/ZHM3MenuFactory.h>
#include <sdk/ZStandardMenuFactory.h>
#include <sdk/ZOnlineElements.h>

namespace ioi { namespace hm3 {

	class ZHM3MenuElements
	{
	public:
		/// === members ===
		ZXMLGUISystem*			m_XMLGUISystem; //0x0004
		char					pad_0008[8196]; //0x0008
		ZStandardMenuFactory*	m_standardMenuFactory_1; //0x200C
		ZHM3MenuFactory*		m_hm3MenuFactory_1; //0x2010
		ZOnlineElements*		m_onlineElementsFactory; //0x2014
		char					pad_2018[8]; //0x2018
		ZStandardMenuFactory*	m_standardMenuFactory; //0x2020
		ZHM3MenuFactory*		m_hm3MenuFactory; //0x2024

		/// === vftable ===
		virtual void Function_0();
		virtual void Function_1();
		virtual void Function_2();
		virtual void Function_3(const char* menuName);
		virtual void Function_4();
		virtual void Function_5();
	};

}}