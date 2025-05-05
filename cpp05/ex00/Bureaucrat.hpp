// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/05 17:14:47 by maurodri          #+#    #+#             //
//   Updated: 2025/05/05 17:57:22 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <ostream>

/**
 * A Bureaucrat must have:
 * • A constant name.
 * • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
 * grade).
 * Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex-
 * ception:
 * either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
 * You will provide getters for both these attributes: getName() and getGrade(). Im-
 * plement also two member functions to increment or decrement the bureaucrat grade. If
 * the grade is out of range, both of them will throw the same exceptions as the constructor.
 * The thrown exceptions must be catchable using try and catch blocks.
 * You will implement an overload of the insertion («) operator to print something like:
 *     ```<name>, bureaucrat grade <grade>.``` 
 * (without the angle brackets):
 */
class Bureaucrat
{
	const std::string name;
	int grade;

	void assertBound() const;
public:

	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	virtual Bureaucrat &operator=(const Bureaucrat &other);
	virtual ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();	
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
