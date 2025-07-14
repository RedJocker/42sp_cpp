// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 01:47:15 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " fileName" << std::endl;
		return 11;
	}

	std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Could not open " << argv[1] << std::endl;
        return 22;
    }

	std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

	BitcoinExchange();
	
	return 0;
}
