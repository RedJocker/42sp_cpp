// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/07 16:21:00 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "iter.hpp"

void printInt(int i)
{
	std::cout << "i: " << i << std::endl;
}

void printStr(std::string str)
{
	std::cout << "str: " << str << std::endl;
}

template <typename Streamable> void printGeneric(Streamable element)
{
	std::cout << "generic: " << element << std::endl;
}

int main( void ) {
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, ::printInt);
	std::cout << std::endl;

	::iter(intArr, 3, ::printInt);
	std::cout << std::endl;
	
	std::string strArr[] = {
		"hello",
		"mate"
	};
	::iter(strArr, 2, ::printStr);
	std::cout << std::endl;

	::iter(intArr, 5, ::printGeneric);
	std::cout << std::endl;
	
	::iter(strArr, 2, ::printGeneric);
	std::cout << std::endl;
	
	return 0;
}
