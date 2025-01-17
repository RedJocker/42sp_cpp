// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:45:51 by maurodri          #+#    #+#             //
//   Updated: 2025/01/17 20:15:15 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <string>
#include <iostream>

void Zombie::announce(void)
{
	std::cout << "<" + name + ">: BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{

}

Zombie::~Zombie()
{
	std::cout << "Destroy " << this->name << std::endl;
}
