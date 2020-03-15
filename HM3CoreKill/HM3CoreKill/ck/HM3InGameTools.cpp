#include <ck/HM3InGameTools.h>

#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>

#include <ck/HM3CutSequencesRegistry.h>
#include <ck/HM3AnimationRegistry.h>
#include <ck/HM3DoorsRegistry.h>
#include <ck/HM3ActionFactory.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Function.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3Game.h>

#include <sdk/actions/ZHitmanActionPickLock.h>
#include <sdk/game/ZM13PosController.h>
#include <sdk/ZHM3ItemTemplateAmmo.h>
#include <sdk/ZHM3BriefingControl.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZHM3ItemTemplate.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/ZEngineDatabase.h>
#include <sdk/ZHM3CameraClass.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ZPathFollower.h>
#include <sdk/CTelePortList.h>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZEventBuffer.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZHM3HmAs.h>
#include <sdk/REFTAB32.h>
#include <sdk/CDoor.h>
#include <sdk/ZOSD.h>
#include <sdk/ZSTD.h>

#include <set>

// Win32 message handler
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace ck
{
	HM3InGameTools& HM3InGameTools::getInstance()
	{
		static HM3InGameTools instance;
		return instance;
	}

	void HM3InGameTools::initialize(HWND hwnd, IDirect3DDevice9* dxDevice)
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDrawCursor = true;
		io.MousePos = ImVec2(0.f, 0.f);
		io.MousePosPrev = io.MousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

		ImGui::StyleColorsDark();

		ImGui_ImplWin32_Init(hwnd);
		ImGui_ImplDX9_Init(dxDevice);

		m_device = dxDevice;
	}

	void HM3InGameTools::reset()
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		ImGui_ImplDX9_CreateDeviceObjects();
	}
	
	void HM3InGameTools::draw()
	{
		HM3_ASSERT(m_device != nullptr, "Device must be initialized before call draw()!");

		if (!m_isVisible)
			return;

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		drawTopMenuBar();
		drawDebugMenu();

		ImGui::EndFrame();

		m_device->SetRenderState(D3DRS_ZENABLE, false);
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		m_device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}

	bool HM3InGameTools::processEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		bool result = ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);

		if (msg == WM_KEYUP)
		{
			if (static_cast<uint32_t>(wParam) == VK_F3)
				toggleVisibility();

			if (static_cast<uint32_t>(wParam) == VK_F4)
				toggleInputState();
		}
		

		return result;
	}

	void HM3InGameTools::toggleVisibility()
	{
		m_isVisible = !m_isVisible;
	}

	bool HM3InGameTools::isVisible() const
	{
		return m_isVisible;
	}

	void HM3InGameTools::setMouseButtonState(int button, bool state)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[button] = state;
	}

	void HM3InGameTools::setMouseWheelState(int value)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += static_cast<float>(value) / static_cast<float>(WHEEL_DELTA);
	}

	void HM3InGameTools::setRenderDevice(IDirect3DDevice9* dxDevice)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		m_device = dxDevice;
		ImGui_ImplDX9_CreateDeviceObjects();
	}

	HM3InGameTools::SceneRenderMode HM3InGameTools::getSceneRenderMode() const
	{
		return m_renderMode;
	}

	void HM3InGameTools::toggleInputState()
	{
		auto sysInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		if (!gameData || !sysInterface)
			return;

		auto hitman3 = gameData->m_Hitman3;
		auto engineDB = sysInterface->m_engineDataBase;
		if (!hitman3 || !engineDB)
			return;

		m_inGameInputIsActive = !m_inGameInputIsActive;

		std::uintptr_t ev = 0x0;

		if (m_inGameInputIsActive)
			ev = engineDB->getEvent("MSG_ENABLECONTROLS", 0, __FILE__, 0);
		else
			ev = engineDB->getEvent("MSG_DISABLECONTROLS", 0, __FILE__, 0);

		if (ev == 0x0)
		{
			m_inGameInputIsActive = !m_inGameInputIsActive; //reset state back, event not found
			return;
		}

		hitman3->sendEvent(ev, 0, 0);
	}

	void HM3InGameTools::resetInputState()
	{
		m_inGameInputIsActive = true;
	}

	void HM3InGameTools::drawTopMenuBar()
	{
		static bool showActorsViewer = false;
		static bool showInventoryEditor = false;

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Tools"))
			{
				ImGui::MenuItem("Actors viewer", nullptr, &showActorsViewer);
				ImGui::MenuItem("Inventory editor", nullptr, &showInventoryEditor);
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}


		if (showActorsViewer) showDebugActorsWindow(&showActorsViewer);
		if (showInventoryEditor) showInventoryEditorWindow(&showInventoryEditor);
	}

	void HM3InGameTools::drawDebugMenu()
	{
		ImGui::Begin("ReHitman | Debugger", nullptr, ImGuiWindowFlags_MenuBar);

		drawPlayerInfo();
		drawSystemsInfo();
		drawLevelInfo();

		ImGui::End();
	}

	void HM3InGameTools::drawPlayerInfo()
	{
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		auto sysInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto inputInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
		auto engineDB = sysInterface->m_engineDataBase;
		auto osd = gameData->m_OSD;
		auto hitman3 = gameData->m_Hitman3;

		if (!hitman3)
			return;

		const bool isAllReady = gameData && gameData->m_ProfileName && sysInterface && engineDB && inputInterface && osd;

		if (ImGui::CollapsingHeader("Player info", ImGuiTreeNodeFlags_None))
		{
			if (!isAllReady)
			{
				ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "NO ACTIVE PROFILE");
				return;
			}

			{ // Information Brief
				// Get Profile Name from & Print to ImGui 
				ImGui::Text("Profile: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), gameData->m_ProfileName);
				{
					// Get Money from ZHM3GameData -> m_PlayerMoney & Print to ImGui
					ImGui::Text("Money: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "%.8d", gameData->m_PlayerMoney); ImGui::SameLine(0.f, 10.f);
					// Add or Subtract 1000 Money
					if (ImGui::Button("-")) gameData->m_PlayerMoney -= 1000;
					ImGui::SameLine(0.f, 5.f);
					if (ImGui::Button("+")) gameData->m_PlayerMoney += 1000;
				}
				// Get Scene from ZSysInterfaceWintel -> m_currentScene & Print to ImGui
				ImGui::Text("Scene: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), sysInterface->m_currentScene);
			}
			
			{ //Get Noise Level from zOSD Data -> m_realNosieLevel & Print to ImGui
				ImGui::Text("Noise level: "); ImGui::SameLine(0.f, 15.f);

				ImVec4 noiseLevelColor = ImVec4(0.f, 1.f, 0.f, 1.f);
				ImGui::ProgressBar(osd->m_realNosieLevel / 100.f, ImVec2(0.0f, 0.0f)); ImGui::SameLine(0.f, 8.5f);
				
				if (osd->m_realNosieLevel >= 0.f && osd->m_realNosieLevel <= 40.f)
					noiseLevelColor = ImVec4(0.f, 1.f, 0.f, 1.f);
				else if (osd->m_realNosieLevel > 40.f && osd->m_realNosieLevel <= 70.f)
					noiseLevelColor = ImVec4(1.f, 1.f, 0.f, 1.f);
				else
					noiseLevelColor = ImVec4(1.f, 0.f, 0.f, 1.f);
				ImGui::TextColored(noiseLevelColor, "%.3f", osd->m_realNosieLevel);
			}

			{ //Teleport
				static float newActorPosition[4] = { 0.f, 0.f, 0.f, 0.f };
				float actorTransform[16] = { 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };
				ImGui::Separator();
				ImGui::Text("Teleport player to: "); ImGui::SameLine(0.f, 5.f); ImGui::InputFloat3("", newActorPosition); ImGui::SameLine(0.f, 2.f);
				if (ImGui::Button("Teleport"))
				{
					DWORD methodAddr = HM3Function::getVirtualFunctionAddress((DWORD)hitman3, 0x2A4);
					typedef int(__thiscall* SetEntityPosition_t)(ioi::hm3::ZHM3Hitman3*, float*, float*);
					SetEntityPosition_t SetEntityPosition = (SetEntityPosition_t)methodAddr;

					SetEntityPosition(hitman3, actorTransform, newActorPosition);
				}
			}

			{ //Notifications test
				if (ImGui::Button("Show test notification"))
				{
					auto osd = gameData->m_OSD;
					if (osd)
					{
						typedef int(__thiscall* UB660EE0_t)(ioi::hm3::ZOSD*, const char*, bool);
						
						UB660EE0_t showNotification = (UB660EE0_t)0x00660EE0;

						showNotification(osd, "Test notification", true);

						//4391B0
					}
				}
			}
		}
	}

	void HM3InGameTools::drawSystemsInfo()
	{
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		auto sysInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto inputInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
		auto engineDB = sysInterface->m_engineDataBase;
		auto osd = gameData->m_OSD;
		
		// Creates a Collapseable ImGui Header which shows the current output for Various Engine Systems
		if (ImGui::CollapsingHeader("Glacier | Systems"))
		{
			{
				ImGui::Text("ZSysInterfaceWintel: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", sysInterface);
			}

			{
				ImGui::Text("ZSysInputWintel: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", inputInterface);
			}

			{
				ImGui::Text("ZEngineDatabase: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", engineDB);
				ImGui::SameLine(0.f, 10.f);
				if (ImGui::Button("Dump vftable"))
				{
					HM3Function::dumpVirtualTableOfInstance((DWORD)engineDB, 80, "ZEngineDataBase.txt", "ZEngineDataBase");
					ImGui::OpenPopup("Dump vftable");
				}

				if (ImGui::BeginPopupModal("Dump vftable", NULL, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::Text("Virtual Functions table was of ZEngineDataBase object was dumped into ZEngineDataBase.txt file");
					ImGui::Separator();

					if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
					ImGui::EndPopup();
				}
			}

			{
				ImGui::Text("ZHitman3: "); ImGui::SameLine(0.f, 15.f);
				if (!gameData || !gameData->m_Hitman3)
					ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
				else
					ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", gameData->m_Hitman3);
			}

			{
				ImGui::Text("ZGui: "); ImGui::SameLine(0.f, 15.f); 
				if (!gameData || !gameData->m_Gui)
					ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
				else
					ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", gameData->m_Gui);
			}

			{
				ImGui::Separator();
				
				if (ImGui::Button("Switch to 'Normal'"))
					m_renderMode = SceneRenderMode::Normal;
				
				ImGui::SameLine(0.f, 5.f);
				if (ImGui::Button("Switch to 'Wireframe'"))
					m_renderMode = SceneRenderMode::Wireframe;

				ImGui::SameLine(0.f, 5.f);
				if (ImGui::Button("Switch to 'Wireframe' and 'Normal'"))
					m_renderMode = SceneRenderMode::WireframeWithNormal;
			}

			// sub_6AE2C0 (on level event?)
			// sub_6ACD90 (on update map)
			// ev int __thiscall sub_461780(int this, unsigned int *a2)
		}
	}

	void HM3InGameTools::drawLevelInfo()
	{
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		auto sysInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto inputInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
		auto renderer = sysInterface->m_renderer;
		auto engineDB = sysInterface->m_engineDataBase;
		auto osd = gameData->m_OSD;
		auto levelControl = gameData->m_LevelControl;
		auto hitman3 = gameData->m_Hitman3;

		auto printRTTI = [](ioi::hm3::ZGlacierRTTI* rtti) {
			ImGui::Separator();
			ImGui::Text("    RTTI      : ");
			ImGui::Text("        ID        : %d", rtti->TypeID);
			ImGui::Text("        Name      : %s", rtti->SelfType);
			ImGui::Text("        Parent    : %s", rtti->Parent);
			ImGui::Text("        Full name : %s", rtti->ComplexTypeName);
			ImGui::Separator();
		};

		if (ImGui::CollapsingHeader("Glacier | Level info"))
		{
			if (!levelControl)
			{
				ImGui::Text("No active level");
				return;
			}

			{
				ImGui::Text("Player position { %.4f; %.4f; %.4f } Level Zone: \"%s\"",
					hitman3->m_position.x,
					hitman3->m_position.y,
					hitman3->m_position.z,
					(hitman3->m_currentZone ? hitman3->m_currentZone->entityName : "N/A")
				);

				ImGui::Separator();
				ImGui::Text("Hands: ");

				drawHandInfo(hitman3->getHand(ioi::hm3::HandType::LeftHand));
				drawHandInfo(hitman3->getHand(ioi::hm3::HandType::RightHand));

				ImGui::Separator();
			}

			ImGui::Text("Level control : "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", levelControl);
			ioi::hm3::ZGlacierRTTI* rtti = ioi::hm3::getTypeInfo(levelControl);
			printRTTI(rtti);

			ImGui::Text("Map           : "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", gameData->m_IngameMap);
			printRTTI(gameData->m_IngameMap->m_RTTI);
			ImGui::Text("    isShowed  : %s", (gameData->m_IngameMap->m_showed ? "Yes" : "No"));
			if (gameData->m_IngameMap->m_showed)
			{
				ImGui::Text("    position  : {%.4f; %.4f}", gameData->m_IngameMap->m_drawPosition.x, gameData->m_IngameMap->m_drawPosition.y);
				ImGui::Text("    cursor    : {%.4f; %.4f}", gameData->m_IngameMap->m_drawPosition.z, gameData->m_IngameMap->m_drawPosition.w);
				if (gameData->m_IngameMap->m_activeMap->m_viewId >= 0)
					ImGui::Text("    floor     : (%.4X) %s", gameData->m_IngameMap->m_activeMap->m_viewId, gameData->m_IngameMap->m_activeMap->m_viewName);
				else
					ImGui::Text("    floor     : %s", gameData->m_IngameMap->m_activeMap->m_viewName);
				ImGui::Text("    renderer  : {%.4f; %.4f; %.4f}", gameData->m_IngameMap->m_iconRenderer->m_position.x, gameData->m_IngameMap->m_iconRenderer->m_position.y, gameData->m_IngameMap->m_iconRenderer->m_position.z);
			}

			{
				ImGui::Separator();
				ImGui::Text("Near actors pool [%d] : ", hitman3->m_nearestActorsPoolCapacity);
				ImGui::Separator();

				for (int i = hitman3->m_nearestActorsPoolCapacity - 1; i >= 0; i--)
				{
					const ioi::hm3::NearActorRef& actorRef = hitman3->getNearActorByTheirIndex(i);
					ImGui::Text("Distance: %.4f | Actor at %s at { %.4f; %.4f; %.4f }",
						actorRef.distance,
						actorRef.actor->ActorInformation->location->entityName,
						actorRef.actor->ActorInformation->location->position.x,
						actorRef.actor->ActorInformation->location->position.y,
						actorRef.actor->ActorInformation->location->position.z
					);
				}
				ImGui::Separator();
			}

			{
				ImGui::Separator();
				ImGui::Text("Player's inventory: ");
				drawInventory(hitman3->m_inventory);
			}

			{
				ImGui::Separator();

				std::string_view levelControlName = gameData->m_LevelControl->getTypeName();

				if (auto foundIt = levelControlName.find("M13") != std::string_view::npos)
				{
					if (ImGui::Button("Teleport podium to out of room"))
					{
						auto ccom = ioi::hm3::getCCOMObjectFromEngineDB(engineDB);
						if (!ccom)
							return;

						std::uintptr_t table = 0;

						ccom->getSTDOBJEntityIdByName("M13Table", &table);

						if (!table)
							return;

						auto tableSTD = ioi::hm3::getSTDOBJById(table);
						if (!tableSTD)
							return;

						tableSTD->m_entityLocation->position.x = -2600.f;
					}
				}
			}

			{
				ImGui::Separator();
				if (ImGui::Button("Show ingame menu"))
				{
					typedef int(__thiscall* showUIMenu_t)(ioi::hm3::ZXMLGUISystem*, const char*, int);
					showUIMenu_t showUIMenu = (showUIMenu_t)0x00568260;
					showUIMenu(gameData->m_MenuElements->m_XMLGUISystem, "IngameMenu", 1);
				}
			}
		}
	}

	void HM3InGameTools::showDebugActorsWindow(bool* pOpen)
	{
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		if (!gameData || !gameData->m_LevelControl)
			return;

		ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);
		if (ImGui::Begin("Actors viewer", pOpen))
		{
			ImGui::Separator();
			// left
			static int selected = 0;
			ImGui::BeginChild("left pane", ImVec2(150, 0), true);
			for (int i = 0; i < gameData->m_ActorsInPoolCount; i++)
			{
				char label[128];
				sprintf(label, "Actor #%.2d", i + 1);
				if (ImGui::Selectable(label, selected == i))
					selected = i;
			}
			ImGui::EndChild();
			ImGui::SameLine();

			// right
			ioi::hm3::ZHM3Actor* currentActor = gameData->m_ActorsPool[selected];

			ImGui::BeginGroup();
			ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us

			if (ImGui::Button("Kill all"))
			{
				for (int i = 0; i < gameData->m_ActorsInPoolCount; i++)
				{
					gameData->m_ActorsPool[i]->kill();
				}
			}

			drawActorInfo(currentActor);
			ImGui::EndChild();
			ImGui::EndGroup();
		}
		ImGui::End();
	}

	void HM3InGameTools::showInventoryEditorWindow(bool* pOpen)
	{
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		if (!gameData || !gameData->m_LevelControl)
			return;

		auto hitman3 = gameData->m_Hitman3;
		auto engineDB = sys->m_engineDataBase;

		ImGui::SetNextWindowSize(ImVec2(750, 400), ImGuiCond_FirstUseEver);
		if (ImGui::Begin("Inventory editor", pOpen))
		{
			ImGui::Separator();
			// left
			static int selected = 0;
			ImGui::BeginChild("left pane", ImVec2(150, 0), true);
			for (int i = 0; i < gameData->m_ActorsInPoolCount; i++)
			{
				char label[128];
				sprintf(label, "Actor #%.2d", i + 1);
				if (ImGui::Selectable(label, selected == i))
					selected = i;
			}
			ImGui::EndChild();
			ImGui::SameLine();

			// right
			if (selected >= 0)
			{
				ioi::hm3::ZHM3Actor* currentActor = gameData->m_ActorsPool[selected];

				ImGui::BeginGroup();
				ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us

				ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "INVENTORY:");
				ImGui::Separator();

				auto inventory = reinterpret_cast<ioi::hm3::CInventory*>(currentActor->getComponent("Inventory"));
				if (inventory)
				{
					ioi::REFTAB32* inventoryREFTAB32 = inventory->getREFTAB32();

					if (inventoryREFTAB32)
					{
						if (inventoryREFTAB32->m_itemsCount == 0)
						{
							ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), " (Empty) ");
						}
						else {
							for (int i = 0; i < inventoryREFTAB32->m_itemsCount; i++)
							{
								std::intptr_t itemId = *ioi::get<std::intptr_t>(inventoryREFTAB32, i);
								ioi::hm3::ZHM3Item* pItem = ioi::hm3::ZHM3Item::findItemByID(itemId);
								if (!pItem || !pItem->m_entityLocator)
								{
									continue;
								}

								auto itemTemplate = pItem->getItemTemplate();
								ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "[0x%.8X]", pItem); ImGui::SameLine(0.f, 4.f);
								ImGui::Text("#%.3d %s (%.4X)", i, pItem->m_entityLocator->entityName, itemId);

								auto lHand = currentActor->getHand(ioi::hm3::HandType::LeftHand);
								auto rHand = currentActor->getHand(ioi::hm3::HandType::RightHand);

								ImGui::SameLine(0.f, 5.f);
								if (ImGui::Button("TAKE"))
								{
									auto addItemEv = engineDB->getEvent("MSG_ADDITEMTOINVENTORY", 0, __FILE__, 0);
									auto removeItemEv = engineDB->getEvent("MSG_REMOVEITEMFROMINVENTORY", 0, __FILE__, 0);

									currentActor->sendEvent(removeItemEv, itemId, 0);
									hitman3->sendEvent(addItemEv, reinterpret_cast<int*>(itemId), 0);

									HM3_DEBUG("AddItemToInventoryEv: 0x%.8X\n", addItemEv);
								}

								ImGui::SameLine(0.f, 5.f);
								if (ImGui::Button("REMOVE"))
								{
									auto removeItemEv = engineDB->getEvent("MSG_REMOVEITEMFROMINVENTORY", 0, __FILE__, 0);

									currentActor->sendEvent(removeItemEv, itemId, 0);
								}
							}
						}
					}
					else
					{
						ImGui::SameLine(0.f, 3.f);
						ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
					}
				}
				else {
					ImGui::SameLine(0.f, 3.f);
					ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
				}
				

				ImGui::EndChild();
				ImGui::EndGroup();
			}
		}
		ImGui::End();
	}

	void HM3InGameTools::drawActorInfo(ioi::hm3::ZHM3Actor* currentActor)
	{
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		HM3_ASSERT(gameData != nullptr, "GameData must be valid here!");

		ImGui::Text("Actor at 0x%.8X", currentActor);
		ImGui::Separator();
		if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("General"))
			{
				ImGui::Text("Entity name: "); ImGui::SameLine(.0f, 4.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), currentActor->ActorInformation->location->entityName);

				float actorPosition[4] = {
					currentActor->ActorInformation->location->position.x,
					currentActor->ActorInformation->location->position.y,
					currentActor->ActorInformation->location->position.z,
					.0f
				};

				ImGui::Text("Location pointer at 0x%.8X", currentActor->ActorInformation->location);
				ImGui::Text("Position:"); ImGui::SameLine(0.f, 4.f); ImGui::InputFloat3("", actorPosition);

				{
					if (auto boid = currentActor->m_boid; boid)
					{
						using BoidState = ioi::hm3::BoidState;

						ImGui::Separator();
						ImGui::Text("Human boid info (0x%.8X)", currentActor->m_boid);
						ImGui::Spacing();
						ImGui::Text("Boid locations : {%.4f; %.4f; %.4f} | {%.4f; %.4f; %.4f}", boid->m_pos.x, boid->m_pos.y, boid->m_pos.z, boid->m_newPos.x, boid->m_newPos.y, boid->m_newPos.z);
						ImGui::Text("Movement speed : %.4f", boid->m_speed); 
						
						ImGui::Text("Boid state     : "); ImGui::SameLine(0.f, 0.f);
						switch (boid->m_boidState)
						{
						case BoidState::Moving:
							ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "MOVE TO POINT");
							break;
						case BoidState::Staying:
							ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "STAY AT POSITION");
							break;
						case BoidState::ParentActorDestroyed:
							ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "ACTOR DEAD");
							break;
						case BoidState::Sitting:
							ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "SITTING");
							break;
						default:
							ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "UNKNOWN STATE (%d)", boid->m_boidState);
							break;
						}

						static float newBoidPosition[] = { 0.f, 0.f, 0.f, 0.f };

						ImGui::Text("Teleport boid to "); ImGui::SameLine(0.f, 5.f);
						ImGui::InputFloat3(" ", newBoidPosition); ImGui::SameLine(0.f, 5.f);

						if (ImGui::Button("Teleport"))
						{
							boid->setPosition(newBoidPosition);
						}
					}
					else
					{
						ImGui::SameLine(0.f, 0.5f);
						ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "NOT AVAILABLE");
					}
				}

				ImGui::Text("Change actor status: "); ImGui::SameLine(0.f, 0.5f);
				{
					using Status = ioi::hm3::ZHM3Actor::ActorStatus;
					ImGui::Separator();

					if (ImGui::Button("Stop AI"))
						currentActor->setStatus(Status::StopAI);

					ImGui::SameLine(0.f, 5.f);
					if (ImGui::Button("Set normal mode"))
						currentActor->setStatus(Status::Normal);

					ImGui::SameLine(0.f, 5.f);
					if (ImGui::Button("Sleep"))
						currentActor->setStatus(Status::Sleep);

					ImGui::SameLine(0.f, 5.f);
					if (ImGui::Button("Reset AI"))
						currentActor->setStatus(Status::ResetAI);

				}

				{
					ImGui::Separator();
					ImGui::Text("Inventory: ");
					auto inventory = reinterpret_cast<ioi::hm3::CInventory*>(currentActor->getComponent("Inventory"));
					if (inventory)
					{
						drawInventory(inventory);
					}
					else
					{
						ImGui::SameLine(0.f, 5.f);
						ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
					}
				}

				{
					ioi::hm3::ZPathFollower* pathFollowerComponent = reinterpret_cast<ioi::hm3::ZPathFollower*>(currentActor->getComponent("PathFollower"));
					
					if (pathFollowerComponent)
					{
						ImGui::Separator();
						ImGui::Text("Path follower (0x%.8X | %s):", pathFollowerComponent, (pathFollowerComponent ? pathFollowerComponent->getTypeName() : "Unknown"));

						int totalPaths = pathFollowerComponent->m_reftab.getCapacity();
						ImGui::Text("Path nodes count : %.4d", totalPaths);

						for (int i = 0; i < totalPaths; i++)
						{
							ioi::ZLIST* pointsList = reinterpret_cast<ioi::ZLIST*>(ioi::hm3::getSTDOBJById(pathFollowerComponent->m_reftab.at(i))); // we know that path can contains only ZLIST as internal data representation
							if (pointsList)
							{
								int pathPointsCount = pointsList->m_reftab->getCapacity();
								ImGui::Text("[%.4d] Path at 0x%.8X (%d points)", i, pointsList, pathPointsCount);
								/*ImGui::SameLine(0.f, 5.f);
								if (ImGui::Button("Follow"))
								{
									using FollowPath_t = int(__thiscall*)(ioi::hm3::ZPathFollower*, int);
									FollowPath_t FollowPath = (FollowPath_t)0x00654380;
									FollowPath(pathFollowerComponent, i);
									
									currentActor->m_boid->setFloat_8(100.f);
									currentActor->m_boid->m_boidState = ioi::hm3::BoidState::Moving;
									pathFollowerComponent->Function_0014();
								}*/

								for (int pointIndex = 0; pointIndex < pathPointsCount; pointIndex++)
								{
									auto entity = ioi::hm3::getSTDOBJById(pointsList->m_reftab->at(pointIndex));
									auto locator = entity->m_entityLocation;
									
									ImGui::Text("    [%.4d] Point %s (#%.4d) at {%.4f; %.4f; %.4f}", i, locator->entityName, pointIndex, locator->position.x, locator->position.y, locator->position.z);
								}
								
							}
							else
							{
								ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "[%.4d] BAD POINTS LIST", i);
							}
						}
					}
				}

				ImGui::Separator();
				drawSuitInfoForActor(currentActor);
				drawHandInfo(currentActor->getHand(ioi::hm3::HandType::LeftHand));
				drawHandInfo(currentActor->getHand(ioi::hm3::HandType::RightHand));

				{
					ImGui::Text("Set animation: "); ImGui::SameLine(0.f, 5.f);

					static std::string item_current = "(None)";            // Here our selection is a single pointer stored outside the object.
					static ioi::hm3::ZAnimationInfo* currentAnim = nullptr;

					if (ImGui::BeginCombo(" ", item_current.c_str())) // The second parameter is the label previewed before opening the combo.
					{
						const ck::HM3AnimationRegistry& registry = ck::HM3AnimationRegistry::getRegistry();
						std::vector<ioi::hm3::ZAnimationInfo*> animations;
						registry.getLoadedAnimations(animations);

						for (int i = 0; i < animations.size(); i++)
						{
							if (!animations[i])
								continue;

							bool is_selected = (item_current == animations[i]->m_name);
							if (ImGui::Selectable(animations[i]->m_name, is_selected))
							{
								item_current = animations[i]->m_name;
								currentAnim = animations[i];
							}

							if (is_selected)
								ImGui::SetItemDefaultFocus();
						}

						ImGui::EndCombo();
					}

					if (currentAnim)
					{
						ImGui::SameLine(0.f, 5.f);
						if (ImGui::Button("Apply"))
						{
							currentActor->dropAnimation(6, 0);
							currentActor->setAnimation(currentAnim);
						}

						ImGui::SameLine(0.f, 5.f);
						if (ImGui::Button("Apply for player"))
						{
							gameData->m_Hitman3->dropCurrentAnimation();
							gameData->m_Hitman3->setAnimation(currentAnim);
						}
					}
				}

				{
					if (ImGui::Button("Kill actor"))
					{
						currentActor->kill();
					}
				}

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
	}

	void HM3InGameTools::drawSuitInfoForActor(ioi::hm3::ZHM3Actor* currentActor)
	{
		ImGui::Text("Suit flags: %c%c%c%c (%d)",
			(static_cast<int>(currentActor->m_suitMask) & 0x08 ? '1' : '0'),
			(static_cast<int>(currentActor->m_suitMask) & 0x04 ? '1' : '0'),
			(static_cast<int>(currentActor->m_suitMask) & 0x02 ? '1' : '0'),
			(static_cast<int>(currentActor->m_suitMask) & 0x01 ? '1' : '0'),
			static_cast<int>(currentActor->m_suitMask)
		);
		ImGui::SameLine(0.f, 5.f);
		
		ImVec4 color = ImVec4(1.f, 0.f, 0.f, 1.f);
		const char* str = "(unknown)";

		using SuiteMask = ioi::hm3::ZHM3Actor::SuiteMask;
		switch (currentActor->m_suitMask)
		{
		case SuiteMask::NoActor:
			str = "(not actor)";
			break;
		case SuiteMask::SkinChangerNotSupported:
			str = "(static suit)";
			break;
		case SuiteMask::Nude:
			str = "(nude)";
			color = ImVec4(1.f, 1.f, 0.f, 1.f);
			break;
		case SuiteMask::OriginalView:
			str = "(skin changable)";
			color = ImVec4(0.f, 1.f, 0.f, 1.f);
			break;
		case SuiteMask::Agent47_WithHeaddress:
			str = "(Agent 47 | With headdress)";
			color = ImVec4(0.f, 0.f, 1.f, 1.f);
			break;
		case SuiteMask::Agent47_WithoutHeaddress:
			str = "(Agent 47 | Without headdress)";
			color = ImVec4(0.f, 0.f, 1.f, 1.f);
			break;
		}

		ImGui::TextColored(color, "%s", str);
	}

	void HM3InGameTools::drawHandInfo(ioi::hm3::ZIKHAND* hand)
	{
		HM3_ASSERT(hand != nullptr, "hand should be valid pointer!");

		if (hand->m_handType != ioi::hm3::HandType::LeftHand && hand->m_handType != ioi::hm3::HandType::RightHand)
		{
			ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "Hand of type %.4d not acceptable for preview", hand->m_handType);
			return;
		}

		ImGui::Text("Item at %s hand",
			(hand->m_handType == ioi::hm3::HandType::LeftHand) ? "left " :
			(hand->m_handType == ioi::hm3::HandType::RightHand) ? "right" :
			"unknown"
		);

		ImGui::SameLine(0.f, 8.f);

		ioi::hm3::ZHM3Item* pItem = hand->getItem();

		if (!pItem)
		{
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "NO ITEM");
		}
		else
		{
			ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "%s (%.4X)", pItem->m_entityLocator->entityName, hand->m_itemID);
		}
	}

	void HM3InGameTools::drawInventory(ioi::hm3::CInventory* inventory)
	{
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		HM3_ASSERT(gameData != nullptr, "GameData must be valid here!");

		ioi::REFTAB32* inventoryREFTAB32 = inventory->getREFTAB32();
		
		if (inventoryREFTAB32)
		{
			if (inventoryREFTAB32->m_itemsCount == 0)
			{
				ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), " (Empty) ");
			}
			else {
				for (int i = 0; i < inventoryREFTAB32->m_itemsCount; i++)
				{
					std::intptr_t itemId = *ioi::get<std::intptr_t>(inventoryREFTAB32, i);
					ioi::hm3::ZHM3Item* pItem = ioi::hm3::ZHM3Item::findItemByID(itemId);
					if (!pItem || !pItem->m_entityLocator)
					{
						continue;
					}

					auto itemTemplate = pItem->getItemTemplate();
					ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "[0x%.8X]", pItem); ImGui::SameLine(0.f, 4.f);
					ImGui::Text("#%.3d %s (%.4X) | Item template (at 0x%.8X) %s | ClassID is 0x%.8X", i, pItem->m_entityLocator->entityName, itemId, itemTemplate, (itemTemplate ? itemTemplate->m_entityLocator->entityName : "(N/A)"), pItem->getClassID());
				}
			}
		}
		else
		{
			ImGui::SameLine(0.f, 3.f);
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
		}
	}
}
