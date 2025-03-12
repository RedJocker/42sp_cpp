// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:50:30 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 16:45:49 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Animal.hpp"

Animal::Animal(const std::string type) : type(type)
{
	std::cout << "Animal::Animal(const std::string type)" << std::endl;
}

Animal::Animal() : type("Animal")
{
	std::cout << "Animal::Animal()" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal::Animal(const Animal &other)" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal &Animal::operator=(const Animal &other)" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal::~Animal()" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " makes animal sound" << std::endl;
}
