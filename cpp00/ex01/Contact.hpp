// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:23:24 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 03:29:18 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

// A saved contact can’t have empty fields.
class Contact {

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	// ellipsis if greater than max size
	static std::string normalized(const std::string &str);

public:

	Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone_number,
			std::string darkest_secret);
	Contact();
	bool is_empty() const;

	std::string firstName() const;
	std::string lastName() const;
	std::string nickname() const;
	std::string phoneNumber() const;
	std::string darkestSecret() const;

	std::string &firstNameRef();
	std::string &lastNameRef();
	std::string &nicknameRef();
	std::string &phoneNumberRef();
	std::string &darkestSecretRef();
};

std::ostream &operator<<(std::ostream &os, Contact &contact);

#endif
