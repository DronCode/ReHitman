#include <sdk/ZConstructors.h>

#include <sdk/ZEntityLocator.h>
#include <sdk/ZHM3Item.h>

namespace ioi::hm3 {
	
	ZHM3Item* ZHM3Item_construct(const char* itemName)
	{
		/// types
		typedef ZEntityLocator* (__cdecl* ZEntityLocator_New_t)(int);
		typedef ZEntityLocator* (__thiscall* ZEntityLocator_Construct_t)(ZEntityLocator*);
		typedef void* (__cdecl* ZQElemsBuffer_Add_t)(int);
		typedef ZHM3Item* (__cdecl* ZHM3Item_Construct_t)(void*, const char*, ZEntityLocator*);

		/// imports
		ZEntityLocator_New_t ZEntityLocator_New = (ZEntityLocator_New_t)0x00431030;
		ZEntityLocator_Construct_t ZEntityLocator_Construct = (ZEntityLocator_Construct_t)0x00435080;
		ZQElemsBuffer_Add_t ZQElemsBuffer_Add = (ZQElemsBuffer_Add_t)0x004E7D90;
		ZHM3Item_Construct_t ZHM3Item_Construct = (ZHM3Item_Construct_t)0x0064AFF0;

		/// code
		auto entity = ZEntityLocator_New(0x70);
		entity = ZEntityLocator_Construct(entity);

		void* pItem = ZQElemsBuffer_Add(0x9C);
		auto item = ZHM3Item_Construct(pItem, itemName, entity);

		ioi::hm3::ZHM3Item::getItemIDByItemInstance(item); //assign item id

		return item;
	}

}