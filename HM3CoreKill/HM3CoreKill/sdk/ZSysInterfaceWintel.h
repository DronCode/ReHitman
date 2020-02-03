#pragma once

#include <cstdint>

#include <sdk/ZEngineDatabase.h>
#include <sdk/ZRenderWintelD3D.h>

namespace ioi {
namespace hm3 {

	class ZSysInterfaceWintel
	{
	public:
		char pad_0000[40]; //0x0000
		int32_t m_lastTickAt; //0x0028
		char pad_002C[140]; //0x002C
		ZEngineDatabase* m_engineDataBase; //0x00B8
		char* m_basePath; //0x00BC
		char pad_00C0[508]; //0x00C0
		char* m_currentScene; //0x02BC
		char pad_02C0[508]; //0x02C0
		char* m_currentConfig; //0x04BC
		char pad_04C0[1212]; //0x04C0
		ZRenderWintelD3D* m_renderer; //0x097C
		char pad_0980[7517]; //0x0980
	}; //Size: 0x26DD

}}