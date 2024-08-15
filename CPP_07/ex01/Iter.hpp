/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:20:29 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 18:30:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define	ITER_HPP
# include	<iostream>

template <typename T>
void	_print(T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void	_double(T &value)
{
	value += value;
}

template <typename T>
void	iter(T array[], size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
