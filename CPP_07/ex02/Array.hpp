/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:32:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 18:38:48 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>

class Array
{
	public:
		Array(void);
		Array(unsigned int size);
		Array(Array const& original);
		~Array(void);
		
		Array	&operator=(Array const& original);
		T		&operator[](unsigned int index)const;

		unsigned int	size(void)const;

	private:
		T	*m_data;
		unsigned int m_size;
};

# include "Array.tpp"

#endif