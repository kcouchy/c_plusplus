/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:36:26 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:15 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap (void);
		FragTrap (std::string const &name);
		FragTrap (FragTrap const &original);
		~FragTrap (void);

		FragTrap &operator=(FragTrap const &original);

		void highFivesGuys(void);
};

#endif