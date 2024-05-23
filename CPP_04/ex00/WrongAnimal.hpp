/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/16 17:15:53 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal				(void);
		WrongAnimal				(std::string const type);
		WrongAnimal				(WrongAnimal const &original);
		virtual ~WrongAnimal	(void);

		WrongAnimal			&operator=(WrongAnimal const &original);

		std::string	const	getType(void) const;
		void				makeSound(void) const;

	protected :
		std::string m_type;
};

#endif