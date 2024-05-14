/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:37 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/01 12:16:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// std::cout, std::endl
#include <iomanip>	// std::setw
#include <cstdlib>	// std::atoi
#include "Phonebook.hpp"

bool	ft_isnum(std::string line)
{
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
		if (isdigit(*it) == false)
			return (false);
	return (true);
}

std::string	ft_getline(std::string prompt)
{
	std::string line;

	line = "";
	while (line.compare("") == 0 && std::cin.eof() == false)
	{
		std::cout << std::endl;
		std::cout << prompt;
		std::getline(std::cin, line);
	}
	return (line);
}

void	ft_add(Phonebook &phone_book)
{
	std::string	line;
	int	i = 0;

	i = phone_book.getContact(i)->getContactNumber() - 1;
	if (i == 8)
		i = 0;
	phone_book.getContact(i)->setFirstName(ft_getline(" Enter First Name: "));
	phone_book.getContact(i)->setLastName(ft_getline(" Enter Last Name: "));
	phone_book.getContact(i)->setNickname(ft_getline(" Enter Nickname: "));
	phone_book.getContact(i)->setPhoneNumber(ft_getline(" Enter Phone Number: "));
	phone_book.getContact(i)->setSecret(ft_getline(" Enter Darkest Secret: "));
	phone_book.getContact(i)->setContactNumber();
	if (std::cin.eof() == false)
		std::cout << std::endl << "Contact added successfully!" << std::endl;
}

void	ft_search(Phonebook phone_book)
{
	std::string	line;
	int	search_index;
	
	std::cout << std::setw(10) << std::endl << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
		phone_book.getContact(i)->displaySearch(0);
	std::cout << std::endl << " Enter contact index for more information, or press enter to return to main menu: ";
	std::getline(std::cin, line);
	if (ft_isnum(line) == true)
	{
		search_index = std::atoi(line.c_str());
		if (search_index > 0 && search_index <= 8)
			phone_book.getContact(search_index - 1)->displaySearch(1);
		else if (std::cin.eof() == false)
			std::cout << std::endl << "Invalid index" << std::endl;
	}
	else if (std::cin.eof() == false || line.compare("") == 0)
		std::cout << std::endl << "Invalid index" << std::endl;
	return ;
}

void	ft_menu(int	mode)
{
	if (std::cin.eof() == false && mode == 0)
	{
		std::cout << std::endl;
		std::cout << "*----------------------*" << std::endl;
		std::cout << "Welcome to the phonebook" << std::endl;
		std::cout << "*----------------------*" << std::endl;
	}
	if (std::cin.eof() == false && (mode == 0 || mode == 1))
	{
		std::cout << std::endl;
		std::cout << " ~~~~~~~~~~" << std::endl;
		std::cout << " Main menu:" << std::endl;
		std::cout << "   ADD" << std::endl;
		std::cout << "   SEARCH" << std::endl;
		std::cout << "   EXIT" << std::endl;
		std::cout << " ~~~~~~~~~~" << std::endl << std::endl;
	}
	if (mode == 2)
	{
		std::cout << std::endl;
		std::cout << "*-------------------------*" << std::endl;
		std::cout << "Phonebook cleared, goodbye!" << std::endl;
		std::cout << "*-------------------------*" << std::endl << std::endl;
	}
}

int	main(void)
{
	Phonebook	phone_book;
	std::string	line;

	ft_menu(0);
	while (std::cin.eof() == false)
	{
		std::getline(std::cin, line);
		if (line.compare("EXIT") == 0)
			break ;
		else if (line.compare("ADD") == 0)
			ft_add(phone_book);
		else if (line.compare("SEARCH") == 0)
			ft_search(phone_book);
		else if (std::cin.eof() == false)
			std::cout << std::endl << "Invalid input, try:" << std::endl << "ADD/SEARCH/EXIT" << std::endl << std::endl;
		ft_menu(1);
	}
	ft_menu(2);
	return (0);
}
