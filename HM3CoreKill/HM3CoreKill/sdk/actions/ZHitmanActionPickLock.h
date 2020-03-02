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

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();///PERFORM ACTION
		virtual void Function3();
		virtual bool Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual const char* GetActionName(); ///#8
		virtual void Function9();
	}; //Size: 0x0048

}}