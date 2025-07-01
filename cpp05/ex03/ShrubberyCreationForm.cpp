// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/08 15:47:00 by maurodri          #+#    #+#             //
//   Updated: 2025/05/09 17:42:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137, target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	assertBound(this->getGradeToSign());
	assertBound(this->getGradeToExecute());
	return *this;
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

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "File failed to open";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::string path = this->getTarget() + "_shruberry";
	std::ofstream outFileStream;

	outFileStream.open(path.c_str());
	if (!outFileStream.is_open())
		throw ShrubberyCreationForm::FileOpenException();

	outFileStream << "                                   **  " << std::endl
				  << "  *  **   **    **   **     ***  ***** " << std::endl
				  << "   #3##**Y*  *&**  *^**   **#@**o*****" << std::endl
				  << "   *vv**/*   *&&* *%Y**  (**Y****WW***" << std::endl
				  << "    \\>/      %%* */.\\    (||)*  | |**" << std::endl
				  << "     \\        )  (        )I(   / \\  " << std::endl
				  << "     ^         | |         I    /\\/\\ " << std::endl
				  << "   @@@@       }}|{{       xMx  xxXxx " << std::endl
				  << "  ......     .......    ..... ......" << std::endl
				  << "...................................." << std::endl;
	std::cout << path << " created" << std::endl;
}
