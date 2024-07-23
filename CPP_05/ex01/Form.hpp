/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:42 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/22 16:55:25 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form (std::string name, int execLevel, int signLevel);
		Form (Form const &original);
		~Form (void);

		Form &operator=(Form const &original);

		static const unsigned int	maxLevel = 1;
		static const unsigned int	minLevel = 150;

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSigLevel(void) const;
		unsigned int	getExecLevel(void) const;

		void	beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		Form (void);
		const std::string	m_name;
		bool				m_isSigned;
		const unsigned int	m_signLevel;
		const unsigned int	m_execLevel;

};

std::ostream &operator<<(std::ostream &outStream, Form const &form);

#endif