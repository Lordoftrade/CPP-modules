#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << name << ": is destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName)
{
	name = newName;
}

