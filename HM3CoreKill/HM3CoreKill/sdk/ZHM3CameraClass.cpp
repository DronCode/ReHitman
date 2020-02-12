#include <sdk/ZHM3CameraClass.h>
#include <sdk/ZRenderWintelD3D.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/ZGameGlobals.h>
#include <ck/HM3Offsets.h>
#include <cstdint>

namespace ioi { namespace hm3 {
	ZHM3CameraClass* getCameraClassByIndex(int cameraIndex)
	{
		typedef ZHM3CameraClass* (__cdecl* getCameraClassById_t)(std::uintptr_t);
		getCameraClassById_t getCameraClassById = (getCameraClassById_t)HM3Offsets::GetCameraClassById_Func;

		auto systemInterface = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
		if (!systemInterface)
			return nullptr;

		auto renderer = systemInterface->m_renderer;
		if (!renderer)
			return nullptr;

		auto cameraId = renderer->getCameraIdByIndex(cameraIndex);
		return getCameraClassById(cameraId);
	}

}}