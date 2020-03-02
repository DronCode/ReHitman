#include <sdk/ZSysMem.h>
#include <sdk/ZGameGlobals.h>

namespace ioi { namespace hm3 {

	void* ZSysMem::allocate(unsigned int _size, const char* _allocSource, int _unk)
	{
		typedef void*(__cdecl* Glacier_malloc_t)(unsigned int, const char*, int);
		Glacier_malloc_t gmalloc = (Glacier_malloc_t)ioi::hm3::GlacierMallocFunc;
		return gmalloc(_size, _allocSource, _unk);
	}
	
	void ZSysMem::deallocate(void* _ptr)
	{
		typedef void(__cdecl* Glacier_free_t)(void*);
		Glacier_free_t gfree = (Glacier_free_t)ioi::hm3::GlacierFreeFunc;
		gfree(_ptr);
	}

}}