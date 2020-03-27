#pragma once

#include <cstdint>
#include <sdk/ZHM3WeaponItem.h>
#include <sdk/ZHM3Hitman3.h>
#include <sdk/ZAnimationInfo.h>
#include <sdk/actions/ZLnkAction.h>

namespace ioi { namespace hm3 {

	class ZHitmanActionChargeHitStungun
	{
	public:
		/// === members ===
		ZLnkActionType		m_actionType; //0x0004
		ZHM3Hitman3*		m_hitman3; //0x0008
		ZHM3Hitman3*		m_hitman3_1; //0x000C
		ZHM3Hitman3*		m_hitman3_2; //0x0010
		char				pad_0014[12]; //0x0014
		ZAnimationInfo**	m_animCloseCombatStunGun; //0x0020
		char				pad_0024[4]; //0x0024
		ZAnimationInfo*		m_animCloseCombatStunGun_1; //0x0028
		ZAnimationInfo*		m_anim1STCloseCombat; //0x002C
		ZAnimationInfo*		m_animCloseCombatStabStunGun; //0x0030
		ZAnimationInfo*		m_anim1STCloseCombatStabStunGun; //0x0034
		ZAnimationInfo*		m_animCloseCombatStabStunGun_1; //0x0038
		ZAnimationInfo*		m_anim1STCloseCombatStabStunGun_1; //0x003C
		ZAnimationInfo*		m_animPullGunRight; //0x0040
		char				pad_0044[68]; //0x0044
		ZHM3ItemWeapon*		m_itemWeapon; //0x0088
		char				pad_008C[124]; //0x008C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00791de4
		virtual void Function_0001(); //#1 +4 .rdata:00791de8
		virtual void Function_0002(); //#2 +8 .rdata:00791dec
		virtual void Function_0003(); //#3 +c .rdata:00791df0
		virtual void Function_0004(); //#4 +10 .rdata:00791df4
		virtual void Function_0005(); //#5 +14 .rdata:00791df8
		virtual void Function_0006(); //#6 +18 .rdata:00791dfc
		virtual void Function_0007(); //#7 +1c .rdata:00791e00
		virtual void Function_0008(); //#8 +20 .rdata:00791e04
		virtual void Function_0009(); //#9 +24 .rdata:00791e08
		virtual void Function_0010(); //#10 +28 .rdata:00791e0c
		virtual void Function_0011(); //#11 +2c .rdata:00791e10
		virtual void Function_0012(); //#12 +30 .rdata:00791e14
		virtual void Function_0013(); //#13 +34 .rdata:00791e18
		virtual void Function_0014(); //#14 +38 .rdata:00791e1c
		virtual void Function_0015(); //#15 +3c .rdata:00791e20
		virtual void Function_0016(); //#16 +40 .rdata:00791e24
		virtual void Function_0017(); //#17 +44 .rdata:00791e28
		virtual void Function_0018(); //#18 +48 .rdata:00791e2c
		virtual void Function_0019(); //#19 +4c .rdata:00791e30
		virtual void Function_0020(); //#20 +50 .rdata:00791e34
		virtual void Function_0021(); //#21 +54 .rdata:00791e38
		virtual void Function_0022(); //#22 +58 .rdata:00791e3c
		virtual void Function_0023(); //#23 +5c .rdata:00791e40
		virtual void Function_0024(); //#24 +60 .rdata:00791e44
		virtual void Function_0025(); //#25 +64 .rdata:00791e48
		virtual void Function_0026(); //#26 +68 .rdata:00791e4c
		virtual void Function_0027(); //#27 +6c .rdata:00791e50
		virtual void Function_0028(); //#28 +70 .rdata:00791e54
		virtual void Function_0029(); //#29 +74 .rdata:00791e58
		virtual void Function_0030(); //#30 +78 .rdata:00791e5c
		virtual void Function_0031(); //#31 +7c .rdata:00791e60
		virtual void Function_0032(); //#32 +80 .rdata:00791e64
		virtual void Function_0033(); //#33 +84 .rdata:00791e68
		virtual void Function_0034(); //#34 +88 .rdata:00791e6c
		virtual void Function_0035(); //#35 +8c .rdata:00791e70
		virtual void Function_0036(); //#36 +90 .rdata:00791e74
		virtual void Function_0037(); //#37 +94 .rdata:00791e78
		virtual void Function_0038(); //#38 +98 .rdata:00791e7c
		virtual void Function_0039(); //#39 +9c .rdata:00791e80
		virtual void Function_0040(); //#40 +a0 .rdata:00791e84
		virtual void Function_0041(); //#41 +a4 .rdata:00791e88
		virtual void Function_0042(); //#42 +a8 .rdata:00791e8c
		virtual void Function_0043(); //#43 +ac .rdata:00791e90
		virtual void Function_0044(); //#44 +b0 .rdata:00791e94
		virtual void Function_0045(); //#45 +b4 .rdata:00791e98
	}; //Size: 0x0108

} }