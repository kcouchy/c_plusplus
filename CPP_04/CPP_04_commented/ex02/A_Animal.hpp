/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class A_Animal
{
	public :
		A_Animal			(void);
		A_Animal			(std::string const type);
		A_Animal			(A_Animal const &original);
		virtual ~A_Animal	(void);

		A_Animal			&operator=(A_Animal const &original);

		std::string const	getType(void) const;
		virtual void		makeSound(void) const = 0;

	protected :
		std::string m_type;
};

#endif
