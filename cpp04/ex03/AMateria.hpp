// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/13 19:51:36 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:52:21 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMATERIA_H
# define AMATERIA_H


# include <string>

class ICharacter;

class AMateria
{

	std::string type;
	AMateria();

public:
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	virtual AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
