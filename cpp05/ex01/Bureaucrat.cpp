// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/05 17:36:25 by maurodri          #+#    #+#             //
//   Updated: 2025/05/06 17:21:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("invalid"), grade(-1)
{
	this->assertBound();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	this->assertBound();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name + "Copy"), grade(other.grade)
{
	this->assertBound();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
	this->assertBound();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::increment()
{
	this->grade--;
	this->assertBound();
}

void Bureaucrat::decrement()
{
	this->grade++;
	this->assertBound();
}

void Bureaucrat::assertBound()
{
	if (this->grade < 1)
	{
		this->grade = 1;
		throw GradeTooHighException();
	}

	if (this->grade > 150)
	{
		this->grade = 150;
		throw GradeTooLowException();
	}
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name
		          << " signed "
				  << form.getName()
				  << std::endl;
	} catch (Form::GradeTooLowException exception)
	{
		std::cout << this->name
		          << " couldn't sign "
				  << form.getName()
				  << " because "
				  << exception.what()
				  << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too High";
}
	
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return os << bureaucrat.getName()
	          << " bureaucrat grade "
			  << bureaucrat.getGrade();
}
