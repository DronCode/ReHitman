#include <sdk/ZHM3Item.h>
#include <sdk/ZGameGlobals.h>

namespace ioi {	namespace hm3 {

	ZHM3Item* ZHM3Item::findItemByID(int itemID)
	{
		typedef ZHM3Item* (__cdecl* GetItemInfoByID_t)(std::intptr_t);
		GetItemInfoByID_t GetItemInfoByID = (GetItemInfoByID_t)GetItemInfoFunc;
		return GetItemInfoByID(itemID);
	}

	int ZHM3Item::getItemIDByItemInstance(ZHM3Item* instance)
	{
		if (!instance)
			return 0;

		typedef int(__thiscall* GetItemIDByInstance_t)(ioi::hm3::ZHM3Item*);
		GetItemIDByInstance_t GetItemIDByInstance = (GetItemIDByInstance_t)0x004E5BC0;
		return GetItemIDByInstance(instance);
	}

}}