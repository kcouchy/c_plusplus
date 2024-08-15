/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:27 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 13:16:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &first, T &second)
{
	T	temp = first;

	first = second;
	second = temp;
}

template <typename T>
T	min(T first, T second)
{
	return (first < second ? first : second);
}

template <typename T>
T	max(T first, T second)
{
	return (first > second ? first : second);
}

#endif