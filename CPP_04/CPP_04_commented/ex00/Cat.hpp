/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:18 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public A_Animal
{
	public :
		Cat		(void);
		Cat		(Cat const &original);
		~Cat	(void);

		Cat		&operator=(Cat const &original);

		void	makeSound(void) const;
};

#endif