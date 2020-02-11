ReHitman
--------

![Debug Console_Preview](GitHub/index_preview.png)

What is ReHitman?
===========

ReHitman is an attempt to reverse the executable of Hitman Blood Money.
The final goal of the project is to develop a multiplayer similar to Mafia 2's Mutli-player.

Game Build Information.
===========

This project is built on the last build of Hitman Blood Money that IO Interactive released.

Executable String: blood-build3-20060616-26123

Directories.
===========

This project includes 2 directories:

 * Launcher    
	- The launcher is the Main DLL injector which controls the game.

 * HM3CoreKill 
	- This is the projects core of reverse engineering and contains various libaries

For developers
===============

You can build & debug ReHitman with game. 

For this just switch solution configuration to "DebugGame" and write path to folder with game into environment variable `ReHitmanGameFolder`

Current Project Goals.
===========

 - [x] Create an open source SDK for the Glacier 1 Engine
 - [ ] Reverse the rendering API
 - [x] Implement ImGUI backend over Glacier renderer wrapper (ZWintelRendererD3D)
 - [x] Reverse the input API (mouse, keyboard)
 - [ ] Reverse the GUI API
 - [ ] Implement a custom widget with logic on CoreKill.dll side
 - [ ] Reverse the scene format
 - [ ] Create a toolset for Hitman Blood Money

Contact Information.
===========

You can contact me in the project's issue tracker (any questions, ideas, etc).
