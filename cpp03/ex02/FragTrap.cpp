// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/07 22:37:13 by maurodri          #+#    #+#             //
//   Updated: 2025/02/11 21:55:37 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

inline int FragTrap::initialHitPoints()
{
	//std::cout << "FragTrap::initialHitPoints()" << std::endl; 
	return 100;
}

inline int FragTrap::initialEnergyPoints()
{
	//std::cout << "FragTrap::initialEnergyPoints()" << std::endl; 
	return 100;
}

inline int FragTrap::initialAttackDamage()
{
	//std::cout << "FragTrap::initialAttackDamage()" << std::endl; 
	return 30;
}


FragTrap::FragTrap() : ClapTrap("frag with no name")
{
	std::cout << "FragTrap()" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap(" << name << ")" << std::endl;
	this->hitPoints = initialHitPoints();
	this->energyPoints = initialEnergyPoints();
	this->attackDamage = initialAttackDamage();
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap(const FragTrap &other[" << other.name << "])" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "operator=(const FragTrap &other[" <<  other.name << "])" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name + "_frag_copy";
	this->hitPoints = std::min(other.hitPoints, initialHitPoints());
	this->energyPoints = std::min(other.energyPoints, initialEnergyPoints());
	this->attackDamage = std::min(other.attackDamage, initialAttackDamage());
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "~FragTrap()" << std::endl;
}


void FragTrap::announce() const
{
	std::cout << "FragTrap " << this->name << ":"
			  << std::endl << "\t";
}

void FragTrap::attack(const std::string& target)
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

void FragTrap::highFivesGuys(void)
{

	this->announce();
	std::cout << "high fives all fams" 
	<< std::endl << std::endl;
}
