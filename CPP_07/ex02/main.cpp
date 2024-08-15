/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:11:37 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 18:46:49 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
void	print_array(std::string message, Array<T> &array)
{
	std::cout << message << std::endl;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << "index = " << i << ": " << array[i] << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	try
	{
		// Array<std::string> feck(4294967295);
	}
	catch(const std::bad_alloc&)
	{
		std::cout << "Fatal error: memory allocation fail" << std::endl;
		return(1);
	}
	try
	{
		Array<int> numbers(500);
		Array<int> _default;
		numbers[501];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Array<std::string> strings(3);
	Array<std::string> empty;
	strings[0] = "hi";
	strings[1] = "there";
	strings[2] = "cowboy";
	print_array("print strings", strings);
	print_array("print empty", empty);
	empty = strings;
	empty[2] = "princess";
	print_array("print empty once copied", empty);
}