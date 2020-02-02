#include <ck/HM3Direct3D.h>
#include <ck/HM3Function.h>

namespace ck
{
	static constexpr const int BeginSceneIndex	= 41;
	static constexpr const int EndSceneIndex	= 42;

	typedef HRESULT(__stdcall* D3DBeginScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DEndScene_t)(IDirect3DDevice9*);

	D3DBeginScene_t			originalBeginSceneFunc;
	D3DEndScene_t			originalEndSceneFunc;
	
	HRESULT WINAPI Direct3DDevice_OnBeginScene(IDirect3DDevice9* device)
	{
		HRESULT result = originalBeginSceneFunc(device);
		
		auto callback = HM3Direct3D::getInstance().onBeginScene;
		if (callback)
			callback(device);
		
		return result;
	}

	HRESULT WINAPI Direct3DDevice_OnEndScene(IDirect3DDevice9* device)
	{
		auto callback = HM3Direct3D::getInstance().onEndScene;
		if (callback)
			callback(device);
		
		auto result = originalEndSceneFunc(device);
		HM3Direct3D::getInstance().initialize(device);	/// D3D can reset their own vftable. We must protect us from M$. They usually do that after EndScene.
		return result;
	}

	HM3Direct3D& HM3Direct3D::getInstance()
	{
		static HM3Direct3D instance;
		return instance;
	}

	void HM3Direct3D::setupHooks(IDirect3DDevice9* device)
	{
		auto beginScenePtr = reinterpret_cast<D3DBeginScene_t>(HM3Function::hookVFTable((DWORD)device, BeginSceneIndex, (DWORD)Direct3DDevice_OnBeginScene, false));
		auto endScenePtr = reinterpret_cast<D3DEndScene_t>(HM3Function::hookVFTable((DWORD)device, EndSceneIndex, (DWORD)Direct3DDevice_OnEndScene, false));

		if ((DWORD)beginScenePtr != (DWORD)&Direct3DDevice_OnBeginScene)
			originalBeginSceneFunc = (D3DBeginScene_t)beginScenePtr;

		if ((DWORD)endScenePtr != (DWORD)&Direct3DDevice_OnEndScene)
			originalEndSceneFunc = (D3DBeginScene_t)endScenePtr;
	}

	void HM3Direct3D::initialize(IDirect3DDevice9* device)
	{
		setupHooks(device);
		if (onD3DReady)
			onD3DReady(device);
	}
}