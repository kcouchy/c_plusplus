/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:06:38 by kcouchma          #+#    #+#             */
/*   Updated: 2024/08/14 17:29:45 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span : protected std::vector<int>
{
	public:
		Span(void);
		Span(unsigned int max);
		Span(Span const &original);
		~Span(void);

		Span &operator=(Span const &original);

		void	addNumber(int number);
		int		shortestSpan(void)const;
		int		longestSpan(void)const;
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	private:
		unsigned int	m_max;
};

#endif