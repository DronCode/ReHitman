#pragma once

#include <Windows.h>
#include <d3d9.h>

namespace ck
{
	class HM3InGameTools
	{
		bool m_isVisible = false;
		IDirect3DDevice9* m_device = nullptr;
		
		void pollEventsFromGlacier();

	public:
		static HM3InGameTools& getInstance();

		void initialize(HWND hwnd, IDirect3DDevice9* dxDevice);
		void reset();
		void draw();
		bool processEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		void toggleVisibility();
		bool isVisible() const;
		void setMouseButtonState(int button, bool state);
		void setMouseWheelState(int value);

	private:
		void drawDebugMenu();
		void drawPlayerInfo();
		void drawSystemsInfo();
		void drawLevelInfo();
	};

}