/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:06:50 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 10:55:54 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <algorithm>

typedef std::vector< std::pair<unsigned int, unsigned int> > vectorPair;
typedef std::deque< std::pair<unsigned int, unsigned int> > dequePair;

class	PmergeMe
{
	public:
									PmergeMe(int argc = 0, char **argv = NULL);
									PmergeMe(const PmergeMe &toCopy);
									~PmergeMe();
		PmergeMe					&operator=(const PmergeMe &toCopy);

		std::vector<unsigned int>	vectorFordJohnson(void);
		std::deque<unsigned int>	dequeFordJohnson(void);

		std::vector<unsigned int>	getVecBefore(void) const;

	private:
		std::vector<unsigned int>	vecBefore;
		std::vector<unsigned int>	vec;
		std::deque<unsigned int>	deq;

		void						fillContainers(char **argv);

		void						vectorFillPairs(vectorPair &pairs);
		void						vectorMergePairs(vectorPair &pairs);
		std::vector<unsigned int>	vectorDefineInsertOrder(unsigned int numberOfPairs, int lastElement);
		unsigned int				vectorBinarySearch(unsigned int value, unsigned int start, unsigned int end);
		void						vectorInsertElements(vectorPair &pairs, int lastElement, std::vector<unsigned int> insertOrder);

		void						dequeFillPairs(dequePair &pairs);
		void						dequeMergePairs(dequePair &pairs);
		std::deque<unsigned int>	dequeDefineInsertOrder(unsigned int numberOfPairs, int lastElement);
		unsigned int				dequeBinarySearch(unsigned int value, unsigned int start, unsigned int end);
		void						dequeInsertElements(dequePair &pairs, int lastElement, std::deque<unsigned int> insertOrder);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c)
{
	typename std::vector<T>::const_iterator	it;
	for (it = c.begin(); it != c.end(); it++)
		os << *it << " ";
	return (os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& c)
{
	typename std::deque<T>::const_iterator	it;
	for (it = c.begin(); it != c.end(); it++)
		os << *it << " ";
	return (os);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T>& c)
{
	os << c.first << "-";
	os << c.second;
	return (os);
}