#include <ck/HM3Game.h>

#include <ck/HM3ActionFactory.h>
#include <ck/HM3DebugConsole.h>
#include <utils/X86Snippets.h>
#include <ck/HM3InGameTools.h>
#include <ck/HM3Function.h>
#include <ck/HM3Direct3D.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3Hooks.h>
#include <ck/Features.h>

#include <sdk/ZGameGlobals.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZSTD.h>
#include <sdk/ZAnimationInfo.h>

#include <functional>
#include <algorithm>

#define HM3_BUILDSTR "blood-build3-20060616-26123"

HM3Game::HM3Game()
	: m_currentPlayer(std::make_shared<HM3Player>())
{
}

HM3Game& HM3Game::getInstance()
{
	static HM3Game instance;
	return instance;
}

void __stdcall OnTeleportsListLoaded_Callback(DWORD R1)
{
	HM3_DEBUG("[ result at 0x%X ]\n", R1);
}

void __stdcall ShowWindowRequest()
{
	HM3_DEBUG("Require show window with HWND is 0x%.8X\n", HM3Game::GetSystemInterface()->m_renderer->m_HWND);
	ShowWindow(HM3Game::GetSystemInterface()->m_renderer->m_HWND, SW_SHOW);
}

void HM3Game::Initialise()
{
	if (!checkBuildVersion())
	{
		MessageBox(nullptr, "This version of Hitman Blood Money not supported by ReHitman.\nGame will works in normal mode.", "Version not supported", MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	HM3DebugConsole::init();

	HM3_DEBUG(
		" _  _ ______ \n"
		"| || |____  |\n"
		"| || |_  / / \n"
		"|__   _|/ /  \n"
		"   | | / /   \n"
		"   |_|/_/    \n"
		"\n"
		"Core Kill\n");

	setupD3DDeviceCreationHook();
	fixEnableCheats();
	setupInputWatcher();	///Make bugs, DO NOT USE IT
	setupDoesPlayerAcceptDamage();
	setupHookToNewSessionInstanceCreator();
	//setupHookZGEOMObjectConstructor();
	setupHookZPlayerDestructor();
	patchFreeBeamHere();
	setupLoadAnimationHook();
	setupNativeObjectsCreationHooks();
	setupOnSTDOBJAttachedHook();
	setupFsZipHook();

	/*
	
	sub_4E6AF0 <- Add resource frontend
sub_4E7770
sub_50C620 <- very interesting too but not used in action
sub_502A80 interesting
sub_502A80

//                                                    * (IDUNNO)
005FC331 -> (ZHM3Actor) sub_516960 - Apply animation (+1F4) : {animPtr}, {loopsCount}, {?}, {?}
==============================


		sub_45DD10(ZEngineDataBase* pThis, ZPackedInput* pPackedInput, DWORD pEntity)
			|
			*
		sub_459B80(ZPackedInput* pThis, ZCheckDistance* pDistanceChecker)


		sub_5EFC00 - preload animations into ZHitman3
	*/

	HM3_DEBUG("----------------< GAME STARTED >----------------\n");
	m_isHackActive = true;
}

void HM3Game::Run()
{
	while (m_isHackActive) {}
}

void HM3Game::DestroyHack()
{
	m_isHackActive = false;
}

bool HM3Game::IsActive() const
{
	return m_isHackActive;
}

void HM3Game::hackActorsForAllDead() {
	const std::uintptr_t addrBegin = 0x00504A20;
	// the original code is 8A 91 E2 05 00 00 33 C0 84 D2 0F 94 C0
	
	HM3_DEBUG("----< Try to hack actor's alive getter to always false >----\n");
	
	/*HM3Function::overrideInstruction(HM3_PROCESS_NAME, addrBegin, {
		//0x31, 0xC0, 0xC3, 
		0xB8, 0xFF, 0x00, 0x00, 0x00, 0xC3,
		0x90, 0x90, 0x90, 
		0x90, 0x90, 0x90, 
		//0x90, 0x90, 0x90, 
		0x90
	});*/

	HM3Function::overrideInstruction(HM3_PROCESS_NAME, addrBegin, {
		//8A 91 E2 05 00 00 33 C0 84 D2 0F 94 C0
		//C7 81 E2 05 00 00 03 00 00 00 31 C0 C3
		0xC7, 0x81, 0xE2, 0x05, 
		0x00, 0x00, 0x02, 0x00, 
		0x00, 0x00, 0x31, 0xC0, 
		0xC3
	});
}

void HM3Game::fixEnableCheats()
{
	DWORD toNop = 0x00448312;
	DWORD toFix = 0x00448316;

	HM3Function::overrideInstruction(HM3_PROCESS_NAME, toNop, { 0x90, 0x90, 0x90, 0x90 });
	HM3Function::overrideInstruction(HM3_PROCESS_NAME, toFix, { 0xC6, 0x05, 0x89, 0xCA, 0x8A, 0x00, 0x01 });
	HM3_DEBUG(" + Enable cheats menu\n");
}

void HM3Game::setupD3DDeviceCreationHook()
{
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 10>(
		HM3_PROCESS_NAME,
		HM3Offsets::ZDirect3DDevice_ConstructorFunc,
		(DWORD)ZDirect3DDevice_OnDeviceReady,
		// pre
		{
			/*
				pushad
				pushfd
				push eax ; it's contains pointer to result structure
			*/
			x86_pushad,
			x86_pushfd,
			x86_push_eax
		},
		// post
		{
			/*
				popfd
				popad
			*/
			x86_popfd,
			x86_popad
		});
	HM3_DEBUG("[Setup ZDirect3DDevice hook]\n");

	HM3Function::hookFunction<void(__stdcall*)(DWORD), 5>(
		HM3_PROCESS_NAME, 
		HM3Offsets::ZWintelMouse_ContructorFunc,
		(DWORD)OnZMouseWintelCreated, 
		// pre
		{
			x86_pushad,
			x86_pushfd,
			x86_push_eax
		}, 
		// post
		{
			x86_popfd,
			x86_popad
		});

	ck::HM3Direct3D::getInstance().onD3DReady	= std::bind(&HM3Game::onD3DInitialized, this, std::placeholders::_1);
	ck::HM3Direct3D::getInstance().onBeginScene	= std::bind(&HM3Game::onD3DBeginScene, this, std::placeholders::_1);
	ck::HM3Direct3D::getInstance().onEndScene	= std::bind(&HM3Game::onD3DEndScene, this, std::placeholders::_1);
}

void HM3Game::patchFreeBeamHere()
{
	HM3Function::overrideInstruction(HM3_PROCESS_NAME, HM3Offsets::ZHM3CheatMenu_BeamHereFuncPatch, { 0x90, 0x90 });
}

void HM3Game::setupLoadAnimationHook()
{
	HM3Function::overrideInstruction(HM3_PROCESS_NAME, HM3Offsets::ZHM3AnimationManager_Pre_OnLoadAnimation, { 0x90, 0x90, 0x90 });

	HM3Function::hookFunction<void(__stdcall)(ioi::hm3::ZAnimationInfo*), 5>(
		HM3_PROCESS_NAME,
		HM3Offsets::ZHM3AnimationManager_OnLoadAnimation,
		(DWORD)ZHM3_OnAnimationLoaded,
		{
			x86_pushad,
			x86_pushfd,
			x86_push_eax
		},
		{
			x86_popfd,
			x86_popad,
			x86_ret_4
		});
}

void HM3Game::setupNativeObjectsCreationHooks()
{
	// CMapObject::ctor ending (with runtime infos)
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 11>(
		HM3_PROCESS_NAME,
		HM3Offsets::CMapObject_ConstructorEnding,
		(DWORD)CMapObject_OnCreate,
		{
			x86_pushad,
			x86_pushfd,
			x86_push_eax
		}, {
			x86_popfd,
			x86_popad
		});
}

void HM3Game::setupOnSTDOBJAttachedHook()
{
	//OnDoorCreated
	HM3Function::moveInstructions<5>(HM3_PROCESS_NAME, HM3Offsets::Global_OnAttachSTDOBJ_OrgEnding, HM3Offsets::Global_OnAttachSTDOBJ_NewEnding);	//Move original ending by 5 bytes next
	HM3Function::overrideInstruction(HM3_PROCESS_NAME, HM3Offsets::Global_OnAttachSTDOBJ_OrgEnding, { 0x90, 0x90, 0x90, 0x90, 0x90 });				//Use free space as our jump space
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 5>(
		HM3_PROCESS_NAME,
		HM3Offsets::Global_OnAttachSTDOBJ_OrgEnding,
		(DWORD)ZGlacier_OnSTDOBJAttached,
		{
			x86_pushad,
			x86_pushfd,
			x86_push_edi
		},
		{
			x86_popfd,
			x86_popad
		});
}

void HM3Game::setupFsZipHook()
{
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 10>(
		HM3_PROCESS_NAME,
		HM3Offsets::FsZip_Constructor,
		(DWORD)FsZip_Constructed,
		{
			x86_pushad,
			x86_pushfd,
			x86_push_eax
		},
		{
			x86_popfd,
			x86_popad
		});
}

void HM3Game::onD3DInitialized(IDirect3DDevice9* device)
{
	const auto renderer = GetSystemInterface()->m_renderer;

	ck::HM3InGameTools::getInstance().initialize(renderer->m_HWND, device);
}

void HM3Game::onD3DBeginScene(IDirect3DDevice9* device)
{
	HM3_UNUSED(device)
}

void HM3Game::onD3DEndScene(IDirect3DDevice9* device)
{
	HM3_UNUSED(device)
	ck::HM3InGameTools::getInstance().draw();
}

void HM3Game::OnNewGameSession(ioi::hm3::ZHM3Hitman3* gameSession)
{
	HM3_DEBUG("[HM3Game::OnNewGameSession] New session instance detected at 0x%.8X\n", gameSession);
}

const HM3Player::Ptr& HM3Game::GetPlayer() const { return m_currentPlayer; }

std::uintptr_t HM3Game::GetCurrentLevelController() const
{
	std::uintptr_t pGameData = reinterpret_cast<std::uintptr_t>(*(void**)ioi::hm3::GameData);
	return reinterpret_cast<std::uintptr_t>(*((void**)(pGameData + HM3Offsets::ZHM3LevelControllerOffset)));
}

bool HM3Game::checkBuildVersion()
{
	const char* buildString = reinterpret_cast<const char*>(HM3Offsets::HM3_BuildString);

	return (strcmp(buildString, HM3_BUILDSTR) == 0);
}

void HM3Game::setupInputWatcher()
{
	HM3Function::overrideInstruction(HM3_PROCESS_NAME, HM3Offsets::ZHM3RegisterWindowClassExA_Func, { x86_nop, x86_nop, x86_nop, x86_nop, x86_nop, x86_nop });
	HM3Function::hookFunction<bool(__stdcall*)(const WNDCLASSEXA*), 6>(HM3_PROCESS_NAME, HM3Offsets::ZHM3RegisterWindowClassExA_Func, (DWORD)RegisterClassExA_Hooked, {}, {});

	HM3Function::overrideInstruction(HM3_PROCESS_NAME, 0x00453EC6, { x86_nop, x86_nop, x86_nop, x86_nop, x86_nop, x86_nop });
	HM3Function::hookFunction<HWND(__stdcall*)(DWORD dwExStyle, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID), 6>(HM3_PROCESS_NAME, 0x00453EC6, (DWORD)CreateWindowExA_Hooked, {}, {});
}

void HM3Game::setupDoesPlayerAcceptDamage()
{
	HM3Function::hookFunction<
		int(__stdcall*)(void*),
		10
	>(
		HM3_PROCESS_NAME, 
		HM3Offsets::HM3ZPlayer_DoesPlayerAcceptDamage,
		(DWORD)ZHM3Player_DoesPlayerAcceptAnyDamage,
		/*
			Before call hook
		 */
		{
			x86_push_ecx, 
			x86_push_ecx
		},
		/*
			After call hook
		*/
		{
			x86_pop_ecx
		});
}

void HM3Game::setupHookToNewSessionInstanceCreator()
{
	HM3Function::moveInstructions<4>(
		HM3_PROCESS_NAME, 
		(DWORD)HM3Offsets::HM3ZHitman3_FactoryMethodCall, 
		(DWORD)HM3Offsets::HM3ZHitman3_FactoryMethodCall + 5);	//Free space for us
	HM3Function::overrideInstruction(
		HM3_PROCESS_NAME, 
		(DWORD)HM3Offsets::HM3ZHitman3_FactoryMethodCall, 
		{ 0x90, 0x90, 0x90, 0x90, 0x90 });						//Fill old code to NOP's
	HM3Function::hookFunction<
		void(__stdcall*)(DWORD)
	>(
		HM3_PROCESS_NAME, 
		(DWORD)0x00604CF1, 
		(DWORD)ZHM3Hitman3_Constructor,
		{
			x86_push_ecx,		///Save old ECX (pThis)
			x86_push_eax,		///Save old EAX
			x86_push_eax		///Store pointer to ZHM3Hitman instance
		}, 
		{
			x86_pop_eax,		///Restore EAX
			x86_pop_ecx			///Restore ECX
		});														//Prepare our hook function
}

void HM3Game::setupHookZGEOMObjectConstructor()
{
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 6>(HM3_PROCESS_NAME, (DWORD)HM3Offsets::ZGEOM_Constructor, (DWORD)ZGEOM_Ctor_CALLBACK, {
		// pre code
		// pushad
		// pushfd
		// push ecx
		0x60, 0x9C,
		0x51
		}, {

			// post code
			// popfd
			// popad
			//0x83, 0xC4, 0x04,
			0x9D, 0x61
		});
}

void HM3Game::setupHookZPlayerDestructor()
{
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 13>(
		HM3_PROCESS_NAME, 
		(DWORD)HM3Offsets::ZPlayer_Constructor, 
		(DWORD)ZPlayer_Destructor, 
		{
			// pre code
			// pushad
			// pushfd
			// push ecx
			0x60, 0x9C,
			0x51
		}, {

			// post code
			// popfd
			// popad
			0x9D, 0x61
		});
}

ioi::hm3::ZHM3GameData* HM3Game::GetGameDataInstancePtr()
{
	return ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
}

ioi::hm3::ZSysInterfaceWintel* HM3Game::GetSystemInterface()
{
	return ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
}
