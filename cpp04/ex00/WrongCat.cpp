// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:59:46 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 16:11:08 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat(const WrongCat &other)
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
}


void WrongCat::makeSound() const
{
	std::cout << this->getType() << " makes cat sound" << std::endl;
}
