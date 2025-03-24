// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMateriaSource.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:05:46 by maurodri          #+#    #+#             //
//   Updated: 2025/03/23 23:07:15 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMATERIA_SOURCE_H
# define IMATERIA_SOURCE_H

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
