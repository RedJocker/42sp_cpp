// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   WrongCat.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/12 17:14:15 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 17:39:48 by maurodri         ###   ########.fr       //
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
