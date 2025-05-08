// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/06 16:37:59 by maurodri          #+#    #+#             //
//   Updated: 2025/05/08 14:30:37 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : name("invalid"), gradeToSign(-1), gradeToExecute(-1)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

Form::Form(const Form &other)
    : name(other.name + "Copy"),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
	assertBound(this->gradeToSign);
	assertBound(this->gradeToExecute);
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->isSigned = other.isSigned;
	this->assertBound(other.gradeToSign);
	this->assertBound(other.gradeToExecute);
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}


void Form::assertBound(int grade)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}
	
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Form::beSigned(Bureaucrat &bureacrat)
{
	if (bureacrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
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
