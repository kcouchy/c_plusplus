/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:21:16 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/28 16:35:11 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

# define GRADE_MIN 150
# define GRADE_MAX 1

class Bureaucrat
{
	public:
		Bureaucrat (void);
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat (const Bureaucrat &original);
		~Bureaucrat (void);

		Bureaucrat &operator=(Bureaucrat const &original);

		std::string		getName(void)const;
		unsigned int	getGrade(void)const;

		void	incrementGrade(void);
		void	decrementGrade(void);

	private:
		std::string		m_name;
		unsigned int	m_grade;

};

std::ostream	&operator<<(std::ostream &outStream, Bureaucrat const &bureaucrat);

#endif
