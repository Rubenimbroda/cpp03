#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
{
	name = "Default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has no hit points!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has no energy points!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			  << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't take more damage because it has no hit points!" << std::endl;
		return;
	}
	if (amount >= static_cast<unsigned int>(hitPoints))
		hitPoints = 0;
	else
		hitPoints -= static_cast<int>(amount);

	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage! Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't be repaired because it has no hit points!" << std::endl;
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't be repaired because it has no energy points!" << std::endl;
		return;
	}

	hitPoints += static_cast<int>(amount);
	--energyPoints;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
			  << " hit points! Hit points: " << hitPoints << std::endl;
}
