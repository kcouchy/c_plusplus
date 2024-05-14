/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:23 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 10:25:46 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed		a;				//calls default constructor: sets m_value to 0
	Fixed const	b( 10 );		//calls int constructor
	Fixed const	c( 42.42f );	//calls float constructor
	Fixed const	d( b );			//calls copy constructor

	a = Fixed( 1234.4321f );	//calls copy assignment operator to replace data in existing instance

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}