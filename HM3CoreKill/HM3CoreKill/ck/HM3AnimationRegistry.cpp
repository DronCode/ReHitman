#include <ck/HM3AnimationRegistry.h>
#include <ck/HM3DebugConsole.h>

namespace ck
{

	HM3AnimationRegistry& HM3AnimationRegistry::getRegistry()
	{
		static HM3AnimationRegistry instance;
		return instance;
	}

	void HM3AnimationRegistry::registerAnimation(ioi::hm3::ZAnimationInfo* info)
	{
		if (!info)
			return;

		m_loadedAnimations[info->m_name] = info;
		HM3_DEBUG("[HM3AnimationRegistry::registerAnimation] register animation \"%s\" with ID %.8X at 0x%.8X\n", info->m_name, info->m_id, info);
	}
	
	void HM3AnimationRegistry::reset()
	{
		m_loadedAnimations.clear();
		HM3_DEBUG("[HM3AnimationRegistry::reset] unload all!\n");
	}

	void HM3AnimationRegistry::getLoadedAnimations(std::vector<ioi::hm3::ZAnimationInfo*>& animations) const
	{
		animations.reserve(m_loadedAnimations.size());

		for (const auto& [name, info] : m_loadedAnimations)
		{
			animations.push_back(info);
		}
	}
}