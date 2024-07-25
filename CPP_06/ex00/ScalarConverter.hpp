/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:30:27 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/25 17:26:27 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

#define	ATOI_ERROR std::numeric_limits<long>::max()

class ScalarConverter
{
	public:
		static void	convert(std::string input);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &original);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &original);

		typedef enum e_type
		{
			CHAR_T,
			INT_T,
			FLOAT_T,
			DOUBLE_T,
			COUNT_T,
		}	type_t;

		static int		detect_type(std::string input);
		static bool		isCharType(std::string input);
		static bool		isIntType(std::string input);
		static bool		isFloatType(std::string input);
		static bool		isDoubleType(std::string input);
		static long		ft_atoi(std::string input);
		static void		printImpossible(void);
};

#endif