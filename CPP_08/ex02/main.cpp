/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:45:08 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/14 16:18:34 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "-------------------MutantStack int version-------------------" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "----------------MutantStack std::list version----------------" << std::endl;

	MutantStack<std::string, std::list<std::string> > mlstack;
	mlstack.push("five");
	mlstack.push("seventeen");
	std::cout << mlstack.top() << std::endl;
	mlstack.pop();
	std::cout << mlstack.size() << std::endl;
	mlstack.push("three");
	mlstack.push("five");
	mlstack.push("seven hundred and thirty-seven");
	//[...]
	mlstack.push("zero");
	MutantStack<std::string, std::list<std::string> >::iterator it2 = mlstack.begin();
	MutantStack<std::string, std::list<std::string> >::iterator ite2 = mlstack.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<std::string, std::list<std::string> > ls(mlstack);

	std::cout << "----------------------std::list version----------------------" << std::endl;

	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	MutantStack<int, std::list<int> >::iterator it3 = lstack.begin();
	MutantStack<int, std::list<int> >::iterator ite3 = lstack.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::stack<int, std::list<int> > l(lstack);

	return 0;
}