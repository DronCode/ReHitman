#include <ck/HM3InGameTools.h>

#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <ck\HM3DebugConsole.h>

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
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsClassic();

		// Setup Platform/Renderer bindings
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

		ImGui::ShowDemoWindow();

		// Draw UI
		ImGui::EndFrame();

		DWORD orgZEnable; m_device->GetRenderState(D3DRS_ZENABLE, &orgZEnable);
		DWORD orgAlphaBlendEnabled; m_device->GetRenderState(D3DRS_ALPHABLENDENABLE, &orgAlphaBlendEnabled);
		DWORD orgScissorsTestEnabled; m_device->GetRenderState(D3DRS_SCISSORTESTENABLE, &orgScissorsTestEnabled);

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
			m_isVisible = !m_isVisible;

		return result;
	}
}