// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Prompter.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/16 17:48:32 by maurodri          #+#    #+#             //
//   Updated: 2025/01/16 18:16:50 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PROMPTER_HPP
# define PROMPTER_HPP

#include "Contact.hpp"
#include <string>

class Prompter {
private:
	static bool is_blank(const std::string &str);
	static bool get_input(std::string &out, const std::string &field_name);
public:
	static bool prompt_contact(Contact &contact);
	static bool prompt_id(int &out_id);
};

#endif
