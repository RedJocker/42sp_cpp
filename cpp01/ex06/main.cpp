// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/27 18:03:54 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Harl.hpp"
#include <iostream>
int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "usage: harl_filter <level>" << std::endl;
		return 1;
	}

	Harl harl;

	harl.filter(argv[1]);
	return (0);
}
