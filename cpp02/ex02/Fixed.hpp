// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:10:49 by maurodri          #+#    #+#             //
//   Updated: 2025/02/04 19:14:19 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

// Add public member functions to your class to overload the following operators:
// • The 6 comparison operators: >, <, >=, <=, == and !=.
// • The 4 arithmetic operators: +, -, *, and /.
// • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
// post-decrement) operators, that will increase or decrease the fixed-point value from
// the smallest representable ϵ such as 1 + ϵ > 1.
// Add these four public overloaded member functions to your class:
// • A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.

class Fixed
{
	static const int fractional_bits = 8;
	static const int sign_mask       = 0b10000000000000000000000000000000;
	static const int uint_mask       = 0b01111111111111111111111100000000;
	static const int decimal_mask    = 0b00000000000000000000000011111111;
	int raw;
public:
	Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();
	Fixed(int num);
	Fixed(float num);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	bool operator>(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
