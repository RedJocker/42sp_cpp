// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScalarConverter.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:20:10 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 21:12:44 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScalarConverter.hpp"
#include <cstring>
#include <cmath>
#include <iostream>
#include <stdlib.h>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(std::string &toConvert) {
	return toConvert.length() == 1 && !std::isdigit(toConvert.at(0));
}

void ScalarConverter::printChar(double *number) {

	std::string value = "";
	if (number == NULL || std::isnan(*number) || std::isinf(*number))
	{
		value = "Impossible";
	}
	else
	{
		char ch = static_cast<char>(*number);
		std::cout << ch << std::endl;
		if (std::isprint(ch))
		{
			value = ch;
		}
		else
		{
			value = "Non displayable";
		}
	}
	std::cout << "char: " << value << std::endl;
}

void ScalarConverter::convert(std::string &toConvert)
{
	std::cout << toConvert << std::endl << std::endl;

	double number = -1;

	char *rest;
	if (isChar(toConvert))
	{
		number = static_cast<double>(static_cast<char>(toConvert.at(0)));
	}
	else
	{
		number = std::strtod(toConvert.c_str(), &rest);
	}
	std::cout << number << std::endl;
	size_t lenRest = std::strlen(rest);
	bool isOk = lenRest == 0 || (lenRest == 1 && (rest[0] == 'f' || rest[0] == 'F'));
	printChar(isOk ? &number : NULL);
}
