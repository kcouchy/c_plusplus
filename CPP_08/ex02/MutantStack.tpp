/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:00:15 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/14 15:57:08 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, class Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack const & original)
{
	*this = original;
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &original)
{
	std::stack<T, Container>::operator=(original);
	return (*this);
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}
