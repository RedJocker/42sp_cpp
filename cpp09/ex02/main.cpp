// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/08/04 17:31:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include "PmergeMe.hpp"
#include <ctime>

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
		// else
		// 	printContainer(maybeVector.second);
		// std::cout << std::endl;
		std::vector<int> vec = maybeVector.second;
		clock_t sortTime = organizer.mergeInsertionSort(vec.begin(), vec.end());
		(void) sortTime;
		organizer.printContainer(vec.begin(), vec.end());
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
