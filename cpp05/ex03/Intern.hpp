// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/13 16:27:54 by maurodri          #+#    #+#             //
//   Updated: 2025/07/01 18:52:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

// Since filling out forms all day would be too cruel for our bureaucrats, interns exist to
// take on this tedious task. In this exercise, you must implement the Intern class. The
// intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
// care about is that they do their job.
// However, the intern has one key ability: the makeForm() function. This function
// takes two strings as parameters: the first one represents the name of a form, and the
// second one represents the target of the form. It returns a pointer to a AForm object
// (corresponding to the form name passed as a parameter), with its target initialized to
// the second parameter.
// It should print something like:
// Intern creates <form>
// If the provided form name does not exist, print an explicit error message.
// You must avoid unreadable and messy solutions, such as using an excessive if/el-
// seif/else structure. This kind of approach will not be accepted during the evaluation
// process. You’re not in the Piscine (pool) anymore. As usual, you must test everything
// to ensure it works as expected.

class Intern
{
	static const std::string formNames[];
	static AForm *(*formConstructors[]) (const std::string &target);
	static AForm *createShrubberryForm(const std::string &target);
	static AForm *createRobotomyForm(const std::string &target);
	static AForm *createPardonForm(const std::string &target);
public:
	AForm *makeForm(std::string formName, std::string formTarget);
	Intern();
	Intern(const Intern &other);
	virtual Intern &operator=(const Intern &other);
	virtual ~Intern();

	class InvalidFormException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};


#endif
