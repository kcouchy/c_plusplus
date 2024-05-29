/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/29 17:59:14 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "- constructor increment and decrement tests -" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	Bureaucrat custom0("Custom0", 50);

	std::cout << custom0 << std::endl;
	
	custom0.incrementGrade();
	custom0.decrementGrade();

	std::cout << "-------------------" << std::endl;
	std::cout << "- try/catch tests -" << std::endl;
	std::cout << "-------------------" << std::endl;
	
	try
	{
		Bureaucrat custom2("Custom2", Bureaucrat::grade_max - 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat custom3("Custom3", Bureaucrat::grade_min + 1);
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat custom1("Custom1", Bureaucrat::grade_max);
	try
	{
		custom1.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	
	return (0);
}