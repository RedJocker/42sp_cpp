// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:15:41 by maurodri          #+#    #+#             //
//   Updated: 2025/02/08 05:05:40 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <cmath>
#include <iostream>


const Fixed Fixed::FIXED_MAX = Fixed::getFixedMax();

const Fixed Fixed::getFixedMax()
{
	Fixed max_fixed;
	max_fixed.setRawBits(FIXED_MAX_RAW);
	return max_fixed;
}

const Fixed Fixed::FIXED_MIN = Fixed::getFixedMin();

const Fixed Fixed::getFixedMin()
{
	Fixed min_fixed;
	min_fixed.setRawBits(FIXED_MIN_RAW);
	return min_fixed;
}


Fixed::Fixed() : raw(0)
{
	
}

Fixed::Fixed(const Fixed &other)
{
	
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	
	this->raw = other.raw;
	return *this;
}

Fixed::~Fixed()
{
	
}

int Fixed::getRawBits(void) const
{
	
	return this->raw;
}

void Fixed::setRawBits(int const raw)
{
	
	this->raw = raw;
}

Fixed::Fixed(int num)
{
	
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

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long res = static_cast<long long>(this->getRawBits())
		* static_cast<long long>(other.getRawBits());
	result.setRawBits(static_cast<int>(res >> fractional_bits));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long numerator = static_cast<long long>(this->getRawBits())
		* (1 << fractional_bits);
	result.setRawBits(numerator / other.getRawBits());
	return result;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (static_cast<long long>(this->raw)
			- static_cast<long long>(other.raw)) > 0;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (static_cast<long long>(this->raw)
			- static_cast<long long>(other.raw)) >= 0;
}

bool Fixed::operator<(const Fixed& other) const
{
	return (static_cast<long long>(this->raw)
			- static_cast<long long>(other.raw)) < 0;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (static_cast<long long>(this->raw)
			- static_cast<long long>(other.raw)) <= 0;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->raw == other.raw;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->raw != other.raw;
}

Fixed &Fixed::operator++(void)
{
	this->raw++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	this->raw++;
	return ret;
}

Fixed &Fixed::operator--(void)
{
	this->raw--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->raw++;
	return ret;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a >= b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a >= b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a <= b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a <= b ? a : b;
}
