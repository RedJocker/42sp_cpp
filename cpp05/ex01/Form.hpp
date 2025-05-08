// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/05/06 16:26:25 by maurodri          #+#    #+#             //
//   Updated: 2025/05/08 14:19:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

/**
 * Now that you have bureaucrats, let’s give them something to do. What better activity
 * could there be than the one of filling out a stack of forms?
 * Then, let’s make a Form class. It has:
 * • A constant name.
 * • A boolean indicating whether it is signed (at construction, it’s not).
 * • A constant grade required to sign it.
 * • And a constant grade required to execute it.
 * All these attributes are private, not protected.
 * The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
 * the following exceptions will be thrown if a form grade is out of bounds:
 * Form::GradeTooHighException and Form::GradeTooLowException.
 * Same as before, write getters for all attributes and an overload of the insertion («)
 * operator that prints all the form’s informations.
 * 
 * Add also a beSigned() member function to the Form that takes a Bureaucrat as
 * parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
 * (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
 * If the grade is too low, throw a Form::GradeTooLowException.
 * Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
 * it will print something like:
 * <bureaucrat> signed <form>
 * Otherwise, it will print something like:
 * <bureaucrat> couldn’t sign <form> because <reason>.
 * Implement and turn in some tests to ensure everything works as expected.
 */
class Form
{
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	static void assertBound(int grade);
	virtual Form &operator=(const Form &other);
public:
  	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	virtual ~Form();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat &bureacrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();	
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
