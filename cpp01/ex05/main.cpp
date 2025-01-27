// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/27 17:16:50 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Harl.hpp"
int main(void)
{
	Harl harl;

	harl.complain("debug");
	harl.complain("Info");
	harl.complain("warNing");
	harl.complain("ERROR");
	harl.complain("");
	return (0);
}
