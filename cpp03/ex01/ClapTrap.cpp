// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/06 02:16:37 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 19:02:32 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include <iostream>

inline int ClapTrap::initialHitPoints()
{
	//std::cout << "ClapTrap::initialHitPoints()" << std::endl; 
	return 10;
}

inline int ClapTrap::initialEnergyPoints()
{
	//std::cout << "ClapTrap::initialEnergyPoints()" << std::endl; 
	return 10;
}

inline int ClapTrap::initialAttackDamage()
{
	//std::cout << "ClapTrap::initialAttackDamage()" << std::endl; 
	return 0;
}

ClapTrap::ClapTrap()
	: name("clap with no name"),
	  hitPoints(this->initialHitPoints()),
	  energyPoints(this->initialEnergyPoints()),
	  attackDamage(this->initialAttackDamage())
{
	std::cout << "ClapTrap()" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name),
	  hitPoints(this->initialHitPoints()),
	  energyPoints(this->initialEnergyPoints()),
	  attackDamage(this->initialAttackDamage())
{
	std::cout << "ClapTrap(" <<  name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap(const ClapTrap &other[" <<  other.name << "])" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "operator=(const ClapTrap &other[" <<  other.name << "])" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name + "_clap_copy";
	this->hitPoints = std::min(other.hitPoints, initialHitPoints());
	this->energyPoints = std::min(other.energyPoints, initialEnergyPoints());
	this->attackDamage = std::min(other.attackDamage, initialAttackDamage());
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "~ClapTrap()" << std::endl;
}

bool ClapTrap::active() const
{
	if (this->energyPoints <= 0)
	{
		this->announce();
		std::cout << "is too tired."
				  << std::endl << std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::alive() const
{
	if (this->hitPoints <=0)
	{
		this->announce();
		std::cout << "is in a coma."
				  << std::endl << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::announce() const
{
	std::cout << "ClapTrap " << this->name << ":"
			  << std::endl << "\t";
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->alive())
	{
		this->announce();
		std::cout << " takes " << amount
				  << " points of damage!";
		this->hitPoints -= amount <= static_cast<unsigned int>(hitPoints)
			? amount
			: hitPoints;
		if (this->hitPoints <= 0)
		{
			std::cout << " ClapTrap " << this->name
					  << " is now in a coma!" << std::endl;
		}
		else
		{
			std::cout << " Remaining " << this->hitPoints
					  << " hit points." << std::endl;
		}
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->alive() && this->active()) {
		this->energyPoints--;
		int restore_amount =
			this->hitPoints + static_cast<int>(amount) <= initialHitPoints() ?
			amount
			: initialHitPoints() - this->hitPoints;
		this->hitPoints += restore_amount;
		this->announce();
		std::cout << "restored " << restore_amount
				  << " hit points!"
				  << " Remaining " << this->energyPoints
				  << " energy points and "
				  << this->hitPoints << " hit points"
				  << std::endl << std::endl;
	}
}
