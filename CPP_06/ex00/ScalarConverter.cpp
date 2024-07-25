/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:30:25 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/25 17:26:12 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//TODO handle nans and infs, float limits

void	ScalarConverter::convert(std::string input)
{
	char	c;
	int		i;
	float	f;
	double	d;
	bool	unknown_type = false;

	switch (ScalarConverter::detect_type(input))
	{
		case CHAR_T:
			c = input[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;

		case INT_T:
			i = ft_atoi(input);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;

		case FLOAT_T:
			f = std::atof(input.c_str());
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;

		case DOUBLE_T:
			d = std::atof(input.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;

		default:
			unknown_type = true;
	}
	if (unknown_type == true)
		printImpossible();
	else
	{
		std::cout << "char: ";
		if (i > 127 || i < 0)
			std::cout << "impossible" << std::endl;
		else if (isprint(c) == false)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;

		std::cout << "int: ";
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d!=d)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;

		std::cout << "float: " << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;

		std::cout << "double: " << d << std::endl;
	}
}

int		ScalarConverter::detect_type(std::string input)
{
	int	i = 0;

	bool	(*aled[COUNT_T])(std::string) = 
	{
		isCharType,
		isIntType,
		isFloatType,
		isDoubleType,
	};
	for (; i < COUNT_T; i++)
	{
		if ((*aled[i])(input) == true)
			break ;
	}
	return (i);
}

bool	ScalarConverter::isCharType(std::string input)
{
	if (input.length() != 1 || std::isdigit(input[0]))
		return (false);
	return (true);
}

long	ScalarConverter::ft_atoi(std::string input)
{
	long	output = 0;
	bool	is_neg = false;

	std::string::iterator iter = input.begin();
	for (; std::isspace(*iter); iter++)
		;
	if ((*iter) == '-')
		is_neg = true;
	if ((*iter) == '-' || (*iter) == '+')
		iter++;
	for (; iter != input.end(); iter++)
	{
		if (std::isdigit(*iter) == false)
			return (ATOI_ERROR);
		output *= 10;
		output += static_cast<char>(*iter) - '0';
		if ((is_neg == false && output > std::numeric_limits<int>::max())
			|| (is_neg == true && output < std::numeric_limits<int>::min()))
			return (ATOI_ERROR);
	}
	return (is_neg ? -output : output);
}

bool	ScalarConverter::isIntType(std::string input)
{
	if (input.length() > 0 && input.find_first_not_of("+-0123456789") == input.npos)
	{
		if (ft_atoi(input) != ATOI_ERROR)
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloatType(std::string input)
{
	if (isDoubleType(input) == true)
	{
		double check = std::atof(input.c_str());
		if (check <= std::numeric_limits<float>::max() && check >= -(std::numeric_limits<float>::max()))
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isDoubleType(std::string input)
{
	if (input.length() <= 0)
		return (false);
	std::string::iterator iter = input.begin();
	for (; std::isspace(*iter); iter++)
		;
	if (*iter == '-' || *iter == '+')
		iter++;
	size_t pos = iter - input.begin();
	if (input.compare(pos, input.length()-pos, "nan") == 0 || input.compare(pos, input.length()-pos, "inf") == 0)
		return (true);
	if (input.find_first_not_of(".0123456789", pos) != input.npos)
		return (false);
	if (input.find_first_of(".", pos) != input.find_last_of(".", input.length()))
		return (false);
	return (true);
}

void	ScalarConverter::printImpossible()
{
	std::cout
		<< "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
}