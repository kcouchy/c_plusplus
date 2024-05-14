/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:49:33 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/06 10:38:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( const std::string &name, Weapon &weapon ) :
	m_name(name), m_weapon(weapon)
{
	return;
}

HumanA::~HumanA( void )
{
	return;
}

void	HumanA::attack( void )
{
	std::cout
		<< m_name
		<< " attacks with their "
		<< m_weapon.getType() << std::endl;
}