/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:51:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/09 16:26:39 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed ( void );								//constructor
		Fixed (Fixed const &original);				//copy constructor
		~Fixed ( void );							//destructor
		
		Fixed &operator= (Fixed const &original);	//copy assignment operator overload.
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:
		int					m_value;
		static int const	m_numBits = 8;

};

#endif