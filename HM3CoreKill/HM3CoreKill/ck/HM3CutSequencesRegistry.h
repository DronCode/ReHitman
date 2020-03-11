#pragma once

#include <set>
#include <string>
#include <functional>
#include <sdk/CCutSequence.h>

namespace ck
{

	class HM3CutSequencesRegistry
	{
		std::set<ioi::hm3::CCutSequence*> m_registry;
	public:
		static HM3CutSequencesRegistry& getRegistry();

		void registerCutSequence(ioi::hm3::CCutSequence* sequence);
		void reset();
		void forEach(std::function<void(ioi::hm3::CCutSequence*)> pred);
	};

}