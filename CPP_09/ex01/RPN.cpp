/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:41:24 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 12:19:26 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(RPN const &o)
{
    *this = o;
}

RPN::~RPN()
{}

RPN	&RPN::operator=(RPN const &o)
{
    if (this == &o)
        return (*this);
    m_stack = o.m_stack;
    return (*this);
}
		
long long RPN::calculate(std::string const &input)
{
    std::string symbols = "+/*-";

    if (input.empty() || input.find_first_not_of("0123456789 +-/*") != input.npos)
        throw std::logic_error("Invalid input argument, use only: \"0123456789 +/*-\"");
    
    for (int i = 0; input[i]; i++)
	{
        //if number, add to stack
		if (isdigit(input[i]))
			this->m_stack.push(input[i] - '0');

        //if symbol, perform operation on stack (that must have at least two numbers in it)
		else if (symbols.find(input[i]) != symbols.npos)
		{
			if (this->m_stack.size() < 2)
				throw std::logic_error("Incorrect syntax: missing number");

            //store numbers in local variables then pop them off the stack
			long long result = 0;
			long long b = this->m_stack.top();
			this->m_stack.pop();
			long long a = this->m_stack.top();
			this->m_stack.pop();

			switch (input[i])
            {
				case '+':
				{
					result = a + b;
					break;
				}
				case '-':
				{
					result = a - b;
					break;
				}
				case '*':
				{
					result = a * b;
					break;
				}
				case '/':
				{
					if (b == 0)
						throw std::logic_error("Illegal operation: division by zero");
					result = a / b;
					break;
				}
			}
            //push the result back onto the stack
			this->m_stack.push(result);
		}
	}
	//this is if there is more than one number in the stack at the end - means that there's an operator missing
	if (this->m_stack.size() != 1)
		throw std::logic_error("Incorrect syntax: missing operator");
	return (this->m_stack.top());
}