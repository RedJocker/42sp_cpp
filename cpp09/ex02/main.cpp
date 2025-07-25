// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/24 21:47:39 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <sstream>
#include <vector>

std::pair<bool, unsigned int> parseUInt(char *str)
{
	std::istringstream iss(str);

	int result;

	iss >> result;

	if (iss.fail() || !iss.eof() || result < 0)
	{
		return std::make_pair(false, 0);
	}
	return std::make_pair(true, result);
}

template <class Container>
std::pair<bool, Container> createListFromArgs(char **args)
{
	Container container;

	for (char **p = args; *p != NULL; p++) {
		std::pair<bool, unsigned int> parseResult = parseUInt(*p);
		if (!parseResult.first)
			return std::make_pair(false, container);
		container.push_back(parseResult.second);
	}
	return std::make_pair(true, container);
}

template<typename ContainerStreamable>
void printContainer(ContainerStreamable container) {
	for (typename ContainerStreamable::iterator i = container.begin();
		 i != container.end();
	) {
		std::cout << *i;
		if (++i != container.end())
			std::cout << " ";
	}
}

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

	std::pair<bool, std::vector<int> > maybeVector =
		createListFromArgs<std::vector<int> >(argv + 1);
	if (!maybeVector.first) {
		std::cerr << "Error" << std::endl;
		return 22;
	}
	else
		printContainer(maybeVector.second);	
	return 0;
}
