// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   whatever.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/03 21:06:47 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 21:08:48 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> T min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T> T max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
}

#endif
