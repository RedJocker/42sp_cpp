// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhoneBook.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:22:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 01:38:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->next_index = 0;
}

void PhoneBook::add(Contact contact)
{
	this->contacts[next_index] = contact;
}

Contact PhoneBook::search(int id)
{
	// TODO
	(void) id;
	return Contact();
}
