// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScalarConverter.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:17:38 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 21:13:27 by maurodri         ###   ########.fr       //
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

	static void printChar(double *number);
	static bool isChar(std::string &toConvert);

public:

	static void convert(std::string &toConvert);
};


#endif
