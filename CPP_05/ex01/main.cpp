/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/30 14:26:45 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "---------------------" << std::endl;
	std::cout << "- constructor tests -" << std::endl;
	std::cout << "---------------------" << std::endl;

	Bureaucrat	custom0("Custom0", 50);
	Form		form0("Form0", 49, 50);

	std::cout << custom0 << std::endl;
	std::cout << form0 << std::endl;

	std::cout << "-------------------" << std::endl;
	std::cout << "- try/catch tests -" << std::endl;
	std::cout << "-------------------" << std::endl;

	try
	{
		form0.beSigned(custom0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	custom0.incrementGrade();

	//TODO print on success not working
	try
	{
		form0.beSigned(custom0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}


	// try
	// {
	// 	Bureaucrat custom2("Custom2", Bureaucrat::grade_max - 1);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat custom3("Custom3", Bureaucrat::grade_min + 1);
	// }
	// catch (Bureaucrat::GradeTooHighException & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// Bureaucrat custom1("Custom1", Bureaucrat::grade_max);
	// try
	// {
	// 	custom1.incrementGrade();
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	std::cout << "------------------------" << std::endl;
	
	return (0);
}