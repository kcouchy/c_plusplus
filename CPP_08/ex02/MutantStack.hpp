/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:45:39 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/14 15:51:54 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const & original);
		~MutantStack(void);

		MutantStack &operator=(MutantStack const &original);

		typedef typename Container::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif