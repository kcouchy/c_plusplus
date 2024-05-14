/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:10:19 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/02 16:55:10 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string hi = "HI THIS IS BRAIN";
	std::string	*hip = &hi;
	std::string &hir = hi;

	std::cout
		<< &hi << std::endl
		<< hip << std::endl
		<< &hir << std::endl;

	std::cout
		<< hi << std::endl
		<< *hip << std::endl
		<< hir << std::endl;

	return (0);
}