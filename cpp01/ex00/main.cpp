// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/17 20:19:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

int main(void)
{
	Zombie yes("Mr. Yes");
	yes.announce();

	Zombie *nope = newZombie("Nope Guy");
	nope->announce();
	delete nope;

	randomChump("Maybe Fellow");
	return (0);
} 
