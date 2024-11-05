#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"
#include <string>

class HumanA {
	private:
		std::string name;
		Weapon& weapon;
	public:

		HumanA(const std::string& name_, Weapon& weapon_);
		void attack() const;
};

#endif 