Scripting & Missions
=====================

Each mission (excluding main menu) contains their own DLL loaded from 'Scriptcs', they contain four sections:

 1. SF. 
	 - Not used (?) by game; NOTE: Loaded in sub_43BF50 but result of ```GetProcAddress(hModule, (LPCSTR)1);``` not used.
 2. ISF
 3. Scripts 
	 - List of required scripts from the Engine.
	 - This is a list (with an offset +4) of strings. Can be empty. Base of this section will be placed at 0x008A89D4
 4. ScriptImports
	 - all imported entities. Max 179 (716 bytes, 4 bytes per import)