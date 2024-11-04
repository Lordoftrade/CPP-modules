#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {};

Weapon::const std:string& getType()
{
	return (type);
}

Weapon::void setType(std::string& typeWeapon)
{
	type = typeWeapon;
}