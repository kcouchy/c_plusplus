/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:55:03 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:37 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Fixed::Fixed (void) : m_value(0)
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

Fixed::Fixed(const int int_value) :
	m_value(int_value * (1 << m_numBits)) //int stocked into fixed point
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed (const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	m_value = (int)float_value * (1 << m_numBits);//get left (int) part into fixed point : cast to int to round off the decimals then stock int into fixed point
	m_value += (float_value - (int)float_value) * (1 << m_numBits);//get right (mantissa) part into fixed point : get rid of left part by subtracting the rounded int version, then stock into fixed point
	return ;
}

Fixed::~Fixed (void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

Fixed &Fixed::operator= (Fixed const &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	m_value = original.getRawBits();
	return (*this);
}

bool Fixed::operator>	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() > rightHandSide.m_value);
}

bool Fixed::operator<	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() < rightHandSide.getRawBits());
}

bool Fixed::operator>=	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() >= rightHandSide.getRawBits());
}

bool Fixed::operator<=	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() <= rightHandSide.getRawBits());
}

bool Fixed::operator==	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() == rightHandSide.getRawBits());
}

bool Fixed::operator!=	(Fixed const &rightHandSide) const
{
	return (this->getRawBits() != rightHandSide.getRawBits());
}

Fixed Fixed::operator+	(Fixed const &rightHandSide) const
{
	return (Fixed(this->toFloat() + rightHandSide.toFloat()));
}

Fixed Fixed::operator-	(Fixed const &rightHandSide) const
{
	return (Fixed(this->toFloat() - rightHandSide.toFloat()));
}

Fixed Fixed::operator*	(Fixed const &rightHandSide) const
{
	return (Fixed(this->toFloat() * rightHandSide.toFloat()));
}

Fixed Fixed::operator/	(Fixed const &rightHandSide) const
{
	return (Fixed(this->toFloat() / rightHandSide.toFloat()));
}

// pre-increment/decrement (++i)
Fixed &Fixed::operator++	(void)
{
	this->m_value++;
	return(*this);
}

Fixed &Fixed::operator--	(void)
{
	this->m_value--;
	return(*this);
}

// post-increment/decrement (i++)
Fixed Fixed::operator++		(int)
{
	Fixed	temp;

	temp = *this;
	this->m_value++;
	return(temp);
}

Fixed Fixed::operator--		(int)
{
	Fixed	temp;

	temp = *this;
	this->m_value--;
	return(temp);
}


/******************************************************************************/
/* Static member function overload operators                                  */
/******************************************************************************/

// ternary operator returns LHS if is <= RHS (comparison ? if true : if false)
Fixed &Fixed::min (Fixed &leftHandSide, Fixed &rightHandSide)
{
	return (leftHandSide.m_value <= rightHandSide.m_value ? leftHandSide : rightHandSide);
}

Fixed const& Fixed::min (Fixed const &leftHandSide, Fixed const &rightHandSide)
{
	return (leftHandSide.m_value <= rightHandSide.m_value ? leftHandSide : rightHandSide);
}

Fixed &Fixed::max (Fixed &leftHandSide, Fixed &rightHandSide)
{
	return (leftHandSide.m_value >= rightHandSide.m_value ? leftHandSide : rightHandSide);
}

Fixed const& Fixed::max (Fixed const &leftHandSide, Fixed const &rightHandSide)
{
	return (leftHandSide.m_value >= rightHandSide.m_value ? leftHandSide : rightHandSide);
}

/******************************************************************************/
/* Getters/Setters                                                            */
/******************************************************************************/

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

/******************************************************************************/
/* Return values                                                              */
/******************************************************************************/

float Fixed::toFloat( void ) const
{
	int		intValue = getRawBits();
	float	floatValue = 0.0;

	floatValue = intValue / (float)(1 << m_numBits);
	return (floatValue);
}

int Fixed::toInt( void ) const
{
	return (m_value / (1 << m_numBits));
}

/******************************************************************************/
/* Class overload operator                                                    */
/******************************************************************************/

std::ostream &operator<<( std::ostream &outStream, Fixed const &fixed )
{
	outStream << fixed.toFloat();
	return (outStream);
}
