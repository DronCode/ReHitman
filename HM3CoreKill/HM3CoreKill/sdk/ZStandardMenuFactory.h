#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {
	class ZStandardMenuFactory
	{
	public:
		virtual void Function_0000(); //#0 +0 .rdata:00780f6c
		virtual void Function_0001(); //#1 +4 .rdata:00780f70
		virtual void Function_0002(); //#2 +8 .rdata:00780f74
		virtual std::uintptr_t getMenuElementByName(const char* elementClassName); //#3 +c .rdata:00780f78
	};
}}