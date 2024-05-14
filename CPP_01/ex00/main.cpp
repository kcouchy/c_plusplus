/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:19 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 15:12:20 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie	*oldie(NULL);

	oldie = newZombie("oldie");
	oldie->announce();
	randomChump("newbie");
	delete oldie;
	return (0);
}