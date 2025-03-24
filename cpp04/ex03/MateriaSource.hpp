// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:07:49 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 02:00:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

#include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	AMateria *templates[4];

public:

	MateriaSource();
	MateriaSource(const MateriaSource &other);
	virtual MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};


#endif
