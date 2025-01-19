// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   zombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/19 17:27:14 by maurodri          #+#    #+#             //
//   Updated: 2025/01/19 17:58:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie	*zombieHorde(int horde_size, std::string name)
{
	Zombie *horde =
		static_cast<Zombie *>(operator new[](horde_size * sizeof(Zombie)));

	for (int i = 0; i < horde_size; i++)
		new (horde + i) Zombie(name);
	return horde;
}
