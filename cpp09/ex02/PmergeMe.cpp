// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PmergeMe.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/05 20:39:45 by maurodri          #+#    #+#             //
//   Updated: 2025/08/05 23:38:06 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PmergeMe.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/04 16:56:04 by maurodri          #+#    #+#             //
//   Updated: 2025/08/05 20:38:22 by maurodri         ###   ########.fr       //
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

PmergeMe::MainChainInfo PmergeMe::mainChainInfo(
	size_t indexCeiling,
	size_t indexToInsert,
	size_t indexFloor,
	size_t groupSize,
	size_t halfGroupSize
) {
	size_t topMainChainSize = indexCeiling >= indexToInsert ? 1 + ((indexCeiling - indexToInsert) / halfGroupSize) : 1;
	size_t middleMainChainSize = (indexToInsert - indexFloor) / groupSize;
	size_t bottomMainChainSize = indexFloor / halfGroupSize; 
	//std::cout << "top main chain size: " << topMainChainSize << std::endl;
	//std::cout << "middle main chain size: " << middleMainChainSize << std::endl;
	//std::cout << "bottom main chain size: " << bottomMainChainSize << std::endl;
	size_t mainChainSizee = topMainChainSize + middleMainChainSize + bottomMainChainSize;

	return (PmergeMe::MainChainInfo) {
		indexCeiling,
		indexToInsert,
		indexFloor,
		groupSize,
		halfGroupSize,
		topMainChainSize,
		middleMainChainSize,
		bottomMainChainSize,
		mainChainSizee,
		bottomMainChainSize + middleMainChainSize
	};
}

size_t PmergeMe::MainChainInfo::indexWithCurrentAsLast(size_t i)
{
	if (i < this->bottomSize)
		return ((i + 1) * this->halfGroupSize) - 1;
	else if (i < this->toInsertMainChainIndex)
	{
		size_t rest = i - this->bottomSize;
		return (indexFloor + this->halfGroupSize)+ (rest * groupSize);
	}
	else if (i + 1 == this->totalSize)
	{
		return indexToInsert;
	}
	size_t rest = i - this->toInsertMainChainIndex;
	return indexToInsert + ((rest + 1) * halfGroupSize);
}

size_t PmergeMe::MainChainInfo::index(size_t i)
{
	if (i < this->bottomSize)
		return ((i + 1) * this->halfGroupSize) - 1;
	else if (i < this->toInsertMainChainIndex)
	{
		size_t rest = i - this->bottomSize;
		return (indexFloor + this->halfGroupSize)+ (rest * groupSize);
	}
	size_t rest = i - this->toInsertMainChainIndex;
	return indexToInsert + (rest * halfGroupSize);
}


