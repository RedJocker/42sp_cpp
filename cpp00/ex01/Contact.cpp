// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:24:12 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 03:27:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.hpp"
#include <stdexcept>
#include <iomanip>

Contact::Contact(std::string first_name,
				 std::string last_name,
				 std::string nickname,
				 std::string phone_number,
				 std::string darkest_secret)
	: _first_name(first_name),
	  _last_name(last_name),
	  _nickname(nickname),
	  _phone_number(phone_number),
	  _darkest_secret(darkest_secret){

	if (this->is_empty())
		throw std::domain_error("A saved contact can't have empty fields");
}

Contact::Contact() {}

bool Contact::is_empty() const
{
	return this->_first_name.empty()
	|| this->_last_name.empty()
	|| this->_nickname.empty()
	|| this->_darkest_secret.empty();
}

std::ostream& operator<<(std::ostream& os, Contact &contact) {
	os
	   << std::setw(10) << contact.firstName() << "|"
	   << std::setw(10) << contact.lastName() << "|"
	   << std::setw(10) << contact.nickname() << "|"
	   << std::setw(10) << contact.phoneNumber() << "|"
	   << std::setw(10) << contact.darkestSecret();
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
