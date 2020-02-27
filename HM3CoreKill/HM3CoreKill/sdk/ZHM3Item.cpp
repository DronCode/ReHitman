#include <sdk/ZHM3Item.h>
#include <sdk/ZGameGlobals.h>

namespace ioi {	namespace hm3 {

	ZHM3Item* getItemById(std::intptr_t itemID)
	{
		typedef ZHM3Item* (__cdecl* GetItemInfoByID_t)(std::intptr_t);
		static GetItemInfoByID_t GetItemInfoByID = (GetItemInfoByID_t)GetItemInfoFunc;
		return GetItemInfoByID(itemID);
	}

} }