#include <sdk/ZAnimationInfo.h>
#include <sdk/ZHM3Hitman3.h>

namespace ioi { namespace hm3 {

	int setAnimationStatusChangedCallback(ZAnimationInfo** animation, ZAnimationStatus flags, ZAnimationCallback_t callback, int _u0, int _u1)
	{
		typedef int(__thiscall* ZANIM_SetCallback_t)(ZAnimationInfo**, ZAnimationStatus, ZAnimationCallback_t, int, int);
		ZANIM_SetCallback_t ZANIM_SetCallback = (ZANIM_SetCallback_t)0x0058C0B0;
		return ZANIM_SetCallback(animation, flags, callback, _u0, _u1);
	}

}}