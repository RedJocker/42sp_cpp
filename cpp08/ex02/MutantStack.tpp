// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MutantStack.tpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/12 01:35:28 by maurodri          #+#    #+#             //
//   Updated: 2025/07/21 18:17:08 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MutantStack.hpp"
#include <iostream>

template <typename StackElement>
MutantStack<StackElement>::MutantStack()
{

}

template <typename StackElement>
MutantStack<StackElement>::~MutantStack()
{

}

template <typename StackElement>
MutantStack<StackElement>::MutantStack(const MutantStack<StackElement> &other)
{
	*this = other;
}

template <typename StackElement>
MutantStack<StackElement> &MutantStack<StackElement>::operator=(
	const MutantStack<StackElement> &other)
{
	if (this == &other)
		return *this;
	this->c = other.c;
	return *this;
}

template <typename StackElement>
typename MutantStack<StackElement>::iterator MutantStack<StackElement>::begin()
{
	return this->c.begin();
}

template <typename StackElement>
typename MutantStack<StackElement>::iterator MutantStack<StackElement>::end()
{
	return this->c.end();
}

template <typename StackElement>
typename MutantStack<StackElement>::reverse_iterator
	MutantStack<StackElement>::rbegin()
{
	return this->c.rbegin();
}

template <typename StackElement>
typename MutantStack<StackElement>::reverse_iterator
	MutantStack<StackElement>::rend()
{
	return this->c.rend();
}
