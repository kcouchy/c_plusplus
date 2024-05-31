/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:30:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 12:38:09 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Bureaucrat::Bureaucrat(void) :
	m_name("Faceless"),
	m_grade(grade_min)
{
	std::cout
		<< m_name << " bureaucrat constructor called (grade "
		<< m_grade << ")"
		<< std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
	m_name(name),
	m_grade(grade)
{
	std::cout 
		<< "Bureaucrat constructor called: " << m_name << " is hired at grade "
		<< grade
		<< std::endl;
	if (grade > grade_min)
		throw GradeTooLowException();
	if (grade < grade_max)
		throw GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
{
	*this = original;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout
		<< "Bureaucrat destructor called: " << m_name << " is fired"
		<< std::endl;
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
/* Nested classes                                                             */
/******************************************************************************/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Invalid grade: maximum grade is 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Invalid grade: minimum grade is 150");
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
	std::cout << "Bureaucrat increment function called" << std::endl;
	if ((m_grade - 1) < grade_max)
		throw GradeTooHighException();
	m_grade--;
	std::cout << m_name << " is promoted to grade " << m_grade << std::endl;
	return;
}

void			Bureaucrat::decrementGrade(void)
{
	std::cout << "Bureaucrat decrement function called" << std::endl;
	if ((m_grade + 1) > grade_min)
		throw GradeTooLowException();
	m_grade++;
	std::cout << m_name << " is demoted to grade " << m_grade << std::endl;
	return;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout
			<< m_name << " cannot sign the "
			<< form.getName() << " form because it is already signed"
			<< std::endl;
		return ;
	}
	if (m_grade > form.getSigLevel())
	{
		std::cout
			<< m_name << " cannot sign the "
			<< form.getName() << " form because their grade is too low"
			<< std::endl;
		return ;
	}
	form.beSigned(*this);
	return ;
}

/******************************************************************************/
/* Non-member operator overload function                                      */
/******************************************************************************/

std::ostream	&operator<<(std::ostream &outStream, Bureaucrat const &bureaucrat)
{
	outStream 
		<< bureaucrat.getName()
		<< " bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";

	return (outStream);
}
