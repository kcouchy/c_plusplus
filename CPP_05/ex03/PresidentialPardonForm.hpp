/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:59:05 by kcouchma          #+#    #+#             */
/*   Updated: 2024/06/03 17:14:47 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define PRES_SIGN 25
# define PRES_EXEC 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &original);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &original);
		~PresidentialPardonForm(void);

		std::string	getTarget(void)const;

	private:
		PresidentialPardonForm(void);

		void	_execute(Bureaucrat const & executor)const;

		std::string m_target;
};

#endif