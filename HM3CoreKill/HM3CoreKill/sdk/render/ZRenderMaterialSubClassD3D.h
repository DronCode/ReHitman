#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {
	class ZRenderMaterialSubClassD3D
	{
	public:
		virtual void Function_0000(); //#0 +0 .rdata:007642ac
		virtual void Function_0001(); //#1 +4 .rdata:007642b0
		virtual void Function_0002(); //#2 +8 .rdata:007642b4
		virtual void Function_0003(); //#3 +c .rdata:007642b8
		virtual void Function_0004(); //#4 +10 .rdata:007642bc
		virtual void Function_0005(); //#5 +14 .rdata:007642c0
		virtual int  draw(std::uintptr_t* materialInstance, std::uintptr_t* context); //#6 +18 .rdata:007642c4 [render]
		virtual void Function_0007(); //#7 +1c .rdata:007642c8
		virtual void Function_0008(); //#8 +20 .rdata:007642cc
		virtual void Function_0009(); //#9 +24 .rdata:007642d0
		virtual void Function_0010(); //#10 +28 .rdata:007642d4 [pure]
		virtual void Function_0011(); //#11 +2c .rdata:007642d8
		virtual void Function_0012(); //#12 +30 .rdata:007642dc
		virtual void Function_0013(); //#13 +34 .rdata:007642e0
		virtual void Function_0014(); //#14 +38 .rdata:007642e4
	};
} }