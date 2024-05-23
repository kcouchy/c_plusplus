/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/16 17:15:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

WrongAnimal::WrongAnimal (void) : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal (std::string const type) : m_type(type)
{
	std::cout << "WrongAnimal string constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal (WrongAnimal const &original)
{
	*this = original;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal (void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &original)
{
	std::cout << "WrongAnimal copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	this->m_type = original.m_type;
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string	const WrongAnimal::getType(void) const
{
	return (m_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "*wrong meh*" << std::endl;
	return ;
}