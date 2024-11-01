/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:06:35 by kcouchma          #+#    #+#             */
/*   Updated: 2024/10/29 14:17:20 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of input arguments" << std::endl
                << "try: ./btc <input_file>" << std::endl;
        return (EXIT_FAILURE);
    }
    
    BitcoinExchange converter;
    if (converter.load_data(INPUT_DB_NAME, ',') == false)
        return (EXIT_FAILURE);
    return (converter.load_data(argv[1], '|'));
}