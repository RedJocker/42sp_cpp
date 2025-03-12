// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/12 16:32:50 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 17:39:32 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat::WrongCat() : WrongAnimal(\"WrongCat\")"
			  << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type)
{
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return *this;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat::~WrongCat()" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->getType() << " makes cat sound" << std::endl;
}
