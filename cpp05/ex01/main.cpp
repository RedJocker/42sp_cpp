// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/16 17:11:59 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << "==A==" << std::endl;
	Bureaucrat mrYes("Mr. Yes", 18);

	Form formA("Form A", 20, 80);
	std::cout << formA << std::endl;
	mrYes.signForm(formA);
	std::cout << formA << std::endl;
	std::cout << std::endl;

	//////
	std::cout << std::endl << "==B==" << std::endl;
	Form formB("Form B", 17, 50);
	std::cout << formB << std::endl;
	mrYes.signForm(formB);
	std::cout << formB << std::endl;

	//////
	std::cout << std::endl << "==C==" << std::endl;
	Form formBCopy(formB);
	std::cout << formBCopy << std::endl;
	std::cout << "Incrementing " << mrYes.getName() << " grade" << std::endl;
	mrYes.increment();
	mrYes.signForm(formBCopy);
	std::cout << formB << std::endl;
	std::cout << formBCopy << std::endl;

	return 0;
}
