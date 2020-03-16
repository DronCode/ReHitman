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

	ZSTDOBJ* getSTDOBJById(std::uintptr_t objectId)
	{
		using sub4E5BE0_t = ZSTDOBJ * (__cdecl*)(std::uintptr_t);
		sub4E5BE0_t sub4E5BE0 = (sub4E5BE0_t)0x004E5BE0;
		return sub4E5BE0(objectId);
	}

	REFTAB32* getEntitiesListFromCCOM(CCOM* instance)
	{
		REFTAB32* result = nullptr;
		__asm {
			mov ecx, instance
			test ecx, ecx
			jz __getEntitiesListFromCCOM__end
			lea eax, [ecx + 0x4008]
		__getEntitiesListFromCCOM__end:
			mov result, eax
		}
		return result;
	}
}}