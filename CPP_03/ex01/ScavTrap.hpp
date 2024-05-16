/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:33:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 15:39:36 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);						//default
		ScavTrap(std::string const &name);	//name constructor
		ScavTrap(ScavTrap const &original);	//copy constructor
		~ScavTrap(void);					//destructor

		ScavTrap &operator=(ScavTrap const &original);	//Copy assignment operator overload function

		void	attack(std::string const& target);
		void	guardGate();
};

#endif