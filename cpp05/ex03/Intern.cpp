// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 17:25:18 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 18:52:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

AForm *Intern::createShrubberryForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

const std::string Intern::formNames[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

AForm *(*Intern::formConstructors[])(const std::string &target) = {
    &Intern::createShrubberryForm,
    &Intern::createRobotomyForm,
	&Intern::createPardonForm
};

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	for (size_t i = 0; i < formNames->length(); i++)
	{
		if (formNames[i].compare(formName) == 0) {
			AForm *newForm = formConstructors[i](formTarget);
			std::cout << "Intern creates " << newForm->getName() << std::endl;
			return newForm;
		}
	}
	
	throw InvalidFormException();
}

Intern::Intern()
{
	return;
}
Intern::Intern(const Intern &other)
{
	(void) other;
	return;
}
Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;	
}

Intern::~Intern()
{
	return;
}

const char *Intern::InvalidFormException::what() const throw()
{
	return "Invalid Form";
}
