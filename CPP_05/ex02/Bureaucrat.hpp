/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/31 12:38:09 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat (const Bureaucrat &original);
		~Bureaucrat (void);

		Bureaucrat &operator=(Bureaucrat const &original);

		static const unsigned int	grade_min = 150;
		static const unsigned int	grade_max = 1;

		std::string		getName(void)const;
		unsigned int	getGrade(void)const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm &form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	private:
		Bureaucrat (void);

		std::string		m_name;
		unsigned int	m_grade;

};

std::ostream	&operator<<(std::ostream &outStream, Bureaucrat const &bureaucrat);

#endif
