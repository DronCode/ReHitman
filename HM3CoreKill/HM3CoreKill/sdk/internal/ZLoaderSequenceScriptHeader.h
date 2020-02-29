#pragma once

#include <cstdint>

namespace ioi {
namespace hm3 {
namespace formats {

	class ZLoaderSequenceScriptHeader
	{
	public:
		uint32_t m_keyFramesCount; //0x0000
		int32_t m_pictureSettingsFieldsCount; //0x0004
		char* m_currentNodeName; //0x0008
		char pad_000C[4]; //0x000C
		float* m_currentFrame; //0x0010
		float m_firstFrame; //0x0014
		float m_endFrame; //0x0018
		int32_t m_screenSizeWidth; //0x001C
		int32_t m_screenSizeHeight; //0x0020
		float m_fullProgressTime; //0x0024
	}; //Size: 0x0028

}}}