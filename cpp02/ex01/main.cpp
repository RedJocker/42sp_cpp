// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/20 18:38:09 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cassert>
#include <iostream>
#include "Fixed.hpp"

// Should output something similar to:
// $> ./a.out
// Default constructor called
// Int constructor called
// Float constructor called
// Copy constructor called
// Copy assignment operator called
// Float constructor called
// Copy assignment operator called
// Destructor called
// a is 1234.43
// b is 10
// c is 42.4219
// d is 10
// a is 1234 as integer
// b is 10 as integer
// c is 42 as integer
// d is 10 as integer
// Destructor called
// Destructor called
// Destructor called
// Destructor called
// $>


void test_raw_bits(void);
void test_to_float(void);
void test_to_int(void);

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// test_raw_bits();
	// test_to_float();
	// test_to_int();
	return 0;
}

void test_raw_bits(void)
{
	// all precise decimals places
	assert(Fixed(0.0f).getRawBits()
		   == 0b00000000000000000000000000000000);
	assert(Fixed(0.5f).getRawBits()
		   == 0b00000000000000000000000010000000);
	assert(Fixed(0.25f).getRawBits()
		   == 0b00000000000000000000000001000000);
	assert(Fixed(0.125f).getRawBits()
		   == 0b00000000000000000000000000100000);
	assert(Fixed(1.0f / 16).getRawBits()
		   == 0b00000000000000000000000000010000);
	assert(Fixed(1.0f / 32).getRawBits()
		   == 0b00000000000000000000000000001000);
	assert(Fixed(1.0f / 64).getRawBits()
		   == 0b00000000000000000000000000000100);
	assert(Fixed(1.0f / 128).getRawBits()
		   == 0b00000000000000000000000000000010);
	assert(Fixed(1.0f / 256).getRawBits()
		   == 0b00000000000000000000000000000001);

	// few mixed decimals precise
	assert(Fixed(0.625f).getRawBits()
		   == 0b00000000000000000000000010100000);
	assert(Fixed(0.66015625f).getRawBits()
		   == 0b00000000000000000000000010101001);

	// round down
	assert(Fixed(0.66015626f).getRawBits()
		   == 0b00000000000000000000000010101001);
	assert(Fixed(0.66015627f).getRawBits()
		   == 0b00000000000000000000000010101001);
	assert(Fixed(0.66015628f).getRawBits()
		   == 0b00000000000000000000000010101001);

	// round up
	assert(Fixed(0.66015624f).getRawBits()
		   == 0b00000000000000000000000010101001);
	assert(Fixed(0.66015623f).getRawBits()
		   == 0b00000000000000000000000010101001);

	// all precise decimals places negative (2complement)
	assert(Fixed(-0.0f).getRawBits()
		   == 0b00000000000000000000000000000000);
	assert(Fixed(-0.5f).getRawBits()
		   == (int) 0b11111111111111111111111110000000);
	assert(Fixed(-0.25f).getRawBits()
		   == (int) 0b11111111111111111111111111000000);
	assert(Fixed(-0.125f).getRawBits()
		   == (int) 0b11111111111111111111111111100000);
	assert(Fixed(-1.0f / 16).getRawBits()
		   == (int) 0b11111111111111111111111111110000);
	assert(Fixed(-1.0f / 32).getRawBits()
		   == (int) 0b11111111111111111111111111111000);
	assert(Fixed(-1.0f / 64).getRawBits()
		   == (int) 0b11111111111111111111111111111100);
	assert(Fixed(-1.0f / 128).getRawBits()
		   == (int) 0b111111111111111111111111111111110);
	assert(Fixed(-1.0f / 256).getRawBits()
		   == (int) 0b11111111111111111111111111111111);

	// few mixed decimals precise
	assert(Fixed(-0.625f).getRawBits()
		   == (int) 0b11111111111111111111111101100000);
	assert(Fixed(-0.66015625f).getRawBits()
		   == (int) 0b11111111111111111111111101010111);

	// round up
	assert(Fixed(-0.66015626f).getRawBits()
		   == (int) 0b11111111111111111111111101010111);
	assert(Fixed(-0.66015627f).getRawBits()
		   == (int) 0b11111111111111111111111101010111);

	// round down
	assert(Fixed(-0.66015624f).getRawBits()
		   == (int) 0b11111111111111111111111101010111);
	assert(Fixed(-0.66015623f).getRawBits()
		   == (int) 0b11111111111111111111111101010111);

	// some positive integers
	assert(Fixed(28.f).getRawBits()
		   == 0b00000000000000000001110000000000);
	assert(Fixed(35.f).getRawBits()
		   == 0b00000000000000000010001100000000);

	// some negative integers (2complement)
	assert(Fixed(-28.f).getRawBits()
		   == (int) 0b11111111111111111110010000000000);
	assert(Fixed(-35.f).getRawBits()
		   == (int) 0b11111111111111111101110100000000);

	// some positive numbers with decimals
	assert(Fixed(256.5f).getRawBits()
		   ==       0b00000000000000010000000010000000);
	assert(Fixed(256.53125f).getRawBits()
		   == 0b00000000000000010000000010001000);
	assert(Fixed(3.14f).getRawBits()
		   == 0b00000000000000000000001100100100);

	// some negative numbers with decimals (2complement)
	assert(Fixed(-256.5f).getRawBits()
		   == (int) 0b11111111111111101111111110000000);
	assert(Fixed(-256.53125f).getRawBits()
		   == (int) 0b11111111111111101111111101111000);
	assert(Fixed(-3.14f).getRawBits()
		   == (int) 0b11111111111111111111110011011100);
}

void test_to_float(void)
{
	// all precise decimals places
	assert(Fixed(0.0f).toFloat() == 0.0f);
	assert(Fixed(0.5f).toFloat() == 0.5f);
	assert(Fixed(0.25f).toFloat() == 0.25f);
	assert(Fixed(0.125f).toFloat() == 0.125f);
	assert(Fixed(1.0f / 16).toFloat() == 1.0f / 16);
	assert(Fixed(1.0f / 32).toFloat() == 1.0f / 32);
	assert(Fixed(1.0f / 64).toFloat() == 1.0f / 64);
	assert(Fixed(1.0f / 128).toFloat() == 1.0f / 128);
	assert(Fixed(1.0f / 256).toFloat() == 1.0f / 256);

	// // few mixed decimals precise
	assert(Fixed(0.625f).toFloat() == 0.625f);
	assert(Fixed(0.66015625f).toFloat() == 0.66015625f);

	// // round down
	assert(Fixed(0.66015626f).toFloat() == 0.66015625f);
	assert(Fixed(0.66015627f).toFloat() == 0.66015625f);
	assert(Fixed(0.66015628f).toFloat() == 0.66015625f);

	// // round up
	assert(Fixed(0.66015624f).toFloat() == 0.66015625f);
	assert(Fixed(0.66015623f).toFloat() == 0.66015625f);

	// // all precise decimals places negative (2complement)
	assert(Fixed(-0.0f).toFloat() == -0.0f);
	assert(Fixed(-0.5f).toFloat() == -0.5f);
	assert(Fixed(-0.25f).toFloat() == -0.25f);
	assert(Fixed(-0.125f).toFloat() == -0.125f);
	assert(Fixed(-1.0f / 16).toFloat() == -1.0f / 16);
	assert(Fixed(-1.0f / 32).toFloat() == -1.0f / 32);
	assert(Fixed(-1.0f / 64).toFloat() == -1.0f / 64);
	assert(Fixed(-1.0f / 128).toFloat() == -1.0f / 128);
	assert(Fixed(-1.0f / 256).toFloat() == -1.0f / 256);

	// // few mixed decimals precise
	assert(Fixed(-0.625f).toFloat() == -0.625f);
	assert(Fixed(-0.66015625f).toFloat() == -0.66015625f);;

	// // round up
	assert(Fixed(-0.66015626f).toFloat() == -0.66015625f);
	assert(Fixed(-0.66015627f).toFloat() == -0.66015625f);;

	// // round down
	assert(Fixed(-0.66015624f).toFloat() == -0.66015625f);
	assert(Fixed(-0.66015623f).toFloat() == -0.66015625f);

	// // some positive integers
	assert(Fixed(28.f).toFloat() == 28.f);
	assert(Fixed(35.f).toFloat() == 35.f);

	// // some negative integers (2complement)
	assert(Fixed(-28.f).toFloat() == -28.f);
	assert(Fixed(-35.f).toFloat() == -35.f);

	// // some positive numbers with decimals
	assert(Fixed(256.5f).toFloat() == 256.5f);
	assert(Fixed(256.53125f).toFloat() == 256.53125f);
	assert(Fixed(3.14f).toFloat() == 3.140625f);

	// // some negative numbers with decimals (2complement)
	assert(Fixed(-256.5f).toFloat() == -256.5f);
	assert(Fixed(-256.53125f).toFloat() == -256.53125f);
	assert(Fixed(-3.14f).toFloat() == -3.140625f);
}

void test_to_int(void)
{
	// all precise decimals places
	assert(Fixed(0.0f).toInt() == 0);
	assert(Fixed(0.5f).toInt() == 0);
	assert(Fixed(0.25f).toInt() == 0);
	assert(Fixed(0.125f).toInt() == 0);
	assert(Fixed(1.0f / 16).toInt() == 0);
	assert(Fixed(1.0f / 32).toInt() == 0);
	assert(Fixed(1.0f / 64).toInt() == 0);
	assert(Fixed(1.0f / 128).toInt() == 0);
	assert(Fixed(1.0f / 256).toInt() == 0);

	// // few mixed decimals precise
	assert(Fixed(0.625f).toInt() == 0);
	assert(Fixed(0.66015625f).toInt() == 0);

	// // round down
	assert(Fixed(0.66015626f).toInt() == 0);
	assert(Fixed(0.66015627f).toInt() == 0);
	assert(Fixed(0.66015628f).toInt() == 0);

	// // round up
	assert(Fixed(0.66015624f).toInt() == 0);
	assert(Fixed(0.66015623f).toInt() == 0);

	// // all precise decimals places negative (2complement)
	assert(Fixed(-0.0f).toInt() == -0);
	assert(Fixed(-0.5f).toInt() == 0);
	assert(Fixed(-0.25f).toInt() == -0);
	assert(Fixed(-0.125f).toInt() == -0);
	assert(Fixed(-1.0f / 16).toInt() == 0);
	assert(Fixed(-1.0f / 32).toInt() == 0);
	assert(Fixed(-1.0f / 64).toInt() == 0);
	assert(Fixed(-1.0f / 128).toInt() == 0);
	assert(Fixed(-1.0f / 256).toInt() == 0);

	// // few mixed decimals precise
	assert(Fixed(-0.625f).toInt() == -0);
	assert(Fixed(-0.66015625f).toInt() == -0);;

	// // round up
	assert(Fixed(-0.66015626f).toInt() == -0);
	assert(Fixed(-0.66015627f).toInt() == -0);;

	// // round down
	assert(Fixed(-0.66015624f).toInt() == -0);
	assert(Fixed(-0.66015623f).toInt() == -0);

	// // some positive integers
	assert(Fixed(28.f).toInt() == 28);
	assert(Fixed(35.f).toInt() == 35);

	// // some negative integers (2complement)
	assert(Fixed(-28.f).toInt() == -28);
	assert(Fixed(-35.f).toInt() == -35);

	// // some positive numbers with decimals
	assert(Fixed(256.5f).toInt() == 256);
	assert(Fixed(256.53125f).toInt() == 256);
	assert(Fixed(3.14f).toInt() == 3);

	// // some negative numbers with decimals (2complement)
	assert(Fixed(-256.5f).toInt() == -256);
	assert(Fixed(-256.53125f).toInt() == -256);
	assert(Fixed(-3.14f).toInt() == -3);

	Fixed min_fixed;
	min_fixed.setRawBits(0b10000000000000000000000000000000);
	assert(Fixed(min_fixed.toFloat()).toFloat() == min_fixed.toFloat());
}
