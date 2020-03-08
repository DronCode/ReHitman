#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>

namespace ioi { namespace hm3 {

	class ZHM3Actor;

	enum class BoidState : int32_t { Moving = 0, Staying = 1, ParentActorDestroyed = 2, Sitting = 5, Unk6 = 6 };

	class ZHumanBoid
	{
	public:
		virtual void Function_0000(); //#0 +0 .rdata:00782d7c
		virtual void Function_0001(); //#1 +4 .rdata:00782d80
		virtual float getFloat_8(); //#2 +8 .rdata:00782d84
		virtual void Function_0003(); //#3 +c .rdata:00782d88
		virtual void Function_0004(); //#4 +10 .rdata:00782d8c
		virtual void Function_0005(); //#5 +14 .rdata:00782d90
		virtual void setPosition(float* newPosition); //#6 +18 .rdata:00782d94
		virtual void Function_0007(float*); //#7 +1c .rdata:00782d98
		virtual float setFloat_8 (float); //#8 +20 .rdata:00782d9c
		virtual void Function_0009(); //#9 +24 .rdata:00782da0
		virtual void Function_0010(); //#10 +28 .rdata:00782da4
		virtual void Function_0011(); //#11 +2c .rdata:00782da8

		/// === members ===
		BoidState m_boidState; //0x0004
		float m_speed; //0x0008
		char pad_000C[4]; //0x000C
		ZHM3Actor* m_actor; //0x0010
		char pad_0014[8]; //0x0014
		Vector3 m_pos; //0x001C
		Vector3 m_newPos; //0x0028
		char pad_0034[132]; //0x0034
		float m_speed2; //0x00B8
		char pad_00BC[52]; //0x00BC
	};

} }