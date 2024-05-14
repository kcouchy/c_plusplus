/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:51:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/13 14:38:05 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed (void);						//constructor
		Fixed (const int intValue);			//int constructor
		Fixed (const float floatValue);		//float constructor
		Fixed (Fixed const &original);		//copy constructor
		~Fixed (void);						//destructor

		Fixed &operator=	( Fixed const &original );	//copy assignment operator overload.

		//returns a boolean (true/false) with the result of the comparison
		bool operator>	(Fixed const &rightHandSide) const;
		bool operator<	(Fixed const &rightHandSide) const;
		bool operator>=	(Fixed const &rightHandSide) const;
		bool operator<=	(Fixed const &rightHandSide) const;
		bool operator==	(Fixed const &rightHandSide) const;
		bool operator!=	(Fixed const &rightHandSide) const;

		//calls float constructor to return result instance
		//(is therefore a kind of constructor)
		Fixed operator+	(Fixed const &rightHandSide) const;
		Fixed operator-	(Fixed const &rightHandSide) const;
		Fixed operator*	(Fixed const &rightHandSide) const;
		Fixed operator/	(Fixed const &rightHandSide) const;

		//returns references to the max/min as static (const or no depending on 
		//input refs)
		static Fixed &min (Fixed &leftHandSide, Fixed &rightHandSide);
		static Fixed const &min (Fixed const &leftHandSide, Fixed const &rightHandSide);
		static Fixed &max (Fixed &leftHandSide, Fixed &rightHandSide);
		static Fixed const &max (Fixed const &leftHandSide, Fixed const &rightHandSide);

		//increment and decrement operator overide functions - the int is 
		//interpreted to refer to a post-in/decrementation (i++/i--)
		Fixed &operator++	(void);
		Fixed operator++	(int);
		Fixed &operator--	(void);
		Fixed operator--	(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					m_value;
		static int const	m_numBits = 8;

};
		std::ostream &operator<< (std::ostream &outStream, Fixed const &fixed);//float constructor

#endif