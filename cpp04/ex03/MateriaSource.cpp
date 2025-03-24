// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:09:03 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 12:00:39 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource::MateriaSource()" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource::MateriaSource(const MateriaSource &other)"
			  << std::endl;
	for (int i = 0; i < 4; ++i)
		this->templates[i] = NULL;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout
		<< "MateriaSource &MateriaSource::operator=(const MateriaSource &other)"
		<< std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] != NULL)
			delete this->templates[i];
		if (other.templates[i] != NULL)
			this->templates[i] = other.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource::~MateriaSource()" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (this->templates[i] != NULL)
			delete this->templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->templates[i] == NULL)
		{
			this->templates[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->templates[i] != NULL
				&& this->templates[i]->getType() == type)
			return this->templates[i]->clone();
	}
	return 0;
}
