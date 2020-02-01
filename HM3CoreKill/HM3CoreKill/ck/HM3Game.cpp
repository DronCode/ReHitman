#include <ck/HM3Game.h>

#include <ck/HM3DebugConsole.h>
#include <ck/HM3VFTableHook.h>
#include <ck/HM3Function.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3Hooks.h>

#include <utils/X86Snippets.h>

#include <sdk/HM3DebugAPI.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/InterfacesProvider.h>
#include <ck/HM3ActionFactory.h>
#include <ck/Features.h>

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

void HM3Game::OnKeyPress(uint32_t keyCode)
{
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
			location->actorName, 
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

void HM3Game::OnKeyRelease(uint32_t keyCode)
{
	if (keyCode == VK_F3)
	{
		ck::completeLevel();
	}

	if (keyCode == VK_F4)
	{
		printActorsPoolInfos();
	}

	if (keyCode == VK_F5)
	{
		const bool newGodModeValue = !m_currentPlayer->isDoesAcceptDamage();
		HM3_DEBUG("God mode: %s\n", (newGodModeValue ? "ON" : "OFF"));
		m_currentPlayer->setDoesAcceptDamage(newGodModeValue);
	}

	if (keyCode == VK_F6)
	{
		HM3_DEBUG(" [ current scene is %s | engine db at 0x%X | render instance at 0x%X ]\n", GetSystemInterface()->m_currentScene, GetSystemInterface()->m_engineDataBase, GetSystemInterface()->m_renderer);
	}

	if (keyCode == VK_F7)
	{
		ck::teleportPlayer();
	}

	if (keyCode == VK_F8)
	{
		ck::printTeleportPointsInCurrentLevel();
	}

	if (keyCode == VK_F9)
	{
		ck::setTeleportPointForAllTeleports(500.f, 500.f, 500.f);
	}
}

void HM3Game::OnNewGameSession(ioi::hm3::ZHM3Hitman3_t gameSession)
{
	HM3_DEBUG("[HM3Game::OnNewGameSession] New session instance detected at 0x%.8X\n", gameSession);
	printActorsPoolInfos();
	/*HM3_DEBUG("[HM3Game::OnNewGameSession] Try to enable camera hack");
	
	auto gameDataPtr = GetGameDataInstancePtr();
	auto cameraPtr = gameDataPtr->m_Camera;

	HM3_DEBUG(
		"MVP matrix : \n"
		"| %.4f %.4f %.4f %.4f |\n"
		"| %.4f %.4f %.4f %.4f |\n"
		"| %.4f %.4f %.4f %.4f |\n"
		"| %.4f %.4f %.4f %.4f |\n",
		cameraPtr->MVP[ 0], cameraPtr->MVP[ 1], cameraPtr->MVP[ 2], cameraPtr->MVP[ 3],
		cameraPtr->MVP[ 4], cameraPtr->MVP[ 5], cameraPtr->MVP[ 6], cameraPtr->MVP[ 7],
		cameraPtr->MVP[ 8], cameraPtr->MVP[ 9], cameraPtr->MVP[10], cameraPtr->MVP[11],
		cameraPtr->MVP[12], cameraPtr->MVP[13], cameraPtr->MVP[14], cameraPtr->MVP[15]
	);*/
}

const HM3Player::Ptr& HM3Game::GetPlayer() const { return m_currentPlayer; }

std::uintptr_t HM3Game::GetCurrentLevelController() const
{
	std::uintptr_t pGameData = reinterpret_cast<std::uintptr_t>(*(void**)ioi::hm3::GameData);
	return reinterpret_cast<std::uintptr_t>(*((void**)(pGameData + HM3Offsets::ZHM3LevelControllerOffset)));
}

void HM3Game::setupInputWatcher()	//Slow, do not use that (crashes M13)
{
	HM3Function::hookFunction<
		void(__stdcall*)(HWND, UINT, WPARAM, LPARAM),
		18
	>(
		HM3_PROCESS_NAME,
		"\x55\x8B\x6C\x24\x10\x56\x8B\x74\x24\x10\x83\xFE\x07\x57",
		"xxxxxxxxxxxxxx",
		(DWORD)ZHM3WndProc_Hook,
		/*
			After trampoline & before hook call
		 */
		{
			x86_push_ecx,				// Save ECX
			0x8B, 0x4C, 0x24, 0x1C,		// mov  ecx,DWORD PTR [esp+0x1c]
			x86_push_ecx,				// Store ECX to our func
			x86_push_ebp,				// Store EBP to our func
			x86_push_esi,				// Store ESI to our func
			x86_push_edi				// Store EDI to our func
		},
		/*
			After hook call & before jump back
		*/
		{
			x86_pop_ecx					// Restore ECX
		}
	);
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
