// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScalarConverter.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:20:10 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 19:31:22 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	
}

void ScalarConverter::convert(std::string &toConvert)
{
	std::cout << toConvert << std::endl << std::endl;

	
}
