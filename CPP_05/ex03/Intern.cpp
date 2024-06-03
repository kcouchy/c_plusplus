/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:40:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 18:32:48 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Intern::Intern (void)
{
	return ;
}

Intern::Intern (Intern const &original)
{
	*this = original;
	return ;
}

Intern::~Intern (void)
{
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
		if (forms[i].name == form_name)
			return (forms[i].function(target));
	return (NULL);
}