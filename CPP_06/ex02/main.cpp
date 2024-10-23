/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:09:57 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/26 16:10:54 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Base *rando1 = generate();
	Base *rando2 = generate();
	Base *rando3 = generate();

	identify(rando1);
	identify(rando2);
	identify(rando3);

	identify(*rando1);
	identify(*rando2);
	identify(*rando3);

	delete rando1;
	delete rando2;
	delete rando3;
	return (0);
}