// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 17:12:48 by maurodri         ###   ########.fr       //
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
	std::cout << std::endl << std::endl << std::endl;
	Bureaucrat mrYes("Mr. Yes", 2);
	Bureaucrat cantMan("Can't man", 100);

	//
	ShrubberyCreationForm shrubberryForm("restaurant");

	mrYes.executeForm(shrubberryForm);
	std::cout << shrubberryForm << std::endl;
	mrYes.signForm(shrubberryForm);
	std::cout << shrubberryForm << std::endl;
	mrYes.executeForm(shrubberryForm);

	std::cout << std::endl << std::endl << std::endl;
	//

	RobotomyRequestForm  robotomyForm("Can't man");

	mrYes.executeForm(robotomyForm);
	std::cout << robotomyForm << std::endl;
	mrYes.signForm(robotomyForm);
	std::cout << robotomyForm << std::endl;
	mrYes.executeForm(robotomyForm);

	std::cout << std::endl << std::endl << std::endl;
	//

	PresidentialPardonForm presidentialForm("Civilian Protesting");
	cantMan.signForm(presidentialForm);
	cantMan.executeForm(presidentialForm);
	std::cout << presidentialForm << std::endl;
	mrYes.signForm(presidentialForm);
	std::cout << presidentialForm << std::endl;
	cantMan.executeForm(presidentialForm);
	std::cout << presidentialForm << std::endl;
	mrYes.executeForm(presidentialForm);
	std::cout << presidentialForm << std::endl;

	return 0;
}
