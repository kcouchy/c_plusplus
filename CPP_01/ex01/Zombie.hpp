/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:11:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 16:14:38 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:

		Zombie( void );
		~Zombie( void );

		void	announce( void );
		void	setName ( std::string new_name );

	private:

		std::string	name;

};

#endif