// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Harl.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/27 16:27:02 by maurodri          #+#    #+#             //
//   Updated: 2025/01/27 18:07:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon for my " << std::endl
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I really do!" << std::endl
			  << std::endl;
	return ;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money."
			  << std::endl
			  << "You didn’t put enough bacon in my burger!" << std::endl
			  << "If you did, I wouldn’t be asking for more!" << std::endl
			  << std::endl;
	return ;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
			  << "I think I deserve to have some extra bacon for free."
			  << std::endl
			  << "I’ve been coming for years whereas you started working here"
				" since last month." << std::endl
			  << std::endl;
	return ;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl
			  << std::endl;
	return ;
}

void Harl::invalid(void)
{
	std::cout << "[INVALID]" << std::endl
			  << "I don't understand what you mean by this."
			  << std::endl
			  << std::endl;
	return ;
}

Harl::Harl()
{
	this->fun_map[0].fun_name = "DEBUG";
	this->fun_map[0].fun = &Harl::debug;
	this->fun_map[1].fun_name = "INFO";
	this->fun_map[1].fun = &Harl::info;
	this->fun_map[2].fun_name = "WARNING";
	this->fun_map[2].fun = &Harl::warning;
	this->fun_map[3].fun_name = "ERROR";
	this->fun_map[3].fun = &Harl::error;
}

static std::string to_upper(const std::string &str)
{
	std::string upper(str);

	for (size_t i = 0; i < upper.length(); i++)
		upper.at(i) = std::toupper(upper.at(i));
	return upper;
}

void Harl::complain(std::string level)
{
	std::string level_norm = to_upper(level);
	
	for (size_t i = 0; i < 4; i++)
	{
		if (level_norm.compare(this->fun_map[i].fun_name) == 0)
		{
			(this->*fun_map[i].fun)();
			return ;
		}
	}
	this->invalid();
	return;
}

void Harl::filter(std::string level)
{
	std::string level_norm = to_upper(level);
	size_t i = 0;
	for (; i < 4; i++)
	{
		if (level_norm.compare(this->fun_map[i].fun_name) == 0)
			break ;
	}
	switch (i) {
		case 0 : (this->*fun_map[0].fun)();
		case 1 : (this->*fun_map[1].fun)();
		case 2 : (this->*fun_map[2].fun)();
		case 3 : (this->*fun_map[3].fun)();
			break;
		default  : this->invalid();
	}
	return;
}
