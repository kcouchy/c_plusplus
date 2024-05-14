/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:17:37 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/01 14:02:52 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string 			str;
	std::string::iterator	it;
	std::string				toprint;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1 && argv)
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (it = str.begin(); it != str.end(); ++it)
				toprint += std::toupper(*it);
		}
		std::cout << toprint;
	}
	std::cout << std::endl;
	return (0);
}
