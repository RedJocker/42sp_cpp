// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/14 01:41:32 by maurodri          #+#    #+#             //
//   Updated: 2025/07/21 23:22:53 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

const std::string BitcoinExchange::DEFAULT_EXCHANGE_HISTORY_FILEPATH =
	"./data.csv";

static bool isValidDate(int year, int month, int day)
{
	int	leapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	if (month < 1 || month > 12)
		return false;
	int daysMoth[] = {
		31, 28 + leapYear, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	return (day >= 1 && day <= daysMoth[month - 1]);
}

static std::istream &operator>>(std::istream &stream, std::tm &time)
{
	std::string token;

	stream >> token;

	size_t delim1 = token.find("-");

	if (delim1 == std::string::npos)
	{
		stream.setstate(stream.failbit);
		return stream;
	}

	size_t delim2 = token.find("-", delim1 + 1);
	if (delim2 == std::string::npos)
	{
		stream.setstate(stream.failbit);
		return stream;
	}

	if (delim2 - delim1 != 3)
	{
		stream.setstate(stream.failbit);
		return stream;
	}

	size_t endTime = delim2 + 3;
	std::string date = token.substr(0, endTime);
	std::string rest = token.substr(endTime);

	for (size_t i = 0; i < rest.length(); i++)
	{
		stream.unget();
	}

	std::istringstream iss(date);

	int year;
	char ch1;
	int month;
	char ch2;
	int day;

	iss >> year >> ch1 >> month >> ch2 >> day;

	if (iss.fail()|| ch1 != '-' || ch2 != '-' || !isValidDate(year, month, day))
	{
		stream.setstate(stream.failbit);
		return stream;
	}

	time.tm_year = year - 1900;
	time.tm_mday = day;
	time.tm_mon = month - 1;
	time.tm_hour = 0;
	time.tm_min = 0;
	time.tm_sec = 0;
	time.tm_isdst = 0;

	return stream;
}

std::pair<int, std::string>
	BitcoinExchange::initExchangeHistoryMap(std::string databaseFilePath)
{
	std::ostringstream output;

	std::ifstream file(databaseFilePath.c_str());
	if (!file.is_open())
	{
		output << "Could not open " << databaseFilePath << std::endl;
		return std::make_pair(22, output.str());
	}
	std::string header;
	std::getline(file, header);
	if (header != "date,exchange_rate")
	{
		file.close();
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

		iss >> tm >> comma >> value;

		if (iss.fail() || comma != ',' || !iss.eof())
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
	std::ifstream file(registryFilePath.c_str());
	if (!file.is_open())
	{
		output << "Could not open " << registryFilePath << std::endl;
		return std::make_pair(22, output.str());
	}
	std::string header;
	std::getline(file, header);
	if (header != "date | value")
	{
		file.close();
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

		iss >> tm >> pipe >> value;
		if (iss.fail() || pipe != '|' || !iss.eof())
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
		std::map<time_t, double>::iterator b =
			this->exchangeHistoryMap.begin();
		std::map<time_t, double>::iterator e =
			this->exchangeHistoryMap.end();
		std::map<time_t, double>::const_iterator currentExchangeRate =
			std::find_if(b, e, GreaterThan(timestamp));

		// expected 11 == size time_format with 4 digit years \0 term
		char dateStr[20];
		strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &tm);

		if (currentExchangeRate == b) {
			output << "Error: no exchange rate at this early date "
				   << dateStr
				   << std::endl;
			continue;
		}
		currentExchangeRate--;

		output << dateStr
			   << " => "
			   << value
			   << " = "
			   << (*currentExchangeRate).second * value
			   << std::endl;
	}

	file.close();
	return std::make_pair(0, output.str());
}
