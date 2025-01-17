// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:24:12 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 18:41:00 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.hpp"

std::ostream& operator<<(std::ostream& os, const Contact &contact) {
	Contact &c = const_cast<Contact&>(contact);
	os
		<< "First name: " << c.firstNameRef() << std::endl
		<< "Last name: " << c.lastNameRef() << std::endl
		<< "Nickname: " << c.nicknameRef() << std::endl
		<< "Phone number: " << c.phoneNumberRef() << std::endl
		<< "Darkest secret: " << c.darkestSecretRef() << std::endl;
	return os;
}

std::string Contact::normalized(const std::string &str) {
	if (str.length() <= 10)
		return str;
	return str.substr(0, 9) + ".";
}

std::string Contact::firstName() const
{
	return normalized(this->_first_name);
}

std::string Contact::lastName() const
{
	return normalized(this->_last_name);
}

std::string Contact::nickname() const
{
	return normalized(this->_nickname);
}

std::string Contact::phoneNumber() const
{
	return normalized(this->_phone_number);
}

std::string Contact::darkestSecret() const
{
	return normalized(this->_darkest_secret);
}

std::string &Contact::firstNameRef()
{
	return this->_first_name;
}

std::string &Contact::lastNameRef()
{
	return this->_last_name;
}

std::string &Contact::nicknameRef()
{
	return this->_nickname;
}

std::string &Contact::phoneNumberRef()
{
	return this->_phone_number;
}

std::string &Contact::darkestSecretRef()
{
	return this->_darkest_secret;
}
