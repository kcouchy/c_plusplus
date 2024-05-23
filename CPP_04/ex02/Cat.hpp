/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:18 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:47 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal
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
