#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

//_name(another.name), _hitPoints(another.hitPoints), _energyPoints(another.energyPoints), attackDamage(another.attackDamage)
ClapTrap::ClapTrap(const ClapTrap& another)
{
	*this = another;
	std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& another)
{
	if (this != &another) {
		_name = another._name;
		_hitPoints = another._hitPoints;
		_energyPoints = another._energyPoints;
		_attackDamage = another._attackDamage;
		std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left and cannot attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already at 0 hit points!" << std::endl;
		return;
	}
	_hitPoints = (amount > _hitPoints) ? 0 : (_hitPoints - amount);
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoints << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself because it has 0 hit points!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left and cannot repair itself!" << std::endl;
		return;
	}
	_hitPoints = ((_hitPoints + amount) > 100) ? 100 : (_hitPoints + amount);
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
}