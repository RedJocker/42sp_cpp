// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/12 17:38:34 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 18:48:16 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Prompter.hpp"

int main(void)
{
	PhoneBook phonebook;

	while (!std::cin.eof())
	{
		std::string command;
		std::cout << "Input command (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof() || command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			Contact contact;
			if (!Prompter::prompt_contact(contact))
				std::cout << "Contact was not added" << std::endl;
			else
				phonebook.add(contact);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.isEmpty())
			{
				std::cout << "Phonebook is empty" << std::endl << std::endl;
				continue;
			}
			int id;
			phonebook.displayContacts();
			if (!Prompter::prompt_id(id))
				continue;
			const Contact *contact = phonebook.search(id);
			std::cout << "Id: " << id << std::endl;
			if (!contact)
				std::cout << "Contact not found" << std::endl;
			else
				std::cout << *contact;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	if (std::cin.eof())
		std::cout << "Input closed" << std::endl;
	std::cout << "Bye!" << std::endl;
	return (0);
}
