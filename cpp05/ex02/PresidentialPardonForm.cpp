// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PresidentialPardonForm.cpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/09 15:49:13 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 20:20:28 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Pardon Form", 25, 5, target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	assertBound(this->getGradeToSign());
	assertBound(this->getGradeToExecute());
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &other)
	: AForm(other.getName(),
			other.getGradeToSign(),
			other.getGradeToExecute(),
			other.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << getTarget()
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
