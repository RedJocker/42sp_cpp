// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/21 21:00:14 by maurodri          #+#    #+#             //
//   Updated: 2025/01/25 15:06:16 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : weapon(weapon),
	  name(name) {}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}



