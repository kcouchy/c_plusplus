/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:08 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:04:02 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Cat::Cat(void)
	: Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	m_type = "Cat";
	return ;
}

Cat::Cat(Cat const &original)
	: Animal(original)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = original;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
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
	Animal::operator=(original);
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "*meow*" << std::endl;
	return ;
}