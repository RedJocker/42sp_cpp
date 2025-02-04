// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 16:15:41 by maurodri          #+#    #+#             //
//   Updated: 2025/02/04 14:30:40 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include <cmath>
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
	bool is_negative = this->raw & sign_mask;
	int pos_raw = is_negative ? ~(this->raw - 1) : this->raw;
	int int_part = (pos_raw & uint_mask) >> fractional_bits;
	float decimal_part = (pos_raw & decimal_mask);
	decimal_part /= (1 << fractional_bits);
	float res = static_cast<float>(int_part) + decimal_part;
	return is_negative ? -res : res;
}

int Fixed::toInt(void) const
{
	bool is_negative = this->raw & sign_mask;
	int pos_raw = is_negative ? ~(this->raw - 1) : this->raw;
	int int_part = (pos_raw & uint_mask) >> fractional_bits;
	return is_negative ? -int_part : int_part;
	
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
	long long res = static_cast<long long>(this->getRawBits())
		/ static_cast<long long>(other.getRawBits());
	result.setRawBits(static_cast<int>(res << fractional_bits));
	return result;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->raw - other.raw) > 0;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->raw - other.raw) >= 0;
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->raw - other.raw) < 0;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->raw - other.raw) <= 0;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->raw == other.raw;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->raw != other.raw;
}
