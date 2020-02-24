#pragma once

#include <sdk/actions/ZLnkAction.h>
#include <sdk/ZHM3Actor.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZBoxPrimitive.h>

namespace ioi {
namespace hm3 {

	struct NearActorRef
	{
		ZHM3Actor* actor;	//+ 00
		float distance;		//+ 04
		float unk0;			//+ 08
		float unk1;			//+ 0C
	};

	class ZHM3Hitman3
	{
	public:
		virtual void Function0();

		// === members ===
		char pad_0004[376]; //0x0004
		uint32_t m_lnkActionQueue; //0x017C
		char pad_0180[612]; //0x0180
		uint32_t m_humanBoid0; //0x03E4
		char pad_03E8[112]; //0x03E8
		uint32_t m_currentZone; //0x0458
		char pad_045C[268]; //0x045C
		uint32_t m_currentAnim; //0x0568
		char pad_056C[104]; //0x056C
		uint32_t m_zMovementAnimation; //0x05D4
		uint32_t m_zMovementStand; //0x05D8
		uint32_t m_zMovementPrimaryMove; //0x05DC
		char pad_05E0[4]; //0x05E0
		uint32_t m_zMovementGuide; //0x05E4
		char pad_05E8[4]; //0x05E8
		uint32_t m_zMovementFall; //0x05EC
		uint32_t m_zMovementGuideToMatPos; //0x05F0
		uint32_t m_zMovementHumanShield; //0x05F4
		uint32_t m_zMovementClimbWall; //0x05F8
		uint32_t m_zMovementHugWall; //0x05FC
		uint32_t m_zMovementClimbBox; //0x0600
		uint32_t m_zMovementPassObstacle; //0x0604
		uint32_t m_zMovementPassThroughWindow; //0x0608
		uint32_t m_zMovementScaleWall; //0x060C
		char pad_0610[4]; //0x0610
		uint32_t m_zMovementClimbLadder; //0x0614
		uint32_t m_zMovementClimbDrainPipe; //0x0618
		uint32_t m_zMovementDead; //0x061C
		uint32_t m_zMovementKillTargetAnimLineup; //0x0620
		uint32_t m_zMovementCutSequence; //0x0624
		uint32_t m_zMovementDialog; //0x0628
		uint32_t m_zMovementJumpBalcony; //0x062C
		uint32_t m_zMovementOnTable; //0x0630
		char pad_0634[28]; //0x0634
		uint32_t m_movementGuidesPoolEntry; //0x0650
		uint32_t m_currentMovementGuide; //0x0654
		char pad_0658[340]; //0x0658
		uint32_t m_controlMouse; //0x07AC
		uint32_t m_controlMouseStrafe; //0x07B0
		char pad_07B4[20]; //0x07B4
		uint32_t m_easeInOut; //0x07C8
		char pad_07CC[884]; //0x07CC
		uint32_t m_inventory; //0x0B40
		char pad_0B44[4]; //0x0B44
		uint32_t m_group; //0x0B48
		uint32_t m_timeMultEffectControl; //0x0B4C
		uint32_t m_camera; //0x0B50
		char pad_0B54[8]; //0x0B54
		uint32_t m_zMovementGuideToMatPos2; //0x0B5C
		char pad_0B60[996]; //0x0B60
		uint32_t m_animationsArray5; //0x0F44
		char pad_0F48[28]; //0x0F48
		uint32_t m_bloodTrails; //0x0F64
		char pad_0F68[104]; //0x0F68
		uint32_t m_HmAs; //0x0FD0
		char pad_0FD4[256]; //0x0FD4
		int32_t m_nearestActorsPoolCapacity; //0x10D4
		uint32_t m_nearestActorsPoolFirstEntity; //0x10D8
		char pad_10DC[524]; //0x10DC
		ZBoxPrimitive* m_zoneControlBoxPrimitive; //0x12E8
		char pad_12EC[352]; //0x12EC
		int32_t		m_availableItemsCount; //0x144C
		ZHM3Item*	m_availableItemsPoolBegin[10]; //0x1450

		/// === custom api ===
		const NearActorRef& getNearActorByTheirIndex(int32_t index);
	}; //Size: 0x1478
}}