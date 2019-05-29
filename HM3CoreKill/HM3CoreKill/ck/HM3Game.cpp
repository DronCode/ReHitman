#include <ck/HM3Game.h>

#include <ck/HM3DebugConsole.h>
#include <ck/HM3VFTableHook.h>
#include <ck/HM3Function.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3Hooks.h>

#include <x86/X86Snippets.h>

#include <sdk/HM3DebugAPI.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/InterfacesProvider.h>

/// PRIVATE (TODO: Move into external file)
int __stdcall OnParameterRequestFilterCallback(char* key)
{
	if (!key)
		return 0;

	auto gmsLen = strlen(".gms");
	auto len = strlen(key);

	if (strcmp(key + (len - gmsLen), ".gms") == 0)
	{
		HM3_DEBUG("Check value '%s' < FOUND\n", key);
		return 1;
	}
	else
	{
		HM3_DEBUG("Check value '%s' < IGNORE\n", key);
	}
	return 0;
}

static const DWORD backJump = HM3Offsets::HM3ZIniParserOnGetValue + 5;
static DWORD g_ignoredParameterValue;
static const char* GMS_VAL = "M04/M04_main.gms\0";

void __declspec(naked) ZHM3_GetIniParameter_Trampoline()
{
	__asm {
		mov g_ignoredParameterValue, eax		// Save value of eax into temp variable

		push eax								// Send EAX as argument to us
		call OnParameterRequestFilterCallback	// Call our 'detector' function
		test eax, eax							// Check result of detector (is eax == 0)
		jz __ignore_and_restore__				// Detector tell 4 us that incoming value NOT scene name and we must jump to __ignore_and_restore__ label
		mov eax, GMS_VAL						// Otherwise put our 'NEW' value into EAX
		jmp __only_exit__						// Jump to exit

		__ignore_and_restore__ :				// Restore point
		mov eax, g_ignoredParameterValue		// Move back 'valid' value
			__only_exit__ :						// Quit point
		jmp dword ptr[backJump]					// Restore control back to process
	}
}

/// -------------------------------------------------------

HM3Game::HM3Game()
	: m_currentPlayer(std::make_shared<HM3Player>())
{
}

HM3Game& HM3Game::getInstance()
{
	static HM3Game instance;
	return instance;
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

	//setupInputWatcher();	///Make bugs, DO NOT USE IT
	setupDoesPlayerAcceptDamage();
	//setupDropItemAction();	//In some cases (M04) we can get the crash here
	//setupOverrideStartupGMSScriptPath();	/// Override path to GMS
	setupNoVideoMode();
	setupHookToNewSessionInstanceCreator();

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

void HM3Game::CompleteCurrentLevel()
{
	auto lvlController = GetCurrentLevelController();
	if (!lvlController)
	{
		HM3_DEBUG("HM3Game::CompleteCurrentLevel| No active level to complete!\n");
		return;
	}

	bool hasAnyNotCompletedTargets = HasAnyUnCompletedTargets();

	HM3_DEBUG("HM3Game::CompleteCurrentLevel| Any not completed targets : %c\n", (hasAnyNotCompletedTargets ? 'Y' : 'N'));
}

bool HM3Game::HasAnyUnCompletedTargets() const
{
	auto lvlController = GetCurrentLevelController();
	if (!lvlController)
	{
		HM3_DEBUG("HM3Game::HasAnyUnCompletedTargets| No active level controller!\n");
		return false;
	}

	return (*((bool(__stdcall*)(int, int))HM3Offsets::ZHM3LevelControllerHasAnyUnCompletedTargets))(1, 0);
}

void HM3Game::OnKeyPress(uint32_t keyCode)
{
}

void HM3Game::OnKeyRelease(uint32_t keyCode)
{
	if (keyCode == VK_F5)
	{
		const bool newGodModeValue = !m_currentPlayer->isDoesAcceptDamage();
		HM3_DEBUG("God mode: %s\n", (newGodModeValue ? "ON": "OFF"));
		m_currentPlayer->setDoesAcceptDamage(newGodModeValue);
	}
	if (keyCode == VK_F9)	// Debug color (remove in future)
	{
		glacier::hm3::DebugColorReference(0, RGB(1, 1, 1), GetModuleHandle(0));
	}
	if (keyCode == VK_F6)
	{
		auto session = GetGameDataInstancePtr();
		if (!session)
		{
			HM3_DEBUG("No active game session!\n");
			return;
		}

		HM3_DEBUG(" *** COMMON INFO ***\n");
		HM3_DEBUG("Save name      : '%s'\n", session->m_ProfileName);
		HM3_DEBUG("Player money   : %d\n", session->m_PlayerMoney);
		HM3_DEBUG(" *** GAMEPLAY CAMERA: ***\n");
		if (session->m_Camera)
		{
			HM3_DEBUG("Camera Z scale : %f\n", session->m_Camera->m_ZCamOffset);
			session->m_Camera->m_ZCamOffset = 0.1f;
		}
		else
		{
			HM3_DEBUG("(No active camera!)\n");
		}
	}
}

void HM3Game::OnNewGameSession(ioi::hm3::ZHM3Hitman3_t gameSession)
{
	HM3_DEBUG("[HM3Game::OnNewGameSession] New session instance detected at 0x%.8X\n", gameSession);
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

void HM3Game::setupDropItemAction()
{
	HM3Function::hookFunction<
		void(__stdcall*)(DWORD),
		11
	>(
		HM3_PROCESS_NAME,
		"\x56\x8B\xF1\x8B\x4E\x0C\x8B\x01\xFF\x50\x0C",
		"xxxxxxxxxxx",
		(DWORD)ZHM3Action_OnDropItem,
		{
			x86_push_eax,
			x86_push_esi
		},
		{
			x86_pop_eax
		});
}

void HM3Game::setupOverrideStartupGMSScriptPath()
{
	x86::X86NearJumpCommit_t customJump;
	customJump.JMP_TO = x86::calculateOffset(
		(DWORD)ZHM3_GetIniParameter_Trampoline, 
		HM3Offsets::HM3ZIniParserOnGetValue, 
		sizeof(customJump)
	);

	std::vector<uint8_t> pCommit(sizeof(customJump) + 0x03);	//Raw data; first 5 bytes - jmp, other 3 bytes - retn 4
	memcpy(pCommit.data(), (void*)& customJump, sizeof(customJump));
	*(pCommit.data() + sizeof(customJump) + 0x00) = 0xC2;		//RETN
	*(pCommit.data() + sizeof(customJump) + 0x01) = 0x04;		//4
	*(pCommit.data() + sizeof(customJump) + 0x02) = 0x00;		//

	HM3Function::overrideInstruction(HM3_PROCESS_NAME, (DWORD)0x0042636F, pCommit);
}

void HM3Game::setupNoVideoMode()
{
	HM3Function::overrideInstruction(
		HM3_PROCESS_NAME,
		(DWORD)HM3Offsets::HM3ZBinkVideo_OpenFromFile_PostCheck,
		{
			x86_nop, //remove JNZ instruction
			x86_nop
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

ioi::hm3::ZHM3GameData* HM3Game::GetGameDataInstancePtr() const
{
	return ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
}