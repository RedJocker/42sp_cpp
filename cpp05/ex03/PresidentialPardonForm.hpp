// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/09 15:49:00 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 17:33:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{

	virtual PresidentialPardonForm &operator=(
		const PresidentialPardonForm &other);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};


#endif
