// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 20:06:27 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << std::endl;
	Bureaucrat mrYes("Mr. Yes", 2);

	RobotomyRequestForm  sbForm("home");

	mrYes.executeForm(sbForm);
	std::cout << sbForm << std::endl;
	mrYes.signForm(sbForm);
	std::cout << sbForm << std::endl;
	mrYes.executeForm(sbForm);
	return 0;
}
