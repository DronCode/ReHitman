#pragma once

#include <Windows.h>
#include <sdk/ZDirect3DDevice.h>

ATOM __stdcall RegisterClassExA_Hooked(WNDCLASSEXA* wndClass);

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

void __stdcall ZPlayer_Constructor(DWORD instance);

void __stdcall ZDirect3DDevice_OnDeviceReady(ioi::hm3::ZDirect3DDevice* device);