// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/10 01:53:35 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

template<typename ForwardIterator>
void printContainer(ForwardIterator begin, ForwardIterator end) {
	std::cout << "{ ";
	for (ForwardIterator i = begin; i != end; i++) {
		std::cout << *i << " ";
	}
	std::cout << "}";
}

int main( void ) {

	try
	{
		int arr[] = {6, 3, 17, 9, 11};
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		Span sp = Span(arrSize);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr[0]);
		sp.addNumber(arr[1]);
		sp.addNumber(arr[2]);
		sp.addNumber(arr[3]);
		sp.addNumber(arr[4]);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		Span sp = Span(arrSize);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		Span sp = Span(arrSize - 2);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize - 2);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize - 2);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		Span sp = Span(arrSize - 2);

		std::cout << "arr: ";
		printContainer(arr + 2, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr + 2, arr + arrSize);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		Span sp = Span(arrSize - 2);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = 0;
		Span sp = Span(arrSize);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize);
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		int arr[] = {6, 3, 17, 9, 11, 100};
		unsigned int arrSize = 0;
		Span sp = Span(arrSize);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize);
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	try
	{
		std::srand(0);
		int arr[2000];
		
		unsigned int arrSize = sizeof(arr) / sizeof(int);
		for (unsigned int i = 0; i < arrSize; i++)
			arr[i] = std::rand();
		Span sp = Span(arrSize);

		std::cout << "arr: ";
		printContainer(arr, arr + arrSize);
		std::cout << std::endl;
		sp.addNumber(arr, arr + arrSize);
		std::cout << "\tmax: " << sp.longestSpan() << std::endl;
		std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}
