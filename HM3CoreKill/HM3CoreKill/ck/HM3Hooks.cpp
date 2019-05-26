#include <ck/HM3Hooks.h>
#include <ck/HM3Game.h>
#include <ck/HM3Player.h>
#include <ck/HM3DebugConsole.h>

#include <sdk/ZLnkAction.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZGameDataFactory.h>

void __stdcall ZHM3WndProc_Hook(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (Msg == WM_KEYDOWN)
		HM3Game::getInstance().OnKeyPress(static_cast<uint32_t>(wParam));
	
	if (Msg == WM_KEYUP)
		HM3Game::getInstance().OnKeyRelease(static_cast<uint32_t>(wParam));
}

int __stdcall ZHM3Player_DoesPlayerAcceptAnyDamage(void* pThis)
{
	return static_cast<int>(HM3Game::getInstance().GetPlayer()->isDoesAcceptDamage());
}

void __stdcall ZHM3Action_OnDropItem(DWORD pThis)
{
	ioi::hm3::ZLnkAction* action = (ioi::hm3::ZLnkAction*)pThis;
	HM3_DEBUG("[GameEvent|> THIS PTR at 0x%.8X] Drop item (%s)\n", pThis, action->GetActionName());
}

void __stdcall ZHM3Hitman3_Constructor(DWORD result)
{
	HM3Game::getInstance().OnNewGameSession((ioi::hm3::ZHM3Hitman3_t)result);
}