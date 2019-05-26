#include <ck/HM3Player.h>

void HM3Player::setDoesAcceptDamage(bool value)
{
	m_doesAcceptDamage = value;
}

bool HM3Player::isDoesAcceptDamage() const
{
	return m_doesAcceptDamage;
}