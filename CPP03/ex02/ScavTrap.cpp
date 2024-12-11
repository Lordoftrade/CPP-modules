#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& another) : ClapTrap(another)
{
	std::cout << "ScavTrap " << _name << " copied!" << std::endl;
	*this = another;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& another)
{
	if (this != &another)
	{
		ClapTrap::operator=(another);
		//_name = another._name;
		//_hitPoints = another._hitPoints;
		//_energyPoints = another._energyPoints;
		//_attackDamage = another._attackDamage;
		std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left and cannot attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}


void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already at 0 hit points!" << std::endl;
		return;
	}
	_hitPoints = (amount > _hitPoints) ? 0 : (_hitPoints - amount);
	std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
}


void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot repair itself because it has 0 hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left and cannot repair itself!" << std::endl;
		return;
	}
	_hitPoints = ((_hitPoints + amount) > 100) ? 100 : (_hitPoints + amount);
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
