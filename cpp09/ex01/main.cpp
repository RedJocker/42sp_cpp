// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/22 22:08:49 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: "
				  << argv[0]
				  << " (list of operands and operators using polish postfix notation)"
				  << std::endl
				  << "ex: " << argv[0] << "  8 9 * 9 - 9 - 9 - 4 - 1 +";
		return 11;
	}

	RPN calculator;
	std::pair<int, std::string> result = calculator.calculate(argv + 1);
	std::cout << result.second << std::endl;

	return result.first;
}
