#pragma once

#include <Windows.h>
#include <sdk/ZDirect3DDevice.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/CMapObject.h>

ATOM __stdcall RegisterClassExA_Hooked(WNDCLASSEXA* wndClass);

HWND __stdcall CreateWindowExA_Hooked(
	DWORD dwExStyle,
	LPCSTR lpClassName,
	LPCSTR lpWindowName,
	DWORD dwStyle,
	int X,
	int Y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam);

/***
	Bugs:
 ***/
int __stdcall ZHM3Player_DoesPlayerAcceptAnyDamage(void* pThis);
/***
	No bugs
 ***/
void __stdcall ZHM3Action_OnDropItem(DWORD pThis);

void __stdcall ZHM3Hitman3_Constructor(DWORD result);

void __stdcall ZGEOM_Ctor_CALLBACK(DWORD ptr);

void __stdcall ZPlayer_Destructor(DWORD instance);

void __stdcall ZDirect3DDevice_OnDeviceReady(ioi::hm3::ZDirect3DDevice* device);

void __stdcall OnZMouseWintelCreated(DWORD device);

void __stdcall ZHM3_OnAnimationLoaded(ioi::hm3::ZAnimationInfo* animationInstance);

void __stdcall CMapObject_OnCreate(ioi::hm3::CMapObject* instance);