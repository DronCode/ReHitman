#pragma once

#include <cstdint>
#include <d3d9.h>

#include <ck/HM3ProcessCache.h>
#include <ck/HM3Player.h>

#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/ZEngineDatabase.h>
#include <sdk/ZHM3Hitman3.h>
class HM3Game
{
	HM3Game();
public:
	static HM3Game& getInstance();

	// API
	void Initialise();
	void Run();
	void DestroyHack();
	bool IsActive() const;

	// Events
	void OnNewGameSession(ioi::hm3::ZHM3Hitman3* gameSession);
	void onD3DInitialized(IDirect3DDevice9* device);
	void onD3DBeginScene(IDirect3DDevice9* device);
	void onD3DEndScene(IDirect3DDevice9* device);

	// Getters
	const HM3Player::Ptr& GetPlayer() const;
	std::uintptr_t GetCurrentLevelController() const;
private:
	bool checkBuildVersion();
	void setupInputWatcher();
	void setupDoesPlayerAcceptDamage();
	void setupHookToNewSessionInstanceCreator();
	void setupHookZGEOMObjectConstructor();
	void setupHookZPlayerDestructor();
	void hackActorsForAllDead();
	void fixEnableCheats();
	void setupD3DDeviceCreationHook();
	void patchFreeBeamHere();
	void setupLoadAnimationHook();
	void setupNativeObjectsCreationHooks();
	void setupOnSTDOBJAttachedHook();
	void setupFsZipHook();
public:
	static ioi::hm3::ZHM3GameData* GetGameDataInstancePtr();
	static ioi::hm3::ZSysInterfaceWintel* GetSystemInterface();
private:
	bool m_isHackActive = false;
	HM3Player::Ptr m_currentPlayer;
};

