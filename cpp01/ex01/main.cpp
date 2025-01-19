// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/19 17:49:04 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

int main(void)
{
	Zombie yes("Mr. Yes");
	yes.announce();

	Zombie *horde = zombieHorde(5, "zombies");

	for (int i = 0; i < 5; i++)
		horde[i].announce();

	for (int i = 0; i < 5; i++)
		horde[i].~Zombie();
	operator delete[](horde);
	return (0);
}
