// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongAnimal.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:50:30 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 16:10:47 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
	
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	
}

std::string WrongAnimal::getType() const
{
	return this->type;	
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " makes animal sound" << std::endl; 	
}
