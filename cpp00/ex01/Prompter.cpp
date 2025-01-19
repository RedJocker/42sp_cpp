// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Prompter.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/16 17:08:31 by maurodri          #+#    #+#             //
//   Updated: 2025/01/19 17:21:25 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Prompter.hpp"
#include <iostream>
#include <cstdlib>

bool Prompter::is_blank(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(str.at(i)))
			return false;
	}
	return true;
}

bool Prompter::get_input(std::string &out, const std::string &field_name)
{
	while (true)
	{
		std::cout << "Input contact "<< field_name << ":" << std::endl;
		std::getline(std::cin, out);
		if (std::cin.eof())
			return false;
		else if (!is_blank(out))
			break;
		std::cout << "Invalid input for " << field_name
				  << ":" << std::endl;
		out = "";
		std::cout << "Try again (y or Y or single space for yes) "
				  << std::endl;
		std::string try_again;
		std::getline(std::cin, try_again);
		if (std::cin.eof() || (try_again != "y"
							   && try_again != "Y" && try_again != " "))
		{
			std::cout << "Not trying again" << std::endl;
			return false;
		}
		else
			std::cout << "Trying again" << std::endl;
	}
	return true;
}

bool Prompter::prompt_contact(Contact &contact)
{
	std::cout << std::endl;
	if (!get_input(contact.firstNameRef(), "first name"))
		return false;
	if (!get_input(contact.lastNameRef(), "last name"))
		return false;
	if (!get_input(contact.nicknameRef(), "nickname"))
		return false;
	if (!get_input(contact.phoneNumberRef(), "phone number"))
		return false;
	if (!get_input(contact.darkestSecretRef(), "darkest secret"))
		return false;
	std::cout << std::endl;
	return true;
}

bool Prompter::prompt_id(int &out_id)
{
	std::cout << "Input contact id" << std::endl;
	std::string id_str;
	std::getline(std::cin, id_str);
	if (std::cin.eof())
		return false;;
	std::cout << std::endl;
	if (id_str.length() != 1 || id_str[0] < '0' || id_str[0] >= '8')
		return false ;
	out_id = atoi(id_str.c_str());
	return  true;
}
