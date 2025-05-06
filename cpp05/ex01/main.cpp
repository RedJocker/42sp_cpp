// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/05/06 17:28:12 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl;
	Bureaucrat mrYes("Mr. Yes", 18);

	Form formA("Form A", 20);
	std::cout << formA << std::endl;
	mrYes.signForm(formA);
	std::cout << formA << std::endl;
	std::cout << std::endl;

	Form formB("Form B", 17);
	std::cout << formB << std::endl;
	mrYes.signForm(formB);
	std::cout << formB << std::endl;
	std::cout << std::endl;

	std::cout << "Incrementing " << mrYes.getName() << " grade" << std::endl;
	mrYes.increment();
	mrYes.signForm(formB);
	std::cout << formB << std::endl;
	return 0;
}
