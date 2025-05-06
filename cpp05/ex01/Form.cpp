// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/06 16:37:59 by maurodri          #+#    #+#             //
//   Updated: 2025/05/06 17:13:30 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : name("invalid"), grade(-1)
{
	this->assertBound();
}

Form::Form(std::string name, int grade) : name(name), isSigned(false), grade(grade)
{
	this->assertBound();
}

Form::Form(const Form &other)
    : name(other.name + "Copy"), isSigned(other.isSigned), grade(other.grade)
{
	this->assertBound();
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->isSigned = other.isSigned;
	this->assertBound();
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGrade() const
{
	return this->grade;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

void Form::assertBound()
{
	if (this->grade < 1)
	{
		throw GradeTooHighException();
	}

	if (this->grade > 150)
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
	if (bureacrat.getGrade() > this->getGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	return os << "Form: "
			  << form.getName()
			  << ", required grade: "
	          << form.getGrade()
			  << ", is signed: "
			  << form.getIsSigned();	
}
