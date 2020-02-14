#pragma once

/// DEFS FOR X86 INSTRUCTIONS

#define x86_pushad   0x60
#define x86_pushfd   0x9C

#define x86_popad    0x61
#define x86_popfd    0x9D

#define x86_push_eax 0x50
#define x86_push_ecx 0x51
#define x86_push_edx 0x52
#define x86_push_ebp 0x55
#define x86_push_esi 0x56
#define x86_push_edi 0x57

#define x86_pop_eax  0x58
#define x86_pop_ecx  0x59
#define x86_pop_esi  0x5E

#define x86_nop		 0x90

#define X86_SAVE_REGION		\
	__asm pushad			\
	__asm pushfd

#define X86_RESTORE_REGION	\
	__asm popfd				\
	__asm popad