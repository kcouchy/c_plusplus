/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:51:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 10:26:40 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed ( void );								//constructor
		Fixed ( const int intValue );				//int constructor
		Fixed ( const float floatValue );			//float constructor
		Fixed (Fixed const &original);				//copy constructor
		~Fixed ( void );							//destructor

		Fixed &operator= ( Fixed const &original );		//copy assignment operator overload.

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
	private:
		int					m_value;
		static int const	m_numBits = 8;

};

		std::ostream &operator<<( std::ostream &outStream, Fixed const &fixed );		//float constructor
		// An overload of the insertion («) operator that inserts a floating-point representation 
		// of the fixed-point number into the output stream object passed as parameter.
#endif