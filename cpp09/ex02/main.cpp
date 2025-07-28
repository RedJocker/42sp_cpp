// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/28 00:28:11 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>

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

template<typename ContainerStreamable>
void printContainer(ContainerStreamable container) {
	for (typename ContainerStreamable::iterator i = container.begin();
		 i != container.end();
	) {
		std::cout << *i;
		if (++i != container.end())
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

	size_t halfGroupSize = groupSize / 2;
	It beginA = leaderA - halfGroupSize;
	It beginB = leaderB - halfGroupSize;
	It endA = leaderA + 1;
	It endB = leaderB + 1;

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

template<typename RandomAccessIterator>
void insertElement(
	RandomAccessIterator toInsert,
	RandomAccessIterator begin,
	RandomAccessIterator end,
	size_t groupSize)
{
	typedef RandomAccessIterator It;
	(It) toInsert;

	std::cout << "toInsert: " << *toInsert << std::endl;
	std::cout << "begin: " << *begin << std::endl;
	std::cout << "end: " << *end << std::endl;
	std::cout << "groupSize: " << groupSize << std::endl;

	// size_t i = 0;
	// for (It current = ;
	// 	 current < end;
	// 	 current = leaderIndexAtGroupSize(i++, groupSize))
	// {
	// 	if (*toInsert >  *current)
	// 	{
	// 		swapGroup(toInsert, current, groupSize);
	// 	}
	// }
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

	size_t jFloor = jacobsthalNumber(jacobIFloor) - 1;
	size_t jCeiling = jacobsthalNumber(jacobICeiling) - 1;

	It itFloor = begin + bottomIndexAtGroupSize(jFloor, groupSize);
	It itCeiling = begin + bottomIndexAtGroupSize(jCeiling, groupSize);
 
	while(true)
	{
		if (itFloor > end)
			return ;
		else 
		{
			long currentJCeiling = jCeiling;
			while (static_cast<long>(jFloor) < currentJCeiling)
			{
				if (itCeiling < end) {
					insertElement(itCeiling, begin, end, groupSize);
				}
				
				currentJCeiling--; 
				itCeiling = begin + bottomIndexAtGroupSize(
					currentJCeiling, 
					groupSize
				);
			}
		}
		jFloor = jacobsthalNumber(++jacobIFloor) - 1;
		jCeiling = jacobsthalNumber(++jacobICeiling) - 1;
		itFloor = begin + bottomIndexAtGroupSize(jFloor, groupSize);
		itCeiling = begin + bottomIndexAtGroupSize(jCeiling, groupSize);
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

	
	sortGroup(begin, end - rest, groupSize * 2);
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
		printContainer(vec);
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
