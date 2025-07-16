// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/16 17:27:37 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl << "==A==" << std::endl;
	Bureaucrat mrYes("Mr. Yes", 2);
	Bureaucrat cantMan("Can't man", 100);
	Intern intern;
	AForm *shrubberryForm = intern.makeForm("shrubbery creation", "restaurant");

	mrYes.executeForm(*shrubberryForm);
	std::cout << *shrubberryForm << std::endl;
	mrYes.signForm(*shrubberryForm);
	std::cout << *shrubberryForm << std::endl;
	mrYes.executeForm(*shrubberryForm);
	delete shrubberryForm;

	///
	std::cout << std::endl << "==B==" << std::endl;
	AForm *robotomyForm = intern.makeForm("robotomy request", "Can't man");

	mrYes.executeForm(*robotomyForm);
	std::cout << *robotomyForm << std::endl;
	mrYes.signForm(*robotomyForm);
	std::cout << *robotomyForm << std::endl;
	mrYes.executeForm(*robotomyForm);
	delete robotomyForm;
	
	//
	std::cout << std::endl << "==C==" << std::endl;
	AForm * presidentialForm = intern.makeForm("presidential pardon", "Civilian Protesting");
	cantMan.signForm(*presidentialForm);
	cantMan.executeForm(*presidentialForm);
	std::cout << *presidentialForm << std::endl;
	mrYes.signForm(*presidentialForm);
	std::cout << *presidentialForm << std::endl;
	cantMan.executeForm(*presidentialForm);
	std::cout << *presidentialForm << std::endl;
	mrYes.executeForm(*presidentialForm);
	std::cout << *presidentialForm << std::endl;
	delete presidentialForm;

	//
	std::cout << std::endl << "==D==" << std::endl;
	try
	{
		intern.makeForm("does not exist", "whatever");
	} catch (Intern::InvalidFormException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
