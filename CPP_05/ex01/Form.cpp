/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:37 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/23 12:09:08 by kcouchma         ###   ########.fr       */
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
	std::cout << "Form constructor called: " << m_name << std::endl;

	if (m_execLevel < maxLevel || m_signLevel < maxLevel)
		throw GradeTooHighException();
	else if (m_execLevel > minLevel || m_signLevel > minLevel)
		throw GradeTooLowException();
	return ;
}

Form::Form (Form const &original):
	m_name(original.m_name),
	m_signLevel(original.m_signLevel),
	m_execLevel(original.m_execLevel)
{
	std::cout << "Form copy constructor called: " << original.getName() << std::endl;
	*this = original;
	return ;
}

Form::~Form (void)
{
	std::cout
		<< "Form destructor called: " 
		<< this->getName() << " has been shredded"
		<< std::endl;
	return ;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

Form &Form::operator=(Form const &original)
{
	if (this != &original)
		m_isSigned = original.m_isSigned;
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
	if (m_isSigned == true)
	{
		std::cout
			<< bureaucrat.getName() << " cannot sign the "
			<< m_name << " form because it is already signed"
			<< std::endl;
		return;
	}
	if (bureaucrat.getGrade() > m_signLevel)
	{
		std::cout
			<< bureaucrat.getName() << " cannot sign the "
			<< m_name << " form because their grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	std::cout
		<< bureaucrat.getName()
		<< " has signed the "
		<< m_name << " form"
		<< std::endl;
	m_isSigned = true;
	return ;
}

/******************************************************************************/
/* Non-member operator overload function                                      */
/******************************************************************************/

std::ostream &operator<<(std::ostream &outStream, Form const &form)
{
	std::cout
		<< " ____________________________________________" << std::endl
		<< "  Form: " << form.getName() << std::endl
		<< "   is signed:	" << form.getIsSigned() << std::endl
		<< "   grade required for signature:	" << form.getSigLevel() << std::endl
		<< "   grade required for execution:	" << form.getExecLevel()
		<< std::endl
		<< " ____________________________________________" << std::endl;
	return (outStream);
}
