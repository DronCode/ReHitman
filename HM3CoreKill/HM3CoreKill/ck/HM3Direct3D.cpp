#include <ck/HM3Direct3D.h>
#include <ck/HM3Function.h>
#include <ck/HM3InGameTools.h>

#include <imgui.h>
#include <imgui_impl_dx9.h>


//#define CKD3D_USE_TEXTURES_HOOK
#define CKD3D_USE_VERTEX_BINDER_HOOK

namespace ck
{
	static constexpr const int BeginSceneIndex	= 41;
	static constexpr const int EndSceneIndex	= 42;
	static constexpr const int ResetIndex		= 16;
	static constexpr const int SetTextureIndex	= 65;
	static constexpr const int DrawIndexedPrimitiveIndex = 82;

	typedef HRESULT(__stdcall* D3DBeginScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DEndScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DReset_t)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
	typedef HRESULT(__stdcall* D3DDrawIndexedPrimitive_t)(IDirect3DDevice9*, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
	typedef HRESULT(__stdcall* D3DSetTexture_t)(IDirect3DDevice9*, DWORD, IDirect3DBaseTexture9*);
	
	D3DBeginScene_t				originalBeginSceneFunc;
	D3DEndScene_t				originalEndSceneFunc;
	D3DReset_t					originalResetFunc;
	D3DDrawIndexedPrimitive_t	originalDrawIndexedPrimitiveFunc;
	D3DSetTexture_t				originalD3DSetTextureFunc;
	
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

		auto callback = HM3Direct3D::getInstance().onDeviceLost;
		if (callback)
			callback(device);
		
		return result;
	}

	HRESULT __stdcall Direct3DDevice_DrawIndexedPrimitive(IDirect3DDevice9* device, D3DPRIMITIVETYPE primType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
	{
		HRESULT result = 0;
		
		auto renderMode = ck::HM3InGameTools::getInstance().getSceneRenderMode();
		
		switch (renderMode)
		{
			case ck::HM3InGameTools::SceneRenderMode::Normal:
			{
				device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				return originalDrawIndexedPrimitiveFunc(device, primType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			}
			break;
			case ck::HM3InGameTools::SceneRenderMode::Wireframe:
			{
				device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				return originalDrawIndexedPrimitiveFunc(device, primType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			}
			break;
			case ck::HM3InGameTools::SceneRenderMode::WireframeWithNormal:
			{
				device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				result = originalDrawIndexedPrimitiveFunc(device, primType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);

				device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				result = originalDrawIndexedPrimitiveFunc(device, primType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);

				device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				return result;
			}
			break;
		}
		
		return result;
	}

	HRESULT __stdcall Direct3DDevice_SetTexture(IDirect3DDevice9* device, DWORD stage, IDirect3DBaseTexture9* texture)
	{
		return originalD3DSetTextureFunc(device, stage, texture);
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

#ifdef CKD3D_USE_VERTEX_BINDER_HOOK
		auto drawIndexedPrimitivePtr = reinterpret_cast<D3DDrawIndexedPrimitive_t>(HM3Function::hookVFTable((DWORD)device, DrawIndexedPrimitiveIndex, (DWORD)Direct3DDevice_DrawIndexedPrimitive, false));
		if ((DWORD)drawIndexedPrimitivePtr != (DWORD)&Direct3DDevice_DrawIndexedPrimitive)
			originalDrawIndexedPrimitiveFunc = (D3DDrawIndexedPrimitive_t)drawIndexedPrimitivePtr;
#endif

#ifdef CKD3D_USE_TEXTURES_HOOK
		auto setTexturePtr = reinterpret_cast<D3DSetTexture_t>(HM3Function::hookVFTable((DWORD)device, SetTextureIndex, (DWORD)Direct3DDevice_SetTexture, false));
		if ((DWORD)setTexturePtr != (DWORD)&Direct3DDevice_SetTexture)
			originalD3DSetTextureFunc = (D3DSetTexture_t)setTexturePtr;
#endif
	}

	void HM3Direct3D::initialize(IDirect3DDevice9* device)
	{
		setupHooksDirectX9Hooks(device);
		if (onD3DReady)
			onD3DReady(device);
	}
}