#pragma once

#include <cstdint>
#include <sdk/InterfacesProvider.h>

/****
	Hitman Blood Money Core Interfaces

	Each address contains dynamic pointer to the system. Use method getInterface<T> for future usage.
****/

namespace ioi {
namespace hm3 {

	static const std::uintptr_t GameDataFactory  = 0x00820838;	//Based on ZHM3GameDataFactory
	static const std::uintptr_t GameData		 = 0x0082083C;	//Based on ZHM3GameData (see sdk/ZHM3GameData.h for details)
	static const std::uintptr_t SysInterface	 = 0x00820820;	//Based on ZSysInterface (67 methods, some of them is purecall), has child class ZSysInterfaceWintel
	static const std::uintptr_t GlobalAllocator  = 0x008208C8;	//Based on ZSysMem
	static const std::uintptr_t NetPlatform		 = 0x00820844;	//Based on ZNetPlatform_Win32_t : ZNetPlatform_t : ZNetAlloc_t
	static const std::uintptr_t GlobalCOM		 = 0x00820830;	//Based on CGlobalCom : CSharedCom
	static const std::uintptr_t LobbyRendezvous  = 0x00820848;	//Based on ZLobbyRendezvous : ZLobby : ZNetAlloc_t
	static const std::uintptr_t ComponentManager = 0x0082084C;	//Based on ZComponentManagerBase : ZComponentBase : NotCopyable
	static const std::uintptr_t QuazalComponent  = 0x008207FC;	//Based on Quazal::HBMDDLDeclarations : Quazal::DDLDeclarations : Quazal::RootObject
	static const std::uintptr_t StreamLogger	 = 0x00820798;	//Based on StdStrLogger_t : StringStreamLogger_t
	static const std::uintptr_t NetFactory		 = 0x00820790;	//Based on NetGateWin32NetFactory_t : NetLayerFactory_t
	static const std::uintptr_t WintelInput		 = 0x008ACAA0;	//Based on ZSysInputWintel : ZSysInput : SysInput::ZInterface
	static const std::uintptr_t MissionDLLFunc2  = 0x008289BC;	//DLL SECTION : ISF
	static const std::uintptr_t MissionDLLFunc3  = 0x008A89D4;	//DLL SECTION : Scripts
	static const std::uintptr_t IsScriptsLoaded  = 0x008ACA2C;	//BOOL FLAG
	static const std::uintptr_t EventBuffer		 = 0x008BA0B8;	//Based on ZEventBuffer : ZSerializable : ZSerializableBase
	static const std::uintptr_t FileSystem		 = 0x0082081C;  //Based on ZSysFileWintel : ZSysFile
	static const std::uintptr_t ScriptCComponent = 0x008ACA28;	//Based on  ZScriptCComponent: ZComponentSingleton<ZScriptCComponent,ZRuntimeComponentBase>, ZRuntimeComponentBase, ZComponent<ZRuntimeComponentBase,ZComponentDescription<0,ZComponentDefaultAllocator> >, ZComponentBase, NotCopyable
	static const std::uintptr_t CollisionWintel  = 0x0090DE98;	//Based on ZCollisionWintel : ZCollisionBase
	static const std::uintptr_t RigidBodyPool	 = 0x009A3554;	//Based on ZRigidBodyPoolManager
	static const std::uintptr_t BoneExtendPool	 = 0x009A37B4;	//Based on ZBoneExtendPool 
	static const std::uintptr_t VertexExtendPool = 0x009A37B8;  //Based on ZVertexExtendPool
	static const std::uintptr_t ScriptComponent  = 0x008A89CC;  //Based on ZScriptComponent
	static const std::uintptr_t ItemIdToNameMap  = 0x008031E0;  //Map between item ID and their code name (1'st - id, 2'nd - char*)
	static const std::uintptr_t ItemNameToIdMap  = 0x008031E4;  //Map between item codename and their id (1'st - name ptr, 2'nd - id)

	static const std::uintptr_t ComponentManager_RuntimeComponentBase = 0x002DB0038;	//Based on ZComponentManager<ZRuntimeComponentBase> : ZComponentManagerBase : ZComponentBase : NotCopyable

	static const std::uintptr_t Direct3DInterface = 0x0090AF08;	//IDirect3D9 device
	static const std::uintptr_t Direct3DDevice    = 0x0090AF0C;	//Based on ZDirect3DDevice : ID3DXEffectStateManager : IUnknown
	static const std::uintptr_t DirectInputDevice = 0x008B4BA0; //DirectInput interface pointer

	static const std::uintptr_t GetItemInfoFunc = 0x004E5BE0; //Get item info by

}}