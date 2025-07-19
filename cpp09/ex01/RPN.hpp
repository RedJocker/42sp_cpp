// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RPN.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/19 18:14:50 by maurodri          #+#    #+#             //
//   Updated: 2025/07/19 18:26:20 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RPN_HPP
# define RPN_HPP

class RPN
{	
	
public:

	RPN();
	RPN(const RPN &other);
	virtual RPN &operator=(const RPN &other);
	virtual ~RPN();
};


#endif
