// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/16 17:02:01 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl << "==A==" << std::endl;
	Bureaucrat mrYes("Mr. Yes", 18);

	std::cout << mrYes << std::endl;
	while (mrYes.getGrade() > 1)
	{
		mrYes.increment();
		std::cout << mrYes << std::endl;
	}
	try
	{
		mrYes.increment();
	} catch (Bureaucrat::GradeTooHighException exception)
	{
		std::cout << exception.what() << std::endl;
	}
	std::cout << mrYes << std::endl;
	

	/////
	std::cout << std::endl << "==B==" << std::endl;
	while (mrYes.getGrade() < 150)
	{
		mrYes.decrement();
		std::cout << mrYes << std::endl;
	}
	try
	{
		mrYes.decrement();
	} catch (Bureaucrat::GradeTooLowException exception)
	{
		std::cout << exception.what() << std::endl;
	}
	std::cout << mrYes << std::endl;

	std::cout << std::endl << "==C==" << std::endl;

	Bureaucrat mrYesCopyConstructor = mrYes;
	std::cout << mrYesCopyConstructor << std::endl;
	mrYesCopyConstructor.increment();
	std::cout << mrYesCopyConstructor << std::endl;
	std::cout << mrYes << std::endl;


	/////
	std::cout << std::endl << "==D==" << std::endl;
	Bureaucrat mrYesCopyAssignment("Mr. YesCopyAssignment", 10);
	mrYesCopyAssignment = mrYes;
	mrYesCopyAssignment.increment();
	std::cout << mrYesCopyAssignment << std::endl;
	std::cout << mrYes << std::endl;

	return 0;
}
