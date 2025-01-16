// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PhoneBook.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/13 18:21:39 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 18:23:39 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	static const int	MAX_CONTACTS = 8;
	Contact				contacts[MAX_CONTACTS];
	int					next_index;
	bool				is_init;
public:
	/*
	* If the user enters this command,
	* they are prompted to input the information
	* of the new contact one field at a time.
	* Once all the fields have been completed,
	* add the contact to the phonebook.
	*/
	void add(Contact contact);

	/*
	 * Display the saved contacts as
	 * a list of 4 columns:
	 * - index
	 * - first name
	 * - last name
	 * - nickname
	 * Each column must be 10 characters wide.
	 * A pipe character (’|’) separates them.
	 * The text must be right-aligned.
	 * If the text is longer than the column, it must be truncated
	 * and the last displayable character
	 * must be replaced by a dot (’.’).
	 * Then, prompt the user again
	 * for the index of the entry to display.
	 * If the index is out of range or wrong, define a relevant behavior.
	 * Otherwise, display the contact information, one field per line.
	*/
	Contact *search(int id);

	void displayContacts();

	PhoneBook();
};

#endif
