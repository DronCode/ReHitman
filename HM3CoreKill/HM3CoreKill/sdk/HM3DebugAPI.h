#pragma once

#include <cstdint>
#include <Windows.h>

namespace glacier
{
	typedef void(__cdecl* Glacier_DebugColorReferences_t)(HWND, COLORREF, HINSTANCE);

	namespace details
	{
		static const uint32_t HM3_DebugColorRef = 0x00AD71F7;
	}
	namespace hm3
	{
		/***
			@brief  Open window in backround filled with specified color. 
					Can be used for color correction or something like that.
			@param HWND - parent window handle. Can be null
			@param COLORRER - window will be filled with COLORREF color
			@param HINSTANCE - pass self HINSTANCE (GetModuleHandle(NULL) <)
		***/
		Glacier_DebugColorReferences_t DebugColorReference = (Glacier_DebugColorReferences_t)details::HM3_DebugColorRef;
	}
}