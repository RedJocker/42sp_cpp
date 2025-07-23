// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RPN.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/19 18:14:50 by maurodri          #+#    #+#             //
//   Updated: 2025/07/22 21:26:48 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{	
	
public:

	RPN();
	RPN(const RPN &other);
	virtual RPN &operator=(const RPN &other);
	virtual ~RPN();

	std::pair<int, std::string> calculate(char **operation);
};


#endif
