// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Point.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/05 01:35:09 by maurodri          #+#    #+#             //
//   Updated: 2025/02/05 05:07:51 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Point &other): x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	const_cast<Fixed&>(this->x) = other.x;
	const_cast<Fixed&>(this->y) = other.y;
	return *this;
}

Point::~Point() {}

Point::Point(const float x, const float y)
	: x(Fixed(x)), y(Fixed(y)) {}

const Fixed& Point::X() const
{
	return this->x;;
}

const Fixed& Point::Y() const
{
	return this->y;
}
