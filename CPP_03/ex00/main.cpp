/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:35:47 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 16:44:44 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap banana;
	ClapTrap banana2("banana");
	ClapTrap smoothie("smoothie");
	
	smoothie.showStats();
	std::cout << "---------------" << std::endl;
	banana2.attack("smoothie");
	banana2.beRepaired(5);

	std::cout << "---------------" << std::endl;
	for (int i = 0; i < 10; i++)
		smoothie.attack("banana");
	smoothie.beRepaired(100);
	smoothie.attack("banana");
	smoothie.takeDamage(100);
	smoothie.beRepaired(100);
	smoothie.attack("banana");
	smoothie.takeDamage(100);

	return (0);
}
