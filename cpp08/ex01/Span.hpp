// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/09 23:03:07 by maurodri          #+#    #+#             //
//   Updated: 2025/07/10 00:54:42 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

// Develop a Span class that can store a maximum of N integers.
// N is an unsigned int variable and will be
// the only parameter passed to the constructor.
// This class will have a member function
// called addNumber() to add a single numbe to the Span.
// It will be used in order to fill it.
// Any attempt to add a new element if there are already N elements stored
// should throw an exception.
// Next, implement two member functions: shortestSpan() and longestSpan()
// They will respectively find out the shortest span or the longest span
// (or distance, if you prefer) between all the numbers stored, and return it.
// If there are no numbers stored, or only one, no span can be found.
// Thus, throw an exception. Of course, you will write your own tests,
// and they will be far more thorough than the ones below.
// Test your Span with at least 10,000 numbers. More would be even better
//
// Last but not least, it would be wonderful to fill your
// Span using a range of iterators.
// Making thousands of calls to addNumber() is so annoying.
// Implement a member function
// to add multiple numbers to your Span in a single call.

# include <set>
# include <string>

class Span
{
	std::multiset<int> numbers;
	unsigned int spanCapacity;

public:
	Span();
	Span(unsigned int capacity);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);

	template <typename IntForwardIterator>
	void addNumber(IntForwardIterator begin, IntForwardIterator endExclusive)
	{
		for (IntForwardIterator current = begin;
			 current != endExclusive;
			 current++)
		{
			addNumber(*current);
		}
	}
	
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class SpanException : public std::exception {
		std::string msg;	
	public:
		SpanException();
		SpanException(std::string msg);
		virtual const char *what() const throw();
		virtual ~SpanException() _NOEXCEPT;
	};
};

#endif
