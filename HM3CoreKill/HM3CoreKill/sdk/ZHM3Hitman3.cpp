#include <sdk/ZHM3Hitman3.h>
#include <ck/HM3DebugConsole.h>

namespace ioi { namespace hm3 {

	const NearActorRef& ZHM3Hitman3::getNearActorByTheirIndex(int32_t index)
	{
		HM3_ASSERT(index >= 0 && index < m_nearestActorsPoolCapacity, "Index should be greater or equal to zero and less than hitman3->m_nearestActorsPoolCapacity!");
		NearActorRef* poolPtr = reinterpret_cast<NearActorRef*>(&this->m_nearestActorsPoolFirstEntity);
		return poolPtr[index];
	}

}}