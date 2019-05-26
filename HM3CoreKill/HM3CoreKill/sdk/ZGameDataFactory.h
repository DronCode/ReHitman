#pragma once

#include <cstdint>

namespace ioi {
namespace hm3 {

	class ZGameDataFactoryBase
	{
	public:
		virtual std::uintptr_t CreateFactory() = 0;
		virtual void DestroyFactory() = 0;
	};

	class ZGameDataFactory : public ZGameDataFactoryBase
	{
	public:
		virtual std::uintptr_t CreateFactory();
		virtual void DestroyFactory();
	};

	/**
	Defs for IDA Pro

	typedef struct {
		DWORD CreateFactory;	///PURE VIRTUAL
		DWORD DestroyFactory;	///PURE VIRTUAL
	} ZGameDataFactoryBase_vftable;

	typedef struct {
		struct ZGameDataFactoryBase_vftable* vftable;
	} ZGameDataFactoryBase;

	typedef struct {
		DWORD CreateFactory;
		DWORD DestroyFactory;
	} ZGameDataFactory_vftable;

	typedef struct {
		struct ZGameDataFactoryBase_vftbl* base_vftable;	///? Think later
		struct ZGameDataFactory_vftable* vftable;
	} ZGameDataFactory;
	**/

}}