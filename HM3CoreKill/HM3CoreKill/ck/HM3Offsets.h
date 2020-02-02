#pragma once

#include <d3d9.h>
#include <ck/HM3Types.h>

namespace HM3Offsets
{
	static const FuncAddr_t HM3ZPlayer_DoesPlayerAcceptDamage		    = 0x00528060;
	static const FuncAddr_t HM3ZAmmoClip_GetClipCapacity				= 0x0050FA00;
	static const FuncAddr_t HM3ZGameDataFactory_CreateGlobalUnkEntity0  = 0x004010B0;	///UNUSED
	static const FuncAddr_t HM3ZGameDataFactory_OnCreatePlayerEntity	= 0x00401050;	///UNUSED
	static const FuncAddr_t HM3ZBrief_OnOpenBrief						= 0x00560390;
	static const FuncAddr_t HM3ZActor_Ctor								= 0x00638715;
	static const FuncAddr_t HM3ZGameEvent_OnCharactedKilled				= 0x006AE44E;
	static const FuncAddr_t HM3ZBinkVideo_OpenFromFile_PostCheck		= 0x0059A653;
	static const FuncAddr_t HM3ZHitman3_FactoryMethodCall				= 0x00604CF1;
	static const FuncAddr_t HM3ZIniParserOnGetValue						= 0x0042636F;

	static const FuncAddr_t ZHM3LevelControllerOffset					= 0x0A48;
	static const FuncAddr_t ZHM3LevelControllerHasAnyUnCompletedTargets = 0x006AC540;

	static const FuncAddr_t ZHM3WindowsSystemOffset						= 0x0B8;

	static const FuncAddr_t ZHM3LogFuncPayloadAddr = 0x0;

	static const FuncAddr_t ZHM3ActorKill								= 0x0063E1C0;
	static const FuncAddr_t ZHM3M04LevelControllerOnMissionFailed		= 0x006BB1D0;
	
	static const FuncAddr_t ZGEOM_Constructor							= 0x004E8AA7;
	static const FuncAddr_t ZPlayer_Constructor							= 0x005277E4;
	
	static const FuncAddr_t ZGetEntityByTheirName_Func					 = 0x00426BA0;
	static const FuncAddr_t ZGetRawEntity_Func							 = 0x004614E0;
	static const FuncAddr_t ZExecuteTeleport_Func						 = 0x0052A970;
	static const FuncAddr_t ZHM3LevelControl_SetObjectiveStatus_Func	 = 0x006AC8F0;
	static const FuncAddr_t ZHM3LevelControl_HasObjectiveWithStatus_Func = 0x006AC540;
	static const FuncAddr_t ZHM3LevelControl_DoesObjectiveCompleted_Func = 0x006AC560;
	static const FuncAddr_t ZHM3RegisterWindowClassExA_Func				 = 0x00453E68;
	static const FuncAddr_t ZDirect3DDevice_ConstructorFunc				= 0x0049091C;
}

namespace D3D9Offsets
{
	static const FuncAddr_t IDirect3DCreate9_Func						= 0x0048B331;
}

namespace DInputOffsets
{
	static const FuncAddr_t DirectInputInterface = 0x008B4BA0;

	/*
	
	.text:004493A2                 mov     eax, [ecx+2Ch]
	.text:004493A5                 mov     cl, [esp+4+8]
	.text:004493A9                 mov     [ebx+eax], cl

	Actual key code in CL
	
	*/
	static const std::uintptr_t ZWintelKeyboard__onKeyPressed_AcceptRoute = 0x004493A2; 
}

//.data:0063E1C0 sub_63E1C0 proc near                    ; DATA XREF: .bss:00796490↓o
//.data:00520D70 TakeWeaponFromGround proc near
//.data:006128A0 OnPickupSniperRifleCase proc near       ; DATA XREF: .bss:007929AC↓o
//bss:0075D9DC ??_7ZSysInterface@@6B@ dd offset nullsub_8 < DEBUG INTERFACE

//.data:00454211

/*

	On shoot to actors we have calls here
		0053F61E - 55 - push ebp
		0053F61F - 90 - nop
		0053F620 - 8B 0E  - mov ecx,[esi] <<
		0053F622 - 8B 01  - mov eax,[ecx]
		0053F624 - FF 90 DC030000  - call dword ptr [eax+000003DC]

		EAX=14A89010
		EBX=00000000 
		ECX=2BD74A68
		EDX=14A890B8
		ESI=14A8901C
		EDI=2BE7CB48
		ESP=0019F2C8
		EBP=038E5D90
		EIP=0053F622

	AND 

		0053F632 - 8D 4C 24 20  - lea ecx,[esp+20]
		0053F636 - 51 - push ecx
		0053F637 - 8B 0E  - mov ecx,[esi] <<
		0053F639 - 8D 54 24 60  - lea edx,[esp+60]
		0053F63D - 52 - push edx

		EAX=00000000
		EBX=00000000
		ECX=2BD74A68
		EDX=14A89001
		ESI=14A8901C
		EDI=2BE7CB48
		ESP=0019F2C4
		EBP=038E5D90
		EIP=0053F639

	sub_504A20 is actor dead?

*/