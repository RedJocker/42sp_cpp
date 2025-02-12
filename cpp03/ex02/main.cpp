// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/11 21:54:35 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	
	FragTrap furious_frag ("furious frag");
	std::cout << "" << std::endl;

	furious_frag.attack("someone");
	furious_frag.beRepaired(1);
	furious_frag.takeDamage(5);
	furious_frag.beRepaired(1);
	furious_frag.highFivesGuys();
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
	std::cout << std::endl;

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
	std::cout << std::endl;

	furious_frag.attack("yet another person");
	furious_frag.beRepaired(1);

	FragTrap tired_copy = furious_frag;
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
