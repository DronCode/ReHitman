#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/ZROOM.h>
#include <sdk/ZEventBuffer.h>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi { namespace hm3 {

	class ZGeomBufferPoolEntity;
	class ZQElemsBuffer;
	class ZBaseGeomLists;

	/// --- { TODO : Move entities to their own files! } ---

	class ZGeomBuffer
	{
	public:
		/// === members ===
		ZEventBuffer* m_eventBuffer; //0x0004
		int32_t m_quartersCount; //0x0008
		ZGeomBufferPoolEntity* m_pool; //0x000C
		ZQElemsBuffer* m_quickElementsBuffer; //0x0010
		ZBaseGeomLists* m_baseGeomLists; //0x0014

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00760fd8
		virtual void Function_0001(); //#1 +4 .rdata:00760fdc
		virtual void Function_0002(); //#2 +8 .rdata:00760fe0
		virtual void Function_0003(); //#3 +c .rdata:00760fe4
		virtual void Function_0004(); //#4 +10 .rdata:00760fe8
		virtual void Function_0005(); //#5 +14 .rdata:00760fec
		virtual void Function_0006(); //#6 +18 .rdata:00760ff0
		virtual void Function_0007(); //#7 +1c .rdata:00760ff4
		virtual void Function_0008(); //#8 +20 .rdata:00760ff8
		virtual void Function_0009(); //#9 +24 .rdata:00760ffc
		virtual void Function_0010(); //#10 +28 .rdata:00761000
		virtual void Function_0011(); //#11 +2c .rdata:00761004
	}; //Size: 0x0018

	class ZGeomBufferPoolEntity
	{
	public:
		/// === members ===
		char pad_0000[4]; //0x0000
		int32_t m_unkInt; //0x0004
		int32_t m_id; //0x0008
		char pad_000C[124]; //0x000C
	}; //Size: 0x0088


	class ZQElemsBuffer
	{
	public:
		/// === members ===
		ZOffsetAlloc* m_offsetAllocator; //0x0004
		ZROOM* m_roomTreeGroup; //0x0008

		/// === vftable ===
		virtual void Function0(); //#0 +0x0 .rdata:00761060
	}; //Size: 0x000C

	class ZBaseGeomLists
	{
	public:
		/// === members ===
		ZOffsetAlloc* m_offsetAllocator; //0x0004
		uint32_t m_unkData; //0x0008
		int32_t m_fieldC; //0x000C
		int32_t m_field10; //0x0010
		int32_t m_field14; //0x0014

		/// === vftable ===
		virtual void Function0(); //#0 +0x0 .rdata:007610A0
	}; //Size: 0x0018


} }