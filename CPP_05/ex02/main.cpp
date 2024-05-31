/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 15:34:14 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "---------------------------------" << std::endl;
	std::cout << "- constructor/<< overload tests -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	Bureaucrat	bob("Bob", 50);
	// AForm		aform("Nope", 49, 50);


	std::cout << bob << std::endl;

	std::cout << "-------------------" << std::endl;
	std::cout << "- try/catch tests -" << std::endl;
	std::cout << "-------------------" << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "- form out of range -" << std::endl;
	std::cout << "---------------------" << std::endl;
	// try
	// {
	// 	AForm	too_high("too_high", 0, 50);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	std::cout << "---------------------" << std::endl;
	std::cout << "- beSigned tests    -" << std::endl;
	std::cout << "---------------------" << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "- signForm tests    -" << std::endl;
	std::cout << "---------------------" << std::endl;

	std::cout << "------------------------" << std::endl;
	
	return (0);
}