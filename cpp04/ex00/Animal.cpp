// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:50:30 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 14:54:11 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Animal.hpp"

Animal::Animal(const std::string type) : type(type)
{
	
}

Animal::Animal() : type("Animal")
{
	
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	
}

std::string Animal::getType() const
{
	return this->type;	
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " makes animal sound" << std::endl; 	
}
