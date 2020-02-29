#pragma once

namespace ioi {
namespace hm3 {

	class ZSysMem
	{
		/***
Vftable	 Methods	Flags	Type	Hierarchy
0075DE8C   15     ZSysMem  ZSysMem: ISysMem, ZComponentSingleton<ISysMem,ZGlobalComponentBase>, ZGlobalComponentBase, ZComponent<ZGlobalComponentBase,ZComponentDescription<1,ZGlobalComponentAllocator> >, ZComponentBase, NotCopyable;
		***/
	public:
		static void* allocate(unsigned int _size, const char* _allocSource, int _unk);
		static void deallocate(void* _ptr);
	};

}}