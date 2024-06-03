/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:03:27 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 16:57:30 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("default", ROBO_SIGN, ROBO_EXEC),
	m_target("home")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	AForm("Robotomy Request", ROBO_SIGN, ROBO_EXEC),
	m_target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &original) :
	AForm("Robotomy Request", ROBO_SIGN, ROBO_EXEC)
{
	*this = original;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &original)
{
	if (this != &original)
		m_target = original.getTarget();
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string RobotomyRequestForm::getTarget(void) const
{
	return (m_target);
}

void	RobotomyRequestForm::_execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "**some drilling noises**" << std::endl;
	if (std::rand() % 2)
	{
		std::cout << RED << "Robotomy failed" << WHITE << std::endl;
	}
	else
		std::cout << GREEN << m_target << " has been successfully robotomised" << WHITE << std::endl;
	return ;
}