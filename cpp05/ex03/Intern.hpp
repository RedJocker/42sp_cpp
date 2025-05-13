// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/13 16:27:54 by maurodri          #+#    #+#             //
//   Updated: 2025/05/13 16:29:31 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{

	

public:
	AForm *makeForm
	Intern();
	Intern(const Intern &other);
	virtual Intern &operator=(const Intern &other);
	virtual ~Intern();
};


#endif
