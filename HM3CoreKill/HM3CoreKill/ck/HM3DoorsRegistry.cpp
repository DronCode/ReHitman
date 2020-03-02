#include <ck/HM3DoorsRegistry.h>
#include <ck/HM3DebugConsole.h>
#include <Windows.h>

namespace ck {

	HM3DoorsRegistry& HM3DoorsRegistry::getRegistry()
	{
		static HM3DoorsRegistry instance;
		return instance;
	}

	void HM3DoorsRegistry::reset()
	{
		m_doors.clear();
	}

	void HM3DoorsRegistry::registerDoor(ioi::hm3::CDoor* door)
	{
		HM3_ASSERT(door != nullptr, "Unable to register wrong door.");

		HM3_DEBUG("[HM3DoorsRegistry::registerDoor] register door %s\n", door->m_doorSTD->m_entityLocation->entityName);
		m_doors[door->m_doorSTD->m_entityLocation->entityName] = door;
	}

	ioi::hm3::CDoor* HM3DoorsRegistry::getDoorByName(const char* doorName) const
	{
		auto foundDoorIter = m_doors.find(doorName);
		if (foundDoorIter == std::end(m_doors))
			return nullptr;

		return foundDoorIter->second;
	}

	void HM3DoorsRegistry::forEachDoor(std::function<void(const std::string_view&, ioi::hm3::CDoor*)> predicate)
	{
		for (const auto& [doorName, doorInstance] : m_doors)
		{
			predicate(doorName, doorInstance);
		}
	}
}