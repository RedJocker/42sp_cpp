// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:46:04 by maurodri          #+#    #+#             //
//   Updated: 2025/01/19 17:53:50 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#endif

class Zombie {
	std::string name;
public:
	void announce(void);
	Zombie(std::string name);
	~Zombie();
};

Zombie	*zombieHorde(int horde_size, std::string name);
