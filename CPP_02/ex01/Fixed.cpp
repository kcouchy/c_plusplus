/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:55:03 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 11:32:27 by kcouchma         ###   ########.fr       */
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
	*this = original; //calls copy assignment because the prototype is the same
	return ;
}

Fixed &Fixed::operator= (Fixed const &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	m_value = original.getRawBits();
	return (*this);
}

Fixed::Fixed( const int int_value ) :
	m_value(int_value * (1 << m_numBits)) //int stocked into fixed point
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed ( const float float_value )
{
	std::cout << "Float constructor called" << std::endl;
	m_value = (int)float_value * (1 << m_numBits);//get left (int) part into fixed point : cast to int to round off the decimals then stock int into fixed point
	m_value += (float_value - (int)float_value) * (1 << m_numBits);//get right (mantissa) part into fixed point : get rid of left part by subtracting the rounded int version, then stock into fixed point
	return ;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	return (m_value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	m_value = raw;
	return;
}

float Fixed::toFloat( void ) const
{
	int		intValue = getRawBits();
	float	floatValue = 0.0;

	floatValue = intValue / (float)(1 << m_numBits); //float cast to ensure mantissa is not discarded by int (1 << 8)
	return (floatValue);
}

int Fixed::toInt( void ) const
{
	return (m_value / (1 << m_numBits)); //converts fixed point to int
}

std::ostream &operator<<( std::ostream &outStream, Fixed const &fixed ) //returns ref to ostream so inline to std::endl works
{
	outStream << fixed.toFloat();
	return (outStream);
}
