/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:06:40 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 10:55:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 3)
		throw (std::runtime_error("Not enough arguments"));

	this->fillContainers(argv);
}

PmergeMe::PmergeMe(const PmergeMe &toCopy):
	vecBefore(toCopy.vecBefore),
	vec(toCopy.vec),
	deq(toCopy.deq)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &toCopy)
{
	this->vecBefore = toCopy.vecBefore;
	this->vec = toCopy.vec;
	this->deq = toCopy.deq;
	return (*this);
}

std::vector<unsigned int>	PmergeMe::getVecBefore(void) const
{
	return (this->vecBefore);
}

void	PmergeMe::fillContainers(char **argv)
{
	char	*endPtr;

	for (int i = 1; argv[i]; i++)
	{
		std::string input_arg = argv[i];
		if (input_arg.find_first_not_of("0123456789") != input_arg.npos)
			throw std::logic_error("Invalid input argument: forbidden characters (\"0123456789\" only)");

		long	value = strtol(argv[i], &endPtr, 10);

		if (endPtr == argv[i] or *endPtr != '\0')
			throw (std::logic_error("Invalid input argument: not a valid number"));

		if (value > INT_MAX || value < 0)
			throw (std::logic_error("Invalid input argument: positive integers only"));

		if (std::find(this->vec.begin(), this->vec.end(), static_cast<unsigned int>(value)) != this->vec.end())
			throw (std::logic_error("Invalid input argument: duplicate found"));

		this->vecBefore.push_back(value);
		this->vec.push_back(value);
		this->deq.push_back(value);
	}
}
