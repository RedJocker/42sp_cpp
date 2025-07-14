// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/14 01:34:01 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 07:05:35 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <map>
# include <string>
# include <utility>
# include <string>

class BitcoinExchange
{

	std::map<time_t, double> exchangeHistoryMap;

public:
	static const std::string DEFAULT_EXCHANGE_HISTORY_FILEPATH;

	BitcoinExchange();
	BitcoinExchange(std::string databaseFilePath);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	std::pair<int, std::string> initExchangeHistoryMap(
		std::string databaseFilePath);
	std::pair<int, std::string> report(std::string registryFilePath);
};

#endif
