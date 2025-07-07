// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/03 21:06:47 by maurodri          #+#    #+#             //
//   Updated: 2025/07/07 16:11:43 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ITER_HPP
# define ITER_HPP

// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be called on every element of the array.
// Turn in a main.cpp file that contains your tests. Provide enough code to generate a
// test executable.
// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template

template <typename T> void iter(T arr[], size_t arrLen, void (*fun)(T element))
{
	for (size_t i = 0; i < arrLen; i++)
	{
		fun(arr[i]);
	}
}

#endif
