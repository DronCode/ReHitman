#include <sdk/ZHM3Item.h>
#include <sdk/ZGameGlobals.h>

namespace ioi {	namespace hm3 {

	ZHM3Item* ZHM3Item::findItemByID(int itemID)
	{
		typedef ZHM3Item* (__cdecl* GetItemInfoByID_t)(std::intptr_t);
		GetItemInfoByID_t GetItemInfoByID = (GetItemInfoByID_t)GetItemInfoFunc;
		return GetItemInfoByID(itemID);
	}

} }