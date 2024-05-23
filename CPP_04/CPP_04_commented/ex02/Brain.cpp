/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:34:54 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 16:42:07 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

Brain::Brain	(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < NUMBER_IDEAS; i++)
		m_ideas[i] = "thought";
	return ;
}

Brain::Brain	(Brain const &original)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = original;
	return ;
}

Brain::~Brain	(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

Brain &Brain::operator=(Brain const &original)
{
	std::cout << "Brain copy asssignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	for (int i = 0; i < NUMBER_IDEAS; i++)
		this->m_ideas[i] = original.m_ideas[i];
	return (*this);
}

const std::string & Brain::operator[](int index)
{
	return (m_ideas[index]);//overload the [] operator to read out m_ideas from Cat
}
