/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:35:47 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 16:56:52 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(void)
{
	ScavTrap banana("banana");
	ScavTrap smoothie("smoothie");
	ScavTrap smoothie2;
	std::cout << "---------------" << std::endl;
	
	smoothie2 = smoothie;
	smoothie2.showStats();

	std::cout << "---------------" << std::endl;
	smoothie.guardGate();

	for (int i = 0; i < 49; i++)
	{
		smoothie.attack("banana");
	}
	smoothie.beRepaired(100);
	smoothie.attack("banana");

	std::cout << "---------------" << std::endl;
	banana.beRepaired(5);
	banana.takeDamage(100);
	banana.takeDamage(10);
	banana.guardGate();
	banana.beRepaired(5);
	banana.takeDamage(10);

	return (0);
}

