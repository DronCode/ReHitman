#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZRenderObjectInstanceD3D
	{
	public:
		virtual void Function_0000();				//#0 +0x00 (.rdata:0076423C)
		virtual void draw(std::uintptr_t* context); //#1 +0x04 (.rdata:00764240)
		virtual bool Function_0002();				//#2 +0x08 (.rdata:00764244)
		virtual void Function_0003();				//#3 +0x0C (.rdata:00764248)
	};

} }