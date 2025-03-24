// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:26:51 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:57:56 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria
{



public:

	Cure();
	Cure(const Cure &other);
	virtual Cure &operator=(const Cure &other);
	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter& target);
};


#endif
