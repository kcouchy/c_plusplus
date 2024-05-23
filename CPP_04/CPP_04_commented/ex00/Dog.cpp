/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:10 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Dog::Dog (void)
	: A_Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	m_type = "Dog";
	return ;
}

Dog::Dog (Dog const &original)
	: A_Animal(original)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = original;
	return ;
}

Dog::~Dog (void)
{
	std::cout << "Dog destructor called" << std::endl;
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
	A_Animal::operator=(original);
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void	Dog::makeSound(void) const
{
	std::cout << "*woof*" << std::endl;
	return ;
}