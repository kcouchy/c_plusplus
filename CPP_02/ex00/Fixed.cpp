/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:55:03 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/10 10:15:05 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ) : m_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed (Fixed const &original)
{
	std::cout << "Copy constructor called" << std::endl;
	m_value = original.getRawBits();
	return ;
}

Fixed &Fixed::operator= (Fixed const &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	m_value = original.getRawBits();
	return (*this);
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	m_value = raw;
	return;
}