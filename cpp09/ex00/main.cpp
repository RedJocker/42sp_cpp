// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 07:05:27 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " fileName" << std::endl;
		return 11;
	}

	BitcoinExchange bitEx;
	std::pair<int, std::string> errorDataLoad = bitEx.initExchangeHistoryMap(
		BitcoinExchange::DEFAULT_EXCHANGE_HISTORY_FILEPATH);
	if (errorDataLoad.first) {
		std::cout << errorDataLoad.second;
		return errorDataLoad.first;
	}
	std::pair<int, std::string> result = bitEx.report(argv[1]);
	std::cout << result.second;
	return result.first;
}
