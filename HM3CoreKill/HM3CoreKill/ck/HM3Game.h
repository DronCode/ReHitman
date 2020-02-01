#pragma once

#include <cstdint>

#include <ck/HM3ProcessCache.h>
#include <ck/HM3Player.h>

#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/ZEngineDatabase.h>

typedef void* ZHM3Hitman3_t;	///For now this is unknown type for me (it's too big class)

class HM3Game
{
	HM3Game();
public:
	static HM3Game& getInstance();

	// API
	void Initialise();
	void Run();
	void DestroyHack();

	// Events
	void OnKeyPress(uint32_t keyCode);
	void OnKeyRelease(uint32_t keyCode);
	void OnNewGameSession(ioi::hm3::ZHM3Hitman3_t gameSession);

	// Getters
	const HM3Player::Ptr& GetPlayer() const;
	std::uintptr_t GetCurrentLevelController() const;
private:
	void setupInputWatcher();
	void setupDoesPlayerAcceptDamage();
	void setupHookToNewSessionInstanceCreator();
	void setupHookZGEOMObjectConstructor();
	void setupHookZPlayerConstructor();
	void printActorsPoolInfos();
	void hackActorsForAllDead();
	void fixEnableCheats();
public:
	static ioi::hm3::ZHM3GameData* GetGameDataInstancePtr();
	static ioi::hm3::ZSysInterfaceWintel* GetSystemInterface();
private:
	bool m_isHackActive = false;
	HM3Player::Ptr m_currentPlayer;
};

