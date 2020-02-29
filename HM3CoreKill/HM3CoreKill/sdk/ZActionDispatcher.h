#pragma once

#include <cstdint>

namespace ioi { namespace hm3 {

	class ZActionDispatcher
	{
	public:
		int32_t m_currentAction; //0x0004

		virtual void Function0();
		virtual bool executeAction(int pAction);
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void __recallAnim_at0x18();
		virtual void resetAction();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
	}; //Size: 0x0008

} }