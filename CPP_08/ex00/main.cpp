/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:20:32 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/15 13:21:26 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int	main(void)
{
	int					to_find = -1;
	std::vector<int>	container_v;
	std::deque<int>		container_d;
	std::list<int>		container_l;

	for (int i = 5; i < 30; i++)
	{
		container_v.push_back(i);
		container_d.push_back(i);
		container_l.push_back(i);
	}

	int	pos_v = easyfind(container_v, to_find) - container_v.begin();
	std::cout << to_find << " is at index: " << pos_v << std::endl;
	std::cout << "searching vector for: " << to_find << "\t found: " << ((easyfind(container_v, to_find)) == container_v.end() ? "no" : "yes") << std::endl;
	std::cout << "searching deque for: " << to_find << "\t found: " << ((easyfind(container_d, to_find)) == container_d.end() ? "no" : "yes") << std::endl;
	std::cout << "searching list for: " << to_find << "\t found: " << ((easyfind(container_l, to_find)) == container_l.end() ? "no" : "yes") << std::endl;

	return (0);
}