/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:33:31 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 16:08:33 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string	Harl::levelTable[4] =
{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
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

	while (i < 4 && level.compare(levelTable[i]) != 0)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			Harl::debug();
			std::cout << std::endl;
		case 1:
			std::cout << "[INFO]" << std::endl;
			Harl::info();
			std::cout << std::endl;
		case 2:
			std::cout << "[WARNING]" << std::endl;
			Harl::warning();
			std::cout << std::endl;
		case 3:
			std::cout << "[ERROR]" << std::endl;
			Harl::error();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "harlFilter: invalid input argument" << std::endl;
			std::cout << "try: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
	}
	return ;
}
