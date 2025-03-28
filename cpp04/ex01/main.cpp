// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:47:40 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl << "using pointers to heap allocated:"  << std::endl;
	{
		const Animal* animal = new Animal();
		const Animal* cat = new Cat();
		const Animal* dog = new Dog();

		std::cout << "*animal type: " << animal->getType() << " " << std::endl;
		std::cout << "*cat type: " << cat->getType() << " " << std::endl;
		std::cout << "*dog type: " << dog->getType() << " " << std::endl;

		animal->makeSound();
		cat->makeSound();
		dog->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}

	std::cout << std::endl
			  << "using pointers to stack allocated:"  << std::endl;
	{
		const Animal animal;
		const Cat cat;
		const Dog dog;

		const Animal *const animalPtr = &animal;
		const Animal *const catPtr = &cat;
		const Animal *const dogPtr = &dog;

		std::cout << "*animalPtr type: " << animalPtr->getType() << " " << std::endl;
		std::cout << "*catPtr type: " << catPtr->getType() << " " << std::endl;
		std::cout << "*dogPtr type: " << dogPtr->getType() << " " << std::endl;

		animalPtr->makeSound();
		catPtr->makeSound();
		dogPtr->makeSound();
	}

	std::cout << std::endl
			  << "stack allocated with copy constructor:"  << std::endl;
	{
		const Animal animal = Animal();
		const Animal cat = Cat();
		const Animal dog = Dog();

		std::cout << "animal type:" << animal.getType() << " " << std::endl;
		std::cout << "cat type:" << cat.getType() << " " << std::endl;
		std::cout << "dog type:" << dog.getType() << " " << std::endl;

		animal.makeSound();
		cat.makeSound();
		dog.makeSound();
	}

	std::cout << std::endl
			  << "copying stack cats and dogs"  << std::endl;
	{
		const Cat cat = Cat();
		const Dog dog = Dog();
		const Cat catCopy = cat;
		const Dog dogCopy = dog;

		std::cout << "cat type:" << cat.getType() << " " << std::endl;
		std::cout << "dog type:" << dog.getType() << " " << std::endl;
		std::cout << "catCopy type:" << catCopy.getType() << " " << std::endl;
		std::cout << "dogCopy type:" << dogCopy.getType() << " " << std::endl;
		cat.makeSound();
		dog.makeSound();
		catCopy.makeSound();
		dogCopy.makeSound();
	}

	std::cout << std::endl
			  << "copying heap cats and dogs"  << std::endl;
	{
		const Cat *cat = new Cat();
		const Dog *dog = new Dog();
		const Cat catCopy = *cat;
		const Dog dogCopy = *dog;

		std::cout << "cat type:" << cat->getType() << " " << std::endl;
		std::cout << "dog type:" << dog->getType() << " " << std::endl;
		std::cout << "catCopy type:" << catCopy.getType() << " " << std::endl;
		std::cout << "dogCopy type:" << dogCopy.getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		delete cat;
		delete dog;
		catCopy.makeSound();
		dogCopy.makeSound();
	}

	return 0;
}
