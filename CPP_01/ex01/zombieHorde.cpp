/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:51:45 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 16:30:03 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*horde;
	int		i;

	horde = new Zombie[N];
	for (i = 0; i < N; i++)
		horde[i].setName( name );
	return (horde);
}
