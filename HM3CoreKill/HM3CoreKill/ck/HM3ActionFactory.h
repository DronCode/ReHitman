#pragma once

#include <cstdint>

#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3GameData.h>

class HM3ActionFactory
{
public:
	static ioi::hm3::ZLnkAction* createActionByType(ioi::hm3::ZHitman3* hitman, ioi::hm3::ZLnkActionType actionType);

	static ioi::hm3::ZLnkAction* createPhoningAction(ioi::hm3::ZHitman3* hitman)
	{
		//1. Create action
		//2. Fill fields (+16, +20)
		//3. Register in lvl ctl
		return nullptr;
	}
};