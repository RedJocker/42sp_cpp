// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Animal.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:42:25 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 16:52:22 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

// Start by implementing a simple base class called Animal. It has one protected
// attribute:
// • std::string type;

class Animal
{
	std::string type;
protected:

	Animal(const std::string type);

public:

	Animal();
	Animal(const Animal &other);
	virtual Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};


#endif
