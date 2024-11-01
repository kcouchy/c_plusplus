/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:51:24 by kcouchma          #+#    #+#             */
/*   Updated: 2024/10/29 14:07:34 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <limits>
#include <string>

#include "Date.hpp"

#define INPUT_DB_NAME "data.csv"

class Date;

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);

        bool    load_data(std::string const &input_file_name, char const &delimiter);
        int     convert_and_print(Date *_key, float _value);
        void    extract_key(std::string const _key, Date *_date);
        float   extract_value(std::string _value);
        float	findClosest(Date const &key) const;

    private:
        BitcoinExchange(BitcoinExchange const &o);
        BitcoinExchange &operator=(BitcoinExchange const &o);
        
        std::map<Date, float> m_input_db;
};

