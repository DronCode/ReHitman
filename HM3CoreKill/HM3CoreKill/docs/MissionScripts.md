Scripting & Missions
=====================

Each mission (exclude main menu) contains their own DLL with four sections:

 1. SF. Not used (?) by game; NOTE: Loaded in sub_43BF50 but result of ```GetProcAddress(hModule, (LPCSTR)1);``` not used.
 2. ISF
 3. Scripts - list of required (from engine) scripts. This is list (with offset +4) of strings. Can be empty. Base of this section will be placed at 0x008A89D4
 4. ScriptImports - all imported entities. Max 179 (716 bytes, 4 bytes per import)