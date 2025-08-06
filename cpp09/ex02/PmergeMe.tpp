// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PmergeMe.tpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/04 17:05:28 by maurodri          #+#    #+#             //
//   Updated: 2025/08/05 23:37:34 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template <class Container>
std::pair<bool, Container> PmergeMe::createListFromArgs(char **args)
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
void PmergeMe::printContainer(Iterator begin, Iterator end) {
	for (Iterator i = begin;
		 i != end;
	) {
		std::cout << *i;
		if (++i != end)
			std::cout << " ";
	}
}

template<typename RandomAccessIterator>
void PmergeMe::swapGroup(
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

// template <typename RandomAccessIterator>
// void PmergeMe::insertElementOld(
// 	size_t indexFloor,
// 	size_t indexCeiling,
// 	size_t indexToInsert,
// 	RandomAccessIterator begin,
// 	RandomAccessIterator end,
// 	size_t groupSize)
// {
// 	typedef RandomAccessIterator It;
// 	It toInsert = begin + indexToInsert;
	
// 	// std::cout << std::endl << "toInsert: " << *toInsert << std::endl;
// 	// std::cout << "begin: " << *begin << std::endl;
// 	// std::cout << "end: " << *end << std::endl;
// 	// std::cout << "groupSize: " << groupSize << std::endl;
// 	// std::cout << "indexFloor: " << indexFloor << std::endl;
// 	// std::cout << "indexToInsert: " << indexToInsert << std::endl;
// 	// std::cout << "indexCeiling: " << indexCeiling << std::endl;

// 	size_t halfGroupSize = groupSize >> 1;
		
// 	if (begin + indexCeiling >= end)
// 	{
// 		size_t wholeSize = end - begin;
// 		indexCeiling = wholeSize - 1;
// 	}

// 	// std::cout << "indexCeiling: " << indexCeiling << std::endl;
// 	// printContainer(begin, end);
// 	// std::cout << std::endl;
// 	PmergeMe::MainChainInfo mainChain = mainChainInfo(indexCeiling, indexToInsert, indexFloor, groupSize, halfGroupSize);
// 	// std::cout << "main chain size: " << mainChain.totalSize << std::endl;
// 	// size_t i = 0;
// 	// for (; i < mainChain.bottomSize; i++)
// 	// {
// 	// 	size_t idx = mainChain.index(i);
// 	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
// 	// }
// 	// for (; i < mainChain.bottomSize + mainChain.middleSize; i++)
// 	// {
// 	// 	size_t idx = mainChain.index(i);
// 	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
// 	// }
// 	// for (; i < mainChain.bottomSize + mainChain.middleSize + mainChain.topSize; i++)
// 	// {
// 	// 	size_t idx = mainChain.index(i);
// 	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
// 	// }
	
// 	// std::cout << "main chain: " << std::endl;
	
// 	long currentIndex = static_cast<long>(indexCeiling);
// 	It currentMainChainIt = begin + currentIndex;
// 	while (currentIndex >= 0)
// 	{
// 		if (currentMainChainIt < end) {
// 			//std::cout << "\t" << *currentMainChainIt << std::endl;
// 			if (currentMainChainIt > toInsert && *toInsert > *currentMainChainIt)
// 			{
// 				// printContainer(begin, end);
// 				// std::cout << std::endl;
// 				swapGroup(toInsert, currentMainChainIt, halfGroupSize);
// 				// printContainer(begin, end);
// 				// std::cout << std::endl;
// 				// std::cout <<  "toInsert: " << *toInsert << std::endl;
// 			} else if (currentMainChainIt < toInsert && *toInsert < *currentMainChainIt)
// 			{
// 				swapGroup(toInsert, currentMainChainIt, halfGroupSize);
// 				toInsert = currentMainChainIt;
// 			}
// 		}
// 		if (currentIndex >= static_cast<long>(indexToInsert)) {
// 			//std::cout <<  "halfStep: " << std::endl;
// 			currentIndex -= static_cast<long>(halfGroupSize);
// 		} else if (currentIndex > static_cast<long>(indexFloor)) {
// 			//std::cout <<  "wholeStep: " << std::endl;
// 			currentIndex -= static_cast<long>(groupSize);
// 		}
// 		else {
// 			//std::cout <<  "halfSTep: " << std::endl;
// 			currentIndex -= static_cast<long>(halfGroupSize);
// 		}
// 		currentMainChainIt = begin + currentIndex;
// 	}
// }

template <typename RandomAccessIterator>
size_t PmergeMe::searchInsertIndex(
	MainChainInfo &mainChainInfo,
 	size_t bottom,
	size_t top,
	RandomAccessIterator begin,
	RandomAccessIterator toInsert
) {
	//std::cout << "bottom: " << bottom << " top: " << top << std::endl;
	if (bottom >= top)
	{
		//	std::cout << "base" << std::endl;
		if (*toInsert > *(begin + mainChainInfo.indexWithCurrentAsLast(top)))
			return top + 1;
		else
			return top;
	}
	size_t middle = bottom + ((top - bottom) / 2);
	
	RandomAccessIterator middleIt = begin + mainChainInfo.indexWithCurrentAsLast(middle);
	//std::cout << "middle: " << middle << " *middleIt: " << *middleIt << std::endl;
	if (*toInsert > *middleIt)
		return searchInsertIndex(mainChainInfo, middle + 1, top, begin, toInsert);
	else
		return searchInsertIndex(mainChainInfo, bottom, middle - 1, begin, toInsert);
}

template <typename RandomAccessIterator>
void PmergeMe::insertElement(
	size_t indexFloor,
	size_t indexCeiling,
	size_t indexToInsert,
	RandomAccessIterator begin,
	RandomAccessIterator end,
	size_t groupSize)
{
	typedef RandomAccessIterator It;
	It toInsert = begin + indexToInsert;
	
	// std::cout << std::endl << "toInsert: " << *toInsert << std::endl;
	// std::cout << "begin: " << *begin << std::endl;
	// std::cout << "end: " << *end << std::endl;
	// std::cout << "groupSize: " << groupSize << std::endl;
	// std::cout << "indexFloor: " << indexFloor << std::endl;
	// std::cout << "indexToInsert: " << indexToInsert << std::endl;
	// std::cout << "indexCeiling: " << indexCeiling << std::endl;

	size_t halfGroupSize = groupSize >> 1;
		
	if (begin + indexCeiling >= end)
	{
		size_t wholeSize = end - begin;
		indexCeiling = wholeSize - 1;
	}

	// std::cout << "indexCeiling: " << indexCeiling << std::endl;
	// printContainer(begin, end);
	// std::cout << std::endl;
	PmergeMe::MainChainInfo mainChain = mainChainInfo(indexCeiling, indexToInsert, indexFloor, groupSize, halfGroupSize);
	//std::cout << "main chain size: " << mainChain.totalSize << std::endl;
	// size_t i = 0;
	// for (; i < mainChain.bottomSize; i++)
	// {
	// 	size_t idx = mainChain.index(i);
	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
	// }
	// for (; i < mainChain.bottomSize + mainChain.middleSize; i++)
	// {
	// 	size_t idx = mainChain.index(i);
	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
	// }
	// for (; i < mainChain.bottomSize + mainChain.middleSize + mainChain.topSize; i++)
	// {
	// 	size_t idx = mainChain.index(i);
	// 		std::cout << "i: " << i << " : " <<  idx << " : " << *(begin + idx) << std::endl;
	// }
	size_t toSwapMainChainIndex = searchInsertIndex(mainChain, 0, mainChain.totalSize - 2, begin, toInsert);

	//std::cout << "toSwapMainChainIndex: " << toSwapMainChainIndex << std::endl;
	if (toSwapMainChainIndex == mainChain.totalSize - 1)
		return;
	size_t indexToSwap = mainChain.indexWithCurrentAsLast(toSwapMainChainIndex);
	if (indexToSwap > indexToInsert) {
		//std::cout << "swap to right" << std::endl;
		for (size_t i = mainChain.toInsertMainChainIndex; i < toSwapMainChainIndex; i++)
		{
			size_t current = mainChain.index(i);
			size_t next = mainChain.index(i + 1);
			It currentIt = begin + current;
			It nextIt = begin + next;
			//	std::cout << "swaping " << *currentIt << " " << *nextIt << std::endl;
			swapGroup(currentIt, nextIt, halfGroupSize);
		}
	}
	else {
		//std::cout << "swap to left" << std::endl;
		for (size_t i = mainChain.toInsertMainChainIndex; i > toSwapMainChainIndex; i--)
		{
			size_t current = mainChain.index(i);
			size_t previous = mainChain.index(i - 1);
			It currentIt = begin + current;
			It previousIt = begin + previous;
			//	std::cout << "swaping " << *currentIt << " " << *previousIt << std::endl;
			swapGroup(currentIt, previousIt, halfGroupSize);
		}	
	}
}


template<typename RandomAccessIterator>
void PmergeMe::mergeGroup(
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
void PmergeMe::sortGroup(
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
	//printContainer(begin, end);
	//std::cout << std::endl;
	sortGroup(begin, end - rest, groupSize * 2);
	mergeGroup(begin, end, groupSize);
	//printContainer(begin, end);
	//std::cout << std::endl;
}

template<typename RandomAccessIterator>
double PmergeMe::mergeInsertionSort(RandomAccessIterator begin, RandomAccessIterator end)
{
	std::clock_t clocks_start = std::clock();
	sortGroup(begin, end, 2);
	std::clock_t clocks_end = std::clock();
	return static_cast<double>(clocks_end - clocks_start) / CLOCKS_PER_SEC * 1000000;
}
