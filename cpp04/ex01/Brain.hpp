// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/12 18:17:45 by maurodri          #+#    #+#             //
//   Updated: 2025/03/12 19:32:36 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain
{
	std::string ideas[100];

public:

	Brain();
	Brain(const Brain &other);
	virtual Brain &operator=(const Brain &other);
	virtual ~Brain();
	void initIdeas();
	std::string idea() const;
};


#endif
