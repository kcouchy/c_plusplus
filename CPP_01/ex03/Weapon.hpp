/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:10:23 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/03 15:46:48 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:

		Weapon( const std::string &type );
		~Weapon( void );

		const std::string	&getType() const;
		void				setType( const std::string &type );
	
	private:

		std::string			m_type;

};

#endif