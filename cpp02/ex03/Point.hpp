// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Point.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:10:49 by maurodri          #+#    #+#             //
//   Updated: 2025/02/05 01:59:50 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

// Let’s start by creating the class Point in Orthodox Canonical Form that represents
// a 2D point:
// • Private members:
// ◦ A Fixed const attribute x.
// ◦ A Fixed const attribute y.
// ◦ Anything else useful.
// • Public members:
// ◦ A default constructor that initializes x and y to 0.
// ◦ A constructor that takes as parameters two constant floating-point numbers.
// It initializes x and y with those parameters.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ Anything else useful.

class Point
{
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	Point(const float x, const float y);
	const Fixed& X() const;
	const Fixed& Y() const;
};

#endif
