#include <ck/HM3InGameTools.h>

#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <ck/HM3DebugConsole.h>

#include <sdk/InterfacesProvider.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZEngineDatabase.h>
#include <sdk/ZHM3GameData.h>
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
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		auto sysInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		auto inputInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
		auto engineDB = sysInterface->m_engineDataBase;
		auto osd = gameData->m_OSD;

		ImGui::Begin("ReHitman | Debugger");
		
		{
			{ // Common game & profile data
				ImGui::Text("Profile: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), gameData->m_ProfileName);
				{
					ImGui::Text("Money: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), "%.8d", gameData->m_PlayerMoney); ImGui::SameLine(0.f, 10.f);
					if (ImGui::Button("-")) gameData->m_PlayerMoney -= 1000;
					ImGui::SameLine(0.f, 5.f);
					if (ImGui::Button("+")) gameData->m_PlayerMoney += 1000;
				}
				ImGui::Text("Scene: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), sysInterface->m_currentScene);
			}
			{ //Noise level
				ImGui::Text("Noise level: "); ImGui::SameLine(0.f, 15.f);

				ImVec4 noiseLevelColor = ImVec4(0.f, 1.f, 0.f, 1.f);
				if (osd->m_realNosieLevel >= 0.f && osd->m_realNosieLevel <= 40.f)
					noiseLevelColor = ImVec4(0.f, 1.f, 0.f, 1.f);
				else if (osd->m_realNosieLevel > 40.f && osd->m_realNosieLevel <= 70.f)
					noiseLevelColor = ImVec4(1.f, 1.f, 0.f, 1.f);
				else
					noiseLevelColor = ImVec4(1.f, 0.f, 0.f, 1.f);
				ImGui::TextColored(noiseLevelColor, "%.3f", osd->m_realNosieLevel);
			}
		}


		if (ImGui::CollapsingHeader("Glacier | Systems"))
		{
			ImGui::Text("ZSysInterfaceWintel: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", sysInterface);
			ImGui::Text("ZSysInputWintel: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", inputInterface);
			ImGui::Text("ZEngineDatabase: "); ImGui::SameLine(0.f, 10.f); ImGui::TextColored(ImVec4(1.f, 1.f, 0.f, 1.f), "0x%.8X", engineDB);
		}

		ImGui::End();
	}
}