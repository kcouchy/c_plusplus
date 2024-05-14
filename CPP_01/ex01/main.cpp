/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:19 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 16:44:05 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define HORDE_SIZE	20
#define NAME		"Zombie Banana!"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	int	N = HORDE_SIZE;
	std::string name = NAME;
	Zombie *horde;
	int	i;

	horde = zombieHorde( N, name );
	for (i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}