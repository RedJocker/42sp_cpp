// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/21 18:17:59 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

void print_element(int element) {
		std::cout << element << std::endl;
}

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	s.push(422);
	s.push(21);
	s.push(22);
	s.push(23);
	std::cout << "" << std::endl;

	std::for_each(mstack.begin(), mstack.end(), ::print_element);
	std::cout << "" << std::endl;

	MutantStack<int> stackCopy(mstack);

	std::for_each(stackCopy.begin(), stackCopy.end(), ::print_element);
	std::cout << "" << std::endl;

	std::for_each(stackCopy.rbegin(), stackCopy.rend(), ::print_element);
	std::cout << "" << std::endl;

	std::for_each(stackCopy.rbegin(), stackCopy.rend(), ::print_element);
	std::cout << "" << std::endl;

	return 0;
}
