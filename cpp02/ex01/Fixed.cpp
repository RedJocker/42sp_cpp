// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:15:41 by maurodri          #+#    #+#             //
//   Updated: 2025/02/05 19:20:21 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cmath>
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = other.raw;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	if (num >= 0)
	{
		this->raw = num << fractional_bits;
	}
	else
	{
		this->raw = -num << fractional_bits;
		this->raw = ~this->raw + 1;
	}
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;

	int int_part = static_cast<int>(num);
	bool is_negative = int_part < 0;
	int_part = is_negative ? -int_part : int_part;
	float decimal_part = is_negative ? (num * -1) - int_part: num - int_part;
	int fixed_decimal = static_cast<int>(
		roundf(decimal_part * (1 << fractional_bits)));
	this->raw = (int_part << fractional_bits) + fixed_decimal;
	if (is_negative)
		this->raw = ~this->raw + 1;
}

float Fixed::toFloat(void) const
{
	int int_part = (this->raw & int_mask) / (1 << fractional_bits);
	float decimal_part = (this->raw & decimal_mask);
	decimal_part /= (1 << fractional_bits);
	float res = static_cast<float>(int_part) + decimal_part;
	return res;
}

int Fixed::toInt(void) const
{
	return static_cast<int>(this->toFloat());
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	std::cout << obj.toFloat();
	return os;
}
