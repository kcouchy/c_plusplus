/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:36 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:41:09 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class Dog : public A_Animal
{
	public :
		Dog		(void);
		Dog		(Dog const &original);
		~Dog	(void);

		Dog		&operator=(Dog const &original);

		void	makeSound(void) const;

	private :
		Brain	*m_brain;
};

#endif
