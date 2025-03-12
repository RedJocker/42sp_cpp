// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 16:52:31 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat::Cat() : Animal(\"Cat\")" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.getType())
{
	std::cout << "Cat::Cat(const Cat &other) : Animal(other.type)" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat &Cat::operator=(const Cat &other)" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat::~Cat()" << std::endl;
}


void Cat::makeSound() const
{
	std::cout << this->getType() << " makes cat sound" << std::endl;
}
