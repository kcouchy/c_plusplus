/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:42 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 18:29:57 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define WHITE	"\e[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm (std::string name, int execLevel, int signLevel);
		AForm (AForm const &original);
		virtual ~AForm (void);

		AForm &operator=(AForm const &original);

		static const unsigned int	maxLevel = 1;
		static const unsigned int	minLevel = 150;

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSigLevel(void) const;
		unsigned int	getExecLevel(void) const;

		void			beSigned(Bureaucrat const &bureaucrat);
		void			execute(Bureaucrat const & executor) const;
	
	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

	protected:
		virtual void	_execute(Bureaucrat const & executor) const = 0;

	private:
		AForm (void);
		const std::string	m_name;
		bool				m_isSigned;
		const unsigned int	m_signLevel;
		const unsigned int	m_execLevel;

};

std::ostream &operator<<(std::ostream &outStream, AForm const &form);

#endif