// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:56:49 by maurodri          #+#    #+#             //
//   Updated: 2025/02/18 16:05:52 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	

public:

	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();
	void makeSound() const;
};


#endif
