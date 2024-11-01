/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:03 by kcouchma          #+#    #+#             */
/*   Updated: 2024/10/29 17:58:04 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
{
	this->tm_sec = 0;
	this->tm_min = 0;
	this->tm_hour = 0;
	this->tm_mday = 1;
	this->tm_mon = 0;
	this->tm_year = 0;
	this->tm_wday = 0;
	this->tm_yday = 0;
	this->tm_isdst = 0;
}

Date::Date(int year, int month, int day)
{
	this->tm_sec = 0;
	this->tm_min = 0;
	this->tm_hour = 0;
	this->tm_mday = day;
	this->tm_mon = month - 1; //months since january
	this->tm_year = year - 1900; //years since 1900
	this->tm_wday = 0;
	this->tm_yday = 0;
	this->tm_isdst = 0;

	if (!this->isValid())
		throw std::logic_error("Error: bad input => ");
		// throw (InvalidDateFormat());
}

Date::Date(Date const &o)
{
	this->tm_sec = o.tm_sec;
	this->tm_min = o.tm_min;
	this->tm_hour = o.tm_hour;
	this->tm_mday = o.tm_mday;
	this->tm_mon = o.tm_mon;
	this->tm_year = o.tm_year;
	this->tm_wday = o.tm_wday;
	this->tm_yday = o.tm_yday;
	this->tm_isdst = o.tm_isdst;
}

Date::~Date()
{
}

// date should be unchanged if it is valid (mktime will adjust otherwise)
bool	Date::isValid()
{
	Date tmp = *this;

	return (std::mktime(&tmp) > 0 && tmp == *this);
}

void	Date::set_date(int year, int month, int day)
{
	this->tm_mday = day;
	this->tm_mon = month - 1; //months since january
	this->tm_year = year - 1900; //years since 1900

	if (!this->isValid())
		throw std::logic_error("Error: bad input => ");
}

Date	&Date::operator=(Date const &o)
{
	
	this->tm_sec = o.tm_sec;
	this->tm_min = o.tm_min;
	this->tm_hour = o.tm_hour;
	this->tm_mday = o.tm_mday;
	this->tm_mon = o.tm_mon;
	this->tm_year = o.tm_year;
	this->tm_isdst = o.tm_isdst;

	return (*this);
}


bool	Date::operator<(Date const &o) const
{
	if (this->tm_year != o.tm_year)
		return (this->tm_year < o.tm_year);
	else if (this->tm_mon != o.tm_mon)
		return (this->tm_mon < o.tm_mon);
	else
		return (this->tm_mday < o.tm_mday);
}

bool	Date::operator==(Date const &o) const
{
	if (this->tm_year != o.tm_year)
		return (this->tm_year == o.tm_year);
	else if (this->tm_mon != o.tm_mon)
		return (this->tm_mon == o.tm_mon);
	else
		return (this->tm_mday == o.tm_mday);
}

std::ostream &operator<<(std::ostream &flux, Date const &date)
{
    //add zeros before single digit days/months
	std::string zero_mon;
	std::string zero_day;
	if (date.tm_mon < 9)
		zero_mon = "0";
	if (date.tm_mday < 10)
		zero_day = "0";

	flux << date.tm_year + 1900 << "-" << zero_mon << date.tm_mon + 1 << "-" << zero_day << date.tm_mday ;
	return (flux);
}