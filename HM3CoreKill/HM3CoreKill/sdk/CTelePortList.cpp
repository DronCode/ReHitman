#include <sdk/CTelePortList.h>
#include <sdk/ZGameGlobals.h>

namespace ioi { namespace hm3 { 
	
	CTelePortList* CTelePortList::create()
	{
		typedef CTelePortList* (__cdecl* CTelePortList__ctor_t)(ZGlacierRTTI*);
		CTelePortList__ctor_t CTelePortList__ctor = (CTelePortList__ctor_t)CTelePortList_ConstructorFunc;
		return CTelePortList__ctor(reinterpret_cast<ZGlacierRTTI*>(CTelePortList_RTTI));
	}

}}