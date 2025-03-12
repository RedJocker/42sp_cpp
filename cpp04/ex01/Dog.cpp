// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:43:13 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog::Dog() : Animal(\"Dog\")" << std::endl;
	this->brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal(other.getType())
{
	std::cout << "Dog::Dog(const Dog &other) : Animal(other.type)" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	this->brain = new Brain(*other.brain);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog::~Dog()" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << this->getType()
			  << " makes dog sound with "
			  << this->brain->idea() << std::endl;
}
