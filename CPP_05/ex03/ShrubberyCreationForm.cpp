/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:42:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 14:20:17 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* Constructors/Destructors                                                   */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation", SHRUB_SIGN, SHRUB_EXEC),
	m_target("home")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation", SHRUB_SIGN, SHRUB_EXEC),
	m_target(target)
{
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &original):
	AForm("Shrubbery Creation", SHRUB_SIGN, SHRUB_EXEC)
{
	*this = original;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

/******************************************************************************/
/* Member function operator overload                                          */
/******************************************************************************/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &original)
{
	if (this != &original)
		m_target = original.getTarget();
	return (*this);
}

/******************************************************************************/
/* Member functions                                                           */
/******************************************************************************/

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (m_target);
}

void		ShrubberyCreationForm::_execute(Bureaucrat const & executor) const
{
	std::string outname = m_target + "_shrubbery";
	std::ofstream outfile;
	outfile.open(outname.c_str(), std::ios::app);

	if (outfile.is_open())
	{
		outfile
			<< std::endl
			<< "          &&& &&  & &&" << std::endl
			<< "      && &\\/&\\|& ()|/ @, &&" << std::endl
			<< "      &\\/(/&/&||/& /_/)_&/_&" << std::endl
			<< "   &() &\\/&|()|/&\\/ '% & ()" << std::endl
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
			<< "&&   && & &| &| /& & % ()& /&&" << std::endl
			<< " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
			<< "     &&     \\|||" << std::endl
			<< "             |||" << std::endl
			<< "       , -=-~  .-^- _" << std::endl;
		outfile.close();
	}
	else
	{
		std::cout << "cannot open output file "
		<< m_target << "_shrubbery"
		<< std::endl;
	}
	return;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	return;
}
