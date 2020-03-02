#pragma once

#include <string>
#include <functional>
#include <string_view>
#include <unordered_map>

#include <sdk/CDoor.h>

namespace ck {
	class HM3DoorsRegistry
	{
		std::unordered_map<std::string, ioi::hm3::CDoor*> m_doors;
	public:
		static HM3DoorsRegistry& getRegistry();

		void reset();
		void registerDoor(ioi::hm3::CDoor* door);
		ioi::hm3::CDoor* getDoorByName(const char* doorName) const;
		void forEachDoor(std::function<void(const std::string_view&, ioi::hm3::CDoor*)> predicate);
	};
}