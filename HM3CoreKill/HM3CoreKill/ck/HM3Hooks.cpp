#include <ck/HM3Hooks.h>
#include <ck/HM3Game.h>
#include <ck/HM3Player.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Function.h>
#include <ck/HM3Direct3D.h>
#include <ck/HM3InGameTools.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3AnimationRegistry.h>
#include <ck/HM3DoorsRegistry.h>
#include <ck/HM3CutSequencesRegistry.h>
#include <ck/HM3FreeFileSystemLocatorProxy.h>
#include <ck/HM3GamepadSupport.h>

#include <sdk/ZMouseWintel.h>
#include <sdk/ZGameControlWintel.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZGameDataFactory.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZHM3Hitman3.h>

#include <windowsx.h>
#include <d3d9.h>

#ifdef HM3_TRACE_NATIVE_OBJECTS_CREATION_ENABLED
#define HM3_TRACE_NATIVE_OBJECT_CREATION(instance) HM3_DEBUG("[NativeObject<%s>::CTOR {TypeID is %d}|0x%.X] native object constructed\n", instance->m_runtimeTypeInfo->SelfType, instance->m_runtimeTypeInfo->TypeID, instance)
#else
#define HM3_TRACE_NATIVE_OBJECT_CREATION(instance)
#endif

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
	ck::HM3GamepadSupport::vibrate();
	return static_cast<int>(HM3Game::getInstance().GetPlayer()->isDoesAcceptDamage());
}

void __stdcall ZHM3Action_OnDropItem(DWORD pThis)
{
	ioi::hm3::ZLnkAction* action = (ioi::hm3::ZLnkAction*)pThis;
	HM3_DEBUG("[GameEvent|> THIS PTR at 0x%.8X] Drop item (%s)\n", pThis, action->GetActionName());
}

void __stdcall ZHM3Hitman3_Constructor(DWORD result)
{
	HM3Game::getInstance().OnNewGameSession(reinterpret_cast<ioi::hm3::ZHM3Hitman3*>(result));
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
	ck::HM3DoorsRegistry::getRegistry().reset();
	ck::HM3CutSequencesRegistry::getRegistry().reset();
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

DWORD m_ZMouseDeviceWintel__OnUpdateOrg = 0x0;
DWORD m_ZGameControllerWintel_OnUpdateOrg = 0x0;

DWORD __stdcall ZMouseWintel_OnUpdate()
{
	DWORD result = false;
	ck::HM3InGameTools& instance = ck::HM3InGameTools::getInstance();
	ioi::hm3::ZSysInputWintel* input = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
	ioi::hm3::ZMouseWintel* mouse = input->m_mouseDevice;

	__asm {
		mov ecx, mouse
		call [m_ZMouseDeviceWintel__OnUpdateOrg]
		mov result, eax
	}

	{
		instance.setMouseButtonState(0, mouse->m_leftButton);
		instance.setMouseButtonState(1, mouse->m_rightButton);
		instance.setMouseWheelState(mouse->m_wheel);
	}

	__asm mov ecx, mouse
	return result;
}

DWORD __stdcall ZGameController_OnUpdate()
{
	DWORD result = false;
	ck::HM3InGameTools& instance = ck::HM3InGameTools::getInstance();
	ioi::hm3::ZSysInputWintel* input = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
	ioi::hm3::ZGameControlWintel* controller = input->m_gameControllerDevice;

	__asm {
		mov ecx, controller
		call[m_ZGameControllerWintel_OnUpdateOrg]
		mov result, eax
	}

	//result = ck::HM3GamepadSupport::onDeviceUpdateRequest(controller);

	__asm mov ecx, controller
	return result;
}

void __stdcall OnZMouseWintelCreated(DWORD device)
{
	HM3_DEBUG("ZMouseWintel created at 0x%.8X\n", device);

	m_ZMouseDeviceWintel__OnUpdateOrg = HM3Function::hookVFTable(device, 26, (DWORD)ZMouseWintel_OnUpdate, true);
}

void __stdcall OnZGameControllerWintelCreated(DWORD device)
{
	HM3_DEBUG("ZGameControllerWintel created at 0x%.8X\n", device);
	//m_ZGameControllerWintel_OnUpdateOrg = HM3Function::hookVFTable(device, 26, (DWORD)ZGameController_OnUpdate, true);
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

void __stdcall CMapObject_OnCreate(ioi::hm3::CMapObject* instance)
{
	if (!instance)
		return;

	HM3_TRACE_NATIVE_OBJECT_CREATION(instance);
}

void __stdcall ZGlacier_OnSTDOBJAttached(DWORD* unknownInstance)
{
	if (!unknownInstance)
		return;

	ioi::hm3::ZGlacierRTTI* runtimeInfo = ioi::hm3::getTypeInfo(unknownInstance);
	if (!runtimeInfo)
		return;

	const std::string_view parentType = runtimeInfo->Parent;

	if (parentType == "ZGEOM")
	{
		const std::string_view instanceType = runtimeInfo->SelfType;
		const bool isTypeBasedOnDoorWord = instanceType.find("Door", 0) != std::string_view::npos;
		if (isTypeBasedOnDoorWord)
		{
			ioi::hm3::CDoor* instance = reinterpret_cast<ioi::hm3::CDoor*>(unknownInstance);
			ck::HM3DoorsRegistry::getRegistry().registerDoor(instance);
			return;
		}
	}
}

void __stdcall FsZip_Constructed(ioi::hm3::FsZip_t* instance)
{
	ck::HM3FreeFileSystemLocatorProxy* proxy = reinterpret_cast<ck::HM3FreeFileSystemLocatorProxy*>(instance);

	//proxy->m_missionZipFilePath = nullptr;
	//proxy->m_zipFilePath		= nullptr;

	HM3_DEBUG("FsZip_t created at 0x%.8X | Hook read() method\n", instance);
	HM3Function::hookVFTable(proxy, HM3Offsets::FsZip_ReadMethodIndex, &ck::HM3FreeFileSystemLocatorProxy::readFileProvider, false);
}

void __stdcall FsZip_Destructor(ioi::hm3::FsZip_t* instance)
{
	ck::HM3FreeFileSystemLocatorProxy* proxy = reinterpret_cast<ck::HM3FreeFileSystemLocatorProxy*>(instance);

	proxy->m_missionZipFilePath = nullptr;
	proxy->m_zipFilePath		= nullptr;

	// Just recover vftable here!
	HM3_DEBUG("FsZip_t restore vftable for at 0x%.8X\n", proxy);
	HM3Function::hookVFTable(reinterpret_cast<DWORD>(proxy), HM3Offsets::FsZip_ReadMethodIndex, HM3Offsets::FsZip_ReadMethodFunc, false); //restore back!
}

void __stdcall ZM13PosController_Constructor(ioi::hm3::ZM13PosController* instance)
{
	if (!instance)
		return;

	HM3_DEBUG("[ZM13PosController] created at 0x%.8X\n", instance);
}

void __stdcall ZCar_Constructor(ioi::hm3::ZCar* instance)
{
	if (!instance)
		return;

	HM3_DEBUG("[ZCar] constructed at 0x%.8X\n", instance);
}

void __stdcall CutSequence_Constructor(ioi::hm3::CCutSequence* instance)
{
	if (!instance)
		return;

	HM3_DEBUG("CutSequence| at 0x%.8X\n", instance);

	ck::HM3CutSequencesRegistry::getRegistry().registerCutSequence(instance);
}