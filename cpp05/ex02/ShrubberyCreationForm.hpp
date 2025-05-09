// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 14:39:34 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 17:33:17 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{

	virtual ShrubberyCreationForm &operator=(
		const ShrubberyCreationForm &other);

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const &executor) const;
	class FileOpenException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};


#endif
