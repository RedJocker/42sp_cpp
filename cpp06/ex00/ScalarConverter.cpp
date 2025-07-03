// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScalarConverter.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:20:10 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 00:14:52 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScalarConverter.hpp"
#include <cstring>
#include <limits>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

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

bool ScalarConverter::isNanOrInf(double *number)
{
	return number != NULL && (std::isnan(*number) || std::isinf(*number));
}

template <typename ImplementsStreamOperator>
std::string ScalarConverter::to_string(ImplementsStreamOperator num, int precision) {
    std::ostringstream oss;
	oss << std::setprecision(precision) << num;
    return oss.str();
}

void ScalarConverter::printChar(double *number) {

	std::string value = "";
	if (number == NULL
		|| isNanOrInf(number)
		|| *number < std::numeric_limits<char>::min()
		|| *number > std::numeric_limits<char>::max())
	{
		value = "Impossible";
	}
	else
	{
		char ch = static_cast<char>(*number);
		if (std::isprint(ch))
		{
			std::ostringstream oss;
			oss << '\'' << ch << '\'';
			value = oss.str();
		}
		else
		{
			value = "Non displayable";
		}
	}
	std::cout << "char: " << value << std::endl;
}

void ScalarConverter::printInt(double *number) {

	std::string value = "";
	if (number == NULL
		|| isNanOrInf(number)
	    || *number < std::numeric_limits<int>::min() 
		|| *number > std::numeric_limits<int>::max())
	{
		value = "Impossible";
	}
	else
	{
		int i = static_cast<int>(*number);
		value = to_string(i, 19);
	}
	std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(double *number, int precision)
{
	std::string value = "";
	if ((number == NULL
		 || *number < std::numeric_limits<float>::lowest()
		 || *number > std::numeric_limits<float>::max())
		&& !isNanOrInf(number))
	{
		value = "Impossible";
	}
	else
	{
		float f = static_cast<float>(*number);
		bool isInt = truncf(f) == f;
		std::string decimal = isInt ? ".0" : "";
		int maxPrecision = std::numeric_limits<float>::digits10 + 1;
		int precisionNorm = std::min(precision, maxPrecision);
		value = to_string(f, precisionNorm) + decimal + "f";
	}
	std::cout << "float: " << value << std::endl;
}

void ScalarConverter::printDouble(double *number, int precision)
{
	std::string value = "";
	if (number == NULL && !isNanOrInf(number))
	{
		value = "Impossible";
	}
	else
	{
		double d = *number;
		bool isInt = trunc(*number) == *number;
		std::string decimal = isInt ? ".0" : "";
		int maxPrecision = std::numeric_limits<double>::digits10 + 1;
		int precisionNorm = std::min(precision, maxPrecision);
		value = to_string(d, precisionNorm) + decimal;
	}
	std::cout << "double: " << value << std::endl;
}

static int precision(std::string &toConvert)
{
	int precision = 0;
	int zeroTail = 0;
	bool hadDot = false;

	for (size_t i = 0; i < toConvert.size(); i++)
	{
		if (toConvert.at(i) == '.')
		{
			hadDot = true;
		}
		else if (!hadDot && std::isdigit(toConvert.at(i)))
		{
			precision++;
		}
		else if (hadDot && std::isdigit(toConvert.at(i)))
		{
			if (toConvert.at(i) != '0')
			{
				precision += 1 + zeroTail;
				zeroTail = 0;
			}
			else
			{
				zeroTail++;
			}
		}
	}
	return precision;
}

void ScalarConverter::convert(std::string &toConvert)
{
	double number = -1;

	char *rest = NULL;
	bool isCh = isChar(toConvert);
	if (isCh)
	{
		number = static_cast<double>(static_cast<char>(toConvert.at(0)));
	}
	else
	{
		number = std::strtod(toConvert.c_str(), &rest);
	}
	size_t lenRest = rest != NULL ? std::strlen(rest) : 0;
	bool isOk = lenRest == 0 || (lenRest == 1 && (rest[0] == 'f' || rest[0] == 'F'));
	int numberPrecision = isOk && !isCh ? precision(toConvert) : 4;

	printChar(isOk ? &number : NULL);
	printInt(isOk ? &number : NULL);
	printFloat(isOk ? &number : NULL, numberPrecision);
	printDouble(isOk ? &number : NULL, numberPrecision);
}
