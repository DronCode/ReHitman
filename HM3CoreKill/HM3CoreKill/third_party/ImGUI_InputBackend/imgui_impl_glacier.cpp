#pragma once

// Configuration file with compile-time options (edit imconfig.h or #define IMGUI_USER_CONFIG to your own filename)
#ifdef IMGUI_USER_CONFIG
#include IMGUI_USER_CONFIG
#endif
#if !defined(IMGUI_DISABLE_INCLUDE_IMCONFIG_H) || defined(IMGUI_INCLUDE_IMCONFIG_H)
#include "imconfig.h"
#endif

#include "imgui.h"

#include <sdk/InterfacesProvider.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/ZSysInputWintel.h>
#include <sdk/ZKeyboardWintel.h>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZGameGlobals.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h> // for DirectInput constants
#include <Windows.h>

static ioi::hm3::ZKeyboardWintel*	g_keyboard			= nullptr;
static ioi::hm3::ZMouseWintel*		g_mouse				= nullptr;
static INT64						g_Time				= 0;
static INT64						g_TicksPerSecond	= 0;
static ImGuiMouseCursor				g_LastMouseCursor	= ImGuiMouseCursor_COUNT;

bool ImGui_ImplGlacier_Init()
{
	auto input = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInputWintel>(ioi::hm3::WintelInput);
	if (!input)
		return false;

	if (!::QueryPerformanceFrequency((LARGE_INTEGER*)&g_TicksPerSecond))
		return false;

	if (!::QueryPerformanceCounter((LARGE_INTEGER*)&g_Time))
		return false;

	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendPlatformName = "imgui_impl_glacier";

	io.KeyMap[ImGuiKey_Tab] = DIK_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = DIK_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = DIK_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = DIK_UP;
	io.KeyMap[ImGuiKey_DownArrow] = DIK_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = DIK_PRIOR;
	io.KeyMap[ImGuiKey_PageDown] = DIK_NEXT;
	io.KeyMap[ImGuiKey_Home] = DIK_HOME;
	io.KeyMap[ImGuiKey_End] = DIK_END;
	io.KeyMap[ImGuiKey_Insert] = DIK_INSERT;
	io.KeyMap[ImGuiKey_Delete] = DIK_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = DIK_BACK;
	io.KeyMap[ImGuiKey_Space] = DIK_SPACE;
	io.KeyMap[ImGuiKey_Enter] = DIK_RETURN;
	io.KeyMap[ImGuiKey_Escape] = DIK_ESCAPE;
	io.KeyMap[ImGuiKey_KeyPadEnter] = DIK_RETURN;
	io.KeyMap[ImGuiKey_A] = DIK_A;
	io.KeyMap[ImGuiKey_C] = DIK_C;
	io.KeyMap[ImGuiKey_V] = DIK_V;
	io.KeyMap[ImGuiKey_X] = DIK_X;
	io.KeyMap[ImGuiKey_Y] = DIK_Y;
	io.KeyMap[ImGuiKey_Z] = DIK_Z;

	g_keyboard = input->m_keyboardDevice;
	g_mouse = input->m_mouseDevice;

	return g_keyboard && g_mouse;
}

void ImGui_ImplGlacier_Shutdown()
{
	g_keyboard = nullptr;
	g_mouse = nullptr;
}

static bool ImGui_ImplGlacier_UpdateMouseCursor()
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
		return false;

	ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
	if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
	{
		// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
		::SetCursor(NULL);
	}
	else
	{
		// Show OS mouse cursor
		LPTSTR win32_cursor = IDC_ARROW;
		switch (imgui_cursor)
		{
		case ImGuiMouseCursor_Arrow:        win32_cursor = IDC_ARROW; break;
		case ImGuiMouseCursor_TextInput:    win32_cursor = IDC_IBEAM; break;
		case ImGuiMouseCursor_ResizeAll:    win32_cursor = IDC_SIZEALL; break;
		case ImGuiMouseCursor_ResizeEW:     win32_cursor = IDC_SIZEWE; break;
		case ImGuiMouseCursor_ResizeNS:     win32_cursor = IDC_SIZENS; break;
		case ImGuiMouseCursor_ResizeNESW:   win32_cursor = IDC_SIZENESW; break;
		case ImGuiMouseCursor_ResizeNWSE:   win32_cursor = IDC_SIZENWSE; break;
		case ImGuiMouseCursor_Hand:         win32_cursor = IDC_HAND; break;
		}
		::SetCursor(::LoadCursor(NULL, win32_cursor));
	}
	return true;
}

static void ImGui_ImplGlacier_UpdateMouseState()
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
		return;

	// Set mouse position
	const float dtX = static_cast<float>(g_mouse->m_x);
	const float dtY = static_cast<float>(g_mouse->m_y);

	if (io.MousePosPrev.x + dtX < io.DisplaySize.x)
		io.MousePos.x = io.MousePosPrev.x + dtX;

	if (io.MousePosPrev.y + dtY < io.DisplaySize.y)
		io.MousePos.y = io.MousePosPrev.y + dtY;

	if (io.WantSetMousePos)
	{
		POINT pos = { static_cast<int>(io.MousePos.x), static_cast<int>(io.MousePos.y) };
		::SetCursorPos(pos.x, pos.y);
	}
}

static void ImGui_ImplGlacier_UpdateKeyboardState()
{

}

void ImGui_ImplGlacier_NewFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

	io.DisplaySize = ImVec2(1920.f, 1200.f);

	// Setup time step
	INT64 current_time;
	::QueryPerformanceCounter((LARGE_INTEGER*)&current_time);
	io.DeltaTime = (float)(current_time - g_Time) / g_TicksPerSecond;
	g_Time = current_time;

	// Read keyboard modifiers inputs
	io.KeyCtrl = (::GetKeyState(VK_CONTROL) & 0x8000) != 0;
	io.KeyShift = (::GetKeyState(VK_SHIFT) & 0x8000) != 0;
	io.KeyAlt = (::GetKeyState(VK_MENU) & 0x8000) != 0;
	io.KeySuper = false;

	// Update OS mouse position
	ImGui_ImplGlacier_UpdateMouseState();

	// Update OS mouse cursor with the cursor requested by imgui
	ImGuiMouseCursor mouse_cursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
	if (g_LastMouseCursor != mouse_cursor)
	{
		g_LastMouseCursor = mouse_cursor;
		ImGui_ImplGlacier_UpdateMouseCursor();
	}

	// Update pressed keys
	ImGui_ImplGlacier_UpdateKeyboardState();
}