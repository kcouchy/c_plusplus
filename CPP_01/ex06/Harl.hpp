/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:26:32 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 15:02:37 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:

		void				complain( std::string level );

	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		static const std::string	levelTable[4];

};

#endif