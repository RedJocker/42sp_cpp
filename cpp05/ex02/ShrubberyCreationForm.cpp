// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 15:47:00 by maurodri          #+#    #+#             //
//   Updated: 2025/05/08 16:01:44 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ShrubberyCreationForm.hpp"
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137, target)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	assertBound(this->getGradeToSign());
	assertBound(this->getGradeToExecute());
}



ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other.getName(), 
            other.getGradeToSign(), 
            other.getGradeToExecute(), 
            other.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeTask()
{
	std::cout << "Executing Shrubbs" << std::endl;
}
