// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/13 19:56:48 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:47:31 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

AMateria::AMateria() : type("unknown")
{
	std::cout << "AMateria::AMateria()" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria::AMateria(const AMateria &other)" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria &AMateria::operator=(const AMateria &other)"
			  << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria::~AMateria()" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* use "
			  << this->getType() << " at " << target.getName() << " *"
			  << std::endl;
}
