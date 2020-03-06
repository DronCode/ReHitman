#pragma once

#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZSTD.h>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZHitmanActionPickLock
	{
	public:
		char pad_0004[8]; //0x0004
		ioi::hm3::ZHM3Hitman3* m_player0; //0x000C [same to m_player]
		ioi::hm3::ZHM3Hitman3* m_player; //0x0010  [prefer to use it instead previous copy]
		char pad_0014[4]; //0x0014
		ioi::hm3::ZAnimationInfo* m_animPickLockLoop; //0x0018
		ioi::hm3::ZAnimationInfo* m_animPickLockStop; //0x001C
		ioi::hm3::ZAnimationInfo* m_animPickLockStart; //0x0020
		ioi::ZSTDOBJ* m_door; //0x0024
		char pad_0028[10]; //0x0028
		int16_t m_unkOffset_x32; //0x0032
		char pad_0034[20]; //0x0034

		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079183c
		virtual void Function_0001(); //#1 +4 .rdata:00791840
		virtual void perform(); //#2 +8 .rdata:00791844
		virtual void Function_0003(); //#3 +c .rdata:00791848
		virtual void Function_0004(); //#4 +10 .rdata:0079184c
		virtual void Function_0005(); //#5 +14 .rdata:00791850
		virtual void Function_0006(); //#6 +18 .rdata:00791854
		virtual void Function_0007(); //#7 +1c .rdata:00791858
		virtual const char* getName(); //#8 +20 .rdata:0079185c
		virtual void Function_0009(); //#9 +24 .rdata:00791860
		virtual void Function_0010(); //#10 +28 .rdata:00791864
		virtual void Function_0011(); //#11 +2c .rdata:00791868
		virtual void Function_0012(); //#12 +30 .rdata:0079186c
		virtual void Function_0013(); //#13 +34 .rdata:00791870
		virtual void Function_0014(); //#14 +38 .rdata:00791874
		virtual void Function_0015(); //#15 +3c .rdata:00791878
		virtual void Function_0016(); //#16 +40 .rdata:0079187c
		virtual void Function_0017(); //#17 +44 .rdata:00791880
	}; //Size: 0x0048

}}