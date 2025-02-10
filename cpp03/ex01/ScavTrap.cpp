// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/07 22:37:13 by maurodri          #+#    #+#             //
//   Updated: 2025/02/07 23:54:56 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

inline int ScavTrap::initialHitPoints()
{
	//std::cout << "ScavTrap::initialHitPoints()" << std::endl; 
	return 100;
}

inline int ScavTrap::initialEnergyPoints()
{
	//std::cout << "ScavTrap::initialEnergyPoints()" << std::endl; 
	return 50;
}

inline int ScavTrap::initialAttackDamage()
{
	//std::cout << "ScavTrap::initialAttackDamage()" << std::endl; 
	return 20;
}


ScavTrap::ScavTrap() : ClapTrap("scav with no name")
{
	std::cout << "ScavTrap()" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap(std::string name)" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap(const ScavTrap &other)" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "operator=(const ScavTrap &other)" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name + "scav_copy";
	this->hitPoints = std::min(other.hitPoints, initialHitPoints());
	this->energyPoints = std::min(other.energyPoints, initialEnergyPoints());
	this->attackDamage = std::min(other.attackDamage, initialAttackDamage());
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "~ScavTrap()" << std::endl; 
}


void ScavTrap::announce() const
{
	std::cout << "ScavTrap " << this->name << ":"
			  << std::endl << "\t";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->alive() && this->active()) {
		this->energyPoints--;
		this->announce();
		std::cout << " attacks " << target
				  << ", causing " << this->attackDamage
				  << " points of damage!"
				  << " Remaining " << this->energyPoints << " energy points."
				  << std::endl << std::endl;
	}
}

