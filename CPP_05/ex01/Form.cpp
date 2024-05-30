/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:37 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/30 14:21:59 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Form::Form (void) : 
	m_name("Default"),
	m_isSigned(false),
	m_signLevel(150),
	m_execLevel(150)
{
	std::cout << "Default form constructor called" << std::endl;
	return ;
}

Form::Form (std::string name, int signLevel, int execLevel):
	m_name(name),
	m_isSigned(false),
	m_signLevel(signLevel),
	m_execLevel(execLevel)
{
	std::cout << m_name << " form constructor called" << std::endl;

	if (m_execLevel < maxLevel || m_signLevel < maxLevel)
		throw GradeTooHighException();
	else if (m_execLevel > minLevel || m_signLevel > minLevel)
		throw GradeTooLowException();
	return ;
}

Form::Form (Form const &original)
{
	std::cout << original.getName() << " form copy constructor called" << std::endl;
	*this = original;
	return ;
}

Form::~Form (void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

Form &Form::operator=(Form const &original)
{
	if (this != &original)
	{
		m_name = original.m_name;
		m_isSigned = original.m_isSigned;
		
		m_execLevel = original.m_execLevel;
		m_signLevel = original.m_signLevel;
	}
	return (*this);
}

/******************************************************************************/
/* Nested classes                                                             */
/******************************************************************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: Invalid grade : grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Invalid grade : grade too low");
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string		Form::getName(void) const
{
	return (m_name);
}

bool			Form::getIsSigned(void) const
{
	return (m_isSigned);
}

unsigned int	Form::getSigLevel(void) const
{
	return (m_signLevel);
}

unsigned int	Form::getExecLevel(void) const
{
	return (m_execLevel);
}

void			Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > m_signLevel)
		throw GradeTooLowException();
	m_isSigned = true;
	return ;
}

/******************************************************************************/
/* Non-member operator overload function                                      */
/******************************************************************************/

std::ostream &operator<<(std::ostream &outStream, Form const &form)
{
	std::cout
		<< "Form " << form.getName() << std::endl
		<< "	is signed: " << form.getIsSigned() << std::endl
		<< "	grade required for signature: " << form.getSigLevel() << std::endl
		<< "	grade required for execution: " << form.getExecLevel()
		<< std::endl;
	return (outStream);
}
