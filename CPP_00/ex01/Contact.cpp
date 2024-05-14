/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:10:12 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/01 14:29:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void):
	first_name(""), last_name(""), nickname(""), phone_number(""), secret("")
{
	index = contact_number;
	setContactNumber();
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	Contact::contact_number = 1;

void	Contact::truncateDisplay(std::string field)const
{
	std::string	truncate;

	truncate = field;
	if (truncate.length() > 10)
		truncate = truncate.substr(0, 9) + ".";
	std::cout << std::setw(10) << truncate;
}

void	Contact::displaySearch(int mode)const
{
	if (mode == 0)
	{
		std::cout << std::setw(10) << index << "|";
		truncateDisplay(first_name);
		std::cout << "|";
		truncateDisplay(last_name);
		std::cout << "|";
		truncateDisplay(nickname);
		std::cout << std::endl;
	}
	else if (mode == 1)
	{
		std::cout << std::setw(10) << std::endl << "Contact Index:	" << Contact::index << std::endl;
		std::cout << std::setw(10) << "First Name:	" << first_name << std::endl;
		std::cout << std::setw(10) << "Last Name:	" << last_name << std::endl;
		std::cout << std::setw(10) << "Nickname:	" << nickname << std::endl;
		std::cout << std::setw(10) << "Phone Number:	" << phone_number << std::endl;
		std::cout << std::setw(10) << "Darkest Secret:	" << secret << std::endl << std::endl;
	}
	return ;
}

int		Contact::getContactNumber(void)const
{
	return(contact_number);
}

void	Contact::setContactNumber(void)
{
	contact_number += 1;
	if (contact_number == 9)
		contact_number = 1;
	return ;
}

void	Contact::setFirstName(std::string value)
{
	first_name = value;
}

void	Contact::setLastName(std::string value)
{
	last_name = value;
}

void	Contact::setNickname(std::string value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	phone_number = value;
}

void	Contact::setSecret(std::string value)
{
	secret = value;
}
