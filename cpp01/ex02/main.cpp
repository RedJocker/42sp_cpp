// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/19 21:49:13 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout
		<< "&string: " << &string << std::endl
		<< "&stringPTR: " << &stringPTR << std::endl
		<< "&stringREF: " << &stringREF << std::endl
		<< "string: " << string << std::endl
		<< "stringPTR: " << stringPTR << std::endl
		<< "stringREF: " << stringREF << std::endl;
	return (0);
}
