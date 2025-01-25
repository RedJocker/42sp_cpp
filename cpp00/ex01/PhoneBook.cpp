// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhoneBook.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:22:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/25 05:02:54 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <ios>

PhoneBook::PhoneBook()
{
	this->next_index = 0;
	this->is_init = false;
}

void PhoneBook::add(Contact contact)
{
	this->contacts[next_index++] = contact;
	if (next_index >= MAX_CONTACTS)
	{
		this->next_index = 0;
		this->is_init = true;
	}
}

const Contact *PhoneBook::search(int id) const
{
	if (id < 0 || id >= MAX_CONTACTS)
		return NULL;
	if (!this->is_init && id >= next_index)
		return NULL;
	return this->contacts + id;
}

void PhoneBook::displayContacts() const
{
	const int top = this->is_init ? MAX_CONTACTS : next_index;

	std::cout << std::endl
			  << "|===========================================|"
			  << std::endl;
	std::cout << std::left << "|"
			  << std::setw(10) << "id" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << "|"
			  << std::right << std::endl;
	std::cout << "|===========================================|"
			  << std::endl;
	for (int i = 0; i < top; ++i)
	{
		const Contact &contact = contacts[i];
		std::cout << "|"
				  << std::setw(10) << i << "|"
				  << std::setw(10) << contact.firstName() << "|"
				  << std::setw(10) << contact.lastName() << "|"
				  << std::setw(10) << contact.nickname() << "|"
				  << std::endl;
	}
	std::cout << "|===========================================|"
			  << std::endl
			  << std::endl;
}

bool PhoneBook::isEmpty() const
{
	return next_index == 0 && !is_init;
} 
