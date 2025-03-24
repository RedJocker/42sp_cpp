// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:18:00 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 00:01:43 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	std::cout << "Character::Character()" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	
}

Character::Character(const Character &other)
{
	std::cout << "Character::Character(const Character &other)" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character &Character::operator=(const Character &other)"
			  << std::endl;
	if (this == &other)
		return *this;
	// make deep copy implementation
	return *this;
}

Character::~Character()
{
	std::cout << "Character::~Character()" << std::endl;
}

std::string const &Character::getName() const
{
	return "TODO";
}
void Character::equip(AMateria *m)
{
	return ;
}
void Character::unequip(int idx)
{
	return ;
}
void Character::use(int idx, ICharacter &target)
{
	return ;
}
