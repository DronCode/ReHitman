﻿#pragma once

#include <cstdint>

namespace ioi {
namespace hm3 {
	enum class ZLnkActionType
	{
		/// Hitman actions
		HitmanActionChangeClothesFromBody		= 0x10000002u,
		HitmanActionPushActor					= 0x10000003u,
		HitmanActionThrowItem					= 0x10000004u,
		HitmanActionPickLock					= 0x10000005u,
		RESERVED_0								= 0x10000007u,						/// ALWAYS NULLPTR
		RESERVED_1								= 0x1000000Cu,						/// ALWAYS NULLPTR
		RESERVED_2								= 0x1000000Eu,						/// ALWAYS NULLPTR
		HitmanActionDropDeadBody				= 0x10000009u,
		HitmanActionHumanShield					= 0x1000000Au,
		HitmanActionHideWeapon					= 0x1000000Du,
		HitmanActionUseKeyCard					= 0x1000000Fu,
		HitmanActionChargeHitKnife				= 0x10000010u,
		HitmanActionChargeHitHedgeCutter		= 0x10000011u,
		HitmanActionHumanShieldRelease			= 0x10000012u,
		HitmanActionChargeHitPickAxe			= 0x10000015u,
		HitmanActionChargeHitFireExtinguisher	= 0x10000016u,
		HitmanActionChargeHitBaseballBat		= 0x10000017u,
		HitmanActionChargeHitPitchfork			= 0x10000018u,
		HitmanActionPackUnpackSuitcase			= 0x1000001Au,
		HitmanActionBalconyJump					= 0x1000001Bu,
		ZHitmanActionPlaceBomb					= 0x1000001Cu,
		HitmanSedateCIAAgent					= 0x1000001Du,
		HitmanPutDownSuitcase					= 0x10000022u,
		HitmanReviveCIAAgent					= 0x10000023u,
		HitmanActionUseSwitch					= 0x10000024u,
		HitmanDropWeight						= 0x10000025u,
		HitmanActionPlaceItemToPos				= 0x10000026u,
		HitmanBreakUtilBox						= 0x10000027u,
		HitmanActionChargeHitHammer				= 0x10000029u,
		HitmanUnlockDoor						= 0x1000002Au,
		HitmanActionChargeHitStungun			= 0x1000002Bu,
		HitmanActionPourFluidOverDevice			= 0x1000002Eu,
		HitmanActionChargeHitScrewdriver		= 0x1000002Fu,
		HitmanActionCloseCombatStunTarget		= 0x10000030u,
		HitmanActionCloseCombatDisarmTarget		= 0x10000031u,
		HitmanStartStrangleInElev				= 0x10000032u,
		HitmanActionStartDragBody				= 0x10000033u,
		HitmanUsePhone							= 0x10000034u,
		HitmanOpenGas							= 0x10000035u,
		HitmanUseComputer						= 0x10000036u,
		HitmanActionDestroyDualWeapons			= 0x10000037u,
		HitmanPickupSuitcase					= 0x10000038u,
		HitmanPhoning							= 0x10000039u,	/// M04 ONLY, CAN CRASH IN OTHER LEVEL
		HitmanPickupBox							= 0x1000003Au,
		HitmanPutDownBox						= 0x1000003Bu,
		HitmanBoxFromElevator					= 0x1000003Cu,
		HitmanBoxToElevator						= 0x1000003Du,
		HitmanActionDieIngame					= 0x1000003Eu,
		HitmanActionStealTape					= 0x1000003Fu,
		HitmanActionChargeHitShovel				= 0x10000040u,
		HitmanPickupBurgers						= 0x10000041u,
		HitmanPutDownBurgers					= 0x10000042u,
		HitmanActionKnockOnDoor					= 0x10000043u, 
		HitmanActionPackUnpackRifle				= 0x10000044u,
		HitmanActionChargeHitCaneSword			= 0x10000045u,
		HitmanActionPoisonBottle				= 0x10000046u,
		/// Other actions
		HitmanActionPickupItem_0				= 0x3u,	//Equal code, not reversed, need to explore
		HitmanActionPickupItem_1				= 0x4u,
		HitmanActionPutItem_0					= 0x5u,
		HitmanActionPutItem_1					= 0x6u,
		ZHitmanActionGetItem_0					= 0x7u,
		ZHitmanActionGetItem_1					= 0x8u,
		HitmanActionDropItem_0					= 0x9u,
		HitmanActionDropItem_1					= 0xAu,
		HitmanActionSwapItems					= 0xBu,
		HitmanActionReloadItem_0				= 0xCu,
		HitmanActionReloadItem_1				= 0xDu,
		HitmanActionChamberItem_0				= 0xEu,
		HitmanActionChamberItem_1				= 0xFu,
	};

	/**
	 * Linked Action - any action who reffers to player (any actions with items as example)
	 */
	class ZLnkAction
	{
	public:
		/// === members ===
		ZLnkActionType m_actionType; //0x0004
		uint32_t m_actor; //0x0008
		uint32_t m_hand; //0x000C
		uint32_t m_animPutGunRight; //0x0010
		uint32_t m_animPutGunRight_1; //0x0014
		uint32_t m_unk0; //0x0018
		int32_t m_unk1; //0x001C
		uint32_t m_unkPtr; //0x0020
		uint32_t m_group; //0x0024

		/// === vftable ===
		virtual void Function_0();				/// sub_51FFB0
		virtual void Function_1();				/// sub_6FDBF0
		virtual bool ApplyAction();				/// sub_69D5C0
		virtual int Function_3();				/// sub_580400
		virtual bool Function_4();				/// sub_580400
		virtual void Function_5(void*);			/// jpeg_mem_term
		virtual void Function_6();				/// nullsub_4
		virtual const char* GetActionName();	/// nullsub_4
		virtual void Function_8();				/// sub_402FE0
		virtual bool Function_9();				/// sub_580400
		virtual void* Function_10();			/// sub_6F7FC0
		virtual bool Function_11(int, int);		/// sub_7113E0
		virtual bool Function_12();				/// sub_69D5C0
		virtual int setup(int, int);			/// sub_50E400
	}; //Size: 0x0028
	/*
HITMAN BLOOD MONEY ACTIONS LIST (TODO)

Vftable	Methods	Flags	Type	Hierarchy
00775810	14		ZLnkAction	ZLnkAction: 
00792F04	18		ZHitmanUsePhone	ZHitmanUsePhone: ZHitmanAction, ZLnkAction;
00792FB4	18		ZHitmanUseComputer	ZHitmanUseComputer: ZHitmanAction, ZLnkAction;
00792C0C	18		ZHitmanUnlockDoor	ZHitmanUnlockDoor: ZHitmanAction, ZLnkAction;
00792E9C	18		ZHitmanStartStrangleInElev	ZHitmanStartStrangleInElev: ZHitmanAction, ZLnkAction;
0079287C	18		ZHitmanSedateCIAAgent	ZHitmanSedateCIAAgent: ZHitmanAction, ZLnkAction;
00792A74	18		ZHitmanReviveCIAAgent	ZHitmanReviveCIAAgent: ZHitmanAction, ZLnkAction;
00792A0C	18		ZHitmanPutDownSuitcase	ZHitmanPutDownSuitcase: ZHitmanAction, ZLnkAction;
007933F4	18		ZHitmanPutDownBurgers	ZHitmanPutDownBurgers: ZHitmanAction, ZLnkAction;
00793194	18		ZHitmanPutDownBox	ZHitmanPutDownBox: ZHitmanAction, ZLnkAction;
007929A4	18		ZHitmanPickupSuitcase	ZHitmanPickupSuitcase: ZHitmanAction, ZLnkAction;
007933A4	18		ZHitmanPickupBurgers	ZHitmanPickupBurgers: ZHitmanAction, ZLnkAction;
00793134	18		ZHitmanPickupBox	ZHitmanPickupBox: ZHitmanAction, ZLnkAction;
007930D4	18		ZHitmanPhoning	ZHitmanPhoning: ZHitmanAction, ZLnkAction;
00792F54	18		ZHitmanOpenGas	ZHitmanOpenGas: ZHitmanAction, ZLnkAction;
00792ADC	18		ZHitmanDropWeight	ZHitmanDropWeight: ZHitmanAction, ZLnkAction;
00792BAC	18		ZHitmanBreakUtilBox	ZHitmanBreakUtilBox: ZHitmanAction, ZLnkAction;
00793264	18		ZHitmanBoxToElevator	ZHitmanBoxToElevator: ZHitmanAction, ZLnkAction;
007931F4	18		ZHitmanBoxFromElevator	ZHitmanBoxFromElevator: ZHitmanAction, ZLnkAction;
007927C4	18		ZHitmanActionUseSwitch	ZHitmanActionUseSwitch: ZHitmanAction, ZLnkAction;
0079259C	18		ZHitmanActionUseKeyCard	ZHitmanActionUseKeyCard: ZHitmanAction, ZLnkAction;
007917AC	19		ZHitmanActionThrowItem	ZHitmanActionThrowItem: ZHitmanAction, ZLnkAction;
0079227C	14		ZHitmanActionSyringe	ZHitmanActionSyringe: ZLnkAction;
0079367C	14		ZHitmanActionSwapItems	ZHitmanActionSwapItems: ZActionSwapItems, ZLnkAction;
00792494	14		ZHitmanActionSuitcase	ZHitmanActionSuitcase: ZLnkAction;
007921A0	14		ZHitmanActionStrangulate	ZHitmanActionStrangulate: ZLnkAction;
00793354	18		ZHitmanActionStealTape	ZHitmanActionStealTape: ZHitmanAction, ZLnkAction;
00792E34	18		ZHitmanActionStartDragBody	ZHitmanActionStartDragBody: ZHitmanAction, ZLnkAction;
007936D4	20		ZHitmanActionReloadItem	ZHitmanActionReloadItem: ZActionReloadItem, ZLnkAction;
00793580	14		ZHitmanActionPutItem	ZHitmanActionPutItem: ZActionPutItem, ZLnkAction;
00791744	18		ZHitmanActionPushActor	ZHitmanActionPushActor: ZHitmanAction, ZLnkAction;
00792C84	18		ZHitmanActionPourFluidOverDevice	ZHitmanActionPourFluidOverDevice: ZHitmanAction, ZLnkAction;
007934B4	18		ZHitmanActionPoisonBottle	ZHitmanActionPoisonBottle: ZHitmanAction, ZLnkAction;
00792228	14		ZHitmanActionPlayAnim	ZHitmanActionPlayAnim: ZLnkAction;
00792B44	18		ZHitmanActionPlaceItemToPos	ZHitmanActionPlaceItemToPos: ZHitmanAction, ZLnkAction;
0079282C	18		ZHitmanActionPlaceBomb	ZHitmanActionPlaceBomb: ZHitmanAction, ZLnkAction;
007935D4	14		ZHitmanActionPickupItem	ZHitmanActionPickupItem: ZActionPickupItem, ZLnkAction;
0079183C	18		ZHitmanActionPickLock	ZHitmanActionPickLock: ZHitmanAction, ZLnkAction;
0079266C	18		ZHitmanActionPackUnpackSuitcase	ZHitmanActionPackUnpackSuitcase: ZHitmanAction, ZLnkAction;
00793444	18		ZHitmanActionPackUnpackRifle	ZHitmanActionPackUnpackRifle: ZHitmanAction, ZLnkAction;
00792CD4	18		ZHitmanActionKnockOnDoor	ZHitmanActionKnockOnDoor: ZHitmanAction, ZLnkAction;
00792438	14		ZHitmanActionHumanShieldRelease	ZHitmanActionHumanShieldRelease: ZLnkAction;
007923E0	14		ZHitmanActionHumanShield	ZHitmanActionHumanShield: ZLnkAction;
007924E8	14		ZHitmanActionHideWeapon	ZHitmanActionHideWeapon: ZLnkAction;
0079352C	14		ZHitmanActionGetItem	ZHitmanActionGetItem: ZActionGetItem, ZLnkAction;
00793628	14		ZHitmanActionDropItem	ZHitmanActionDropItem: ZActionDropItem, ZLnkAction;
007922DC	19		ZHitmanActionDropDeadBody	ZHitmanActionDropDeadBody: ZHitmanAction, ZLnkAction;
007932CC	18		ZHitmanActionDieIngame	ZHitmanActionDieIngame: ZHitmanAction, ZLnkAction;
00792374	18		ZHitmanActionDestroyDualWeapons	ZHitmanActionDestroyDualWeapons: ZHitmanAction, ZLnkAction;
00792D3C	18		ZHitmanActionCloseCombatStunTarget	ZHitmanActionCloseCombatStunTarget: ZHitmanAction, ZLnkAction;
007918A4	46		ZHitmanActionCloseCombatHit	ZHitmanActionCloseCombatHit: ZHitmanAction, ZLnkAction;
00792DBC	18		ZHitmanActionCloseCombatDisarmTarget	ZHitmanActionCloseCombatDisarmTarget: ZHitmanAction, ZLnkAction;
00792604	18		ZHitmanActionClimbHatch	ZHitmanActionClimbHatch: ZHitmanAction, ZLnkAction;
00791DE4	46		ZHitmanActionChargeHitStungun	ZHitmanActionChargeHitStungun: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00792024	46		ZHitmanActionChargeHitShovel	ZHitmanActionChargeHitShovel: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791F64	46		ZHitmanActionChargeHitScrewdriver	ZHitmanActionChargeHitScrewdriver: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791D24	46		ZHitmanActionChargeHitPitchfork	ZHitmanActionChargeHitPitchfork: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791AE4	46		ZHitmanActionChargeHitPickAxe	ZHitmanActionChargeHitPickAxe: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791964	46		ZHitmanActionChargeHitKnife	ZHitmanActionChargeHitKnife: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791A24	46		ZHitmanActionChargeHitHedgeCutter	ZHitmanActionChargeHitHedgeCutter: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791EA4	46		ZHitmanActionChargeHitHammer	ZHitmanActionChargeHitHammer: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791BA4	46		ZHitmanActionChargeHitFireExtinguisher	ZHitmanActionChargeHitFireExtinguisher: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
007920E4	46		ZHitmanActionChargeHitCaneSword	ZHitmanActionChargeHitCaneSword: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
00791C64	46		ZHitmanActionChargeHitBaseballBat	ZHitmanActionChargeHitBaseballBat: ZHitmanActionCloseCombatHit, ZHitmanAction, ZLnkAction;
007916CC	18		ZHitmanActionChangeClothesFromBundle	ZHitmanActionChangeClothesFromBundle: ZHitmanAction, ZLnkAction;
0079165C	18		ZHitmanActionChangeClothesFromBody	ZHitmanActionChangeClothesFromBody: ZHitmanAction, ZLnkAction;
0079253C	15		ZHitmanActionChamberItem	ZHitmanActionChamberItem: ZLnkAction;
0079275C	18		ZHitmanActionBalconyJump	ZHitmanActionBalconyJump: ZHitmanAction, ZLnkAction;
007915F4	18		ZHitmanAction	ZHitmanAction: ZLnkAction;
00797504	14		ZHM3WardenRemovesCIAAgent	ZHM3WardenRemovesCIAAgent: ZLnkAction;
00792944	18		ZHM3RetrieveAction	ZHM3RetrieveAction: ZHitmanAction, ZLnkAction;
007928E4	18		ZHM3PlaceAction	ZHM3PlaceAction: ZHitmanAction, ZLnkAction;
00797460	14		ZHM3ActorStrangleInElevator	ZHM3ActorStrangleInElevator: ZLnkAction;
00797644	14		ZHM3ActorRepairUtilBox	ZHM3ActorRepairUtilBox: ZLnkAction;
007972FC	15		ZHM3ActorPunch	ZHM3ActorPunch: ZLnkAction;
0079755C	14		ZHM3ActorMoveChair	ZHM3ActorMoveChair: ZLnkAction;
007974B8	14		ZHM3ActorBite	ZHM3ActorBite: ZLnkAction;
007975AC	15		ZHM3ActorAttackWithStunGun	ZHM3ActorAttackWithStunGun: ZLnkAction;
00797374	14		ZHM3ActorActionPushed	ZHM3ActorActionPushed: ZLnkAction;
00775980	14		ZActionSwapItems	ZActionSwapItems: ZLnkAction;
007759CC	20		ZActionReloadItem	ZActionReloadItem: ZLnkAction;
00775898	14		ZActionPutItem	ZActionPutItem: ZLnkAction;
007758E4	14		ZActionPickupItem	ZActionPickupItem: ZLnkAction;
0077584C	14		ZActionGetItem	ZActionGetItem: ZLnkAction;
00775934	14		ZActionDropItem	ZActionDropItem: ZLnkAction;
00775A34	14		ZActionChamberItem	ZActionChamberItem: ZLnkAction;
	*/
}}