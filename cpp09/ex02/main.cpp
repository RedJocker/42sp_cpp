// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/30 20:54:07 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <cmath>

std::pair<bool, unsigned int> parseUInt(char *str)
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

template <class Container>
std::pair<bool, Container> createListFromArgs(char **args)
{
	Container container;

	for (char **p = args; *p != NULL; p++) {
		std::pair<bool, unsigned int> parseResult = parseUInt(*p);
		if (!parseResult.first)
			return std::make_pair(false, container);
		container.push_back(parseResult.second);
	}
	return std::make_pair(true, container);
}

template<typename Iterator>
void printContainer(Iterator begin, Iterator end) {
	for (Iterator i = begin;
		 i != end;
	) {
		std::cout << *i;
		if (++i != end)
			std::cout << " ";
	}
}

template<typename RandomAccessIterator>
void swapGroup(
	RandomAccessIterator leaderA,
	RandomAccessIterator leaderB,
	size_t groupSize)
{
	typedef RandomAccessIterator It;

	It beginA = leaderA - groupSize + 1;
	It beginB = leaderB - groupSize + 1;
	It endA = leaderA + 1;
	It endB = leaderB + 1;

	//std::cout << "swap: " << *leaderA << " " << *leaderB << " " << groupSize << std::endl;
	for (It a = beginA, b = beginB;
		 a < endA && b < endB;
		 a++, b++)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

size_t leaderIndexAtGroupSize(size_t i, size_t groupSize)
{
	return (groupSize * (i + 1)) - 1;
}

size_t bottomIndexAtGroupSize(size_t i, size_t groupSize)
{
	return leaderIndexAtGroupSize(2 * i, groupSize >> 1);
}

template <typename RandomAccessIterator>
void insertElement(
	size_t indexFloor,
	size_t indexCeiling,
	size_t indexToInsert,
	RandomAccessIterator begin,
	RandomAccessIterator end,
	size_t groupSize)
{
	typedef RandomAccessIterator It;
	It toInsert = begin + indexToInsert;

	// std::cout << "toInsert: " << *toInsert << std::endl;
	// std::cout << "begin: " << *begin << std::endl;
	// std::cout << "end: " << *end << std::endl;
	// std::cout << "groupSize: " << groupSize << std::endl;
	// std::cout << "indexFloor: " << indexFloor << std::endl;
	// std::cout << "indexCeiling: " << indexCeiling << std::endl;
	// std::cout << "indexToInsert: " << indexToInsert << std::endl;

	size_t halfGroupSize = groupSize >> 1;
	
	long currentIndex = static_cast<long>(indexCeiling);
	//std::cout << "main chain: " << std::endl;
	
	It currentMainChainIt = begin + currentIndex;
	while (currentIndex >= 0)
	{
		if (currentMainChainIt < end) {
			//		std::cout << "\t" << *currentMainChainIt << std::endl;
			if (currentMainChainIt > toInsert && *toInsert > *currentMainChainIt)
			{
				swapGroup(toInsert, currentMainChainIt, halfGroupSize);
				return;
			} else if (currentMainChainIt < toInsert && *toInsert < *currentMainChainIt)
			{
				swapGroup(toInsert, currentMainChainIt, halfGroupSize);
				toInsert = currentMainChainIt;
			}
		}
		if (static_cast<long>(indexCeiling) == currentIndex) {
			currentIndex -= static_cast<long>(halfGroupSize);
		} else if (currentIndex > static_cast<long>(indexFloor))
			currentIndex -= static_cast<long>(groupSize);
		else
			currentIndex -= static_cast<long>(halfGroupSize);
		currentMainChainIt = begin + currentIndex;
	}
}

size_t jacobsthalNumber(size_t n)
{
	double result = (std::pow(2, n) - std::pow(-1, n)) / 3.0;
	return static_cast<size_t>(result);
}


template<typename RandomAccessIterator>
void mergeGroup(
	RandomAccessIterator begin, RandomAccessIterator end, size_t groupSize)
{
	typedef RandomAccessIterator It;

	size_t jacobIFloor = 2;
	size_t jacobICeiling = 3;

	size_t jacobFloor = jacobsthalNumber(jacobIFloor);
	size_t jacobCeiling = jacobsthalNumber(jacobICeiling) - 1;

	size_t indexFloor = bottomIndexAtGroupSize(jacobFloor, groupSize);
	size_t indexCeiling = bottomIndexAtGroupSize(jacobCeiling, groupSize);
	It itFloor = begin + indexFloor;
	It itCeiling = begin + indexCeiling;
 
	while(true)
	{
		if (itFloor > end)
			return ;
		else 
		{
			long currentJacobCeiling = static_cast<long>(jacobCeiling);
			long currentIndexCeiling = static_cast<long>(indexCeiling);
			while (static_cast<long>(jacobFloor) <= currentJacobCeiling)
			{
				if (itCeiling < end) {
					insertElement(indexFloor,
					    indexCeiling,
					    currentIndexCeiling,
						begin,
					    end,
						groupSize
					);
				}

				currentJacobCeiling--;
				currentIndexCeiling = static_cast<long>(bottomIndexAtGroupSize(
					currentJacobCeiling, 
					groupSize
				));
				itCeiling = begin + currentIndexCeiling;
			}
		}
		jacobFloor = jacobsthalNumber(++jacobIFloor);
		jacobCeiling = jacobsthalNumber(++jacobICeiling) - 1;
		indexFloor = bottomIndexAtGroupSize(jacobFloor, groupSize);
		indexCeiling = bottomIndexAtGroupSize(jacobCeiling, groupSize);
		itFloor = begin + indexFloor;
		itCeiling = begin + indexCeiling;
	}
}

template<typename RandomAccessIterator>
void sortGroup(
	RandomAccessIterator begin, RandomAccessIterator end, size_t groupSize)
{
	

	size_t wholeSize = end - begin;
	if (groupSize > wholeSize)
		return;

	typedef RandomAccessIterator It;
	size_t halfGroupSize = groupSize / 2;
	size_t rest = wholeSize % groupSize;
	It front = begin + groupSize - 1;
	It back = begin + halfGroupSize - 1;
	
	for (; front < end; back += groupSize, front += groupSize)
	{
		if (*back > *front)
		{
			swapGroup(back, front, halfGroupSize);
		}
	}

	//std::cout << "groupSize: " << groupSize << std::endl;
	// printContainer(begin, end);
	// std::cout << std::endl;
	sortGroup(begin, end - rest, groupSize * 2);
	// printContainer(begin, end);
	// std::cout << std::endl;
	mergeGroup(begin, end, groupSize);
}

template<typename RandomAccessIterator>
void mergeInsertionSort(RandomAccessIterator begin, RandomAccessIterator end)
{	
	sortGroup(begin, end, 2);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: "
				  << argv[0]
				  << " (list of natural numbers to be sorted)"
				  << std::endl
				  << "ex: " << argv[0] << " 10 0 12 22 55 13";
		return 11;
	}

	{
		std::pair<bool, std::vector<int> > maybeVector =
			createListFromArgs<std::vector<int> >(argv + 1);
		if (!maybeVector.first) {
			std::cerr << "Error" << std::endl;
			return 22;
		}
		// else
		// 	printContainer(maybeVector.second);
		// std::cout << std::endl;
		std::vector<int> vec = maybeVector.second;
		mergeInsertionSort(vec.begin(), vec.end());
		printContainer(vec.begin(), vec.end());
		std::cout << std::endl;
	}

	// {
	// 	std::pair<bool, std::deque<int> > maybeDeque =
	// 		createListFromArgs<std::deque<int> >(argv + 1);
	// 	if (!maybeDeque.first) {
	// 		std::cerr << "Error" << std::endl;
	// 		return 22;
	// 	}
	// 	else
	// 		printContainer(maybeDeque.second);
	// 	std::cout << std::endl;
	// 	std::deque<int> deq = maybeDeque.second;
	// 	mergeInsertionSort(deq.begin(), deq.end());
	// 	printContainer(deq);
	// 	std::cout << std::endl;
		
	// }

	
	return 0;
}
