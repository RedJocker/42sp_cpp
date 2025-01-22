// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/21 21:01:16 by maurodri          #+#    #+#             //
//   Updated: 2025/01/21 21:53:19 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course, without the
// angle brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.


class HumanB {
	Weapon 		*weapon;
	std::string	name;

public:
	HumanB(std::string str);	
	void attack(void) const;
	void setWeapon(Weapon *weapon);
};

#endif
