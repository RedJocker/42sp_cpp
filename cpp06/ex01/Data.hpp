// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Data.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/03 01:33:18 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 01:54:11 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	Data();
	Data &operator=(const Data &other);
	const std::string _data;
public:
	Data(const std::string &data);
	Data(const Data &other);	
	~Data();
	const std::string data() const;
};

#endif
