#pragma once

#include <sdk/REFTAB32.h>
#include <sdk/ZHM3Item.h>
#include <sdk/ZHM3ItemTemplate.h>
#include <sdk/ZHM3ItemTemplateAmmo.h>

namespace ioi { namespace hm3 {

	class CInventory
	{
	public:
		// === vftable ===
		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual void Function13();
		virtual void Function14();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
		virtual void Function31();
		virtual void Function32();
		virtual void Function33();
		virtual void Function34();
		virtual void Function35();
		virtual void Function36();
		virtual void Function37();
		virtual void Function38();
		virtual void Function39();
		virtual void Function40();
		virtual std::intptr_t getItemIdByAmmoTemplate(ZHM3ItemTemplateAmmo* pAmmo, REFTAB32* _unkRefTab);
		virtual REFTAB32* getREFTAB32();
		virtual void Function43();
	}; //Size: 0x0080

} }