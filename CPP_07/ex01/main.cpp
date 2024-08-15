/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:39:24 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 14:02:26 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>


int	main(void)
{
	size_t	array_i[] = {0,1,2,3,4,5,6,7,8,9};
	std::string	array_s[] = {"this", "is", "a", "string", "array"};

	iter(array_i, 10, _print);
	iter(array_i, 10, _double);
	iter(array_i, 10, _print);

	iter(array_s, 5, _print);
	iter(array_s, 5, _double);
	iter(array_s, 5, _print);
	return (0);
}
