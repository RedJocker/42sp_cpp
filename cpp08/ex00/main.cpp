// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/09 03:48:05 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <iostream>
#include <set>

template<typename ContainerStreamable>
void printContainer(ContainerStreamable container) {
	std::cout << "{ ";
	for (typename ContainerStreamable::iterator i = container.begin();
		 i != container.end();
		 i++
	) {
		std::cout << *i << " ";
	}
	std::cout << "}";
}

int main( void ) {

	//
	std::cout << "vec<int>:" << std::endl;
	{
		int arr[] = {1, 4, 3, 2};
		int toFind = 2;
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::vector<int>::iterator i = easyFind(vec, toFind);

		printContainer(vec);
		if (i == vec.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			std::cout << " found: " << *i << " atPosition: " << i - vec.begin() << std::endl;	
		}
	}
	{
		int arr[] = {1, 2, 3, 2};
		int toFind = 2;
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::vector<int>::iterator i = easyFind(vec, toFind);

		printContainer(vec);
		if (i == vec.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			std::cout << " found: " << *i << " atPosition: " << i - vec.begin() << std::endl;	
		}
	}
	{
		int arr[] = {10, 20, 30, 40, 10, 20};
		int toFind = 2;
		std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::deque<int>::iterator i = easyFind(deq, toFind);

		printContainer(deq);
		if (i == deq.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			std::cout << " found: " << *i << " atPosition: " << i - deq.begin() << std::endl;	
		}
	}
	//
	std::cout << "deque<int>:" << std::endl;
	{
		int arr[] = {10, 20, 30, 40, 10, 20};
		int toFind = 20;
		std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::deque<int>::iterator i = easyFind(deq, toFind);

		printContainer(deq);
		if (i == deq.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			std::cout << " found: " << *i << " atPosition: " << i - deq.begin() << std::endl;	
		}
	}
	{
		int arr[] = {10, 20, 30, 40, 10, 20};
		int toFind = 40;
		std::deque<int> deq(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::deque<int>::iterator i = easyFind(deq, toFind);

		printContainer(deq);
		if (i == deq.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			std::cout << " found: " << *i << " atPosition: " << i - deq.begin() << std::endl;	
		}
	}
	//
	std::cout << "set<int>:" << std::endl;
	{
		int arr[] = {-42, 0, 42, -42, 0, 42};
		int toFind = -100;
		std::set<int> set(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::set<int>::iterator i = easyFind(set, toFind);

		printContainer(set);
		if (i == set.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			int found = *i;
			int atPosition = 0;
			
			while (i != set.begin())
			{
				std::cout << *i;
				atPosition++;
				i--;
			}
			std::cout << " found: " << found << " atPosition: " << atPosition << std::endl;	
		}
	}
	{
		int arr[] = {-42, 0, 42, -42, 0, 42};
		int toFind = -42;
		std::set<int> set(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::set<int>::iterator i = easyFind(set, toFind);

		printContainer(set);
		if (i == set.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			int found = *i;
			int atPosition = 0;
			
			while (i != set.begin())
			{
				atPosition++;
				i--;
			}
			std::cout << " found: " << found << " atPosition: " << atPosition << std::endl;	
		}
	}
	{
		int arr[] = {-42, 0, 42, -42, 0, 42};
		int toFind = 0;
		std::set<int> set(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::set<int>::iterator i = easyFind(set, toFind);

		printContainer(set);
		if (i == set.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			int found = *i;
			int atPosition = 0;
			
			while (i != set.begin())
			{
				atPosition++;
				i--;
			}
			std::cout << " found: " << found << " atPosition: " << atPosition << std::endl;	
		}
	}
	{
		int arr[] = {-42, 42, -42, 0, 42};
		int toFind = 42;
		std::set<int> set(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::set<int>::iterator i = easyFind(set, toFind);

		printContainer(set);
		if (i == set.end()) {
			std::cout << " notFound: " << toFind << std::endl;	
		} else {
			int found = *i;
			int atPosition = 0;
			
			while (i != set.begin())
			{
				atPosition++;
				i--;
			}
			std::cout << " found: " << found << " atPosition: " << atPosition << std::endl;	
		}
	}
	
	return 0;
}
