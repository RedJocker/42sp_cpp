// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScalarConverter.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:17:38 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 23:07:01 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	virtual ScalarConverter &operator=(const ScalarConverter &other);
	virtual ~ScalarConverter();

	template <typename ImplementsStreamOperator>
	static std::string to_string(ImplementsStreamOperator num, int precision);

	static bool isNanOrInf(double *number);
	static void printChar(double *number);
	static void printInt(double *number);
	static void printFloat(double *number, int precision);
	static void printDouble(double *number, int precision);
	static bool isChar(std::string &toConvert);

public:

	static void convert(std::string &toConvert);
};


#endif
