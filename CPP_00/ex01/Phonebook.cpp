/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:43:52 by kcouchma          #+#    #+#             */
/*   Updated: 2024/04/30 17:05:54 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

Contact	*Phonebook::getContact(int index)
{
	return (&m_contacts[index]);
}
