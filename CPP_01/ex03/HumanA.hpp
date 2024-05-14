/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:37:29 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/06 10:37:30 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:

		HumanA( const std::string &name, Weapon &weapon );
		~HumanA( void );

		void	attack( void );

	private:

		std::string	m_name;
		Weapon		&m_weapon;
	
};

#endif