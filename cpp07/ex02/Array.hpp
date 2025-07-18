// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/07 16:33:25 by maurodri          #+#    #+#             //
//   Updated: 2025/07/07 17:14:24 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_HPP
# define ARRAY_HPP


// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that con-
// tains your tests.

template <typename T>
class Array
{

	T *arr;
	unsigned int arrSize;
public:

	Array();
	Array(unsigned int size);
	Array(const Array<T> &other);
	virtual Array &operator=(const Array<T> &other);
	virtual ~Array();
	unsigned int size() const;
	T &operator[](const unsigned int index);
	T &operator[](const unsigned int index) const;
};

#include "Array.tpp"
#endif
