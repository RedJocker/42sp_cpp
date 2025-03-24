// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:28:10 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:52:07 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure::Cure()" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.getType())
{
	std::cout << "Cure::Cure(const Cure &other)" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure &Cure::operator=(const Cure &other)" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure::~Cure()" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *"
			  << std::endl;
}
