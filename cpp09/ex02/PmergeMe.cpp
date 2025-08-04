// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PmergeMe.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/04 16:56:04 by maurodri          #+#    #+#             //
//   Updated: 2025/08/04 17:17:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PmergeMe.hpp"

#include <sstream>
#include <cmath>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void) other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

std::pair<bool,unsigned int> PmergeMe::parseUInt(char *str)
{
	std::istringstream iss(str);

	int result;

	iss >> result;

	if (iss.fail() || !iss.eof() || result < 0)
	{
		return std::make_pair(false, 0);
	}
	return std::make_pair(true, result);
}

size_t PmergeMe::leaderIndexAtGroupSize(size_t i, size_t groupSize)
{
	return (groupSize * (i + 1)) - 1;
}

size_t PmergeMe::bottomIndexAtGroupSize(size_t i, size_t groupSize)
{
	return leaderIndexAtGroupSize(2 * i, groupSize >> 1);
}

size_t PmergeMe::jacobsthalNumber(size_t n)
{
	double result = (std::pow(2, n) - std::pow(-1, n)) / 3.0;
	return static_cast<size_t>(result);
}
