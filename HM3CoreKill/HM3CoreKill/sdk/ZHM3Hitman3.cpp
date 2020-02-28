#include <sdk/ZHM3Hitman3.h>
#include <ck/HM3DebugConsole.h>

namespace ioi { namespace hm3 {

	static constexpr int ZHitman3_LeftHandOffset  = 0x2C8;
	static constexpr int ZHitman3_RightHandOffset = 0x348;

	const NearActorRef& ZHM3Hitman3::getNearActorByTheirIndex(int32_t index)
	{
		HM3_ASSERT(index >= 0 && index < m_nearestActorsPoolCapacity, "Index should be greater or equal to zero and less than hitman3->m_nearestActorsPoolCapacity!");
		NearActorRef* poolPtr = reinterpret_cast<NearActorRef*>(&this->m_nearestActorsPoolFirstEntity);
		return poolPtr[index];
	}

	ZIKHAND* ZHM3Hitman3::getHand(HandType type)
	{
		switch (type)
		{
		case HandType::LeftHand:
			return reinterpret_cast<ZIKHAND*>(reinterpret_cast<std::byte*>(this) + ZHitman3_LeftHandOffset);
		case HandType::RightHand:
			return reinterpret_cast<ZIKHAND*>(reinterpret_cast<std::byte*>(this) + ZHitman3_RightHandOffset);
		default:
			return nullptr;
		}
	}
}}