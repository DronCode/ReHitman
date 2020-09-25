#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZRenderMaterialSubClassD3D;

	class ZRenderBinderList
	{
	public:
		virtual void Function_0000(); //#0 +0x0 (.rdata:007627E8)
	};

	class ZRenderMaterialInstanceD3D
	{
	public:
		char* m_name; //0x0004
		ZRenderMaterialSubClassD3D* m_materialSubClass; //0x0008
		uint32_t m_params; //0x000C
		ZRenderBinderList* m_binders[18]; //0x0010
		int32_t m_unk0; //0x0058
		int32_t m_unk1; //0x005C

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
	}; //Size: 0x0060

} }