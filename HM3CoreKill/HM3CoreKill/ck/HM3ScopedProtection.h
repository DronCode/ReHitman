#pragma once

#include <Windows.h>

class HM3ScopedProtection
{
	DWORD m_memPtr, m_memSize, m_oldProtection, m_newProtection;
public:
	HM3ScopedProtection(DWORD memPtr, DWORD memSize, DWORD newProtection)
		: m_memPtr(memPtr)
		, m_memSize(memSize)
		, m_newProtection(newProtection)
	{
		VirtualProtect((LPVOID)memPtr, memSize, newProtection, &m_oldProtection);
	}

	~HM3ScopedProtection()
	{
		VirtualProtect((LPVOID)m_memPtr, m_memSize, m_oldProtection, nullptr);
	}
};