// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 14:39:34 by maurodri          #+#    #+#             //
//   Updated: 2025/05/08 14:45:52 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : AForm
{

	virtual ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm();
	
public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	virtual void executeTask();
};


#endif
