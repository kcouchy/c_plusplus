/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:41:58 by kcouchma          #+#    #+#             */
/*   Updated: 2024/10/29 17:53:56 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl
            << "Wrong number of input arguments" << std::endl
            << "try: ./RPN \"input expression\"" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        RPN calculator;
        std::cout << calculator.calculate(argv[1]) << std::endl;
    }
    catch (const std::logic_error& e)
    {
        std::cerr << "Error" << std::endl << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}