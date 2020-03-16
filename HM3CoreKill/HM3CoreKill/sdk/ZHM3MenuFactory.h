#pragma once

#include <cstdint>
#include <sdk/ZGUIBase.h>

namespace ioi { namespace hm3 {

	class ZHM3MenuFactory
	{
	public:
		virtual std::uintptr_t getZListInterfaceProviderByInterfaceName(const char* interfaceName); //#0 +0 .rdata:007a57c8
		virtual void Function_0001(); //#1 +4 .rdata:007a57cc
		virtual std::uintptr_t getOnlineWindowByName(const char* windowName, int unk1); //#2 +8 .rdata:007a57d0
		virtual ZGUIBase* getUIComponentByName(const char* componentName); //#3 +c .rdata:007a57d4
	};

}}