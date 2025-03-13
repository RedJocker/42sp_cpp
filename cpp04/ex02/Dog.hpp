// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Dog.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:56:49 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:43:12 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain *brain;

public:

	Dog();
	Dog(const Dog &other);
	virtual Dog &operator=(const Dog &other);
	virtual ~Dog();
	virtual void makeSound() const;
};


#endif
