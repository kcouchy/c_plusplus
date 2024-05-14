/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:14:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/03 15:46:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( const std::string &type ) : m_type(type)
{
	return ;
}

Weapon::~Weapon ( void )
{
	return ;
}

const std::string	&Weapon::getType()const
{
	return (m_type);
}

void				Weapon::setType( const std::string &type )
{
	m_type = type;
	return ;
}
