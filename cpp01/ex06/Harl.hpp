// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Harl.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/27 16:20:29 by maurodri          #+#    #+#             //
//   Updated: 2025/01/27 17:57:06 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

// You have to create a Harl class with the following private member functions:
// • void debug( void );
// • void info( void );
// • void warning( void );
// • void error( void );
// Harl also has a public member function that calls the four member functions
// above depending on the level passed as parameter: void complain( std::string
// level ); The goal of this exercise is to use pointers to member functions.
// This is not a suggestion. Harl has to complain without using a forest of
// if/else if/else. It doesn’t think twice!

class Harl {
	typedef void (Harl::* HarlFun)();

	typedef struct HarlFunEntryStruct {
		std::string fun_name;
		HarlFun fun;
	} HarlFunEntry ;
	
	HarlFunEntry fun_map[4];

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void invalid(void);

  public:
	void complain(std::string level);
	void filter(std::string level);
	Harl();
};

#endif
