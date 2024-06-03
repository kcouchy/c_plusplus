/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:50 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 17:38:07 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm ("Presidential Pardon", PRES_SIGN, PRES_EXEC),
	m_target("home")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm ("Presidential Pardon", PRES_SIGN, PRES_EXEC),
	m_target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &original) :
	AForm ("Presidential Pardon", PRES_SIGN, PRES_EXEC)
{
	*this = original;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &original)
{
	if (this != &original)
		m_target = original.getTarget();
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string PresidentialPardonForm::getTarget(void)const
{
	return (m_target);
}

void	PresidentialPardonForm::_execute(Bureaucrat const & executor)const
{
	(void)executor;
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}
