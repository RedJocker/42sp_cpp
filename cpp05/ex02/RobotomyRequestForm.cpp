// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RobotomyRequestForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 15:47:00 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 15:44:01 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45, target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	assertBound(this->getGradeToSign());
	assertBound(this->getGradeToExecute());
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getName(),
			other.getGradeToSign(),
			other.getGradeToExecute(),
			other.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << "Executing Robotomy" << std::endl;
}
