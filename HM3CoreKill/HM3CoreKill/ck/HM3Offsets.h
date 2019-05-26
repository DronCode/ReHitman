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
}

namespace D3D9Offsets
{
	static const FuncAddr_t IDirect3DCreate9_Func						= 0x0048B331;
}

//.data:0063E1C0 sub_63E1C0 proc near                    ; DATA XREF: .bss:00796490↓o
//.data:00520D70 TakeWeaponFromGround proc near
//.data:006128A0 OnPickupSniperRifleCase proc near       ; DATA XREF: .bss:007929AC↓o
//bss:0075D9DC ??_7ZSysInterface@@6B@ dd offset nullsub_8 < DEBUG INTERFACE

//.data:00454211