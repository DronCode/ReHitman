#pragma once

#include <cstdint>

#include <sdk/ZHM3Camera.h>

#define DECLARE_UNKNOWN_TYPE_PTR(name) using name = std::uintptr_t;

namespace ioi {
namespace hm3 {
	DECLARE_UNKNOWN_TYPE_PTR(ZHitman3);
	DECLARE_UNKNOWN_TYPE_PTR(N00001B3F);
	DECLARE_UNKNOWN_TYPE_PTR(ZHM3Actor);
	DECLARE_UNKNOWN_TYPE_PTR(N000033C1);
	DECLARE_UNKNOWN_TYPE_PTR(REFTAB);
	DECLARE_UNKNOWN_TYPE_PTR(ZHM3MenuElements);
	DECLARE_UNKNOWN_TYPE_PTR(ZHM3GameStats);
	DECLARE_UNKNOWN_TYPE_PTR(N0000163D);
	DECLARE_UNKNOWN_TYPE_PTR(HM3LevelController);
	DECLARE_UNKNOWN_TYPE_PTR(ZOSD);
	DECLARE_UNKNOWN_TYPE_PTR(ZGui);
	DECLARE_UNKNOWN_TYPE_PTR(m_Gui);
	DECLARE_UNKNOWN_TYPE_PTR(CIngameMap);
	DECLARE_UNKNOWN_TYPE_PTR(CGlobalCom);
	
	class ZHM3GameData
	{
	public:
		virtual void Function0(); //
		virtual void Function1(); //
		virtual void Function2(); //
		virtual void Function3(); //
		virtual void Function4(); //
		virtual void Function5(); //
		virtual void Function6(); //
		virtual void Function7(); //
		virtual void Function8(); //
		virtual void Function9(); //
		virtual void Function10(); //
		virtual void Function11(); //
		virtual void Function12(); //
		virtual void Function13(); //
		virtual void Function14(); //
		virtual void Function15(); //
		virtual void Function16(); //
		virtual void Function17(); //
		virtual void Function18(); //
		virtual void Function19(); //
		virtual void Function20(); //
		virtual void Function21(); //
		virtual void Function22(); //
		virtual void Function23(); //
		virtual void Function24(); //
		virtual void Function25(); //
		virtual void Function26(); //
		virtual void Function27(); //
		virtual void Function28(); //
		virtual void Function29(); //
		virtual void Function30(); //
		virtual void Function31(); //
		virtual void Function32(); //
		virtual void Function33(); //
		virtual void Function34(); //
		virtual void Function35(); //
		virtual void Function36(); //

		N00001B3F* m_HumanInfo; //0x0004 
		int32_t m_ActorsInPoolCount; //0x0008 
		ZHM3Actor* m_ActorsPool[512]; //0x000C 
		N000033C1* m_UNKNOWN_LIST; //0x080C 
		char pad_0x0810[0x208]; //0x0810
		REFTAB* m_REFTAB00; //0x0A18 
		ZHM3MenuElements* m_MenuElements; //0x0A1C 
		ZHitman3* m_Hitman3; //0x0A20 
		char pad_0x0A24[0xC]; //0x0A24
		ZHM3GameStats* m_GameStats; //0x0A30 
		char pad_0x0A34[0xC]; //0x0A34
		N0000163D* N0000357E; //0x0A40 unknown thing
		char pad_0x0A44[0x4]; //0x0A44
		HM3LevelController* m_LevelController; //0x0A48 
		ZOSD* m_OSD; //0x0A4C 
		ZGui* m_Gui; //0x0A50 
		CIngameMap* m_IngameMap; //0x0A54 
		char pad_0x0A58[0x4]; //0x0A58
		CGlobalCom* m_GlobCom; //0x0A5C 
		char m_ProfileName[16]; //0xFC5888 
		char pad_0x0A70[0x64]; //0x0A70
		int32_t m_PlayerMoney; //0x0AD4 
		char pad_0x0AD8[0x5EA0]; //0x0AD8
		ZHM3Camera* m_Camera; //0x6978 
		char pad_0x697C[0x95C]; //0x697C
	}; //Size=0x72D8
} }