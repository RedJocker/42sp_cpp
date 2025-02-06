// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bsp.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/05 01:49:13 by maurodri          #+#    #+#             //
//   Updated: 2025/02/05 22:19:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

/**
 * returns dy/dx,
 * with dy == b.y - a.y
 * and dx == b.x - a.x
 * if dx == 0 returns FIXED_MAX
 */
Fixed slope(Point const &a, Point const &b)
{
	const Fixed denom = b.X() - a.X();
	
	if (denom == Fixed(0))
	{
		return a.Y() >= b.Y() ? Fixed::FIXED_MIN : Fixed::FIXED_MAX;
	}
		

	const Fixed numer = b.Y() - a.Y();
	return numer / denom;
}


/**
 * taking the straight lines oa, ob and op inside(o, a, b, p)
 * returns true if op is between oa and ob, considering also their prolongations
 * (excluding points on the lines oa and ob)
 * if ob slope is greater than oa it returns value equivalent to inside(o, b, a, p)
 * if ob slope is equal to oa than always returns false
 * 
 *                 
 *                    a
 *                   /
 *             f    /  t
 *                 /
 *           -----o-----f--b
 *            t  /   f
 *              /
 *             f
 *            /
 *
 *  the "quadrants" condired t and f depend on relative position of o, a and b
 *            a
 *             \
 *            t \   f
 *               \
 *           b----o-----f---
 *            f    \   
 *                  \  t
 *                   \
 *            
 *
 */
int inside(Point const &o, Point const &a, Point const &b, Point const &p)
{
	const Fixed slope_oa = slope(o, a);
	const Fixed slope_ob = slope(o, b);
	const Fixed slope_op = slope(o, p);

	if (slope_oa == slope_ob)
		return 0;
	else if (slope_oa > slope_ob)
		return slope_oa > slope_op && slope_op > slope_ob;
	else 
		return slope_ob > slope_op && slope_op > slope_oa;
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Fixed &min_x = Fixed::min(a.X(), Fixed::min(b.X(), c.X()));
	const Fixed &max_x = Fixed::max(a.X(), Fixed::max(b.X(), c.X()));
	if (a.X() == min_x && b.X() == min_x && c.X() == min_x)
		return false;
	else if (a.X() != min_x)
	{
		return b.X() == min_x ? bsp(b, a, c, point) : bsp(c, b, a, point);
	}
	else if (c.X() != max_x)
	{
		return b.X() == max_x ? bsp(a, c, b, point) : bsp(c, b, a, point);
	}
	
	int inside_a = inside(a, b, c, point);
	int inside_c = inside(c, a, b, point);
	return inside_a && inside_c;
}
