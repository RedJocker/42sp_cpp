// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RPN.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/07/22 19:25:57 by maurodri          #+#    #+#             //
//   Updated: 2025/07/22 22:31:56 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RPN.hpp"
#include <cstring>
#include <stack>
#include <stdexcept>
#include <sstream>

RPN::RPN()
{
	
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return *this;
	return *this;
}

RPN::~RPN()
{
	
}

bool isValidOperator(char *maybeOperator)
{
	size_t len = std::strlen(maybeOperator);
	if (len != 1)
		return false;
	switch (maybeOperator[0])
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}


bool isValidOperand(char *mayberOperand)
{

	for (char *ptr = mayberOperand; *ptr != '\0'; ptr++)
	{
		if (!std::isdigit(*ptr))
			return false;
	}
	return true;
}

bool isValidMember(char *operationMember)
{
	return isValidOperator(operationMember)
	    || isValidOperand(operationMember);
}

int makeOperation(char operatorr, int operand1, int operand2)
{
	switch (operatorr)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	}
	throw std::invalid_argument("unexpected operatorr at makeOperation");
}

std::pair<int, std::string> RPN::calculate(char **operation)
{
	std::stack<int> operands;
	for (char **ptr = operation; *ptr != NULL; ptr++)
	{
		if (isValidOperator(*ptr))
		{
			if (operands.size() < 2)
				return std::make_pair(22, "Error");
			int operand2 = operands.top();
			operands.pop();
			int operand1 = operands.top();
			operands.pop();
			char operatorr = (*ptr)[0];
			int result = makeOperation(operatorr, operand1, operand2);
			operands.push(result);
		}
		else if (isValidOperand(*ptr))
		{
			std::istringstream iss(*ptr);
			int operand;
			iss >> operand;
			if (iss.fail() || !iss.eof())
				return std::make_pair(22, "Error");
			operands.push(operand);
		} 
		else
			return std::make_pair(22, "Error");
	}
	if (operands.size() != 1)
		return std::make_pair(22, "Error");
	int finalResult = operands.top();

	std::ostringstream strRes;
	strRes << finalResult;
	return std::make_pair(0, strRes.str());
}

