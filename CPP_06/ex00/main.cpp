/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:32:25 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/24 15:57:46 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout
			<< "Invalid input, try: ./convert <literal>" << std::endl
			<< "literal = char/int/float/double/nan/inf"
			<< std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}