#include <ck/HM3AnimationRegistry.h>
#include <ck/HM3DebugConsole.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/ZHM3GameData.h> //ZHitman3 definition (pre-def)

#ifdef HM3_TRACE_ANIMATIONS
#define HM3_TRACE_LOAD_ANIM(name, id, pInfo)	HM3_DEBUG("[HM3AnimationRegistry::registerAnimation] register animation \"%s\" with ID %.8X at 0x%.8X\n", name, id, pInfo)
#define HM3_TRACE_UNLOAD_ALL					HM3_DEBUG("[HM3AnimationRegistry::reset] unload all!\n")
#define HM3_TRACE_BAD_ANIMATION(path)			HM3_DEBUG("[HM3AnimationRegistry::loadCustomAnimation] failed to load animation \"%s\"\n", path)
#else
#define HM3_TRACE_LOAD_ANIM(name, id, pInfo)
#define HM3_TRACE_UNLOAD_ALL
#define HM3_TRACE_BAD_ANIMATION(path)
#endif

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
		HM3_TRACE_LOAD_ANIM(info->m_name, info->m_id, info);
	}
	
	void HM3AnimationRegistry::reset()
	{
		m_loadedAnimations.clear();
		HM3_TRACE_UNLOAD_ALL;
	}

	ioi::hm3::ZAnimationInfo* HM3AnimationRegistry::loadCustomAnimation(const char* animationPath)
	{
		auto gameData = ioi::hm3::getGlacierInterface<ioi::hm3::ZHM3GameData>(ioi::hm3::GameData);
		HM3_ASSERT(gameData, "GameData should be initialized here!");
		if (!gameData)
			return nullptr;

		typedef ioi::hm3::ZAnimationInfo* (__thiscall* Glacier_PreloadAnimation_t)(ioi::hm3::ZHitman3*, const char*);
		Glacier_PreloadAnimation_t preloadAnimation = (Glacier_PreloadAnimation_t)0x00519AE0;
		
		auto animation = preloadAnimation(gameData->m_Hitman3, animationPath);
		if (!animation)
		{
			HM3_TRACE_BAD_ANIMATION(animationPath);
			return nullptr;
		}

		registerAnimation(animation);
		return animation;
	}

	ioi::hm3::ZAnimationInfo* HM3AnimationRegistry::getAnimationByName(const char* animationName) const
	{
		auto foundIter = m_loadedAnimations.find(animationName);
		if (foundIter == std::end(m_loadedAnimations))
			return nullptr;

		return foundIter->second;
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