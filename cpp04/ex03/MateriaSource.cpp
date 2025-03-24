// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:09:03 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 00:06:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource::MateriaSource()" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource::MateriaSource(const MateriaSource &other)"
			  << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout
		<< "MateriaSource &MateriaSource::operator=(const MateriaSource &other)"
		<< std::endl;
	if (this == &other)
		return *this;
	// make deep copy implementation
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource::~MateriaSource()" << std::endl;
}

void MateriaSource::learnMateria(AMateria *)
{
	return ;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	return NULL;
}
