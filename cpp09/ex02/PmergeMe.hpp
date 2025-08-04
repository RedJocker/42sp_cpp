// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PmergeMe.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/08/04 16:48:14 by maurodri          #+#    #+#             //
//   Updated: 2025/08/04 18:02:33 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <utility>
# include <cstddef>
# include <ctime>

class PmergeMe
{
	std::pair<bool, unsigned int> parseUInt(char *str);

	template<typename RandomAccessIterator>
	void swapGroup(
		RandomAccessIterator leaderA,
		RandomAccessIterator leaderB,
		size_t groupSize);

	size_t leaderIndexAtGroupSize(size_t i, size_t groupSize);

	size_t bottomIndexAtGroupSize(size_t i, size_t groupSize);

	template <typename RandomAccessIterator>
	void insertElement(
		size_t indexFloor,
		size_t indexCeiling,
		size_t indexToInsert,
		RandomAccessIterator begin,
		RandomAccessIterator end,
		size_t groupSize);

	size_t jacobsthalNumber(size_t n);

	template<typename RandomAccessIterator>
	void mergeGroup(
		RandomAccessIterator begin, RandomAccessIterator end, size_t groupSize);

	template<typename RandomAccessIterator>
	void sortGroup(
		RandomAccessIterator begin, RandomAccessIterator end, size_t groupSize);

public:

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	virtual PmergeMe &operator=(const PmergeMe &other);
	virtual ~PmergeMe();

	template <typename Container>
	std::pair<bool, Container> createListFromArgs(char **args);

	template<typename RandomAccessIterator>
	double mergeInsertionSort(RandomAccessIterator begin, RandomAccessIterator end);

	template<typename Iterator>
	void printContainer(Iterator begin, Iterator end);
};

# include "PmergeMe.tpp"

#endif
