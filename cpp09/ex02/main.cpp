// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/08/04 19:03:49 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

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

	PmergeMe organizer;

	{
		std::pair<bool, std::vector<int> > maybeVector =
			organizer.createListFromArgs<std::vector<int> >(argv + 1);
		if (!maybeVector.first) {
			std::cerr << "Error" << std::endl;
			return 22;
		}
		std::vector<int> vec = maybeVector.second;
		std::cout << std::setprecision(6);
		std::cout << "Before:  ";
		organizer.printContainer(vec.begin(), vec.end());
		std::cout << std::endl;
		double sortTime = organizer.mergeInsertionSort(vec.begin(), vec.end());
		std::cout << "After:   ";
		organizer.printContainer(vec.begin(), vec.end());
		std::cout << std::endl;
		std::cout << "Time to process a range of "
				  << vec.size()
				  << " elements with std::vector<int> : "
				  << sortTime
				  << "us"
				  << std::endl;
	}

	{
		std::pair<bool, std::deque<int> > maybeDeque =
			organizer.createListFromArgs<std::deque<int> >(argv + 1);
		if (!maybeDeque.first) {
			std::cerr << "Error" << std::endl;
			return 22;
		}
		std::deque<int> deq = maybeDeque.second;
		double sortTime = organizer.mergeInsertionSort(deq.begin(), deq.end());
		std::cout << "Time to process a range of "
				  << deq.size()
				  << " elements with std::deque<int> : "
				  << sortTime
				  << "us"
				  << std::endl;
	}
	
	return 0;
}
