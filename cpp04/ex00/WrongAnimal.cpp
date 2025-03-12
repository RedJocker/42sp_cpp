// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongAnimal.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/12 17:16:04 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 17:18:26 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
	std::cout << "WrongAnimal::WrongAnimal(const std::string type)"
			  << std::endl;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal::WrongAnimal() : type(\"WrongAnimal\")"
			  << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal::WrongAnimal(const WrongAnimal &other)"
			  << std::endl;
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
	std::cout << "WrongAnimal::~WrongAnimal()"
			  << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << " makes animal sound" << std::endl;
}
