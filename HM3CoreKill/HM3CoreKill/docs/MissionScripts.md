Scripting & Missions
=====================

Each mission (excluding the main menu) contains their own DLL loaded from \Scriptcs, each DLL contains four sections:

 1. SF. 
	 - Not used by the game
		- NOTE: Loaded in sub_43BF50 but result of ```GetProcAddress(hModule, (LPCSTR)1);``` not used.
 2. ISF
 3. Scripts 
	 - List of required scripts from the Engine.
	 - This is a list (with an offset of +4) of strings. Can be empty. Base of this section will be placed at 0x008A89D4
 4. ScriptImports
	 - All imported entities. Max 179 (716 bytes, 4 bytes per import)