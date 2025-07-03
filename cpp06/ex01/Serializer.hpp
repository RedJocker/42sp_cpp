// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Serializer.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/01 19:17:38 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 01:58:52 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

// Chapter V
// Exercise 01: Serialization
// Exercise : 01
// Serialization
// Turn-in directory: ex01/
// Files to turn in: Makefile, *.cpp, *.{h, hpp}
// Forbidden functions: None
// Implement a class Serializer, which will not be initializable by the user in any way,
// with the following static methods:
// uintptr_t serialize(Data* ptr);
// It takes a pointer and converts it to the unsigned integer type uintptr_t.
// Data* deserialize(uintptr_t raw);
// It takes an unsigned integer parameter and converts it to a pointer to Data.
// Write a program to test that your class works as expected.
// You must create a non-empty (meaning it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure.

# include "Data.hpp"

class Serializer
{
	Serializer();
	Serializer(const Serializer &other);
	virtual Serializer &operator=(const Serializer &other);
	virtual ~Serializer();

public:

	static uintptr_t serialize(Data* ptr);
	static 	Data* deserialize(uintptr_t raw);
};


#endif
