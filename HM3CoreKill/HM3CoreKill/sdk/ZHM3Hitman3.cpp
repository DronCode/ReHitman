#include <sdk/ZHM3Hitman3.h>
#include <ck/HM3DebugConsole.h>

static constexpr const std::size_t ZIKHAND_ComponentOffset = 0x348;

namespace ioi { namespace hm3 {

	const NearActorRef& ZHM3Hitman3::getNearActorByTheirIndex(int32_t index)
	{
		HM3_ASSERT(index >= 0 && index < m_nearestActorsPoolCapacity, "Index should be greater or equal to zero and less than hitman3->m_nearestActorsPoolCapacity!");
		NearActorRef* poolPtr = reinterpret_cast<NearActorRef*>(&this->m_nearestActorsPoolFirstEntity);
		return poolPtr[index];
	}

	ZIKHAND* ZHM3Hitman3::getZIKHAND()
	{
		return reinterpret_cast<ZIKHAND*>(reinterpret_cast<std::byte*>(this) + ZIKHAND_ComponentOffset);
	}
}}