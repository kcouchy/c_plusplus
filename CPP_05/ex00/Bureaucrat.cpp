/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:30:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/28 16:45:08 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Bureaucrat::Bureaucrat(void) :
	m_name("Faceless"),
	m_grade(GRADE_MIN)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
	m_name(name),
	m_grade(grade)
{
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
{
	*this = original;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &original)
{
	if (this == &original)
		return (*this);
	this->m_name = original.m_name;
	this->m_grade = original.m_grade;
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string		Bureaucrat::getName(void)const
{
	return(this->m_name);
}

unsigned int	Bureaucrat::getGrade(void)const
{
	return(this->m_grade);
}

void			Bureaucrat::incrementGrade(void)
{
	m_grade--;
	return;
}

void			Bureaucrat::decrementGrade(void)
{
	m_grade++;
	return;
}

std::ostream	&operator<<(std::ostream &outStream, Bureaucrat const &bureaucrat)
{
	outStream 
		<< bureaucrat.getName()
		<< " bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";

	return (outStream);
}
