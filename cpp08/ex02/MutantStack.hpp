// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MutantStack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/12 01:28:43 by maurodri          #+#    #+#             //
//   Updated: 2025/07/12 16:09:39 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename StackElement>
class MutantStack : public std::stack<StackElement>
{

public:

	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);

	~MutantStack();

	typedef typename
		std::stack<StackElement>
			::container_type
			::iterator iterator;
	typedef typename
		std::stack<StackElement>
			::container_type
			::const_iterator const_iterator;
	typedef typename
		std::stack<StackElement>
			::container_type
			::reverse_iterator reverse_iterator;
	typedef typename
		std::stack<StackElement>
			::container_type
			::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator cbegin();
	const_iterator cend();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator crbegin();
	const_reverse_iterator crend();

};

#include "MutantStack.tpp"

#endif
