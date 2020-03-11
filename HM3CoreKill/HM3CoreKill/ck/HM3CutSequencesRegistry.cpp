#include <ck/HM3CutSequencesRegistry.h>
#include <sdk/ZSTD.h>

namespace ck {

	HM3CutSequencesRegistry& HM3CutSequencesRegistry::getRegistry()
	{
		static HM3CutSequencesRegistry instance;
		return instance;
	}

	void HM3CutSequencesRegistry::registerCutSequence(ioi::hm3::CCutSequence* sequence)
	{
		if (!sequence)
			return;

		m_registry.insert(sequence);
	}
	
	void HM3CutSequencesRegistry::reset()
	{
		m_registry.clear();
	}
	
	void HM3CutSequencesRegistry::forEach(std::function<void(ioi::hm3::CCutSequence*)> pred)
	{
		for (const auto& sequence : m_registry)
		{
			pred(sequence);
		}
	}
}