#include <sdk/ZEngineDatabase.h>

namespace ioi { namespace hm3 {

	CCOM* getCCOMObjectFromEngineDB(ZEngineDatabase* instance)
	{
		CCOM* result = nullptr;
		__asm {
			push ecx
			push eax

			mov ecx, dword ptr[instance]
			lea eax, dword ptr[ecx + 0x1164]
			mov result, eax

			pop eax
			pop ecx
		}	// ref to sub_45AED0

		return result;
	}

}}