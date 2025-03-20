// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/20 18:46:00 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cassert>
#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed slope(Point const &a, Point const &b);
bool inside(Point const &o, Point const &a, Point const &b, Point const &p);
bool bsp(Point const a, Point const b, Point const c, Point const point);

void test_slope(void);
void test_inside(void);
void test_triangle(void);
void assert_triangle(
	Point const &a, Point const &b, Point const &c, Point const &p, bool expect);

// online calculator: is point in triangle?
// https://planetcalc.com/8108/
int main(void)
{
	std::cout << bsp(
		Point(1, 7),
		Point(11, 1),
		Point(2, 20),
		Point(7, 6)
	);
	test_triangle();
	test_inside();
	test_slope();
	return (0);
}

void assert_triangle(
	Point const &a, Point const &b, Point const &c, Point const &p, bool expect)
{
	assert(bsp(a, b, c, p) == expect);
	assert(bsp(a, c, b, p) == expect);
	assert(bsp(b, a, c, p) == expect);
	assert(bsp(b, c, a, p) == expect);
	assert(bsp(c, a, b,p) == expect);
	assert(bsp(c, b, a, p) == expect);
}

void test_triangle(void)
{
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(1, 1),
		true);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(-1, -1),
		false);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(1, -1),
		false);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(-1, 1),
		false);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(0, 0),
		false);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(0, 10),
		false);
	assert_triangle(
		Point(0, 0),
		Point(0, 10),
		Point(10, 0),
		Point(10, 0),
		false);

	assert_triangle(
		Point(0, 10),
		Point(-10, -10),
		Point(10, -10),
		Point(0, 0),
		true);
	assert_triangle(
		Point(0, 10),
		Point(-10, -10),
		Point(10, -10),
		Point(0, 0.5f),
		true);
	assert_triangle(
		Point(0, 10),
		Point(-10, -10),
		Point(10, -10),
		Point(3, 1),
		true);
	assert_triangle(
		Point(0, 10),
		Point(0, -10),
		Point(10, -10),
		Point(2, 2),
		true);
	assert_triangle(
		Point(0, 10),
		Point(0, -10),
		Point(10, -10),
		Point(4, 4),
		false);
}

void test_slope()
{
	assert(slope(Point(1, 1),Point(0, 0)) == Fixed(1));
	assert(slope(Point(1, 2),Point(0, 0)) == Fixed(2));
	assert(slope(Point(2, 1),Point(0, 0)) == Fixed(0.5f));
	
	assert(slope(Point(1, -1),Point(0, 0)) == Fixed(-1));
	assert(slope(Point(1, -2),Point(0, 0)) == Fixed(-2));
	assert(slope(Point(2, -1),Point(0, 0)) == Fixed(-0.5f));

	assert(slope(Point(-1, -1),Point(0, 0)) == Fixed(1));
	assert(slope(Point(-1, -2),Point(0, 0)) == Fixed(2));
	assert(slope(Point(-2, -1),Point(0, 0)) == Fixed(0.5f));

	assert(slope(Point(-1, 1),Point(0, 0)) == Fixed(-1));
	assert(slope(Point(-1, 2),Point(0, 0)) == Fixed(-2));
	assert(slope(Point(-2, 1),Point(0, 0)) == Fixed(-0.5f));

	assert(slope(Point(10, 0),Point(0, 0)) == Fixed(0));
	assert(slope(Point(0, 10),Point(0, 0)) == Fixed::FIXED_MIN);
	assert(slope(Point(0, -10),Point(0, 0)) == Fixed::FIXED_MAX);
}

void test_inside()
{	
	assert(
		   inside(
				  Point(0, 0),
				  Point(0, 10),
				  Point(10, 0),
				  Point(1, 1)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(0, 10),
				  Point(1, 1)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(0, 10),
				  Point(10, 0),
				  Point(-1, -1)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(0, 10),
				  Point(-1, -1)) == true);

	assert(
		   inside(
				  Point(0, 0),
				  Point(0, 10),
				  Point(10, 0),
				  Point(1, -1)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(0, 10),
				  Point(1, -1)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(0, 10),
				  Point(10, 0),
				  Point(-1, 1)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(0, 10),
				  Point(-1, 1)) == false);


	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 10),
				  Point(10, 0),
				  Point(10, 5)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(10, 10),
				  Point(10, 5)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 10),
				  Point(10, 0),
				  Point(-10, -5)) == true);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(10, 10),
				  Point(-10, -5)) == true);

	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 10),
				  Point(10, 0),
				  Point(-10, 5)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(10, 10),
				  Point(-10, 5)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 10),
				  Point(10, 0),
				  Point(10, -5)) == false);
	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 0),
				  Point(10, 10),
				  Point(10, -5)) == false);

	assert(
		   inside(
				  Point(0, 0),
				  Point(10, 10),
				  Point(10, 0),
				  Point(10, 20)) == false);
}
