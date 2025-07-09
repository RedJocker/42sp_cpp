// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/09 02:59:10 by maurodri          #+#    #+#             //
//   Updated: 2025/07/09 02:59:32 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// A first easy exercise is the way to start off on the right foot.
// Write a function template easyfind that accepts a type T. It takes two parameters:
// the first one is of type T, and the second one is an integer.
// Assuming T is a container of integers, this function has to find the first occurrence
// of the second parameter in the first parameter.
// If no occurrence is found, you can either throw an exception or return an error value
// of your choice. If you need some inspiration, analyze how standard containers behave.
// Of course, implement and turn in your own tests to ensure everything works as ex-
// pected.

template<typename IntContainer>
typename IntContainer::iterator easyFind(IntContainer &haystack, int needle)
{
	for(typename IntContainer::iterator i = haystack.begin();
		i != haystack.end();
		i++
    ) {
		if (*i == needle) {
			return i;
		}
	}
	return haystack.end();
}
