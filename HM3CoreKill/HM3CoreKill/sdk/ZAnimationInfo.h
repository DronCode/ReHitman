#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZHM3Hitman3;

	class ZAnimationInfo
	{
	public:
		int32_t m_id; //0x0000
		char pad_0004[56]; //0x0004
		char* m_name; //0x003C
	}; //Size: 0x0040

	typedef int(__thiscall* ZAnimationCallback_t)(ioi::hm3::ZHM3Hitman3*);

	enum ZAnimationStatus : uint32_t {
		Completed = 0x41200000
	};

	///General problem is ZAnimationCallback_t must be __thiscall. 
	static int setAnimationStatusChangedCallback(ZAnimationInfo** animation, ZAnimationStatus flags, ZAnimationCallback_t callback, int _u0 = 0, int _u1 = 0);
}}