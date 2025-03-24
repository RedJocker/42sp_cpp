// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 22:55:13 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:58:30 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{

public:

	Ice();
	Ice(const Ice &other);
	virtual Ice &operator=(const Ice &other);
	virtual ~Ice();
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};


#endif
