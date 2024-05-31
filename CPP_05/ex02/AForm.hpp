/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:42 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 12:43:21 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm (std::string name, int execLevel, int signLevel);
		AForm (AForm const &original);
		~AForm (void);

		AForm &operator=(AForm const &original);

		static const unsigned int	maxLevel = 1;
		static const unsigned int	minLevel = 150;

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSigLevel(void) const;
		unsigned int	getExecLevel(void) const;

		void			beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		AForm (void);
		std::string		m_name;
		bool			m_isSigned;
		unsigned int	m_signLevel;
		unsigned int	m_execLevel;

};

std::ostream &operator<<(std::ostream &outStream, AForm const &form);

#endif