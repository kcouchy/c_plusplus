/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:41 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 10:54:58 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<unsigned int>	PmergeMe::vectorFordJohnson(void)
{
	vectorPair					pairs;
	int							lastElement = (this->vec.size() % 2 == 0) ? -1 : *(this->vec.end() - 1);
	std::vector<unsigned int>	insertOrder;

	this->vectorFillPairs(pairs);

	this->vectorMergePairs(pairs);

	insertOrder = this->vectorDefineInsertOrder(pairs.size(), lastElement);
	this->vectorInsertElements(pairs, lastElement, insertOrder);

	return (this->vec);
}

void	PmergeMe::vectorFillPairs(vectorPair &pairs)
{
	for (unsigned int i = 0; i < this->vec.size() - 1; i += 2)
	{
		if (this->vec[i] > this->vec[i + 1])
			pairs.push_back(std::make_pair(this->vec[i], this->vec[i + 1]));
		else
			pairs.push_back(std::make_pair(this->vec[i + 1], this->vec[i]));
	}

	this->vec.clear();
}

static void	merge(std::vector<unsigned int> &mainChain, unsigned int start, unsigned int middle, unsigned int end)
{
	std::vector<unsigned int>	left(mainChain.begin() + start, mainChain.begin() + middle + 1);
	std::vector<unsigned int>	right(mainChain.begin() + middle + 1, mainChain.begin() + end + 1);

	unsigned int	i = 0;
	unsigned int	j = 0;
	unsigned int	k = start;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			mainChain[k++] = left[i++];
		else
			mainChain[k++] = right[j++];
	}

	while (i < left.size())
		mainChain[k++] = left[i++];
	
	while (j < right.size())
		mainChain[k++] = right[j++];
}

static void	mergeSort(std::vector<unsigned int> &mainChain, unsigned int start, unsigned int end)
{
	if (start >= end)
		return ;
	unsigned int middle = start + (end - start) / 2;
	mergeSort(mainChain, start, middle);
	mergeSort(mainChain, middle + 1, end);
	merge(mainChain, start, middle, end);
}

void	PmergeMe::vectorMergePairs(vectorPair &pairs)
{
	std::vector<unsigned int>	mainChain;

	for (unsigned int i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);

	mergeSort(mainChain, 0, mainChain.size() - 1);

	vectorPair	tmp;

	for (unsigned int i = 0; i < mainChain.size(); i++)
	{
		unsigned int	j = 0;

		while (pairs[j].first != mainChain[i] && j < pairs.size())
			j++;
		if (pairs[j].first == mainChain[i])
			tmp.push_back(pairs[j]);
	}

	pairs = tmp;
}

std::vector<unsigned int>	PmergeMe::vectorDefineInsertOrder(unsigned int numberOfPairs, int lastElement)
{
	std::vector<unsigned int>	groupSizes;
	unsigned long long			currentSizesSum;
	unsigned int				powerOfTwo;

	groupSizes.push_back(2);
	currentSizesSum = 2;
	powerOfTwo = 2;

	while (currentSizesSum <= numberOfPairs)
	{
		powerOfTwo *= 2;
		groupSizes.push_back(powerOfTwo - *(groupSizes.end() - 1));
		currentSizesSum += *(groupSizes.end() - 1);
	}
	if (lastElement != -1)
		numberOfPairs++;
	if (lastElement != -1 && currentSizesSum == numberOfPairs)
		groupSizes.push_back(1);

	std::vector<unsigned int>	indexOrder;
	unsigned int				numberOfElementsLeftInGroup = groupSizes[0];
	int				largestIndexInGroup = 0;
	int				vectorSize = 0;
	unsigned int				j = 0;

	indexOrder.push_back(0);

	for (unsigned int i = 0; i + 1 < numberOfPairs; i++)
	{
		if (numberOfElementsLeftInGroup == 1)
		{
			j++;
			numberOfElementsLeftInGroup = groupSizes[j];
		}

		vectorSize = indexOrder.size() - 1;
		largestIndexInGroup = groupSizes[j] + vectorSize;
		if (largestIndexInGroup >= (int)numberOfPairs)
			largestIndexInGroup = (int)numberOfPairs - 1;

		while (largestIndexInGroup - vectorSize > 0)
		{
			indexOrder.push_back(largestIndexInGroup);
			largestIndexInGroup--;
		}

		numberOfElementsLeftInGroup--;
	}

	return (indexOrder);
}

unsigned int	PmergeMe::vectorBinarySearch(unsigned int value, unsigned int start, unsigned int end)
{
	if (end <= start)
		return start;

	unsigned int	mid = (start + end) / 2;

	if (value < this->vec[mid])
		return (vectorBinarySearch(value, start, mid));
	else if (value > this->vec[mid])
		return (vectorBinarySearch(value, mid + 1, end));
	return (mid);
}

void	PmergeMe::vectorInsertElements(vectorPair &pairs, int lastElement, std::vector<unsigned int> insertOrder)
{
	for (unsigned int i = 0; i < pairs.size(); i++)
		this->vec.push_back(pairs[i].first);

	std::vector<unsigned int>	bees;
	for (unsigned int i = 0; i < pairs.size(); i++)
		bees.push_back(pairs[i].second);
	if (lastElement != -1)
		bees.push_back(lastElement);

	for (unsigned int i = 0; i < insertOrder.size(); i++)
	{
		unsigned int	index = vectorBinarySearch(bees[insertOrder[i]], 0, vec.size());
		this->vec.insert(this->vec.begin() + index, bees[insertOrder[i]]);
	}
}
