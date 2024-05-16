/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:35:47 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 16:52:50 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap banana;
	ClapTrap banana2("banana");
	std::cout << "---------------" << std::endl;
	ScavTrap smoothie("smoothie");
	std::cout << "---------------" << std::endl;
	ScavTrap smoothie2 = smoothie;
	std::cout << "---------------" << std::endl;
	FragTrap milkshake("milkshake");

	milkshake.showStats();

	std::cout << "---------------" << std::endl;
	banana2.beRepaired(5);
	banana2.attack("smoothie");

	std::cout << "---------------" << std::endl;
	for (int i = 0; i < 49; i++)
		smoothie.attack("banana");
	smoothie.beRepaired(100);
	smoothie.attack("banana");
	smoothie.beRepaired(50);

	std::cout << "---------------" << std::endl;
	milkshake.highFivesGuys();
	milkshake.attack("banana");

	return (0);
}
