/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:12:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:16 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout
		<< name
		<< " Deaded"
		<< std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout 
		<< name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}

void	Zombie::setName( std::string new_name )
{
	name = new_name;
	return ;
}