#include <cstdint>
#include <sdk/ZHM3Actor.h>

namespace ioi { namespace hm3 {

	static constexpr int ZHM3Actor_LeftHandOffset = 0x2C8;
	static constexpr int ZHM3Actor_RightHandOffset = 0x348;

	ZIKHAND* ZHM3Actor::getHand(HandType type)
	{
		switch (type)
		{
		case HandType::LeftHand:
			return reinterpret_cast<ZIKHAND*>(reinterpret_cast<uint8_t*>(this) + ZHM3Actor_LeftHandOffset);
		case HandType::RightHand:
			return reinterpret_cast<ZIKHAND*>(reinterpret_cast<uint8_t*>(this) + ZHM3Actor_RightHandOffset);
		default:
			return nullptr;
		}
	}

}}