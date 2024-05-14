/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:37:29 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/06 10:56:36 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:

		HumanB( const std::string &name );
		HumanB( const std::string &name, Weapon &weapon);
		~HumanB( void );

		void	attack( void );
		void	setWeapon( Weapon &weapon );

	private:

		std::string	m_name;
		Weapon		*m_weapon;

};

#endif