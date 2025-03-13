// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/12 18:17:39 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:38:17 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain::Brain()" << std::endl;
	initIdeas();
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain::Brain(const Brain &other)" << std::endl;
	*this = other;
	initIdeas();
}

void Brain::initIdeas()
{
	for(int i = 0; i < 100; ++i) {
		std::ostringstream s;
		s << "idea" << i;
		this->ideas[i] = s.str();
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain &Brain::operator=(const Brain &other)" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain::~Brain()" << std::endl;
}

std::string Brain::idea() const
{
	return this->ideas[rand() % 100];
};
