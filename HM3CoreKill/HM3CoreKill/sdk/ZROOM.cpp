#include <sdk/ZROOM.h>

namespace ioi { namespace hm3 {

	ZROOM* ZROOM::getRoomByEntityLocator(ioi::hm3::ZEntityLocator* _entity)
	{
		typedef ZROOM* (__thiscall* GetRoomByEntityLocator_t)(ioi::hm3::ZEntityLocator*);
		GetRoomByEntityLocator_t GetRoomByEntityLocator = (GetRoomByEntityLocator_t)0x00432890;
		return _entity ? GetRoomByEntityLocator(_entity) : nullptr;
	}

} }