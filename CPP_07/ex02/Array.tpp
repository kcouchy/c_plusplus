/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:47:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/12 18:35:27 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

template <typename T>
Array<T>::Array(void) :
	m_data(NULL),
	m_size(0)
{}

template <typename T>
Array<T>::Array(unsigned int size)
{
	m_size = size;
	if (size == 0)
		m_data = NULL;
	else
		m_data = new T[size];
}

template <typename T>
Array<T>::Array(Array const& original)
{
	*this = original;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] m_data;
}

template <typename T>
unsigned int	Array<T>::size(void)const
{
	return (m_size);
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &original)
{
	delete[] m_data;
	m_size = original.size();
	if (m_size == 0)
		m_data = NULL;
	else
	{
		m_data = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++)
			m_data[i] = original[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)const
{
	if (index >= m_size)
		throw std::logic_error("Error: index out of bounds");
	return (m_data[index]);
}
