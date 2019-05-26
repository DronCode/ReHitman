#pragma once

namespace ioi {
namespace hm3 {
	/**
	 * Linked Action - any action who reffers to player (any actions with items as example)
	 */
	class ZLnkAction
	{
	public:
		/***
		 * @brief Constructor
		 **/
		virtual ZLnkAction* Function_0(bool isFirstInstance);	/// sub_51FFB0
		virtual int Function_1();								/// sub_6FDBF0
		virtual bool ApplyAction();								/// sub_69D5C0
		virtual bool Function_3();								/// sub_580400
		virtual bool Function_4();								/// sub_580400
		virtual void Function_5(void*);							/// jpeg_mem_term
		virtual void Function_6();								/// nullsub_4
		virtual const char* GetActionName();					/// nullsub_4
		virtual void Function_8();								/// sub_402FE0
		virtual bool Function_9();								/// sub_580400
		virtual void* Function_10();							/// sub_6F7FC0
		virtual bool Function_11(int, int);						/// sub_7113E0
		virtual bool Function_12();								/// sub_69D5C0
		virtual int Function_13(int, int);						/// sub_50E400
	};

	class ZHitmanAction : public ZLnkAction
	{
	public:
		virtual ZLnkAction* Function_0(bool isFirstInstance);	/// sub_6FDBF0    +
		virtual int Function_1();								/// sub_69D5C0    +
		virtual bool ApplyAction();								/// sub_580400    +
		virtual bool Function_3();								/// sub_580400    +
		virtual bool Function_4();								/// sub_580400    +
		virtual void Function_5(void*);							/// jpeg_mem_term +
		virtual void Function_6();								/// nullsub_4     +
		virtual const char* GetActionName();					/// nullsub_4     +
		virtual void Function_8();								/// sub_6063B0    +
		virtual bool Function_9();								/// sub_580400    +
		virtual void* Function_10();							/// sub_6F7FC0    +
		virtual bool Function_11(int, int);						/// sub_7113E0    +
		virtual bool Function_12();								/// sub_69D5C0    +
		virtual int Function_13(int, int);						/// sub_50E400	  +

		// OWN
		virtual void Function_14();								/// sub_60E190
		virtual void Function_15();								/// sub_60E160
		virtual void Function_16();								/// sub_60E130
		virtual void Function_17();								/// sub_6063C0
	};

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