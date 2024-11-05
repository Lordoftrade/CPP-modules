#include "HumanA.hpp"

HumanA::HumanA(const std::string& name_, Weapon& weapon_) : name(name_), weapon(weapon_) {}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}