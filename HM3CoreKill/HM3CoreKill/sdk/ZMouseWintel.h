#pragma once

namespace ioi { namespace hm3 {

	class ZMouseWintel
	{
	public:
		char pad_0000[44]; //0x0000
		uint32_t m_mouseState; //0x002C
		char pad_0030[60]; //0x0030
		uint32_t m_directInput; //0x006C
		uint32_t m_device2; //0x0070
		char pad_0074[540]; //0x0074
		int32_t m_x; //0x0290
		int32_t m_y; //0x0294
		int32_t m_wheel; //0x0298
		uint8_t m_leftButton; //0x029C
		uint8_t m_rightButton; //0x029D
		uint8_t m_midButton; //0x029E
		char pad_029F[177]; //0x029F

	}; //Size: 0x0088

}}