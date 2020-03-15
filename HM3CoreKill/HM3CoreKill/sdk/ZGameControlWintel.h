#pragma once

namespace ioi { namespace hm3 {

	class ZGameControlWintel
	{
	public:
		/// === members ===
		char pad_0004[76]; //0x0004
		int32_t m_tick; //0x0050
		char pad_0054[496]; //0x0054

		/// === vftable ===
		virtual void Function0();
	};

} }