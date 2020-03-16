#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZOnlineElements
	{
	public:
		virtual void getListInterfaceProviderByName(const char* interfaceName); //#0 +0 .rdata:007a7884
		virtual void getTableInterfaceProviderByName(const char* interfaceName); //#1 +4 .rdata:007a7888
		virtual void Function_0002(); //#2 +8 .rdata:007a788c
		virtual void getMenuByName(const char* menuName); //#3 +c .rdata:007a7890
	};

}}