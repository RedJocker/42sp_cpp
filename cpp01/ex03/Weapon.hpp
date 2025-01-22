// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/21 18:50:41 by maurodri          #+#    #+#             //
//   Updated: 2025/01/21 21:59:30 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

//Implement a Weapon class that has:
class Weapon
{
	//• A private attribute type, which is a string.
	std::string type;

public:
	//• A getType() member function that returns a const reference to type.
	const std::string &getType() const;
	//• A setType() member function that sets type using the new one passed as parameter
	void setType(std::string type);
	Weapon(std::string type);
};

#endif
