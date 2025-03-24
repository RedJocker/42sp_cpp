// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:18:00 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 02:06:53 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"
#include <iostream>

Character::Character()
{
	std::cout << "Character::Character()" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character::Character(" << name << ")" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = NULL;
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
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character::~Character()" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
