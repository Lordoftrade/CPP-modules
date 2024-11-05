#include "Weapon.hpp"

Weapon::Weapon(std::string newtype) : type(newtype) {};

const std::string& Weapon::getType() const
{
	return (type);
}

void Weapon::setType(const std::string& typeWeapon)
{
	type = typeWeapon;
}