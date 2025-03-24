// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:01:47 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:48:10 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice::Ice()" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.getType())
{
	std::cout << "Ice::Ice(const Ice &other)" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice &Ice::operator=(const Ice &other)" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice::~Ice()" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
