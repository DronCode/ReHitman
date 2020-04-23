#include <sdk/ZGROUP.h>

namespace ioi { namespace hm3 {

	ZGROUP* ZGROUP::getGroupByEntityLocator(ioi::hm3::ZEntityLocator* _entity)
	{
		typedef ZGROUP* (__thiscall* GetGroupByEntityLocator_t)(ioi::hm3::ZEntityLocator*);
		GetGroupByEntityLocator_t method = (GetGroupByEntityLocator_t)0x00432640;
		return _entity ? method(_entity) : nullptr;
	}

} }