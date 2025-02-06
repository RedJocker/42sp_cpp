// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/06 02:16:37 by maurodri          #+#    #+#             //
//   Updated: 2025/02/06 02:30:02 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap()" << std::endl; 
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap(std::string name)" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap(const ClapTrap &other)" << std::endl; 
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "operator=(const ClapTrap &other)" << std::endl; 
}

ClapTrap::~ClapTrap()
{
	std::cout << "~ClapTrap()" << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "attack(const std::string& target)" << std::endl; 
}	

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "takeDamage(unsigned int amount)" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "beRepaired(unsigned int amount)" << std::endl; 
}
