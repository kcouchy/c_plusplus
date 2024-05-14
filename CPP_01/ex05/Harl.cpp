/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:33:31 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 14:40:34 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const Harl::t_func	Harl::functionTable[4] =
{
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error,
};

const std::string	Harl::levelTable[4] =
{
	"debug",
	"info",
	"warning",
	"error"
};

void	Harl::debug( void )
{
	std::cout << "Debug level message" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "Info level message" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "Warning level message" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "Error level message" << std::endl;
}

void	Harl::complain( std::string level )
{
	int	i = 0;

	while (i <= 3 && level.compare(levelTable[i]) != 0)
		i++;
	(this->*Harl::functionTable[i])();
	return ;
}

const std::string	Harl::getLevel( int i )
{
	return (levelTable[i]);
}