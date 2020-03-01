#include <ck/HM3FreeFileSystemLocatorProxy.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Offsets.h>

#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/FsZip_t.h>

#include <filesystem>

namespace fs = std::filesystem;

namespace ck {

	std::string HM3FreeFileSystemLocatorProxy::findFileInFolderRecursively(const std::string& folder, const std::string& file) try
	{
		try {
			for (const auto& entry : fs::directory_iterator(folder)) {
				const auto filenameStr = entry.path().filename().string();
				if (entry.is_directory()) {
					auto result = findFileInFolderRecursively(entry.path().string(), file);
					if (!result.empty())
						return result;
				}
				else if (entry.is_regular_file()) {
					if (filenameStr == file)
						return entry.path().string();
				}
			}
		}
		catch (...) {
			return "";
		}
		
		return "";
	}
	catch (const std::exception & ex)
	{
		HM3_DEBUG("findFileInFolderRecursively| Exception : %s\n", ex.what());
		HM3_ASSERT(false, "FATAL ERROR: See log for details");
	}

	int HM3FreeFileSystemLocatorProxy::readFileProvider(const char* name, void* dest, int fileSize, int unk1)
	{
		// --- copy pack info before pthis not corrupted ---
		int zipPackagePathLength = 0;
		const int zipPackagePathBuffLength = 512;
		char zipPackagePath[zipPackagePathBuffLength] = { 0 };

		if (this->m_zipFilePath && reinterpret_cast<DWORD>(this->m_zipFilePath) > 0xFFFFF)
		{
			zipPackagePathLength = strlen(this->m_zipFilePath);
			memcpy(zipPackagePath, this->m_zipFilePath, zipPackagePathLength);
		}
		else
		{
			zipPackagePathLength = strlen(this->m_missionZipFilePath);
			memcpy(zipPackagePath, this->m_missionZipFilePath, zipPackagePathLength);
		}

		// --- continue ---
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);

		// --- detect scene ---
		const int sceneIdBufferSize = 32;
		char sceneIdBuffer[sceneIdBufferSize] = { 0 };

		int missionNameLength = 0;
		int missionNameStartsAt = 0;
		int fullLength = strlen(sys->m_currentScene);
		int currentDividerId = 0;

		for (int i = 0; i < fullLength; i++)
		{
			if (sys->m_currentScene[i] == '\\' || sys->m_currentScene[i] == '/') //thx windows for this
			{
				++currentDividerId;
				if (currentDividerId > 1)
					break;
			}
			else if (sys->m_currentScene[i] == '.')
			{
				break;
			}
			else
			{
				if (currentDividerId == 1)
				{
					if (missionNameLength == 0)
						missionNameStartsAt = i;

					++missionNameLength;
					HM3_ASSERT(missionNameLength < sceneIdBufferSize, "MEMORY CORRUPTION: We trying to write more data than we have a free space!");
				}
			}
		}
		memcpy((void*)sceneIdBuffer, sys->m_currentScene + missionNameStartsAt, missionNameLength);
		// --- detect pack ---
		const int packageNameLength = 32;
		char packageName[packageNameLength] = { 0 };

		int zipPackageEndPtr = zipPackagePathLength - 1;
		int zipPackageStartPtr = -1;
		for (int i = zipPackagePathLength - 1; i >= 0; i--)
		{
			if (zipPackagePath[i] == '\\' || zipPackagePath[i] == '/')
			{
				break;
			}
			zipPackageStartPtr = i;
		}

		if (zipPackageStartPtr != -1 && zipPackageEndPtr - zipPackageStartPtr < packageNameLength) //In some cases we have corrupted environment. In that case best solution is use ZIP FS.
		{
			memcpy((void*)&packageName, zipPackagePath + zipPackageStartPtr, zipPackageEndPtr - zipPackageStartPtr - 3);
			// --- detect various file ---
			std::string fileName(name);
			bool fileNameResolved = false;

			if (fileName[0] == '*')
			{
				// Oh shit, IOI, I really hate you!
				// Here we need to find file by passed mask!
				const int maskedPathLength = 512;
				char maskedPath[maskedPathLength] = { 0 };


				//snprintf(maskedPath, maskedPathLength, "%s\\UnpackedScenes\\%s\\%s\\%s", currentPath, sceneIdBuffer, packageName, fileName);
				snprintf(maskedPath, maskedPathLength, "UnpackedScenes\\%s\\%s", sceneIdBuffer, packageName);

				std::string foundFile = findFileInFolderRecursively(maskedPath, fileName.c_str() + 1);
				if (!foundFile.empty())
				{
					fileName = foundFile;
					fileNameResolved = true;
				}

			}
			// --- detect full path to pure fs ---
			std::string finalFilePath;

			if (!fileNameResolved)
			{
				const int fullPathBufferSize = 512;
				char fullPathBuffer[fullPathBufferSize];
				snprintf(fullPathBuffer, fullPathBufferSize, "UnpackedScenes\\%s\\%s\\%s", sceneIdBuffer, packageName, fileName.c_str());
				finalFilePath = fullPathBuffer;
			}
			else {
				finalFilePath = fileName;
			}

			FILE* fileHandle = fopen(finalFilePath.c_str(), "rb");
			if (fileHandle)
			{
				if (fileSize == 0)
				{
					// The game engine doesn't know the actual size of file and pass zero to us
					// We must explore how much bytes will be used by file in memory space.
					fseek(fileHandle, 0L, SEEK_END);	//move to end
					fileSize = ftell(fileHandle); //save the endpoint
					rewind(fileHandle); //move to start of file
				}

				const int readyBytes = fread(dest, 1, fileSize, fileHandle);
				fclose(fileHandle);
				HM3_DEBUG("[0x%.8X] FsZip::readContents| read file from raw fs %s (ready bytes %d)\n", reinterpret_cast<int>(this), finalFilePath.c_str(), readyBytes);
				return readyBytes;
			}
		}

		// original code
		typedef int(__thiscall* FsZip_read_t)(ioi::hm3::FsZip_t*, const char*, void*, int, int);
		FsZip_read_t original = (FsZip_read_t)HM3Offsets::FsZip_ReadMethodFunc;
		int result = original(reinterpret_cast<ioi::hm3::FsZip_t*>(this), name, dest, fileSize, unk1);
		HM3_DEBUG("[0x%.8X] FsZip::readContents| read from ZIP FS file %s result put at 0x%.8X [%d;%d] => %d\n", reinterpret_cast<int>(this), name, dest, fileSize, unk1, result);
		return result;
	}

}