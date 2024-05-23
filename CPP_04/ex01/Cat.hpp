/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:18 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:22:39 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat		(void);
		Cat		(Cat const &original);
		~Cat	(void);

		Cat		&operator=(Cat const &original);

		void	makeSound(void) const;

	private :
		Brain	*m_brain;
};

#endif