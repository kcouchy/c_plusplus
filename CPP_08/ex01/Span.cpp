/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:06:10 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/14 17:39:33 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <ctime>

Span::Span(void) :
	m_max(0)
{}

Span::Span(unsigned int max) :
	m_max(max)
{}

Span::Span(Span const &original)
{
	*this = original;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &original)
{
	
	if (this == &original)
		return (*this);
	Span::vector::operator=(original);
	this->m_max = original.m_max;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->size() >= m_max)
		throw std::logic_error("Cannot add more numbers, Span capacity has been reached");
	this->push_back(number);
}

int		Span::shortestSpan(void)const
{
	int	span = longestSpan();
	std::vector<int>::const_iterator iter;
	std::vector<int> copy(*this);
	std::sort(copy.begin(), copy.end());

	for (iter = copy.begin() + 1; iter != copy.end(); iter++)
		if (*iter - *(iter - 1) < span)
			span = *iter - *(iter - 1);

	return (span);
}

int		Span::longestSpan(void)const
{
	if (this->size() < 2)
		throw std::logic_error("Span cannot be found, not enough values in Span");
	return (*(std::max_element(this->begin(), this->end()))
			- *(std::min_element(this->begin(), this->end())));
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->size() + (end - begin) > this->m_max)
		throw std::logic_error("Cannot add numbers, Span capacity is insufficient");
	this->insert(this->end(), begin, end);
}
