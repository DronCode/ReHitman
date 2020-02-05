#pragma once

#include <functional>
#include <d3d9.h>

namespace ck
{

	class HM3Direct3D
	{
	public:
		static HM3Direct3D& getInstance();
		void initialize(IDirect3DDevice9* device);
		void setupHooksDirectX9Hooks(IDirect3DDevice9* device);

		using CommonCallback = std::function<void(IDirect3DDevice9*)>;

		CommonCallback onD3DReady;
		CommonCallback onBeginScene;
		CommonCallback onEndScene;
	};

}