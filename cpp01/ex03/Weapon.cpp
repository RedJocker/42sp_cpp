// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/21 19:02:33 by maurodri          #+#    #+#             //
//   Updated: 2025/01/25 15:06:43 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"
#include <iostream>

//• A getType() member function that returns a const reference to type.
const std::string &Weapon::getType() const
{
	return this->type;
}

//• A setType() member function that sets type using the new one passed as parameter
void Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type) : type(type) {}
