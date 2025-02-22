// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/21 21:00:14 by maurodri          #+#    #+#             //
//   Updated: 2025/01/25 15:05:56 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
    : weapon(NULL),
	  name(name) {}

void HumanB::attack(void) const
{
	std::string weapon = this->weapon == NULL ? "bare hands" : this->weapon->getType();
	std::cout << name << " attacks with their " << weapon << std::endl;
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon; 
}
