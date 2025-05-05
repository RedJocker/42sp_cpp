// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/05/05 18:25:41 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
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
	
	return 0;
}
