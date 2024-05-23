/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:08 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Cat::Cat(void) :
	A_Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
	return ;
}

Cat::Cat(Cat const &original) :
	A_Animal(original),
	m_brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = original;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete m_brain;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

Cat &Cat::operator=(Cat const &original)
{
	std::cout << "Cat copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	A_Animal::operator=(original);
	if (m_brain != NULL)
		delete m_brain;//in case this has been set to anything other than NULL, to avoid leaks
	m_brain = new Brain(*original.m_brain);//dereferences the pointer stocked in m_brain to copy it
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

//modified to speak thoughts
void	Cat::makeSound(void) const
{
	for (int i = 0; i < NUMBER_IDEAS; i++)
		std::cout << "Cat " << (*m_brain)[i] << std::endl;
	return ;
}
