// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/21 22:12:31 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>


int main(void)
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("steel club");
	bob.attack();


	Weapon firearm = Weapon("pistol");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(&firearm);
	jim.attack();
	firearm.setType("machine gun");
	jim.attack();

	return (0);
}
