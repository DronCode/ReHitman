#include <ck/HM3FreeFileSystemLocatorProxy.h>
#include <ck/HM3DebugConsole.h>
#include <ck/HM3Offsets.h>

#include <sdk/ZSysInterfaceWintel.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/FsZip_t.h>

#include <filesystem>
#include <fmt/format.h>

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
		auto sys = ioi::hm3::getGlacierInterface<ioi::hm3::ZSysInterfaceWintel>(ioi::hm3::SysInterface);

		// --- detect scene ---
		std::string fileName = name;
		std::string zipPackageFileName = fs::path(this->m_missionZipFilePath).stem().string();
		std::string sceneName = fs::path(sys->m_currentScene).stem().string();

		if (fileName[0] == '*')
		{
			fileName = findFileInFolderRecursively(
				fmt::format("UnpackedScenes\\{}\\{}", sceneName, zipPackageFileName),
				fileName.substr(1, fileName.length())
			);
		}

		std::string path = fmt::format("UnpackedScenes\\{}\\{}\\{}", sceneName, zipPackageFileName, fileName);
		
		FILE* fp = fopen(path.c_str(), "rb");
		if (fp)
		{
			if (fileSize == 0)
			{
				// The game engine doesn't know the actual size of file and pass zero to us
				// We must explore how much bytes will be used by file in memory space.
				fseek(fp, 0L, SEEK_END);	//move to end
				fileSize = ftell(fp); //save the endpoint
				rewind(fp); //move to start of file
			}

			const int readyBytes = fread(dest, 1, fileSize, fp);
			fclose(fp);
			HM3_DEBUG("[0x%.8X] FsZip::readContents| read file from raw fs %s (ready bytes %d)\n", reinterpret_cast<int>(this), path.c_str(), readyBytes);
			return readyBytes;
		}

		// original code
		typedef int(__thiscall* FsZip_read_t)(ioi::hm3::FsZip_t*, const char*, void*, int, int);
		FsZip_read_t original = (FsZip_read_t)HM3Offsets::FsZip_ReadMethodFunc;
		int result = original(reinterpret_cast<ioi::hm3::FsZip_t*>(this), name, dest, fileSize, unk1);
		HM3_DEBUG("[0x%.8X] FsZip::readContents| read from ZIP FS file %s result put at 0x%.8X [%d;%d] => %d\n", reinterpret_cast<int>(this), name, dest, fileSize, unk1, result);
		return result;
	}

}