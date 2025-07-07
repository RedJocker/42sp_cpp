// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/07 18:27:33 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750
int given_main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(void) {

	{
		Array<int> arr0;
		std::cout << "arr0.size(): " << arr0.size() << std::endl;
		try
		{
			int i = arr0[1];
			std::cout << "should not print i: " << i << std::endl;
		} catch (std::out_of_range)
		{
			std::cout << "out of range access on arr0" << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Array<int> arr1(10);
		std::cout << "arr1.size(): " << arr1.size() << std::endl;
		std::cout << "arr1[0] before setting: " << arr1[0] << std::endl;
		arr1[0] = 100;
		std::cout << "arr1[0] after setting: " << arr1[0] << std::endl;
		std::cout << "arr1[9]: " << arr1[9] << std::endl;
	}
	std::cout << std::endl;
	{
		Array<std::string> arrStr(5);
		std::cout << "arrStr.size(): " << arrStr.size() << std::endl;
		std::cout << "arrStr[2] before setting: '" << arrStr[2] << "'" << std::endl;
		arrStr[2] = "some string value";
		std::cout << "arrStr[2] after setting: '" << arrStr[2] << "'" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "testing copy constructor:" << std::endl;
		Array<int> arrOriginal(10);
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			arrOriginal[i] = (i + 1) * 10;
		}
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			std::cout << "arrOriginal[i]: " << arrOriginal[i] << std::endl;
		}
		Array<int> arrCopy(arrOriginal);
		std::cout << "before modify copy:" << std::endl;
		for (unsigned int i = 0; i < arrCopy.size(); i++)
		{
			std::cout << "arrCopy[i]: " << arrCopy[i] << std::endl;
			arrCopy[i] /= 10;
		}
		std::cout << "after modify copy:" << std::endl;
		for (unsigned int i = 0; i < arrCopy.size(); i++)
		{
			std::cout << "arrCopy[i]: " << arrCopy[i] << std::endl;
		}
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			std::cout << "arrOriginal[i]: " << arrOriginal[i] << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "testing assignment operator:" << std::endl;
		Array<int> arrOriginal(3);
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			arrOriginal[i] = (i + 1) * 10;
		}
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			std::cout << "arrOriginal[i]: " << arrOriginal[i] << std::endl;
		}
		Array<int> arrCopy(0);
		std::cout << "arrCopy.size(), before assignment: " << arrCopy.size() << std::endl;
		arrCopy = arrOriginal;
		std::cout << "arrCopy.size(), after assignment: " << arrCopy.size() << std::endl;
		std::cout << "before modify copy:" << std::endl;
		for (unsigned int i = 0; i < arrCopy.size(); i++)
		{
			std::cout << "arrCopy[i]: " << arrCopy[i] << std::endl;
			arrCopy[i] /= 10;
		}
		std::cout << "after modify copy:" << std::endl;
		for (unsigned int i = 0; i < arrCopy.size(); i++)
		{
			std::cout << "arrCopy[i]: " << arrCopy[i] << std::endl;
		}
		for (unsigned int i = 0; i < arrOriginal.size(); i++)
		{
			std::cout << "arrOriginal[i]: " << arrOriginal[i] << std::endl;
		}
	}
	std::cout << std::endl;
	given_main();
	return 0;
}
