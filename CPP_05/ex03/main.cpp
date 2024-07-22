/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:41:34 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 18:27:20 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "---------------------------------" << std::endl;
	std::cout << "- constructor/<< overload tests -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	Bureaucrat	bob("Bob", 40);
	Bureaucrat	fred("Fred", 150);
	Bureaucrat	kiri("Kiri", 1);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	pres("pres");

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
	shrub.execute(bob);

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
	robo.execute(bob);
	robo.execute(bob);
	robo.execute(bob);
	robo.execute(bob);
	robo.execute(bob);
	robo.execute(bob);
	robo.execute(bob);

	std::cout << std::endl;
	pres.execute(kiri);

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

	Intern massias;
	
	AForm *fick = massias.makeForm("ShrubberyCreationForm", "banana");

	delete fick;
	std::cout << "------------------------" << std::endl;
	
	return (0);
}