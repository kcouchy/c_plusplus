/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:36:09 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :
		Animal			(void);
		Animal			(std::string const type);
		Animal			(Animal const &original);
		virtual ~Animal	(void);

		Animal			&operator=(Animal const &original);

		std::string const	getType(void) const;
		virtual void		makeSound(void) const;

	protected :
		std::string m_type;
};

#endif
