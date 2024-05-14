/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:26:32 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 14:32:05 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:

		// Defines a type t_func that is a pointer to a member function of 
		// the class Harl. The function takes no args and returns void.
		typedef void		(Harl::*t_func)(void);
		void				complain( std::string level );
		const std::string	getLevel( int );

	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

// Defines the arrays of function pointers and level names 
// (static = non-member)
// Static data is initialised to 0 by default, can initialise outside of 
// the class using the scope resolution operator `::` to identify 
// the class to which it belongs (see .cpp).
		static const t_func			functionTable[4];
		static const std::string	levelTable[4];

};

#endif