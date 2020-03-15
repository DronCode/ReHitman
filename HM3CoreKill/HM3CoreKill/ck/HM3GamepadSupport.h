#pragma once

#include <cstdint>
#include <sdk/ZGameControlWintel.h>

namespace ck {

	class HM3GamepadSupport
	{
		struct GamepadDeviceInfo;
		static GamepadDeviceInfo* m_deviceInfo;

		static void initializeDeviceInfo();
	public:
		static bool onDeviceUpdateRequest(ioi::hm3::ZGameControlWintel* gamepad);
		static void vibrate(uint16_t left = 32000, uint16_t right = 32000);
	};

}