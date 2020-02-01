#include <Windows.h>

#include <ck/HM3Game.h>
#include <ck/HM3MemoryProvider.h>
#include <ck/HM3CrashHandler.h>

#include <utils/X86MemAccessEngine.h>

DWORD WINAPI HM3Thread(VOID*)
{ 
	HM3CrashHandler::Setup();	/// RUN OUR CUSTOM CRASH HANDLER

	HM3MemoryProvider* g_memoryProvider = new HM3MemoryProvider(); /// Our abstract memory provider (just concept)
	x86::X86MemAccessEngine::getInstance().setAccessorInterface(g_memoryProvider); /// Setup memory provider

	HM3Game::getInstance().Initialise(); /// Initialise all patches and hooks
	HM3Game::getInstance().Run(); /// Lock current thread before we will ready to exit

	delete g_memoryProvider;
	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		/// RUN THE EXTERNAL DETACHED THREAD AND RELEASE THIS THREAD NOW
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HM3Thread, nullptr, 0, 0);
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		/// KILL ALL THREADS
		FreeLibraryAndExitThread(hinstDLL, 0);
	}

	return true;
}