#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	name = "Default";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has no hit points!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has no energy points!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
