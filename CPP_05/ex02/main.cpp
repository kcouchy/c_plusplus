/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 12:38:09 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "---------------------------------" << std::endl;
	std::cout << "- constructor/<< overload tests -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	Bureaucrat	bob("Bob", 50);
	AForm		form_banana("Banana", 49, 50);


	std::cout << bob << std::endl;
	std::cout << form_banana << std::endl;

	std::cout << "-------------------" << std::endl;
	std::cout << "- try/catch tests -" << std::endl;
	std::cout << "-------------------" << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "- form out of range -" << std::endl;
	std::cout << "---------------------" << std::endl;
	try
	{
		AForm	too_high("too_high", 0, 50);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		AForm	too_high("too_high", 50, 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		AForm	too_low("too_low", 151, 50);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		AForm	too_low("too_low", 50, 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "- beSigned tests    -" << std::endl;
	std::cout << "---------------------" << std::endl;

	std::cout << bob << std::endl;
	std::cout << form_banana << std::endl;

	try
	{
		form_banana.beSigned(bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << form_banana << std::endl;
	bob.incrementGrade();

	try
	{
		form_banana.beSigned(bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << form_banana << std::endl;

	try
	{
		form_banana.beSigned(bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "- signForm tests    -" << std::endl;
	std::cout << "---------------------" << std::endl;

	AForm	form_bananas("Bananas", 48, 48);
	try
	{
		bob.signForm(form_bananas);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << form_bananas << std::endl;
	bob.incrementGrade();
	bob.signForm(form_bananas);
	std::cout << form_bananas << std::endl;
	bob.signForm(form_bananas);

	std::cout << "------------------------" << std::endl;
	
	return (0);
}