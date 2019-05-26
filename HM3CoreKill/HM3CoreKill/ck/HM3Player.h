#pragma once

#include <memory>

class HM3Player
{
public:
	using Ptr = std::shared_ptr<HM3Player>;

	void setDoesAcceptDamage(bool value);
	bool isDoesAcceptDamage() const;
private:
	bool m_doesAcceptDamage = true;
};