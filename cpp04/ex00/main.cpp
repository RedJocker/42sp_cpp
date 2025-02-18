// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 16:07:42 by maurodri         ###   ########.fr       //
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
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << "*dog type:" << dog->getType() << " " << std::endl;
		std::cout << "*cat type:" << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();
		delete animal;
		delete dog;
		delete cat;
	}

	std::cout << std::endl << "using pointers to stack allocated:"  << std::endl;
	{
		const Animal animal;
		const Dog dog;
		const Cat cat;

		const Animal *const animalPtr = &animal;
		const Animal *const dogPtr = &dog;
		const Animal *const catPtr = &cat;

		std::cout << "*dogPtr type:" << dogPtr->getType() << " " << std::endl;
		std::cout << "*catPtr type:" << catPtr->getType() << " " << std::endl;
		catPtr->makeSound();
		dogPtr->makeSound();
		animalPtr->makeSound();
	}

	std::cout << std::endl << "using pointers to stack allocated:"  << std::endl;
	{
		const Animal dog = Dog();
		const Animal cat = Cat();

		std::cout << "dog type:" << dog.getType() << " " << std::endl;
		std::cout << "cat type:" << cat.getType() << " " << std::endl;
		cat.makeSound();
		dog.makeSound();
	}

	std::cout << std::endl << "using class hierarchy without using virtual keyword:"  << std::endl;
	{
		const WrongCat* wrongCat = new WrongCat();
		const WrongAnimal *wrongAnimalCat = new WrongCat();
		const WrongAnimal* wrongAnimal = new WrongAnimal();

		std::cout << "wrongCat type:" << wrongCat->getType() << " " << std::endl;
		std::cout << "wrongAnimalCat type:" << wrongAnimalCat->getType() << " " << std::endl;
		std::cout << "wrongAnimal type:" << wrongAnimalCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		wrongAnimalCat->makeSound();
		wrongAnimal->makeSound();
		delete wrongAnimalCat;
		delete wrongCat;
		delete wrongAnimal;
	}
	return 0;
}
