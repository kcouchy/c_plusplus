/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

A_Animal::A_Animal (void) : m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

A_Animal::A_Animal (std::string const type) : m_type(type)
{
	std::cout << "Animal string constructor called" << std::endl;
	return ;
}

A_Animal::A_Animal (A_Animal const &original)
{
	*this = original;
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

A_Animal::~A_Animal (void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

A_Animal &A_Animal::operator=(A_Animal const &original)
{
	std::cout << "Animal copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	this->m_type = original.m_type;
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string	const A_Animal::getType(void) const
{
	return (m_type);
}

void A_Animal::makeSound(void) const
{
	std::cout << "*meh*" << std::endl;
	return ;
}