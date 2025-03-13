// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cat.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 17:56:49 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:06:58 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	Brain	*brain;
	void	init();

public:

	Cat();
	Cat(const Cat &other);
	virtual Cat &operator=(const Cat &other);
	virtual ~Cat();
	virtual void makeSound() const;

};


#endif
