// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/07 23:42:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap furious_clap ("furious clap");
	std::cout << "" << std::endl;

	furious_clap.attack("someone");
	furious_clap.beRepaired(1);
	furious_clap.takeDamage(5);
	furious_clap.beRepaired(1);

	{
		ClapTrap furious_copy = furious_clap;
		std::cout << std::endl;

		furious_copy.attack("another person");
		furious_copy.takeDamage(1);
		furious_copy.beRepaired(10);

		furious_clap.attack("someone else");
		furious_clap.beRepaired(1);
		furious_clap.takeDamage(5);
	}
	std::cout << std::endl;

	furious_clap.attack("yet another person");
	furious_clap.beRepaired(1);

	ClapTrap tired_copy = furious_clap;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		tired_copy.beRepaired(2);
	tired_copy.attack("tired person");
	tired_copy.takeDamage(3);

	furious_clap.takeDamage(5);
	furious_clap.beRepaired(100);
	furious_clap.attack("dead person");
	furious_clap.takeDamage(5);

	return 0;
}
