#include <ck/HM3Direct3D.h>
#include <ck/HM3Function.h>
#include <ck/HM3InGameTools.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>

namespace ck
{
	static constexpr const int BeginSceneIndex	= 41;
	static constexpr const int EndSceneIndex	= 42;
	static constexpr const int ResetIndex		= 16;
	static constexpr const int CreateVertexBufferIndex = 26;
	static constexpr const int DrawIndexedPrimitiveIndex = 82;

	typedef HRESULT(__stdcall* D3DBeginScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DEndScene_t)(IDirect3DDevice9*);
	typedef HRESULT(__stdcall* D3DReset_t)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
	typedef HRESULT(__stdcall* D3DCreateVertexBuffer_t)(IDirect3DDevice9*, UINT, DWORD, DWORD, D3DPOOL, IDirect3DVertexBuffer9**, HANDLE*);
	typedef HRESULT(__stdcall* D3DDrawIndexedPrimitive_t)(IDirect3DDevice9*, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
	
	D3DBeginScene_t				originalBeginSceneFunc;
	D3DEndScene_t				originalEndSceneFunc;
	D3DReset_t					originalResetFunc;
	D3DCreateVertexBuffer_t		originalCreateVertexBufferFunc;
	D3DDrawIndexedPrimitive_t	originalDrawIndexedPrimitiveFunc;
	
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

	HRESULT __stdcall Direct3DDevice_CreateVertexBuffer(IDirect3DDevice9* device, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
	{
		auto result = originalCreateVertexBufferFunc(device, Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
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
		auto createVertexBufferPtr = reinterpret_cast<D3DCreateVertexBuffer_t>(HM3Function::hookVFTable((DWORD)device, CreateVertexBufferIndex, (DWORD)Direct3DDevice_CreateVertexBuffer, false));
		auto drawIndexedPrimitivePtr = reinterpret_cast<D3DDrawIndexedPrimitive_t>(HM3Function::hookVFTable((DWORD)device, DrawIndexedPrimitiveIndex, (DWORD)Direct3DDevice_DrawIndexedPrimitive, false));

		if ((DWORD)beginScenePtr != (DWORD)&Direct3DDevice_OnBeginScene)
			originalBeginSceneFunc = (D3DBeginScene_t)beginScenePtr;

		if ((DWORD)endScenePtr != (DWORD)&Direct3DDevice_OnEndScene)
			originalEndSceneFunc = (D3DBeginScene_t)endScenePtr;

		if ((DWORD)resetPtr != (DWORD)&Direct3DDevice_OnReset)
			originalResetFunc = (D3DReset_t)resetPtr;

		if ((DWORD)createVertexBufferPtr != (DWORD)&Direct3DDevice_CreateVertexBuffer)
			originalCreateVertexBufferFunc = (D3DCreateVertexBuffer_t)createVertexBufferPtr;

		if ((DWORD)drawIndexedPrimitivePtr != (DWORD)&Direct3DDevice_DrawIndexedPrimitive)
			originalDrawIndexedPrimitiveFunc = (D3DDrawIndexedPrimitive_t)drawIndexedPrimitivePtr;
	}

	void HM3Direct3D::initialize(IDirect3DDevice9* device)
	{
		setupHooksDirectX9Hooks(device);
		if (onD3DReady)
			onD3DReady(device);
	}
}