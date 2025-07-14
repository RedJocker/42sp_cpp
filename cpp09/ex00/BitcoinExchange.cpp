// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/14 01:41:32 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 02:51:25 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

void BitcoinExchange::initExchangeHistoryMap(std::string databaseFilePath)
{
	std::ifstream file(databaseFilePath);
    if (!file.is_open())
	{
        std::cout << "Could not open " << databaseFilePath << std::endl;
        throw std::invalid_argument("invalid database file path");
    }
	std::string header;
	std::getline(file, header);
	if (header != "date,exchange_rate")
	{
		throw std::runtime_error("invalid header on " + databaseFilePath);
	}
	std::string line;
	while(!std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::tm tm = {};
		char comma;
		double value;

		iss >> std::get_time(&tm, "%Y-%m-%d") >> comma >> value;
		if (iss.fail() || comma != ',')
		{
			throw std::runtime_error(
				"invalid format of database file" + databaseFilePath);
		}
		time_t timestamp = std::mktime(&tm);
		this->exchangeHistoryMap[timestamp] = value;
	}
    file.close();
}

BitcoinExchange::BitcoinExchange()
{
	initExchangeHistoryMap("./data.csv");
}

BitcoinExchange::BitcoinExchange(std::string databaseFilePath)
{
	initExchangeHistoryMap(databaseFilePath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	//TODO();
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}
