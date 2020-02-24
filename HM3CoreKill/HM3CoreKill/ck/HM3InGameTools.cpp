#include <ck/HM3InGameTools.h>

#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>

#include <ck/HM3AnimationRegistry.h>
#include <ck/HM3DoorsRegistry.h>
#include <ck/HM3ActionFactory.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Function.h>
#include <ck/HM3Offsets.h>
#include <ck/HM3Game.h>

#include <sdk/actions/ZHitmanActionPickLock.h>
#include <sdk/ZHM3BriefingControl.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/ZEngineDatabase.h>
#include <sdk/ZHM3CameraClass.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/CTelePortList.h>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZEventBuffer.h>
#include <sdk/CDoor.h>
#include <sdk/ZOSD.h>

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

		if (msg == WM_KEYUP && static_cast<uint32_t>(wParam) == VK_F3)
		{
			toggleVisibility();
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

	void HM3InGameTools::drawDebugMenu()
	{
		static bool showActorsViewer = false;

		ImGui::Begin("ReHitman | Debugger", nullptr, ImGuiWindowFlags_MenuBar);

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Level tools"))
			{
				ImGui::MenuItem("Actors viewer", nullptr, &showActorsViewer);
				ImGui::EndMenu();
			}
		}
		ImGui::EndMenuBar();

		drawPlayerInfo();
		drawSystemsInfo();
		drawLevelInfo();

		ImGui::End();

		if (showActorsViewer)
			showDebugActorsWindow(&showActorsViewer);
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
				ImGui::Text("ZGui: "); ImGui::SameLine(0.f, 15.f); 
				if (!gameData || !gameData->m_Gui)
					ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "N/A");
				else
					ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", gameData->m_Gui);
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

		auto printRTTR = [](ioi::hm3::ZGlacierRTTI* rtti) {
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
			
			ImGui::Text("Level control : "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", levelControl);
			ioi::hm3::ZGlacierRTTI* rtti = ioi::hm3::getTypeInfo(levelControl);
			printRTTR(rtti);

			ImGui::Text("Map           : "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", gameData->m_IngameMap);
			printRTTR(gameData->m_IngameMap->m_RTTI);
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
		}
	}

	void HM3InGameTools::showDebugActorsWindow(bool* pOpen)
	{
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		if (!gameData || !gameData->m_LevelControl)
			return;

		ImGui::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);
		if (ImGui::Begin("Actors viewer", pOpen))
		{
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
			ImGui::Text("Actor: %.2d at 0x%.8X", selected + 1, currentActor);
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
					ImGui::Text("Inventory: 0x%.8X", currentActor->ActorInformation->equipment);

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
						ImGui::SameLine(0.f, 5.f);
						if (currentAnim && ImGui::Button("Apply"))
						{
							currentActor->dropAnimation(6, 0);
							currentActor->setAnimation(currentAnim);
						}

						ImGui::SameLine(0.f, 5.f);
						if (currentAnim && ImGui::Button("Apply for player"))
						{
							gameData->m_Hitman3->dropCurrentAnimation();
							gameData->m_Hitman3->setAnimation(currentAnim);
						}
					}

					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			ImGui::EndChild();
			ImGui::EndGroup();
		}
		ImGui::End();
	}
}
