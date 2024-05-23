/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:35:07 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:35 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define NUMBER_IDEAS 100

class Brain
{
	public:
		Brain	(void);
		Brain	(Brain const &original);

		~Brain	(void);

		Brain &operator=(Brain const &original);
		const std::string &operator[](int index);

	private:
		std::string	m_ideas[NUMBER_IDEAS];
};

#endif
