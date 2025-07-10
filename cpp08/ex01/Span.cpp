// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/09 23:15:59 by maurodri          #+#    #+#             //
//   Updated: 2025/07/10 00:16:07 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Span.hpp"
#include <cstdlib>

Span::Span()
	: numbers(std::multiset<int>()), spanCapacity(10)
{
}
Span::Span(unsigned int capacity)
	: numbers(std::multiset<int>()), spanCapacity(capacity)
{
}

Span::Span(const Span &other)
	: numbers(std::multiset<int>(other.numbers)), spanCapacity(other.spanCapacity)
{
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	this->spanCapacity = other.spanCapacity;
	this->numbers = std::multiset<int>(other.numbers);
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (this->numbers.size() == this->spanCapacity)
		throw SpanException("Span is full, cannot addNumber");
	this->numbers.insert(number);
}

unsigned int Span::shortestSpan()
{
	if (this->numbers.size() < 2)
		throw SpanException(
				"Not Enough elements on span to retrieve shortestSpan");
	std::multiset<int>::const_iterator forward = ++this->numbers.cbegin();
	std::multiset<int>::const_iterator backward = this->numbers.cbegin();
	int minSpan = abs(*forward - *backward);
	for (; forward != this->numbers.cend(); forward++, backward++)
	{
		int currentSpan = abs(*forward - *backward);
		if (currentSpan < minSpan)
		{
			minSpan = currentSpan;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (this->numbers.size() < 2)
		throw SpanException(
				"Not Enough elements on span to retrieve longestSpan");
	return *this->numbers.crbegin() - *this->numbers.cbegin();
}


Span::SpanException::SpanException(std::string msg) : msg(msg)
{

}

Span::SpanException::SpanException() : msg("Invalid Span operation")
{

}

Span::SpanException::~SpanException() _NOEXCEPT
{		
}

const char * Span::SpanException::what() const throw()
{
	return this->msg.c_str();
}

