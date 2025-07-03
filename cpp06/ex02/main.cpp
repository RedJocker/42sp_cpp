// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 20:50:13 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cmath>
#include <ctime>
// Implement the following functions:

// Including the typeinfo header is forbidden.
// Write a program to test that everything works as expected.


Base* newA()
{
	return dynamic_cast<Base *>(new A());
}

Base* newB()
{
	return dynamic_cast<Base *>(new B());
}

Base* newC()
{
	return dynamic_cast<Base *>(new C());
}

// Base * generate(void);
// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base *generate(void)
{
	static Base *(*factory[])() = {
		::newA,
		::newB,
		::newC
	};
	int choice = rand() % 3;
	return factory[choice]();
}

// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "identified A*";
	} else if  (dynamic_cast<B *>(p))
	{
		std::cout << "identified B*";
	} else if  (dynamic_cast<C *>(p))
	{
		std::cout << "identified C*";
	}
	std::cout << std::endl;
}

// void identify(Base& p);
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base &ref)
{
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "identified A&";
		std::cout << std::endl;
		return;
	} catch (std::exception ex)
	{
		(void) ex;
	}

	try
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << "identified B&";
		std::cout << std::endl;
		return;
	} catch (std::exception ex)
	{
		(void) ex;
	}
	try
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << "identified C&";
		std::cout << std::endl;
		return;
	} catch (std::exception ex)
	{
		(void) ex;
	}
}

int main(void)
{
	srand(std::time(0));
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return 0;
}
