/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:50:23 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:38 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;//calls default constructor (initialises a = 0)
	//calls two constructors (float and int), then the overload operator which 
	//calls the float constructor again (to keep precision)
	//then the first two instances (float and int) are destroyed
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	c( Fixed( 5.05f ) / 0 );

	std::cout << "a " << a << std::endl;
	std::cout << "a " << ++a << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "a " << a++ << std::endl;
	std::cout << "a " << a << std::endl;

	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

return (0);
}