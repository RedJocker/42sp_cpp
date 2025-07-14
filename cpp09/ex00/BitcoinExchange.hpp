// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BitcoinExchange.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/14 01:34:01 by maurodri          #+#    #+#             //
//   Updated: 2025/07/14 01:48:40 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <map>
# include <string>
class BitcoinExchange
{
	std::map<time_t, double> exchangeHistoryMap;

	void initExchangeHistoryMap(std::string databaseFilePath);
public:
	BitcoinExchange();
	BitcoinExchange(std::string databaseFilePath);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	
};

#endif
