#include <ck/HM3Hooks.h>
#include <ck/HM3Game.h>
#include <ck/HM3Player.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Function.h>
#include <ck/HM3Direct3D.h>
#include <ck/HM3InGameTools.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3AnimationRegistry.h>

#include <sdk/ZMouseWintel.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZGameDataFactory.h>

#include <windowsx.h>
#include <d3d9.h>

LRESULT WINAPI Glacier_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	typedef LRESULT(__stdcall* GlacierWndProc_t)(HWND, UINT, WPARAM, LPARAM);
	GlacierWndProc_t glacierWndProc = (GlacierWndProc_t)HM3Offsets::Glacier_OriginalWNDPROC;

	if (ck::HM3InGameTools::getInstance().processEvent(hWnd, msg, wParam, lParam))
		return true;

	const bool glacierResult = glacierWndProc(hWnd, msg, wParam, lParam);

	return glacierResult; //if glacier returns false we must ignore that event
}

ATOM __stdcall RegisterClassExA_Hooked(WNDCLASSEXA* wndClass)
{
	HM3_DEBUG("Register window class with custom WndProc\n");
	wndClass->lpfnWndProc = Glacier_WndProc;
	return RegisterClassExA(wndClass);
}

HWND __stdcall CreateWindowExA_Hooked(
	DWORD dwExStyle,
	LPCSTR lpClassName,
	LPCSTR lpWindowName,
	DWORD dwStyle,
	int X,
	int Y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam)
{
	HWND result = CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	return result;
}

int __stdcall ZHM3Player_DoesPlayerAcceptAnyDamage(void* pThis)
{
	//HM3_DEBUG("ZHM3Player_DoesPlayerAcceptAnyDamage| ZHitman3 vftable instance at 0x%X", pThis);
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

void __stdcall ZPlayer_Destructor(DWORD instance)
{
	HM3_DEBUG("ZPlayer::~ZPlayer() at 0x%X\n", instance);
	
	// Free session base data
	ck::HM3AnimationRegistry::getRegistry().reset();
}

void __stdcall ZDirect3DDevice_OnDeviceReady(ioi::hm3::ZDirect3DDevice* device)
{
	HM3_DEBUG("ZDirect3DDevice::ZDirect3DDevice() device ready at 0x%.8X\n", device);
	HM3_DEBUG(" [+0x04] m_device  at 0x%.8X\n", device->m_d3dDevice);
	HM3_DEBUG(" [+0x08] m_unknown at 0x%.8X\n", device->m_unknown);

	ck::HM3Direct3D::getInstance().initialize(device->m_d3dDevice);
	HM3_DEBUG(" D3D9 Hooked\n");
}

/// --------------------------------------------------------------------------------

DWORD originalMember = 0x0;

DWORD __stdcall ZMouseWintel_OnUpdate()
{
	DWORD result = false;
	ioi::hm3::ZSysInputWintel* input = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
	ioi::hm3::ZMouseWintel* mouse = input->m_mouseDevice;

	__asm {
		mov ecx, mouse
		call [originalMember]
		mov result, eax
	}

	{
		ck::HM3InGameTools& instance = ck::HM3InGameTools::getInstance();

		instance.setMouseButtonState(0, mouse->m_leftButton);
		instance.setMouseButtonState(1, mouse->m_rightButton);
		instance.setMouseWheelState(mouse->m_wheel);
	}

	__asm mov ecx, mouse
	return result;
}

void __stdcall OnZMouseWintelCreated(DWORD device)
{
	HM3_DEBUG("ZMouseWintel created at 0x%.8X\n", device);

	originalMember = HM3Function::hookVFTable(device, 26, (DWORD)ZMouseWintel_OnUpdate, true);
}

void __stdcall ZHM3_OnAnimationLoaded(ioi::hm3::ZAnimationInfo* animationInstance)
{
	auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
	if (!gameData || !gameData->m_LevelControl)
	{
		/*
		 * @brief Here we must know that we have an active mission before register new animation.
		 *        The main menu trying to load animations too, but that animations will be invalidated in missions and our cache could be poisoned by us.
		 */
		return;
	}

	if (animationInstance)
	{		
		ck::HM3AnimationRegistry::getRegistry().registerAnimation(animationInstance);
	}
}