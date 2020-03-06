#pragma once

#include <cstdint>
#include <sdk/internal/ZLoaderSequenceScriptHeader.h>

namespace ioi { namespace hm3 {

	struct ZLoader_Sequence_Config
	{
		int* field_0;
		unsigned int m_keyFramesCount;
		int m_pictureSettingsFieldsCount;
		char* m_nodeName;
		int field_10;
		float* m_currentFrame;
		float m_firstFrame;
		float m_endFrame;
		unsigned int m_screenSizeWidth;
		unsigned int m_screenSizeHeight;
		float m_fullProgressTime;
	};

	class ZLoader_Sequence_Wintel_D3D
	{
	public:
		virtual void Function_0(); //ctor&dtor o_0
		virtual void onLoad();
		virtual void onDraw();
		virtual void onUpdate();
		virtual void Function_4(); /// on thread locker
		virtual void Function_5(); /// on thread locker

		// === data ===
		int field_4;
		int field_8;
		ZLoader_Sequence_Config* m_loaderSequenceConfig;
		int field_10;
		float field_14;
		int field_18;
		int field_1C;
		int field_20;
	};

} }