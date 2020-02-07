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

#include <sdk/HM3DebugAPI.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZSTD.h>

#include <functional>
#include <algorithm>

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
	setupHookZPlayerConstructor();

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

#define BOOL_TO_STR(b) (b ? "True" : "False")

void HM3Game::printActorsPoolInfos()
{
	auto gameData = GetGameDataInstancePtr();
	if (!gameData)
		return;

	HM3_DEBUG("Total actors count is %.4d\n", gameData->m_ActorsInPoolCount);

	for (int actorIndex = 0; actorIndex < gameData->m_ActorsInPoolCount; actorIndex++)
	{
		auto location = gameData->m_ActorsPool[actorIndex]->ActorInformation->location;
		HM3_DEBUG("Actor[%.4d] at 0x%.8X | name %.50s location at 0x%.8X ; position Vec3 { %.8f; %.8f; %.8f } ; is member of group 0x%.8X\n", 
			actorIndex, 
			gameData->m_ActorsPool[actorIndex], 
			location->entityName, 
			location,
			location->position.x, 
			location->position.y, 
			location->position.z, 
			location->group);
	}
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

void HM3Game::OnNewGameSession(ioi::hm3::ZHM3Hitman3_t gameSession)
{
	HM3_DEBUG("[HM3Game::OnNewGameSession] New session instance detected at 0x%.8X\n", gameSession);
	{
		auto gd = GetGameDataInstancePtr();
		//HM3_DEBUG(" [BriefControl at 0x%.8X Camera at 0x%.8X ]\n", gd->m_BriefingControl, gd->m_Camera);
	}
	printActorsPoolInfos();
}

const HM3Player::Ptr& HM3Game::GetPlayer() const { return m_currentPlayer; }

std::uintptr_t HM3Game::GetCurrentLevelController() const
{
	std::uintptr_t pGameData = reinterpret_cast<std::uintptr_t>(*(void**)ioi::hm3::GameData);
	return reinterpret_cast<std::uintptr_t>(*((void**)(pGameData + HM3Offsets::ZHM3LevelControllerOffset)));
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

void HM3Game::setupHookZPlayerConstructor()
{
	HM3Function::hookFunction<void(__stdcall*)(DWORD), 13>(
		HM3_PROCESS_NAME, 
		(DWORD)HM3Offsets::ZPlayer_Constructor, 
		(DWORD)ZPlayer_Constructor, 
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
