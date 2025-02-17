// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/02/17 19:53:56 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " makes sound" << std::endl;
}
