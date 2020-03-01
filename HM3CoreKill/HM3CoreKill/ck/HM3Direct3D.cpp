#include <ck/HM3Direct3D.h>
#include <ck/HM3Function.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>

namespace ck
{
	static constexpr const int BeginSceneIndex	= 41;
	static constexpr const int EndSceneIndex	= 42;
	static constexpr const int ResetIndex		= 16;

	typedef HRESULT(__stdcall* D3DBeginScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DEndScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DReset_t)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

	D3DBeginScene_t			originalBeginSceneFunc;
	D3DEndScene_t			originalEndSceneFunc;
	D3DReset_t				originalResetFunc;
	
	HRESULT __stdcall Direct3DDevice_OnBeginScene(IDirect3DDevice9* device)
	{
		HRESULT result = originalBeginSceneFunc(device);
		
		auto callback = HM3Direct3D::getInstance().onBeginScene;
		if (callback)
			callback(device);
		
		return result;
	}

	HRESULT __stdcall Direct3DDevice_OnEndScene(IDirect3DDevice9* device)
	{
		auto callback = HM3Direct3D::getInstance().onEndScene;
		if (callback)
			callback(device);
		
		auto result = originalEndSceneFunc(device);
		HM3Direct3D::getInstance().setupHooksDirectX9Hooks(device);	/// D3D can reset their own vftable. We must protect us from M$. They usually do that after EndScene.
		return result;
	}

	HRESULT __stdcall Direct3DDevice_OnReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pPresentationParameters)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		auto result = originalResetFunc(device, pPresentationParameters);
		ImGui_ImplDX9_CreateDeviceObjects();
		return result;
	}

	HM3Direct3D& HM3Direct3D::getInstance()
	{
		static HM3Direct3D instance;
		return instance;
	}

	void HM3Direct3D::setupHooksDirectX9Hooks(IDirect3DDevice9* device)
	{
		auto beginScenePtr = reinterpret_cast<D3DBeginScene_t>(HM3Function::hookVFTable((DWORD)device, BeginSceneIndex, (DWORD)Direct3DDevice_OnBeginScene, false));
		auto endScenePtr = reinterpret_cast<D3DEndScene_t>(HM3Function::hookVFTable((DWORD)device, EndSceneIndex, (DWORD)Direct3DDevice_OnEndScene, false));
		auto resetPtr = reinterpret_cast<D3DReset_t>(HM3Function::hookVFTable((DWORD)device, ResetIndex, (DWORD)Direct3DDevice_OnReset, false));

		if ((DWORD)beginScenePtr != (DWORD)&Direct3DDevice_OnBeginScene)
			originalBeginSceneFunc = (D3DBeginScene_t)beginScenePtr;

		if ((DWORD)endScenePtr != (DWORD)&Direct3DDevice_OnEndScene)
			originalEndSceneFunc = (D3DBeginScene_t)endScenePtr;

		if ((DWORD)resetPtr != (DWORD)&Direct3DDevice_OnReset)
			originalResetFunc = (D3DReset_t)resetPtr;
	}

	void HM3Direct3D::initialize(IDirect3DDevice9* device)
	{
		setupHooksDirectX9Hooks(device);
		if (onD3DReady)
			onD3DReady(device);
	}
}