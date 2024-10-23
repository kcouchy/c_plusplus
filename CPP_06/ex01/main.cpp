/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:32:25 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/26 14:58:24 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data _data;
	
	_data.a = 50;
	_data.b = INT_MAX + 10;

	std::cout << "base data" << std::endl;
	std::cout << "_data: " << _data.a << " | " << _data.b << std::endl;
	std::cout << std::endl;
	Serializer::deserialize(Serializer::serialize(&_data));
	std::cout << "post-serialize/deserialize" << std::endl;
	std::cout << "_data: " << _data.a << " | " << _data.b << std::endl;
	return (0);
}