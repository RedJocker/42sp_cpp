// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Wronganimal.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:42:25 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 14:47:19 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>


class WrongAnimal
{

protected:

	std::string type;
	WrongAnimal(const std::string type);

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};


#endif
