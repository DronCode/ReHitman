#pragma once

#include <cstdint>

#include <ck/HM3ProcessCache.h>
#include <ck/HM3Player.h>

#include <sdk/ZHM3Hitman3.h>

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
	void CompleteCurrentLevel();
	bool HasAnyUnCompletedTargets() const;

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
	void setupDropItemAction();
	void setupOverrideStartupGMSScriptPath();
	void setupNoVideoMode();
	void setupHookToNewSessionInstanceCreator();
private:
	std::uintptr_t GetGameDataInstancePtr() const;
private:
	bool m_isHackActive = false;
	HM3Player::Ptr m_currentPlayer;
};

