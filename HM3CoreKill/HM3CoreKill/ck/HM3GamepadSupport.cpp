#include <ck/HM3GamepadSupport.h>

#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZHM3MenuElements.h>
#include <sdk/ZActionManager.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h>
#include <sdk/CCutSequence.h>
#include <sdk/ZWINDOWS.h>
#include <sdk/ZGUI.h>

#include <ck/HM3CutSequencesRegistry.h>

#include <cmath>
#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "Xinput9_1_0.lib")

#define KEY_RELEASED(k) (!m_deviceInfo->CurrentInputState.##k && m_deviceInfo->OldInputState.##k)
#define KEY_PRESSED(k) (!m_deviceInfo->CurrentInputState.##k && !m_deviceInfo->OldInputState.##k)

namespace ck {

	static constexpr uint64_t VibrationTicksCountOnPlayerGotDamage = 500;

	struct HM3GamepadSupport::GamepadDeviceInfo
	{
		int				ControllerID				= -1;
		XINPUT_STATE	ControllerState;
		bool			IsVibrationStarted			= false;
		uint64_t		LastTick					= 0;
		uint64_t		CurrentTick					= 0;
		uint64_t		TickWhenVibrationStarted	= 0;

		struct InputState
		{
			bool A				= false;
			bool B				= false;
			bool X				= false;
			bool Y				= false;
			bool Left			= false;
			bool Right			= false;
			bool Top			= false;
			bool Bottom			= false;
			bool LB				= false;
			bool RB				= false;
			bool Back			= false;
			bool Start			= false;
			bool LStick			= false; //Analog stick as button
			bool RStick			= false; //Analog stick as button

			float deadZoneX		= 0.05f;
			float deadZoneY		= 0.02f;

			float LTrigger		= 0.f;
			float RTrigger		= 0.f;
			float LStickPosX	= 0.f;
			float LStickPosY	= 0.f;
			float RStickPosX	= 0.f;
			float RStickPosY	= 0.f;
			
			void read(XINPUT_STATE state)
			{
				A		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_A				) != 0); //OK
				B		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_B				) != 0); //OK
				X		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_X				) != 0); //OK
				Y		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_Y				) != 0); //OK
				Left	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT		) != 0);
				Right	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT		) != 0);
				Top		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP			) != 0);
				Bottom	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN		) != 0);
				LB		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER	) != 0);
				RB		= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER	) != 0);
				Back	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK			) != 0); //Wrong
				Start	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_START			) != 0); //Wrong
				LStick	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB		) != 0);
				RStick	= ((state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB		) != 0);

				
				float normLX = fmaxf(-1, (float) state.Gamepad.sThumbLX / 32767);
				float normLY = fmaxf(-1, (float) state.Gamepad.sThumbLY / 32767);
 
				LStickPosX = (abs(normLX) < deadZoneX ? 0 : (abs(normLX) - deadZoneX) * (normLX / abs(normLX)));
				LStickPosY = (abs(normLY) < deadZoneY ? 0 : (abs(normLY) - deadZoneY) * (normLY / abs(normLY)));
 
				if (deadZoneX > 0) LStickPosX *= 1 / (1 - deadZoneX);
				if (deadZoneY > 0) LStickPosY *= 1 / (1 - deadZoneY);
 
				float normRX = fmaxf(-1, (float) state.Gamepad.sThumbRX / 32767);
				float normRY = fmaxf(-1, (float) state.Gamepad.sThumbRY / 32767);
 
				RStickPosX = (abs(normRX) < deadZoneX ? 0 : (abs(normRX) - deadZoneX) * (normRX / abs(normRX)));
				RStickPosY = (abs(normRY) < deadZoneY ? 0 : (abs(normRY) - deadZoneY) * (normRY / abs(normRY)));
 
				if (deadZoneX > 0) RStickPosX *= 1 / (1 - deadZoneX);
				if (deadZoneY > 0) RStickPosY *= 1 / (1 - deadZoneY);
 
				LTrigger = (float) state.Gamepad.bLeftTrigger / 255;
				RTrigger = (float) state.Gamepad.bRightTrigger / 255;
			}
		} OldInputState, CurrentInputState;
	};

	HM3GamepadSupport::GamepadDeviceInfo* HM3GamepadSupport::m_deviceInfo = nullptr;

	void HM3GamepadSupport::initializeDeviceInfo()
	{
		XINPUT_STATE state;
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(0, &state) != ERROR_SUCCESS)
		{
			// XBox controller is not available
			return;
		}

		int controllerId = -1;

		for (DWORD i = 0; i < XUSER_MAX_COUNT && controllerId == -1; i++)
		{
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			if (XInputGetState(i, &state) == ERROR_SUCCESS)
			{
				controllerId = i;
				break;
			}
		}

		if (controllerId < 0)
			return;

		m_deviceInfo = new HM3GamepadSupport::GamepadDeviceInfo();
		m_deviceInfo->ControllerID = controllerId;
		ZeroMemory(&m_deviceInfo->ControllerState, sizeof(XINPUT_STATE));
	}

	bool HM3GamepadSupport::onDeviceUpdateRequest(ioi::hm3::ZGameControlWintel* gamepad)
	{
		if (!gamepad)
			return false;

		if (!m_deviceInfo)
		{
			initializeDeviceInfo();
			if (!m_deviceInfo)
				return false;
		}

		m_deviceInfo->LastTick = m_deviceInfo->CurrentTick;
		m_deviceInfo->CurrentTick = gamepad->m_tick;

		ZeroMemory(&m_deviceInfo->ControllerState, sizeof(XINPUT_STATE));
		if (XInputGetState(m_deviceInfo->ControllerID, &m_deviceInfo->ControllerState) != ERROR_SUCCESS)
		{
			return false;
		}

		m_deviceInfo->OldInputState = m_deviceInfo->CurrentInputState;
		m_deviceInfo->CurrentInputState.read(m_deviceInfo->ControllerState);

		/// ======================================================================================================
		
		typedef void(__thiscall* sub_449410_t)(ioi::hm3::ZGameControlWintel*, float*, float*);
		typedef void(__thiscall* sub_449350_t)(ioi::hm3::ZGameControlWintel*, int, bool, int);
		typedef bool(__thiscall* sub_4493E0_t)(ioi::hm3::ZGameControlWintel*, int, float, int);

		sub_449410_t sub_449410 = (sub_449410_t)0x00449410;
		sub_449350_t sub_449350 = (sub_449350_t)0x00449350;
		sub_4493E0_t sub_4493E0 = (sub_4493E0_t)0x004493E0;

		// Stick position correction 
		sub_449410(gamepad, &m_deviceInfo->CurrentInputState.LStickPosX, &m_deviceInfo->CurrentInputState.LStickPosY);
		sub_449410(gamepad, &m_deviceInfo->CurrentInputState.RStickPosX, &m_deviceInfo->CurrentInputState.RStickPosY);

		// Buttons
		sub_449350(gamepad,  0, m_deviceInfo->CurrentInputState.A,      gamepad->m_tick);
		sub_449350(gamepad,  1, m_deviceInfo->CurrentInputState.B,      gamepad->m_tick);
		sub_449350(gamepad,  2, m_deviceInfo->CurrentInputState.X,      gamepad->m_tick);
		sub_449350(gamepad,  3, m_deviceInfo->CurrentInputState.Y,      gamepad->m_tick);

		sub_449350(gamepad,  4, m_deviceInfo->CurrentInputState.Left,   gamepad->m_tick);
		sub_449350(gamepad,  5, m_deviceInfo->CurrentInputState.Right,  gamepad->m_tick);
		sub_449350(gamepad,  6, m_deviceInfo->CurrentInputState.Top,    gamepad->m_tick);
		sub_449350(gamepad,  7, m_deviceInfo->CurrentInputState.Bottom, gamepad->m_tick);

		sub_449350(gamepad,  8, m_deviceInfo->CurrentInputState.LB,     gamepad->m_tick);
		sub_449350(gamepad,  9, m_deviceInfo->CurrentInputState.RB,     gamepad->m_tick);
		sub_449350(gamepad, 10, m_deviceInfo->CurrentInputState.Back,   gamepad->m_tick);
		sub_449350(gamepad, 11, m_deviceInfo->CurrentInputState.Start,  gamepad->m_tick);

		// Sticks
		sub_4493E0(gamepad, 0, m_deviceInfo->CurrentInputState.LStickPosX, gamepad->m_tick);
		sub_4493E0(gamepad, 1, m_deviceInfo->CurrentInputState.LStickPosY, gamepad->m_tick);
		sub_4493E0(gamepad, 2, m_deviceInfo->CurrentInputState.RStickPosX, gamepad->m_tick);
		sub_4493E0(gamepad, 3, m_deviceInfo->CurrentInputState.RStickPosY, gamepad->m_tick);

		auto currentState = m_deviceInfo->CurrentInputState;

		HM3_DEBUG(
			" ----< GAMEPAD DUMP STATE >---- \n "
			" A: %d | B: %d | X: %d | Y: %d  \n"
			" L: %d | R: %d | T: %d | B: %d  \n"
			" Left  stick button:        %d  \n"
			" Right stick button:        %d  \n"
			" Back: %d | Start: %d \n"
			" Left stick: %f;%f | Right stick: %f;%f \n"
			" Left trigger : %f | Right trigger : %f \n"
			" -------------------------------------- \n",
			currentState.A, currentState.B, currentState.X, currentState.Y,
			currentState.LStick, currentState.RStick,
			currentState.Back, currentState.Start,
			currentState.LStickPosX, currentState.LStickPosY, currentState.RStickPosX, currentState.RStickPosY,
			currentState.LTrigger, currentState.RTrigger
		);

		return true;
		/// ======================================================================================================

		/*if (KEY_RELEASED(A))
		{
			auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);
			auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
			auto actionManager = ioi::hm3::getGlacierInterface<ioi::hm3::ZActionManager>(ioi::hm3::ActionManager);

			if (sys && gameData && actionManager)
			{
				const int sub_568260 = 0x00568260;
				const char* aIngamemenu = "IngameMenu";

				__asm {
					mov     eax, gameData
					mov     ecx, [eax + 0x0A1C]
					mov     ecx, [ecx + 0x4]
					push    1
					push    aIngamemenu
					call    sub_568260
					xor		eax, eax
				}
			}
		}*/

		/// Logic
		/*if (m_deviceInfo->IsVibrationStarted)
		{
			if (m_deviceInfo->TickWhenVibrationStarted + VibrationTicksCountOnPlayerGotDamage < m_deviceInfo->CurrentTick)
			{
				m_deviceInfo->IsVibrationStarted = false;
				m_deviceInfo->TickWhenVibrationStarted = 0;
				vibrate(0, 0);
			}
		}*/
	}

	void HM3GamepadSupport::vibrate(uint16_t left, uint16_t right)
	{
		if (m_deviceInfo && m_deviceInfo->ControllerID >= 0)
		{
			XINPUT_VIBRATION vibration;
			ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
			vibration.wLeftMotorSpeed = left;
			vibration.wRightMotorSpeed = right;
			XInputSetState(m_deviceInfo->ControllerID, &vibration);

			m_deviceInfo->IsVibrationStarted = true;
			m_deviceInfo->TickWhenVibrationStarted = m_deviceInfo->CurrentTick;
		}
	}
}