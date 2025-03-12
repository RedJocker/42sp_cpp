// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 17:26:55 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
			  << "using class hierarchy without using virtual keyword:"
			  << std::endl;
	{
		const WrongAnimal	*wrongAnimal = new WrongAnimal();
		const WrongCat	*wrongCat = new WrongCat();
		const WrongAnimal *wrongAnimalCat = new WrongCat();

		std::cout << "wrongAnimal type:" << wrongAnimal->getType() << " " << std::endl;
		std::cout << "wrongCat type:" << wrongCat->getType() << " " << std::endl;
		std::cout << "wrongAnimalCat type:" << wrongAnimalCat->getType() << " " << std::endl;

		wrongCat->makeSound();
		wrongAnimal->makeSound();
		wrongAnimalCat->makeSound();
		delete wrongAnimal;
		delete wrongCat;
		delete wrongAnimalCat;
	}
	return 0;
}
