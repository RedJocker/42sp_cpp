// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/07 16:33:25 by maurodri          #+#    #+#             //
//   Updated: 2025/07/07 17:48:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstddef>

template <typename T> Array<T>::Array(): arr(new T[0]()), arrSize(0)
{
}

template <typename T> Array<T>::Array(unsigned int size): arr(new T[size]()), arrSize(size)
{
	
}

template <typename T> Array<T>::Array(const Array<T> &other) : arr(NULL)
{
	*this = other;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
	{
		return *this;
	}
	if (this->arr != NULL)
		delete[] this->arr;
	this->arrSize = other.size();
	this->arr = new T[other.size()];
	for (unsigned int i = 0; i < this->arrSize; i++)
	{
		this->arr[i] = other[i]; 
	}
	return *this;
}

template <typename T> Array<T>::~Array()
{
	if (this->arr != NULL)
		delete[] this->arr;
}

template <typename T> unsigned int Array<T>::size() const
{
	return this->arrSize;	
}

template <typename T> T &Array<T>::operator[](const unsigned int index)
{
	if (index >= this->size())
		throw std::out_of_range("Index out of bounds");
	return this->arr[index];
}

template <typename T> T &Array<T>::operator[](const unsigned int index) const
{
	if (index >= this->size())
		throw std::out_of_range("Index out of bounds");
	return this->arr[index];
}
