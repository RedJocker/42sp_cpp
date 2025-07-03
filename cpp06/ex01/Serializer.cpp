// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Serializer.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:20:10 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 02:02:47 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other)
{
	(void) other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void) other;
	return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr) {
	
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
