// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiamondTrap.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 15:44:00 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 19:17:32 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DiamondTrap.hpp"
#include <iostream>

inline int DiamondTrap::initialHitPoints()
{
	return this->FragTrap::initialHitPoints();
}

inline int DiamondTrap::initialEnergyPoints()
{
	return this->ScavTrap::initialEnergyPoints();
}

inline int DiamondTrap::initialAttackDamage()
{
	return this->FragTrap::initialAttackDamage();
}

DiamondTrap::DiamondTrap()
    : FragTrap("diamond with no name"),
      ScavTrap("diamond with no name"),
	  name("diamond with no name")
{
	this->ClapTrap::name = this->name + "_clap_name";
	std::cout << "DiamondTrap()" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name)
	    : FragTrap(name),
          ScavTrap(name),
		  name(name)
{
	this->ClapTrap::name = this->name + "_clap_name";
	std::cout << "DiamondTrap(" <<  name << ")" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap(const DiamondTrap &other[" <<  other.name << "])" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "operator=(const DiamondTrap &other[" <<  other.name << "])" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name + "_clap_copy";
	this->hitPoints = std::min(other.hitPoints, initialHitPoints());
	this->energyPoints = std::min(other.energyPoints, initialEnergyPoints());
	this->attackDamage = std::min(other.attackDamage, initialAttackDamage());
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "~DiamondTrap()" << std::endl;
}


void DiamondTrap::announce() const
{
	std::cout << "DiamondTrap " << this->name << ":"
			  << std::endl << "\t";
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	this->announce();
	std::cout << "My name is " << this->name
			  << ", and my clap name is " << this->ClapTrap::name
	          << std::endl << std::endl;
		
		
}
