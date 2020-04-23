#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZROOM.h>
#include <sdk/ZGEOM.h>
#include <sdk/ZCAMERA.h>
#include <sdk/REFTAB32.h>
#include <sdk/ZEventBase.h>
#include <sdk/ZGeomBuffer.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ResourceCollection.h>
#include <sdk/scripting/ZScriptC.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZEngineDatabase
	{
	public:
		/// === members ===
		int32_t m_field4; //0x0004
		int32_t m_field8; //0x0008
		int32_t m_fieldC; //0x000C
		ZGeomBuffer* m_geomBuffer; //0x0010
		uint32_t m_pf4runtime__data; //0x0014
		ZAnimationInfo* m_animUnknown; //0x0018
		uint32_t m_ppPF4Runtime__Data; //0x001C
		int32_t m_field20; //0x0020
		int32_t m_field24; //0x0024
		char* m_field28; //0x0028
		int32_t m_field2C; //0x002C
		int32_t m_field30; //0x0030
		/// ---{ LINKED LIST GOD RAY BEGIN }---
		
		///TODO: Use ZLinkedList<T> for this we need to implement ZEventBase, CWinEvent<ZWINDOW>, ZLIST, ZGEOM, ZCAMERA, CBaseEvent<ZGEOM> and ZPostFilterBoxEvent
		
		//uint32_t m_ZEventBase_LinkedList_EndPtr; //0x0034
		//uint32_t m_ZEventBase_LinkedList_BeginPtr; //0x0038
		ZLinkedListHeader<ZEventBase> m_eventBase_LinkedList; //0x0034
		
		//uint32_t m_CWinEvent_LinkedList_EndPtr; //0x003C
		//uint32_t m_CWinEvent_LinkedList_BeginPtr; //0x0040
		ZLinkedListHeader<ZEventBase> m_cWinEvent_LinkedList; //0x003C
		
		//uint32_t m_UnknownClass0_LinkedListPtr_EndPtr_BP; //0x0044
		//uint32_t m_UnknownClass0_LinkedListPtr_BeginPtr_BP; //0x0048
		ZLinkedListHeader<void> m_unknownClass0_LinkedList; //0x0044

		//uint32_t m_ZLIST_LinkedList_EndPtr; //0x004C
		//uint32_t m_ZLIST_LinkedList_BeginPtr; //0x0050
		ZLinkedListHeader<ZLIST> m_zList_LinkedList; //0x004C
		
		//uint32_t m_ZGEOM_LinkedList_EndPtr; //0x0054
		//uint32_t m_ZGEOM_LinkedList_BeginPtr; //0x0058
		ZLinkedListHeader<ZGEOM> m_zGeom_LinkedList; //0x0054
		
		//uint32_t m_UnknownClass1_LinkedListPtr_EndPtr_BP; //0x005C
		//uint32_t m_UnknownClass1_LinkedListPtr_BeginPtr_BP; //0x0060
		ZLinkedListHeader<void> m_unknownClass1_LinkedList; //0x005C

		//uint32_t m_ZCAMERA_LinkedList_EndPtr; //0x0064
		//uint32_t m_ZCAMERA_LinkedList_BeginPtr; //0x0068
		ZLinkedListHeader<ZCAMERA> m_zCamera_LinkedList; //0x0064
		
		//uint32_t m_ZGEOMPostFilterEvent_LinkedList_EndPtr; //0x006C
		//uint32_t m_ZGEOMPostFilterEvent_LinkedList_BeginPtr; //0x0070
		ZLinkedListHeader<ZGEOM> m_zGeomPostFilterEvent_LinkedList; //0x006C
		
		//uint32_t m_ZCAMERAPostFilterEvent_LinkedList_EndPtr; //0x0074
		//uint32_t m_ZCAMERAPostFilterEvent_LinkedList_BeginPtr; //0x0078
		ZLinkedListHeader<ZCAMERA> m_zCameraPostFilterEvent_LinkedList; //0x0074
		
		//uint32_t ZGEOM2_LinkedList_EndPtr; //0x007C
		//uint32_t ZGEOM2_LinkedList_BeginPtr; //0x0080
		ZLinkedListHeader<ZGEOM> m_zGeom2_LinkedList; //0x0074
		
		//uint32_t m_unk_LinkedList_EndPtr; //0x0084
		//uint32_t m_unk_LinkedList_BeginPtr; //0x0088
		ZLinkedListHeader<void> m_unknownClass2_LinkedList; //0x0084
		
		/// ---{ LINKED LIST GOD RAY END }---
		ZScheduledScript* m_ppScheduledScript; //0x008C
		ZROOM* m_room; //0x0090
		char pad_0094[4]; //0x0094
		ResourceCollection* m_resourceCollection; //0x0098
		char pad_009C[56]; //0x009C
		char* m_gms; //0x00D4


		/// === vftable ===
		virtual void Function0();	//+0x0
		virtual void Function1();	//+0x4
		virtual void Function2();	//+0x8
		virtual void Function3();	//+0xC
		virtual void Function4();	//+0x10
		virtual void Function5();	//+0x14
		virtual void Function6();	//+0x18
		virtual void Function7();	//+0x1C
		virtual void Function8();	//+0x20
		virtual void Function9();	//+0x24
		virtual void Function10();	//+0x28
		virtual void Function11();	//+0x2C
		virtual void Function12();	//+0x30
		virtual void Function13();	//+0x34
		virtual void Function14();	//+0x38
		virtual void Function15();	//+0x3C
		virtual void Function16();	//+0x40
		virtual void Function17();	//+0x44
		virtual void Function18();	//+0x48
		virtual void Function19();	//+0x4C
		virtual void Function20();	//+0x50
		virtual void Function21();	//+0x54
		virtual void Function22();	//+0x58
		virtual void Function23();	//+0x5C
		virtual void Function24();	//+0x60
		virtual void Function25();	//+0x64
		virtual void Function26();	//+0x68
		virtual void Function27();	//+0x6C
		virtual void Function28();	//+0x70
		virtual void Function29();	//+0x74
		virtual std::uintptr_t getEvent(const char* eventName, int unk0, const char* allocationSource, signed int eventIndex);	//+0x78 #30
		virtual void Function31();	//+0x7C
		virtual void Function32();	//+0x80
		virtual void Function33();	//+0x84
		virtual void Function34();	//+0x88
		virtual void Function35();	//+0x8C
		virtual void Function36();	//+0x90
		virtual void Function37();	//+0x94
		virtual bool Function38();	//+0x98
		virtual void Function39();	//+0x9C
		virtual void Function40();	//+0x100
		virtual void Function41();	//+0x100
		virtual void Function42();	//+0x104
		virtual void Function43();	//+0x108
		virtual void Function44();	//+0x10C
		virtual void Function45();	//+0x110
		virtual void Function46();	//+0x114
		virtual void Function47();	//+0x118
		virtual void Function48();	//+0x11C
		virtual void Function49();	//+0x120
		virtual void Function50();	//+0x124
		virtual void Function51();	//+0x128
		virtual void Function52();	//+0x12C
		virtual void Function53();	//+0x130
		virtual void Function54();	//+0x134
		virtual void Function55();	//+0x138
		virtual void Function56();	//+0x13C
		virtual void Function57();	//+0x140
		virtual void Function58();	//+0x144
		virtual void Function59();	//+0x148
		virtual void Function60();	//+0x14C
		virtual void Function61();	//+0x150
		virtual void Function62();	//+0x154
		virtual void Function63();	//+0x158
		virtual void Function64();	//+0x15C
		virtual void Function65();	//+0x160
		virtual void Function66();	//+0x164
		virtual void Function67();	//+0x168
		virtual void Function68();	//+0x16C
		virtual void Function69();	//+0x170
		virtual void Function70();	//+0x174
		virtual void Function71();	//+0x178
		virtual void Function72();	//+0x17C
		virtual void Function73();	//+0x180
		virtual void Function74();	//+0x184
		virtual void Function75();	//+0x188
		virtual void Function76();	//+0x18C
		virtual void Function77();	//+0x190
		virtual void Function78();	//+0x194
		virtual void Function79();	//+0x198
		virtual void Function80();	//+0x19C
	}; //Size: 0x0014


	class CCOM
	{
	public:
		virtual void Function_0000(); //#0000 +0000 .rdata:00756464
		virtual void Function_0001(); //#0001 +0004 .rdata:00756468
		virtual void Function_0002(); //#0002 +0008 .rdata:0075646c
		virtual void Function_0003(); //#0003 +000c .rdata:00756470
		virtual void Function_0004(); //#0004 +0010 .rdata:00756474
		virtual void Function_0005(); //#0005 +0014 .rdata:00756478
		virtual void Function_0006(); //#0006 +0018 .rdata:0075647c
		virtual void Function_0007(); //#0007 +001c .rdata:00756480
		virtual void Function_0008(); //#0008 +0020 .rdata:00756484
		virtual void Function_0009(); //#0009 +0024 .rdata:00756488
		virtual void Function_0010(); //#0010 +0028 .rdata:0075648c
		virtual void Function_0011(); //#0011 +002c .rdata:00756490
		virtual void Function_0012(); //#0012 +0030 .rdata:00756494
		virtual void Function_0013(); //#0013 +0034 .rdata:00756498
		virtual void Function_0014(); //#0014 +0038 .rdata:0075649c
		virtual void Function_0015(); //#0015 +003c .rdata:007564a0
		virtual void Function_0016(); //#0016 +0040 .rdata:007564a4
		virtual void Function_0017(); //#0017 +0044 .rdata:007564a8
		virtual void Function_0018(); //#0018 +0048 .rdata:007564ac
		virtual void Function_0019(); //#0019 +004c .rdata:007564b0
		virtual void Function_0020(); //#0020 +0050 .rdata:007564b4
		virtual int Function_0021(const char* entityName, int entityId, int unk0 = 16); //#0021 +0054 .rdata:007564b8
		virtual void Function_0022(); //#0022 +0058 .rdata:007564bc
		virtual void Function_0023(); //#0023 +005c .rdata:007564c0
		virtual void Function_0024(); //#0024 +0060 .rdata:007564c4
		virtual void Function_0025(); //#0025 +0064 .rdata:007564c8
		virtual void Function_0026(); //#0026 +0068 .rdata:007564cc
		virtual void Function_0027(); //#0027 +006c .rdata:007564d0
		virtual void Function_0028(); //#0028 +0070 .rdata:007564d4
		virtual void Function_0029(); //#0029 +0074 .rdata:007564d8
		virtual void Function_0030(); //#0030 +0078 .rdata:007564dc
		virtual void getSTDOBJEntityIdByName(const char* entityName, std::uintptr_t* result); //#0031 +007C .rdata:007564e0
		virtual void Function_0032(); //#0032 +0080 .rdata:007564e4
		virtual void Function_0033(); //#0033 +0084 .rdata:007564e8
		virtual void Function_0034(); //#0034 +0088 .rdata:007564ec
		virtual void Function_0035(); //#0035 +008c .rdata:007564f0
		virtual void Function_0036(); //#0036 +0090 .rdata:007564f4
		virtual void Function_0037(); //#0037 +0094 .rdata:007564f8
		virtual void Function_0038(); //#0038 +0098 .rdata:007564fc
		virtual void Function_0039(); //#0039 +009c .rdata:00756500
		virtual void Function_0040(); //#0040 +00a0 .rdata:00756504
		virtual void Function_0041(); //#0041 +00a4 .rdata:00756508
		virtual void Function_0042(); //#0042 +00a8 .rdata:0075650c
	};

	CCOM* getCCOMObjectFromEngineDB(ZEngineDatabase* instance);
	ZSTDOBJ* getSTDOBJById(std::uintptr_t objectId);
	REFTAB32* getEntitiesListFromCCOM(CCOM* instance);
}}