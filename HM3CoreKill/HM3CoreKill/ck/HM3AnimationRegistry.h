#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include <sdk/ZAnimationInfo.h>

namespace ck {

	class HM3AnimationRegistry
	{
		std::unordered_map<std::string, ioi::hm3::ZAnimationInfo*> m_loadedAnimations;

	public:
		static HM3AnimationRegistry& getRegistry();

		void registerAnimation(ioi::hm3::ZAnimationInfo* info);
		void reset();
		ioi::hm3::ZAnimationInfo* loadCustomAnimation(const char* animationPath);

		void getLoadedAnimations(std::vector<ioi::hm3::ZAnimationInfo*>& animations) const;
	};

}