/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:41:27 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 12:19:35 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <exception>

#include <cctype>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(RPN const &o);
		~RPN();

        RPN	&operator=(RPN const &o);

		long long calculate(std::string const &input);

	private:
		std::stack<long long>	m_stack;

};