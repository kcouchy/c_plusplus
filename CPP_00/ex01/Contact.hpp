/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:08:29 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/01 14:13:11 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>	// std::string
# include <iomanip>		// std::setw

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		void	displaySearch(int mode)const;
		void	truncateDisplay(std::string field)const;

		int		getContactNumber(void)const;
		void	setContactNumber(void);

		void	setFirstName(std::string value);
		void	setLastName(std::string value);
		void	setNickname(std::string value);
		void	setPhoneNumber(std::string value);
		void	setSecret(std::string value);

	private:
	
		static int	contact_number;

		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;

};

#endif