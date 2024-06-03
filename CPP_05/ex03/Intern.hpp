/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:40:18 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 18:21:31 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern (void);
		Intern (Intern const &original);
		~Intern (void);

		Intern &operator=(Intern const &original);

		AForm *makeForm(std::string form_name, std::string target);

	private:
		static AForm*	createShrubberyCreationForm(std::string const& target);
		static AForm*	createRobotomyRequestForm(std::string const& target);
		static AForm*	createPresidentialPardonForm(std::string const& target);
};

#endif