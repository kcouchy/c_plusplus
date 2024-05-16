/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:40:54 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/15 16:56:47 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap (void)
	: ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	return ;
}

FragTrap::FragTrap (std::string const &name)
	: ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	m_name = name;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	return ;
}

FragTrap::FragTrap (FragTrap const &original)
	: ClapTrap(original)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = original; 
	return ;
}

FragTrap::~FragTrap (void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &original)
{
	std::cout << "FragTrap copy assignment operator overload function called" << std::endl;
	if (this == &original)
		return (*this);
	ClapTrap::operator=(original);
	return (*this);
}

void FragTrap::FragTrap::highFivesGuys(void)
{
	std::cout
		<< "FragTrap " << m_name
		<< " requests a high five from you guys."
		<< std::endl;
	return (showStats());
}