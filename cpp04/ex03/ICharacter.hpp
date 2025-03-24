// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ICharacter.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 22:57:23 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:00:21 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include "AMateria.hpp"
# include <string>

class ICharacter
{
public:

	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
