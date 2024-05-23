/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:05:18 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 16:56:37 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat	(void);
		WrongCat	(WrongCat const &original);
		~WrongCat	(void);

		WrongCat	&operator=(WrongCat const &original);

		void		makeSound(void) const;
};

#endif
