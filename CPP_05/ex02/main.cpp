/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/23 14:04:58 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int	main(void)
{
	std::cout << "---------------------------------" << std::endl;
	std::cout << "- constructor/<< overload tests -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	Bureaucrat	bob("Bob", 40);
	Bureaucrat	fred("Fred", 150);
	Bureaucrat	kiri("Kiri", 1);
	ShrubberyCreationForm	shrub("Shrub");
	RobotomyRequestForm		robo("Robo");
	PresidentialPardonForm	pres("Pres");

	std::cout << std::endl;
	std::cout << bob << std::endl;
	std::cout << fred << std::endl;
	std::cout << kiri << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robo << std::endl;
	std::cout << pres << std::endl;

	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "- signForm/beSigned tests -" << std::endl;
	std::cout << "---------------------------" << std::endl;

	fred.signForm(shrub);
	fred.signForm(robo);
	bob.signForm(pres);

	try
	{
		shrub.beSigned(fred);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "- execute/executeForm tests -" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	fred.executeForm(shrub);
	shrub.execute(fred);

	bob.executeForm(robo);
	robo.execute(bob);

	shrub.beSigned(bob);
	std::cout << shrub << std::endl;

	robo.beSigned(bob);
	std::cout << robo << std::endl;

	pres.beSigned(kiri);
	std::cout << pres << std::endl;

	bob.executeForm(pres);

	std::cout << bob << std::endl;
	shrub.execute(bob);
	shrub.execute(bob);

	std::cout << std::endl;
	robo.execute(bob);
	usleep(1500000);
	robo.execute(bob);

	std::cout << std::endl;
	pres.execute(kiri);
	kiri.executeForm(pres);

	std::cout << std::endl;
	try
	{
		shrub.execute(fred);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		robo.execute(fred);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		pres.execute(fred);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	fred.executeForm(shrub);
	fred.executeForm(robo);
	fred.executeForm(pres);


	std::cout << "------------------------" << std::endl;
	
	return (0);
}