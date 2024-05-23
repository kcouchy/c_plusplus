/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:08 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 16:56:33 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

WrongCat::WrongCat(void)
	: WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	m_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const &original)
	: WrongAnimal(original)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = original;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

WrongCat &WrongCat::operator=(WrongCat const &original)
{
	std::cout << "WrongCat copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	WrongAnimal::operator=(original);
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "*wrong meow*" << std::endl;
	return ;
}
