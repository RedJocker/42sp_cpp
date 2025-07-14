// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/14 01:41:32 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 07:07:45 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

const std::string BitcoinExchange::DEFAULT_EXCHANGE_HISTORY_FILEPATH =
	"./data.csv";

std::pair<int, std::string>
	BitcoinExchange::initExchangeHistoryMap(std::string databaseFilePath)
{
	std::ostringstream output;

	std::ifstream file(databaseFilePath);
	if (!file.is_open())
	{
		output << "Could not open " << databaseFilePath << std::endl;
		return std::make_pair(22, output.str());
	}
	std::string header;
	std::getline(file, header);
	if (header != "date,exchange_rate")
	{
		output << "invalid header on " << databaseFilePath;
		return std::make_pair(33, output.str());
	}
	std::string line;
	int line_number = 1;
	while(std::getline(file, line))
	{
		line_number++;
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::tm tm = {};
		char comma;
		double value;

		iss >> std::get_time(&tm, "%Y-%m-%d") >> comma >> value;
		if (iss.fail() || comma != ',')
		{
			file.close();
			output << "invalid format of database file on line "
				   << line_number
				   << " with content: "
				   << line << std::endl;
			return std::make_pair(44, output.str());
		}
		time_t timestamp = std::mktime(&tm);
		this->exchangeHistoryMap[timestamp] = value;
	}
	file.close();
	return std::make_pair(0, "");
}

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	this->exchangeHistoryMap = other.exchangeHistoryMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

struct GreaterThan {
	GreaterThan(const time_t value) : threshold(value) {}

	bool operator()(const std::pair<time_t, double> value) const {
		return value.first > threshold;
	}

	time_t threshold;
};

std::pair<int, std::string> BitcoinExchange::report(
	std::string registryFilePath)
{
	std::ostringstream output;
	std::ifstream file(registryFilePath);
	if (!file.is_open())
	{
		output << "Could not open " << registryFilePath << std::endl;
		return std::make_pair(22, output.str());
	}
	std::string header;
	std::getline(file, header);
	if (header != "date | value")
	{
		output << "invalid header on " << registryFilePath << std::endl;
		return std::make_pair(33, output.str());
	}

	std::string line;
	while(std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::istringstream iss(line);
		std::tm tm = {};
		char pipe;
		double value;

		iss >> std::get_time(&tm, "%Y-%m-%d") >> pipe >> value;
		if (iss.fail() || pipe != '|')
		{
			output << "Error: bad input => "
				   << line << std::endl;
			continue;
		} else if (value < 0)
		{
			output << "Error: not a positive number." << std::endl;
			continue;
		} else if (value > 1000)
		{
			output << "Error: too large a number." << std::endl;
			continue;
		}
		time_t timestamp = std::mktime(&tm);
		std::map<time_t, double>::const_iterator b =
			this->exchangeHistoryMap.cbegin();
		std::map<time_t, double>::const_iterator e =
			this->exchangeHistoryMap.cend();
		std::map<time_t, double>::const_iterator currentExchangeRate =
			std::find_if(b, e, GreaterThan(timestamp));
		if (currentExchangeRate == b) {
			output << "Error: no exchange rate at this early date "
				   << std::put_time(&tm, "%Y-%m-%d")
				   << std::endl;
			continue;
		}
		currentExchangeRate--;
		output << std::put_time(&tm, "%Y-%m-%d")
			   << " => "
			   << value
			   << " = "
			   << (*currentExchangeRate).second * value
			   << std::endl;
	}

	file.close();
	return std::make_pair(0, output.str());
}
