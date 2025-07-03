// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Data.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/03 01:33:04 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 01:54:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Data.hpp"

Data::Data(): _data("") {
	
}
Data::Data(const std::string &data) : _data(data) {

}
Data::Data(const Data &other) : _data(other.data()){

}
Data &Data::operator=(const Data &other) {
	(void) other;
	return *this;	
}
Data::~Data(){

}

const std::string Data::data() const{
	return this->_data;
}
