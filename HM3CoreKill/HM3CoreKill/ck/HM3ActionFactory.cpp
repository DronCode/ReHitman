#include <ck/HM3ActionFactory.h>

#include <sdk/ZGameFunctions.h>
#include <utils/X86Snippets.h>

ioi::hm3::ZLnkAction* HM3ActionFactory::createActionByType(ioi::hm3::ZHM3Hitman3* hitman, ioi::hm3::ZLnkActionType actionType)
{
	ioi::hm3::ZLnkAction* result = nullptr;
	
	X86_SAVE_REGION

	__asm {
		push actionType
		mov ecx, hitman
		call ioi::hm3::CreateGameAction
		mov result, eax
	}

	X86_RESTORE_REGION

	return result;
}