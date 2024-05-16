/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:43:19 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 15:26:15 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

ClapTrap::ClapTrap (void) : 
		m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap (std::string const name) : 
		m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap (ClapTrap const &original)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = original;
	return ;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

/******************************************************************************/
/* Member function overload operators                                         */
/******************************************************************************/

ClapTrap &ClapTrap::operator=(ClapTrap const &original)
{
	if (this == &original)
		return (*this);
	std::cout << "Claptrap copy assignment operator overload function called" << std::endl;
	m_name = original.m_name;
	m_hitPoints = original.m_hitPoints;
	m_energyPoints = original.m_energyPoints;
	m_attackDamage = original.m_attackDamage;
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

void ClapTrap::showStats(void)
{
	std::cout
		<< "\t(HP " << m_hitPoints
		<< " | EP " << m_energyPoints
		<< ")" << std::endl << std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (m_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << m_name
			<< " is already deaded, attack is impossible"
			<< std::endl;
		return (showStats());
	}
	if (m_energyPoints == 0)
	{
		std::cout
			<< "ClapTrap " << m_name
			<< " can't attack " << target
			<< ", it has insufficient energy"
			<< std::endl;
		return (showStats());
	}
	m_energyPoints--;
	std::cout
		<< "ClapTrap " << m_name
		<< " attacks " << target
		<< " causing " << m_attackDamage
		<< " points of damage!"
		<< std::endl;
	return (showStats());
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (m_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << m_name
			<< " is attacked, but there's no point beating a dead horse, it is already deaded"
			<< std::endl;
		return (showStats());
	}
	std::cout
		<< "ClapTrap " << m_name
		<< " is attacked, taking " << amount
		<< " points of damage!"
		<< std::endl;
	if (amount >= m_hitPoints)
	{
		m_hitPoints = 0;
		std::cout
			<< "Damage is fatal, ClapTrap " << m_name
			<< " is deaded"
			<< std::endl;
		return (showStats());
	}
	m_hitPoints -=amount;
	return (showStats());
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_hitPoints == 0)
	{
		std::cout
			<< "ClapTrap " << m_name
			<< " cannot be repaired, it is already deaded"
			<< std::endl;
		return (showStats());
	}
	if (m_energyPoints == 0)
	{
		std::cout
			<< "ClapTrap " << m_name
			<< " can't be repaired, it has insufficient energy"
			<< std::endl;
		return  (showStats());
	}
	m_energyPoints--;
	std::cout
		<< "ClapTrap " << m_name
		<< " is repaired, fixing " << amount
		<< " points of damage!"
		<< std::endl;
	m_hitPoints +=amount;

	return  (showStats());
}
