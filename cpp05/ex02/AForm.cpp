// ************************************************************************** //
//																			  //
//														  :::	   ::::::::	  //
//	 AForm.cpp											:+:		 :+:	:+:	  //
//													  +:+ +:+		  +:+	  //
//	 By: maurodri <maurodri@student.42sp...>		+#+	 +:+	   +#+		  //
//												  +#+#+#+#+#+	+#+			  //
//	 Created: 2025/05/08 14:32:22 by maurodri		   #+#	  #+#			  //
//   Updated: 2025/05/09 15:35:06 by maurodri         ###   ########.fr       //
//																			  //
// ************************************************************************** //

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : name("invalid"), gradeToSign(-1), gradeToExecute(-1)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

AForm::AForm(
	std::string name, int gradeToSign, int gradeToExecute, std::string target)
	: name(name),
	  target(target),
	  isSigned(false),
	  gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

AForm::AForm(const AForm &other)
	: name(other.name + "Copy"),
	  target(other.target),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	this->isSigned = other.isSigned;
	this->assertBound(other.gradeToSign);
	this->assertBound(other.gradeToExecute);
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->name;
}


std::string AForm::getTarget() const
{
	return this->target;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}


void AForm::assertBound(int grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}

	if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return "Form is not signed";
}

void AForm::beSigned(Bureaucrat &bureacrat)
{
	if (bureacrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	return os << "Form: "
			  << form.getName()
			  << ", is signed: "
			  << form.getIsSigned()
			  << ", required grade to sign: "
			  << form.getGradeToSign()
			  << ", to execute: "
			  << form.getGradeToExecute();
}
