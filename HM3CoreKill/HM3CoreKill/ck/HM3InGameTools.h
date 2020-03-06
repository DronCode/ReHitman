#pragma once

#include <Windows.h>
#include <d3d9.h>

namespace ioi {
namespace hm3 {
	class CInventory;
	class ZHM3Actor;
	class ZIKHAND; 
	class ZM13PosController;
} }

namespace ck
{
	class HM3InGameTools
	{
		bool m_isVisible = false;
		bool m_inGameInputIsActive = true;
		IDirect3DDevice9* m_device = nullptr;

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
		void setRenderDevice(IDirect3DDevice9* dxDevice);

		enum class SceneRenderMode
		{
			Normal, 
			Wireframe, 
			WireframeWithNormal
		};

		SceneRenderMode getSceneRenderMode() const;

	protected:
		void toggleInputState();

	public:
		void resetInputState();

	private:
		void drawTopMenuBar();
		void drawDebugMenu();
		void drawPlayerInfo();
		void drawSystemsInfo();
		void drawLevelInfo();
		void showDebugActorsWindow(bool* pOpen);
		void drawActorInfo(ioi::hm3::ZHM3Actor* currentActor);
		void drawSuitInfoForActor(ioi::hm3::ZHM3Actor* currentActor);
		void drawHandInfo(ioi::hm3::ZIKHAND* hand);
		void drawInventory(ioi::hm3::CInventory* inventory);

	private:
		SceneRenderMode m_renderMode = SceneRenderMode::Normal;
	};

}