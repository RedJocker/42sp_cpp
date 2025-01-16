// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/12 17:38:34 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 03:07:46 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>
#include <string>


int main(void)
{
	//PhoneBook phonebook;
	Contact c ("01234567890", "wwwaaaaaaaaaa", "abbbbbbbbbbbbbbb", "a", "a");
	std::cout <<  c;
}
