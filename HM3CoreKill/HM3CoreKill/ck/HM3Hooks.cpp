#include <ck/HM3Hooks.h>
#include <ck/HM3Game.h>
#include <ck/HM3Player.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Function.h>
#include <ck/HM3Direct3D.h>

#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZGameDataFactory.h>
#include <ck/HM3InGameTools.h>

#include <d3d9.h>

LRESULT WINAPI Glacier_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	typedef LRESULT(__stdcall* GlacierWndProc_t)(HWND, UINT, WPARAM, LPARAM);
	GlacierWndProc_t glacierWndProc = (GlacierWndProc_t)0x004513E0;

	if (ck::HM3InGameTools::getInstance().processEvent(hWnd, msg, wParam, lParam))
		return true;

	return glacierWndProc(hWnd, msg, wParam, lParam);
}

ATOM __stdcall RegisterClassExA_Hooked(WNDCLASSEXA* wndClass)
{
	HM3_DEBUG("Register window class with custom WndProc\n");
	wndClass->lpfnWndProc = Glacier_WndProc;
	return RegisterClassExA(wndClass);
}

int __stdcall ZHM3Player_DoesPlayerAcceptAnyDamage(void* pThis)
{
	HM3_DEBUG("ZHM3Player_DoesPlayerAcceptAnyDamage| ZHitman3 vftable instance at 0x%X", pThis);
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

void __stdcall ZGEOM_Ctor_CALLBACK(DWORD ptr)
{
	HM3_DEBUG("ZGEOM::ZGEOM() at 0x%X\n", ptr);
}

void __stdcall ZPlayer_Constructor(DWORD instance)
{
	HM3_DEBUG("ZPlayer::ZPlayer() at 0x%X\n", instance);
}

void __stdcall ZDirect3DDevice_OnDeviceReady(ioi::hm3::ZDirect3DDevice* device)
{
	HM3_DEBUG("ZDirect3DDevice::ZDirect3DDevice() device ready at 0x%.8X\n", device);
	HM3_DEBUG(" [+0x04] m_device  at 0x%.8X\n", device->m_d3dDevice);
	HM3_DEBUG(" [+0x08] m_unknown at 0x%.8X\n", device->m_unknown);

	ck::HM3Direct3D::getInstance().initialize(device->m_d3dDevice);
	HM3_DEBUG(" D3D9 Hooked\n");
}