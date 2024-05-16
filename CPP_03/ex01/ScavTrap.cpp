/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:34:02 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/16 11:47:54 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string const &name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	m_name = name;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &original)
	: ClapTrap(original)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = original;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

ScavTrap &ScavTrap::operator=(ScavTrap const &original)
{
	std::cout << "ScavTrap copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	ClapTrap::operator=(original);
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void	ScavTrap::attack(std::string const& target)
{
	if (m_hitPoints == 0)
	{
		std::cout << "Attack is impossible, ScavTrap is deaded" << std::endl;
		return;
	}
	if (m_energyPoints == 0)
	{
		std::cout
			<< "ScavTrap " << m_name
			<< " can't attack " << target
			<< ", it has insufficient energy"
			<< std::endl;
		return (showStats());
	}
	m_energyPoints--;
	std::cout
		<< "ScavTrap " << m_name
		<< " attacks " << target
		<< " causing " << m_attackDamage
		<< " points of damage!"
		<< std::endl;
	return (showStats());
}

void	ScavTrap::guardGate(void)
{
	if (m_hitPoints == 0)
	{
		std::cout
			<< "ScavTrap " << m_name
			<< " cannot guard the Gate, it is deaded"
			<< std::endl;
		return (showStats());
	}
	std::cout
		<< "ScavTrap " << m_name
		<< " is now in Gate keeper mode."
		<< std::endl;
	return (showStats());
}

