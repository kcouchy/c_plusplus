/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:48:17 by kcouchma          #+#    #+#             */
/*   Updated: 2024/04/30 16:57:33 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class Phonebook
{
	public:

		Phonebook(void);
		~Phonebook(void);

		Contact		*getContact(int index);

	private:

		Contact		m_contacts[8];

};

#endif