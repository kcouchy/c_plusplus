/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:39:10 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/15 10:41:16 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>

int	main(void)
{
//test Span addNumber
	std::cout << "1. test Span addNumber" << std::endl;
	Span	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

//test Span addNumbers
	std::cout << "2. test Span addNumbers" << std::endl;
	try
	{
		Span	sp2 = Span(5);
		int		numbers_arr[] = {6,3,17,9,11};
		std::vector<int> numbers_v(numbers_arr, numbers_arr + sizeof(numbers_arr) / sizeof (numbers_arr[0]));
		sp2.addNumbers(numbers_v.begin(), numbers_v.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

//not enough elements in Span
	std::cout << "3. test not enough elements in Span" << std::endl;
	try
	{
		Span	sp2 = Span();
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

//span capacity insufficient
	std::cout << "4. test addNumber span capacity insufficient" << std::endl;
	try
	{
		Span	sp2 = Span(1);
		sp2.addNumber(5);
		sp2.addNumber(10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "5. test addNumbers span capacity insufficient" << std::endl;
	try
	{
		Span	sp2 = Span(5);
		int		numbers_arr[] = {6,3,17,9,11,13,15};
		std::vector<int> numbers_v(numbers_arr, numbers_arr + sizeof(numbers_arr) / sizeof (numbers_arr[0]));
		sp2.addNumbers(numbers_v.begin(), numbers_v.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

//maaaaaaaaany numbers
	std::cout << "5. test with biiiiiiiiig vector" << std::endl;
	#define BIG_NUMBERS 100000
	std::srand(unsigned(std::time(NULL)));
	try
	{
		Span	sp2 = Span(BIG_NUMBERS);
		std::vector<int> numbers_v(BIG_NUMBERS);
		std::generate(numbers_v.begin(), numbers_v.end(), std::rand);

		sp2.addNumbers(numbers_v.begin(), numbers_v.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}