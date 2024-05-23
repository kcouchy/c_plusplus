/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:10 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:22:39 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Dog::Dog (void) :
	Animal(),
	m_brain(NULL)
{
	std::cout << "Dog default constructor called" << std::endl;
	m_type = "Dog";
	m_brain = new Brain();
	return ;
}

Dog::Dog (Dog const &original) :
	Animal(original),
	m_brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = original;
	return ;
}

Dog::~Dog (void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

Dog &Dog::operator=(Dog const &original)
{
	std::cout << "Dog copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	if (m_brain != NULL)
		delete m_brain;
	Animal::operator=(original);
	m_brain = new Brain(*original.m_brain);
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void	Dog::makeSound(void) const
{
	for (int i = 0; i < NUMBER_IDEAS; i++)
		std::cout << "Dog " << (*m_brain)[i] << std::endl;
	return ;
}
