#pragma once

#include <Windows.h>

/*** 
	Bugs:
		1) Shooting issues
 ***/
void __stdcall ZHM3WndProc_Hook(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
/***
	Bugs:
 ***/
int __stdcall ZHM3Player_DoesPlayerAcceptAnyDamage(void* pThis);
/***
	No bugs
 ***/
void __stdcall ZHM3Action_OnDropItem(DWORD pThis);

void __stdcall ZHM3Hitman3_Constructor(DWORD result);