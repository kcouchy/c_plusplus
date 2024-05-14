/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:19 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/06 11:20:01 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon	club2 = Weapon("crude spiked club");

	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();

	return 0;
}