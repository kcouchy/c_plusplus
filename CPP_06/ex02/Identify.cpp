/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:50 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/29 11:39:29 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base* generate(void)
{
	Base *rando;

	int random = std::rand();
	if (random % 3 == 0)
		rando = new A;
	else if (random % 3 == 1)
		rando = new B;
	else
		rando = new C;
	return (rando);
}

void identify(Base* p)
{
	std::cout << "Identify pointer type: ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A-type" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B-type" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C-type" << std::endl;
	else
		std::cout << "wtf" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Identify reference type: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A-type" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B-type" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C-type" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{}
	std::cout << "wtf" << std::endl;
}