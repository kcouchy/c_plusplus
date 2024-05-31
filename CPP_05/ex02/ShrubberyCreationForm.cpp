/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:42:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 15:57:27 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//TODO FINISH THE CPP CREATION OF SHRUBBERY

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation Form", 145, 137),
	m_target("home")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation Form", 145, 137),
	m_target(target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}
