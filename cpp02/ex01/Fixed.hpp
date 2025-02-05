// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:10:49 by maurodri          #+#    #+#             //
//   Updated: 2025/02/05 19:00:57 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

// Add the following public constructors and public member functions to your class:
// • A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00.
// • A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.
// And add the following function to the Fixed class files:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.

class Fixed
{
	static const int fractional_bits = 8;
	static const int sign_mask       = 0b10000000000000000000000000000000;
	static const int int_mask        = 0b11111111111111111111111100000000;
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
