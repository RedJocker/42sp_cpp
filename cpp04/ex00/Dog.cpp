// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 16:52:38 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog::Dog() : Animal(\"Dog\")" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.getType())
{
	std::cout << "Dog::Dog(const Dog &other) : Animal(other.type)" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog::~Dog()" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " makes dog sound" << std::endl;
}
