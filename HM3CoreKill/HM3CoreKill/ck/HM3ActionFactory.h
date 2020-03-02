#pragma once

#include <cstdint>

#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3GameData.h>

class HM3ActionFactory
{
public:
	static ioi::hm3::ZLnkAction* createActionByType(ioi::hm3::ZHM3Hitman3* hitman, ioi::hm3::ZLnkActionType actionType);
};