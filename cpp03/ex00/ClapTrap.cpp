// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/06 02:16:37 by maurodri          #+#    #+#             //
//   Updated: 2025/02/06 19:35:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("clap with no name"),
	  hitPoints(INITIAL_HIT_POINTS),
	  energyPoints(INITIAL_ENERGY_POINTS),
	  attackDamage(INITIAL_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap()" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name),
	  hitPoints(INITIAL_HIT_POINTS),
	  energyPoints(INITIAL_ENERGY_POINTS),
	  attackDamage(INITIAL_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap(std::string name)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap(const ClapTrap &other)" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "operator=(const ClapTrap &other)" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name + " copy";
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
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
		int restore_amount = this->hitPoints + amount <= INITIAL_HIT_POINTS ?
			amount
			: INITIAL_HIT_POINTS - this->hitPoints;
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
