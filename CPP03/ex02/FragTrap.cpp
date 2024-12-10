#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& another) : ClapTrap(another)
{
	std::cout << "FragTrap " << _name << " copied!" << std::endl;
	*this = another;
}
FragTrap& FragTrap::operator=(const FragTrap& another)
{
	if (this != &another)
	{
		ClapTrap::operator=(another);
		std::cout << "FragTrap " << _name << " assigned!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
