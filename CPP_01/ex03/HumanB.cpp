/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:09:12 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:35 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( const std::string &name ) :
	m_name(name), m_weapon(NULL)
{
	return;
}

HumanB::HumanB( const std::string &name, Weapon &weapon) :
	m_name(name), m_weapon(&weapon)
{
	return ;
}
HumanB::~HumanB( void )
{
	return;
}

void	HumanB::attack( void )
{
	if (m_weapon)
	{
		std::cout
			<< m_name
			<< " attacks with their "
			<< m_weapon->getType() << std::endl;
	}
	else
	{
		std::cout
			<< m_name
			<< " attacks with their teeth" << std::endl;
	}
	return ;
}
void	HumanB::setWeapon( Weapon &weapon )
{
	m_weapon = &weapon;
	return;
}