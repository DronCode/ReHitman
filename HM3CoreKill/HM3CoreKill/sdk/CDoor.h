#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class CDoor
	{
	public:
		std::uintptr_t m_prevEntity; //0x0004
		std::uintptr_t m_nextEntity; //0x0008
		int32_t m_unkOffset_0xC; //0x000C
		int32_t m_unkOffset_0x10; //0x0010
		int32_t m_unkOffset_0x14; //0x0014
		int32_t m_unkOffset_0x18; //0x0018
		int32_t m_unkOffset_0x1C; //0x001C
		int32_t m_unknown0; //0x0020
		ZSTDOBJ* m_doorSTD; //0x0024
		int32_t m_unkOffset_0x28; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
	}; //Size: 0x0030

}}