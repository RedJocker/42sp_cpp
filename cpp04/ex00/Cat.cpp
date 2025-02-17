// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/02/17 19:53:59 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal("Cat")
{
	
}

Cat::Cat(const Cat &other)
{
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Cat::~Cat()
{
	
}


void Cat::makeSound() const
{
	std::cout << this->getType() << " makes sound" << std::endl;
}
