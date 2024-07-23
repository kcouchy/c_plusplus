/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:40:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/23 11:27:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Intern::Intern (void)
{
	std::cout << "Intern constructor called: faceless intern is hired" << std::endl;
	return ;
}

Intern::Intern (Intern const &original)
{
	std::cout << "Intern copy constructor called " << std::endl;
	*this = original;
	return ;
}

Intern::~Intern (void)
{
	std::cout << "Intern destructor called: faceless intern is fired" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

Intern &Intern::operator=(Intern const &original)
{
	(void)original;
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

typedef struct {
	std::string	name;
	AForm*		(*function)(const std::string &);
} t_form;

AForm*	Intern::createShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	t_form	forms[] = 
	{
		{"ShrubberyCreationForm", createShrubberyCreationForm},
		{"RobotomyRequestForm", createRobotomyRequestForm},
		{"PresidentialPardonForm", createPresidentialPardonForm}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (forms[i].name == form_name)
		{
			std::cout << "Intern creates a new " << form_name << std::endl;
			return (forms[i].function(target));
		}
	}
	std::cout << "Intern cannot create invalid form type: " << form_name << std::endl;
	return (NULL);
}