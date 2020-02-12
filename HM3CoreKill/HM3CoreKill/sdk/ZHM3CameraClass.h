#pragma once

namespace ioi { namespace hm3 {

	class ZHM3CameraClass
	{
	public:
		virtual void Func0();
	};

	ZHM3CameraClass* getCameraClassByIndex(int cameraIndex);
}}