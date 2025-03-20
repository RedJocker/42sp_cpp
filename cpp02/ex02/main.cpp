// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/20 18:38:38 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cassert>
#include <iostream>
#include "Fixed.hpp"

// Should output something like (for greater readability, the constructor/destructor mes-
// sages are removed in the example below):
// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// $>

void test_raw_bits(void);
void test_to_float(void);
void test_to_int(void);
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);
void test_greater(void);
void test_greater_equal(void);
void test_less(void);
void test_less_equal(void);

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// test_raw_bits();
	// test_to_float();
	// test_to_int();
	// test_add();
	// test_subtract();
	// test_multiply();
	// test_divide();
	// test_greater();
	// test_greater_equal();
	// test_less();
	// test_less_equal();
	return 0;
}

void test_add(void)
{
	assert((Fixed(1) + Fixed(1)).toFloat() == 2.0f);
	assert((Fixed(1.5f) + Fixed(1)).toFloat() == 2.5f);
	assert((Fixed(1.5f) + Fixed(1.5f)).toFloat() == 3.0f);
	assert((Fixed(10.0f) + Fixed(-10.0f)).toFloat() == 0.0f);
	assert((Fixed(-10.0f) + Fixed(10.0f)).toFloat() == 0.0f);
	assert((Fixed(1.0f) + Fixed(-0.5f)).toFloat() == 0.5f);
	assert((Fixed(-1.0f) + Fixed(0.5f)).toFloat() == -0.5f);
	assert((Fixed(-42.0f) + Fixed(0.0f)).toFloat() == -42.0f);
	assert((Fixed(42.0f) + Fixed(0.0f)).toFloat() == 42.0f);
	assert((Fixed(0.0f) + Fixed(-42.0f)).toFloat() == -42.0f);
	assert((Fixed(0.0f) + Fixed(42.0f)).toFloat() == 42.0f);

}


void test_subtract(void)
{
	assert((Fixed(1) - Fixed(1)).toFloat() == 0.0f);
	assert((Fixed(1.5f) - Fixed(1)).toFloat() == 0.5f);
	assert((Fixed(1.5f) - Fixed(1.5f)).toFloat() == 0.0f);
	assert((Fixed(10.0f) - Fixed(-10.0f)).toFloat() == 20.0f);
	assert((Fixed(-10.0f) - Fixed(10.0f)).toFloat() == -20.0f);
	assert((Fixed(1.0f) - Fixed(-0.5f)).toFloat() == 1.5f);
	assert((Fixed(-1.0f) - Fixed(0.5f)).toFloat() == -1.5f);
	assert((Fixed(-42.0f) - Fixed(0.0f)).toFloat() == -42.0f);
	assert((Fixed(42.0f) - Fixed(0.0f)).toFloat() == 42.0f);
	assert((Fixed(0.0f) - Fixed(-42.0f)).toFloat() == 42.0f);
	assert((Fixed(0.0f) - Fixed(42.0f)).toFloat() == -42.0f);
}


void test_multiply(void)
{
	assert((Fixed(1) * Fixed(1)).toFloat() == 1.0f);
	assert((Fixed(1.5f) * Fixed(1)).toFloat() == 1.5f);
	assert((Fixed(1.5f) * Fixed(1.5f)).toFloat() == 2.25f);
	assert((Fixed(10.0f) * Fixed(-10.0f)).toFloat() == -100.0f);
	assert((Fixed(-10.0f) * Fixed(10.0f)).toFloat() == -100.0f);
	assert((Fixed(1.0f) * Fixed(-0.5f)).toFloat() == -0.5f);
	assert((Fixed(-1.0f) * Fixed(0.5f)).toFloat() == -0.5f);
	assert((Fixed(-42.0f) * Fixed(0.0f)).toFloat() == -0.0f);
	assert((Fixed(42.0f) * Fixed(0.0f)).toFloat() == 0.0f);
	assert((Fixed(0.0f) * Fixed(-42.0f)).toFloat() == 0.0f);
	assert((Fixed(0.0f) * Fixed(42.0f)).toFloat() == -0.0f);
	assert((Fixed(0.5f) * Fixed(0.5f)).toFloat() == 0.25f);
	assert((Fixed(-0.5f) * Fixed(0.5f)).toFloat() == -0.25f);
	assert((Fixed(0.5f) * Fixed(-0.5f)).toFloat() == -0.25f);
}

void test_divide(void)
{
	assert((Fixed(1) / Fixed(1)).toFloat() == 1.0f);
	assert((Fixed(1.5f) / Fixed(1)).toFloat() == 1.5f);
	assert((Fixed(1.5f) / Fixed(1.5f)).toFloat() == 1.0f);
	assert((Fixed(10.0f) / Fixed(-10.0f)).toFloat() == -1.0f);
	assert((Fixed(-10.0f) / Fixed(10.0f)).toFloat() == -1.0f);
	assert((Fixed(1.0f) / Fixed(-0.5f)).toFloat() == -2.0f);
	assert((Fixed(-1.0f) / Fixed(0.5f)).toFloat() == -2.0f);
	assert((Fixed(-42.0f) / Fixed(1.0f)).toFloat() == -42.0f);
	assert((Fixed(42.0f) / Fixed(1.0f)).toFloat() == 42.0f);
	assert((Fixed(0.0f) / Fixed(-42.0f)).toFloat() == 0.0f);
	assert((Fixed(0.0f) / Fixed(42.0f)).toFloat() == -0.0f);
	assert((Fixed(0.5f) / Fixed(0.5f)).toFloat() == 1.0f);
	assert((Fixed(-0.5f) / Fixed(0.5f)).toFloat() == -1.0f);
	assert((Fixed(0.5f) / Fixed(-0.5f)).toFloat() == -1.0f);
	assert((Fixed(-1.0f) / Fixed(-2.0f)).toFloat() == 0.5f);
}

void test_greater(void)
{
	assert((Fixed(1) > Fixed(1)) == false);
	assert((Fixed(1.5f) > Fixed(1)) == true);
	assert((Fixed(1.5f) > Fixed(1.5f)) == false);
	assert((Fixed(10.0f) > Fixed(-10.0f)) == true);
	assert((Fixed(-10.0f) > Fixed(10.0f)) == false);
	assert((Fixed(1.0f) > Fixed(-0.5f)) == true);
	assert((Fixed(-1.0f) > Fixed(0.5f)) == false);
	assert((Fixed(-42.0f) > Fixed(1.0f)) == false);
	assert((Fixed(42.0f) > Fixed(1.0f)) == true);
	assert((Fixed(0.0f) > Fixed(-42.0f)) == true);
	assert((Fixed(0.0f) > Fixed(42.0f)) == false);
	assert((Fixed(-42.0f) > Fixed(0.0f)) == false);
	assert((Fixed(42.0f) > Fixed(0.0f)) == true);
	assert((Fixed(0.5f) > Fixed(-42.0f)) == true);
	assert((Fixed(0.5f) > Fixed(42.0f)) == false);
	assert((Fixed(-42.0f) > Fixed(0.5f)) == false);
	assert((Fixed(42.0f) > Fixed(0.5f)) == true);
	assert((Fixed(0.0f) > Fixed(-42.5f)) == true);
	assert((Fixed(0.0f) > Fixed(42.5f)) == false);
	assert((Fixed(-42.5f) > Fixed(0.0f)) == false);
	assert((Fixed(42.5f) > Fixed(0.0f)) == true);
	assert((Fixed(0.5f) > Fixed(-42.5f)) == true);
	assert((Fixed(0.5f) > Fixed(42.5f)) == false);
	assert((Fixed(-42.5f) > Fixed(0.5f)) == false);
	assert((Fixed(42.5f) > Fixed(0.5f)) == true);
	assert((Fixed(0.5f) > Fixed(0.5f)) == false);
	assert((Fixed(-0.5f) > Fixed(0.5f)) == false);
	assert((Fixed(0.5f) > Fixed(-0.5f)) == true);
	assert((Fixed(-0.5f) > Fixed(-0.5f)) == false);
	Fixed min;
	min.setRawBits(0b10000000000000000000000000000000);
	assert(Fixed(0) > min);
	Fixed max;
	max.setRawBits(0b01111111111111111111111111111111);
	assert((max > Fixed(0)) == true);
	assert((max > min) == true);
	assert((min + 1 > min) == true);
	assert((max > max - 1) == true);
	assert((Fixed(0) > max) == false);
	assert((min > max) == false);
	assert((min > min + 1) == false);
	assert((max - 1 > max) == false);
	assert((min > min) == false);
	assert((max > max) == false);
}

void test_greater_equal(void)
{
	assert((Fixed(1) >= Fixed(1)) == true);
	assert((Fixed(1.5f) >= Fixed(1)) == true);
	assert((Fixed(1.5f) >= Fixed(1.5f)) == true);
	assert((Fixed(10.0f) >= Fixed(-10.0f)) == true);
	assert((Fixed(-10.0f) >= Fixed(10.0f)) == false);
	assert((Fixed(1.0f) >= Fixed(-0.5f)) == true);
	assert((Fixed(-1.0f) >= Fixed(0.5f)) == false);
	assert((Fixed(-42.0f) >= Fixed(1.0f)) == false);
	assert((Fixed(42.0f) >= Fixed(1.0f)) == true);
	assert((Fixed(0.0f) >= Fixed(-42.0f)) == true);
	assert((Fixed(0.0f) >= Fixed(42.0f)) == false);
	assert((Fixed(-42.0f) >= Fixed(0.0f)) == false);
	assert((Fixed(42.0f) >= Fixed(0.0f)) == true);
	assert((Fixed(0.5f) >= Fixed(-42.0f)) == true);
	assert((Fixed(0.5f) >= Fixed(42.0f)) == false);
	assert((Fixed(-42.0f) >= Fixed(0.5f)) == false);
	assert((Fixed(42.0f) >= Fixed(0.5f)) == true);
	assert((Fixed(0.0f) >= Fixed(-42.5f)) == true);
	assert((Fixed(0.0f) >= Fixed(42.5f)) == false);
	assert((Fixed(-42.5f) >= Fixed(0.0f)) == false);
	assert((Fixed(42.5f) >= Fixed(0.0f)) == true);
	assert((Fixed(0.5f) >= Fixed(-42.5f)) == true);
	assert((Fixed(0.5f) >= Fixed(42.5f)) == false);
	assert((Fixed(-42.5f) >= Fixed(0.5f)) == false);
	assert((Fixed(42.5f) >= Fixed(0.5f)) == true);
	assert((Fixed(0.5f) >= Fixed(0.5f)) == true);
	assert((Fixed(-0.5f) >= Fixed(0.5f)) == false);
	assert((Fixed(0.5f) >= Fixed(-0.5f)) == true);
	assert((Fixed(-0.5f) >= Fixed(-0.5f)) == true);
	Fixed min;
	min.setRawBits(0b10000000000000000000000000000000);
	assert(Fixed(0) > min);
	Fixed max;
	max.setRawBits(0b01111111111111111111111111111111);
	assert((max >= Fixed(0)) == true);
	assert((max >= min) == true);
	assert((min + 1 >= min) == true);
	assert((max >= max - 1) == true);
	assert((Fixed(0) >= max) == false);
	assert((min >= max) == false);
	assert((min >= min + 1) == false);
	assert((max - 1 >= max) == false);
	assert((min >= min) == true);
	assert((max >= max) == true);
}

void test_less(void)
{
	assert((Fixed(1) < Fixed(1)) == false);
	assert((Fixed(1.5f) < Fixed(1)) == false);
	assert((Fixed(1.5f) < Fixed(1.5f)) == false);
	assert((Fixed(10.0f) < Fixed(-10.0f)) == false);
	assert((Fixed(-10.0f) < Fixed(10.0f)) == true);
	assert((Fixed(1.0f) < Fixed(-0.5f)) == false);
	assert((Fixed(-1.0f) < Fixed(0.5f)) == true);
	assert((Fixed(-42.0f) < Fixed(1.0f)) == true);
	assert((Fixed(42.0f) < Fixed(1.0f)) == false);
	assert((Fixed(0.0f) < Fixed(-42.0f)) == false);
	assert((Fixed(0.0f) < Fixed(42.0f)) == true);
	assert((Fixed(-42.0f) < Fixed(0.0f)) == true);
	assert((Fixed(42.0f) < Fixed(0.0f)) == false);
	assert((Fixed(0.5f) < Fixed(-42.0f)) == false);
	assert((Fixed(0.5f) < Fixed(42.0f)) == true);
	assert((Fixed(-42.0f) < Fixed(0.5f)) == true);
	assert((Fixed(42.0f) < Fixed(0.5f)) == false);
	assert((Fixed(0.0f) < Fixed(-42.5f)) == false);
	assert((Fixed(0.0f) < Fixed(42.5f)) == true);
	assert((Fixed(-42.5f) < Fixed(0.0f)) == true);
	assert((Fixed(42.5f) < Fixed(0.0f)) == false);
	assert((Fixed(0.5f) < Fixed(-42.5f)) == false);
	assert((Fixed(0.5f) < Fixed(42.5f)) == true);
	assert((Fixed(-42.5f) < Fixed(0.5f)) == true);
	assert((Fixed(42.5f) < Fixed(0.5f)) == false);
	assert((Fixed(0.5f) < Fixed(0.5f)) == false);
	assert((Fixed(-0.5f) < Fixed(0.5f)) == true);
	assert((Fixed(0.5f) < Fixed(-0.5f)) == false);
	assert((Fixed(-0.5f) < Fixed(-0.5f)) == false);
	Fixed min;
	min.setRawBits(0b10000000000000000000000000000000);
	assert(Fixed(0) > min);
	Fixed max;
	max.setRawBits(0b01111111111111111111111111111111);
	assert((max < Fixed(0)) == false);
	assert((max < min) == false);
	assert((min + 1 < min) == false);
	assert((max < max - 1) == false);
	assert((Fixed(0) < max) == true);
	assert((min < max) == true);
	assert((min < min + 1) == true);
	assert((max - 1 < max) == true);
	assert((min < min) == false);
	assert((max < max) == false);
}

void test_less_equal(void)
{
	assert((Fixed(1) <= Fixed(1)) == true);
	assert((Fixed(1.5f) <= Fixed(1)) == false);
	assert((Fixed(1.5f) <= Fixed(1.5f)) == true);
	assert((Fixed(10.0f) <= Fixed(-10.0f)) == false);
	assert((Fixed(-10.0f) <= Fixed(10.0f)) == true);
	assert((Fixed(1.0f) <= Fixed(-0.5f)) == false);
	assert((Fixed(-1.0f) <= Fixed(0.5f)) == true);
	assert((Fixed(-42.0f) <= Fixed(1.0f)) == true);
	assert((Fixed(42.0f) <= Fixed(1.0f)) == false);
	assert((Fixed(0.0f) <= Fixed(-42.0f)) == false);
	assert((Fixed(0.0f) <= Fixed(42.0f)) == true);
	assert((Fixed(-42.0f) <= Fixed(0.0f)) == true);
	assert((Fixed(42.0f) <= Fixed(0.0f)) == false);
	assert((Fixed(0.5f) <= Fixed(-42.0f)) == false);
	assert((Fixed(0.5f) <= Fixed(42.0f)) == true);
	assert((Fixed(-42.0f) <= Fixed(0.5f)) == true);
	assert((Fixed(42.0f) <= Fixed(0.5f)) == false);
	assert((Fixed(0.0f) <= Fixed(-42.5f)) == false);
	assert((Fixed(0.0f) <= Fixed(42.5f)) == true);
	assert((Fixed(-42.5f) <= Fixed(0.0f)) == true);
	assert((Fixed(42.5f) <= Fixed(0.0f)) == false);
	assert((Fixed(0.5f) <= Fixed(-42.5f)) == false);
	assert((Fixed(0.5f) <= Fixed(42.5f)) == true);
	assert((Fixed(-42.5f) <= Fixed(0.5f)) == true);
	assert((Fixed(42.5f) <= Fixed(0.5f)) == false);
	assert((Fixed(0.5f) <= Fixed(0.5f)) == true);
	assert((Fixed(-0.5f) <= Fixed(0.5f)) == true);
	assert((Fixed(0.5f) <= Fixed(-0.5f)) == false);
	assert((Fixed(-0.5f) <= Fixed(-0.5f)) == true);
	Fixed min;
	min.setRawBits(0b10000000000000000000000000000000);
	assert(Fixed(0) > min);
	Fixed max;
	max.setRawBits(0b01111111111111111111111111111111);
	assert((max <= Fixed(0)) == false);
	assert((max <= min) == false);
	assert((min + 1 <= min) == false);
	assert((max <= max - 1) == false);
	assert((Fixed(0) <= max) == true);
	assert((min <= max) == true);
	assert((min <= min + 1) == true);
	assert((max - 1 <= max) == true);
	assert((min <= min) == true);
	assert((max <= max) == true);
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
}
