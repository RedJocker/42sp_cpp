// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/06 02:49:50 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap furious_clap ("furious clap");

	furious_clap.attack("someone");
	furious_clap.beRepaired(3);
	furious_clap.takeDamage(5);

	return 0;
}

