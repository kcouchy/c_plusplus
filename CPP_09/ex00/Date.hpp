/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:00 by kcouchma          #+#    #+#             */
/*   Updated: 2024/10/28 15:22:22 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>

class Date : public std::tm
{
	public :
		Date();
		Date(int year, int month, int day);
		Date(Date const &o);
		~Date();

		Date	&operator=(Date const &o);
		bool	operator<(Date const &o) const;
		bool	operator==(Date const &o) const;

		void	set_date(int year, int month, int day);
		bool	isValid();
		
};

std::ostream &operator<<(std::ostream &flux, Date const &date);