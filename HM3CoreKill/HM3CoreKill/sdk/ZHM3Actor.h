#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>

namespace ioi {
namespace hm3 {

	class ZHM3Actor;

	class ActorInfos
	{
	public:
		char pad_0000[0x50];		//0x0000
		ZEntityLocator* location;	//0x0050
		char pad_0054[12];			//0x0054
		ZHM3Actor* actor;			//0x0060
		char pad_0064[8];			//0x0064
		char* unkType;				//0x006C
		char pad_0070[80];			//0x0070
		uint32_t equipment;			//0x00C0 [ptr]
		char pad_00C4[12];			//0x00C4
		uint32_t group;				//0x00D0 [ptr]
		char pad_00D4[92];			//0x00D4
		uint32_t unk_equ2;			//0x0130 [ptr]
		char pad_0134[12];			//0x0134
	}; //Size: 0x0140

	class ZHM3Actor
	{
	public:
		virtual void Function0(); //
		virtual void Function1(); //
		virtual void Function2(); //
		virtual void Function3(); //
		virtual void Function4(); //
		virtual void Function5(); //
		virtual void Function6(); //
		virtual void Function7(); //
		virtual void Function8(); //
		virtual void Function9(); //
		virtual void Function10(); //
		virtual void Function11(); //
		virtual void Function12(); //
		virtual void Function13(); //
		virtual void Function14(); //
		virtual void Function15(); //
		virtual void Function16(); //
		virtual void Function17(); //
		virtual void Function18(); //
		virtual void Function19(); //
		virtual void Function20(); //
		virtual void Function21(); //
		virtual void Function22(); //
		virtual void Function23(); //
		virtual void Function24(); //
		virtual void Function25(); //
		virtual void Function26(); //
		virtual void Function27(); //
		virtual void Function28(); //
		virtual void Function29(); //
		virtual void Function30(); //
		virtual void Function31(); //
		virtual void Function32(); //
		virtual void Function33(); //
		virtual void Function34(); //
		virtual void Function35(); //
		virtual void Function36(); //
		virtual void Function37(); //
		virtual void Function38(); //
		virtual void Function39(); //
		virtual void Function40(); //
		virtual void Function41(); //
		virtual void Function42(); //
		virtual void Function43(); //
		virtual void Function44(); //
		virtual void Function45(); //
		virtual void Function46(); //
		virtual void Function47(); //
		virtual void Function48(); //
		virtual void Function49(); //
		virtual void Function50(); //
		virtual void Function51(); //
		virtual void Function52(); //
		virtual void Function53(); //
		virtual void Function54(); //
		virtual void Function55(); //
		virtual void Function56(); //
		virtual void Function57(); //
		virtual void Function58(); //
		virtual void Function59(); //
		virtual void Function60(); //
		virtual void Function61(); //
		virtual void Function62(); //
		virtual void Function63(); //
		virtual void Function64(); //
		virtual void Function65(); //
		virtual void Function66(); //
		virtual void Function67(); //
		virtual void Function68(); //
		virtual void Function69(); //
		virtual void Function70(); //
		virtual void Function71(); //
		virtual void Function72(); //
		virtual void Function73(); //
		virtual void Function74(); //
		virtual void Function75(); //
		virtual void Function76(); //
		virtual void Function77(); //
		virtual void Function78(); //
		virtual void Function79(); //
		virtual void Function80(); //
		virtual void Function81(); //
		virtual void Function82(); //
		virtual void Function83(); //
		virtual void Function84(); //
		virtual void Function85(); //
		virtual void Function86(); //
		virtual void Function87(); //
		virtual void Function88(); //
		virtual void Function89(); //
		virtual void Function90(); //
		virtual void Function91(); //
		virtual void Function92(); //
		virtual void Function93(); //
		virtual void Function94(); //
		virtual void Function95(); //
		virtual void Function96(); //
		virtual void Function97(); //
		virtual void Function98(); //
		virtual void Function99(); //
		virtual void Function100(); //
		virtual void Function101(); //
		virtual void Function102(); //
		virtual void Function103(); //
		virtual void Function104(); //
		virtual void Function105(); //
		virtual void Function106(); //
		virtual void Function107(); //
		virtual void Function108(); //
		virtual void Function109(); //
		virtual void Function110(); //
		virtual void Function111(); //
		virtual void Function112(); //
		virtual void Function113(); //
		virtual void Function114(); //
		virtual void Function115(); //
		virtual void Function116(); //
		virtual void Function117(); //
		virtual void Function118(); //
		virtual void Function119(); //
		virtual void Function120(); //
		virtual void Function121(); //
		virtual void Function122(); //
		virtual void Function123(); //
		virtual void Function124(); //
		virtual void Function125(); //
		virtual void Function126(); //
		virtual void Function127(); //
		virtual void Function128(); //
		virtual void Function129(); //
		virtual void Function130(); //
		virtual void Function131(); //
		virtual void Function132(); //

		ActorInfos* ActorInformation; //0x0004
	}; //Size: 0x0008

}}