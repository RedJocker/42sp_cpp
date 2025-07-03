// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/02 23:33:43 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		std::cout << "Usage: converter strToConvert" << std::endl;
		return 2;
	}

	std::string toConvert = argv[1];
	ScalarConverter::convert(toConvert);
	return 0;
}
