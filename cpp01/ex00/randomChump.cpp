// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   randomChump.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:49:04 by maurodri          #+#    #+#             //
//   Updated: 2025/01/17 20:19:07 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie(name).announce();
	return ;
}
