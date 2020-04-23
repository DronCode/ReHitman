#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>

namespace ioi { namespace hm3 {

	class ZHM3Actor;

	enum class BoidState : int32_t { Moving = 0, Staying = 1, ParentActorDestroyed = 2, Sitting = 5, Unk6 = 6 };

	class ZHumanBoid
	{
	public:
		virtual void create(int _a0, float _a1); //#0 +0 .rdata:00782d7c
		virtual void __nullstub(); //#1 +4 .rdata:00782d80 { really useless stuff }
		virtual float getSpeed(); //#2 +8 .rdata:00782d84
		virtual void Function_0003(); //#3 +c .rdata:00782d88
		virtual void reset(Vector3* vec); //#4 +10 .rdata:00782d8c
		virtual void resetVec3(Vector3* vec); //#5 +14 .rdata:00782d90
		virtual void setCurrentPosition(Vector3* newPosition); //#6 +18 .rdata:00782d94
		virtual void setTrackingPosition(Vector3* _a0); //#7 +1c .rdata:00782d98
		virtual float setSpeed(float _speed); //#8 +20 .rdata:00782d9c
		virtual void loadParameters(int _packedInput, int _a2); //#9 +24 .rdata:00782da0
		virtual void Function_0010(); //#10 +28 .rdata:00782da4
		virtual void loadTargetParameters(int _packedInput, int _a2); //#11 +2c .rdata:00782da8

		/// === members ===
		BoidState m_boidState; //0x0004
		float m_speed; //0x0008
		char pad_000C[4]; //0x000C
		ZHM3Actor* m_actor; //0x0010 [self object, for player ZHitman3, for actor ZHM3Actor]
		char pad_0014[8]; //0x0014
		Vector3 m_pos; //0x001C
		Vector3 m_newPos; //0x0028
		char pad_0034[124]; //0x0034
		float m_ActualSpeed; //0x00B0
		float m_fMaxSpeed; //0x00B4
		float m_speed2; //0x00B8
		std::uintptr_t m_PF4RunTime__ZData; ///0xBC pointer to PF4RunTime::ZData of ZInterface
		int m_PathRemaining; //0xC0
		int field_C4;
		int field_C8;
		int field_CC;
		float m_fSpeedMultiplier;
		float m_fEndSpeed;
		Vector3 m_vEndDir;
		float m_fPauseMovementAtDistance;
		int m_PathEndsInObstacle;
		int field_EC;

		//char pad_00BC[52]; //0x00BC
	};

} }