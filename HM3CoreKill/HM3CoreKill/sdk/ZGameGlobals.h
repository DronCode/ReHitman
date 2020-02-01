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
	static const std::uintptr_t F = 0x009728DC;
}}