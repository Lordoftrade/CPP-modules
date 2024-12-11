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


void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left and cannot attack!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is already at 0 hit points!" << std::endl;
		return;
	}
	_hitPoints = (amount > _hitPoints) ? 0 : (_hitPoints - amount);
	std::cout << "FragTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
}


void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " cannot repair itself because it has 0 hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy left and cannot repair itself!" << std::endl;
		return;
	}
	_hitPoints = ((_hitPoints + amount) > 100) ? 100 : (_hitPoints + amount);
	_energyPoints--;
	std::cout << "FragTrap " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
