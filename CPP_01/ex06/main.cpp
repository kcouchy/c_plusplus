/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:22:44 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 15:14:30 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "harlFilter: wrong number of arguments" << std::endl;
		std::cout << "try: ./harlFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}