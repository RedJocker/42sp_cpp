// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/17 17:27:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap furious_frag ("furious frag");
	std::cout << "" << std::endl;

	furious_frag.attack("someone");
	furious_frag.beRepaired(1);
	furious_frag.takeDamage(5);
	furious_frag.beRepaired(1);
	furious_frag.highFivesGuys();
	furious_frag.guardGate();
	furious_frag.whoAmI();
	{
		ClapTrap furious_copy = furious_frag;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_frag.attack("someone else");
		furious_frag.beRepaired(1);
		furious_frag.takeDamage(5);
	}
	std::cout << "==A==" << std::endl << std::endl;

	{
		ScavTrap furious_copy = furious_frag;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);
	}
	std::cout << "==B==" << std::endl << std::endl;

	{
		FragTrap furious_copy = furious_frag;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_frag.attack("someone else");
		furious_frag.beRepaired(1);
		furious_frag.takeDamage(5);
	}
	std::cout << "==C==" << std::endl << std::endl;

	{
		DiamondTrap furious_copy = furious_frag;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_frag.attack("someone else");
		furious_frag.beRepaired(1);
		furious_frag.takeDamage(5);
	}
	std::cout << std::endl;

	furious_frag.attack("yet another person");
	furious_frag.beRepaired(1);

	DiamondTrap tired_copy = furious_frag;
	std::cout << std::endl;

	for (int i = 0; i < 41; i++)
		tired_copy.beRepaired(1);
	tired_copy.attack("tired person");
	tired_copy.takeDamage(3);

	furious_frag.takeDamage(89);
	furious_frag.beRepaired(100);
	furious_frag.attack("dead person");
	furious_frag.takeDamage(5);

	return 0;
}
