#include "Zombie.hpp"

Zombie::Zombie() {
	name = "Default";
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << "Zombie created with name: " << name << std::endl;
}

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

