// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/07 23:54:32 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap furious_scav ("furious scav");
	std::cout << "" << std::endl;

	furious_scav.attack("someone");
	furious_scav.beRepaired(1);
	furious_scav.takeDamage(5);
	furious_scav.beRepaired(1);

	{
		ClapTrap furious_copy = furious_scav;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_scav.attack("someone else");
		furious_scav.beRepaired(1);
		furious_scav.takeDamage(5);
	}
	std::cout << std::endl;

	{
		ScavTrap furious_copy = furious_scav;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_scav.attack("someone else");
		furious_scav.beRepaired(1);
		furious_scav.takeDamage(5);
	}
	std::cout << std::endl;

	furious_scav.attack("yet another person");
	furious_scav.beRepaired(1);

	ClapTrap tired_copy = furious_scav;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		tired_copy.beRepaired(2);
	tired_copy.attack("tired person");
	tired_copy.takeDamage(3);

	furious_scav.takeDamage(5);
	furious_scav.beRepaired(100);
	furious_scav.attack("dead person");
	furious_scav.takeDamage(5);

	// furious_clap = furious_clap;
	// std::cout << std::endl;

	// furious_clap.takeDamage(5);
	// furious_clap.beRepaired(100);
	// furious_clap.attack("dead person");
	// furious_clap.takeDamage(5);

	return 0;
}
