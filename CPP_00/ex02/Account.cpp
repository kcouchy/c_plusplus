/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:23:32 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/01 16:38:15 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_nbAccounts = getNbAccounts() + 1;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

// #define USE_DEFAULT_TIME

void	Account::_displayTimestamp( void )
{
#ifndef USE_DEFAULT_TIME
	time_t		current_time;
	struct tm	local_time;

	std::time(&current_time);
	local_time = *std::localtime(&current_time);
	std::cout 
		<< "["
		<< local_time.tm_year + 1900
		<< std::setw(2) << std::setfill('0') << local_time.tm_mon
		<< std::setw(2) << std::setfill('0') << local_time.tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << local_time.tm_hour
		<< std::setw(2) << std::setfill('0') << local_time.tm_min
		<< std::setw(2) << std::setfill('0') << local_time.tm_sec
		<< "] ";
#else
	std::cout << "[19920104_091532] ";
#endif
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" <<_totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
	return ;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
	return ;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount;
	_amount += deposit;
	std::cout
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
	}
	std::cout
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return (true);
}