// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 14:39:34 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 15:50:12 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{

	virtual RobotomyRequestForm &operator=(
		const RobotomyRequestForm &other);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
};


#endif
