/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:36 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:04:02 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog		(void);
		Dog		(Dog const &original);
		~Dog	(void);

		Dog		&operator=(Dog const &original);

		void	makeSound(void) const;
};

#endif