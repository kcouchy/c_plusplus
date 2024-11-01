/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:51:28 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 11:13:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
    *this = o;
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &o)
{
    if (this == &o)
        return (*this);
    m_input_db = o.m_input_db;
    return (*this);
}

bool    BitcoinExchange::load_data(std::string const &input_file_name, char const &delimiter)
{
    std::ifstream   input_file;
    std::string     line;
    std::string     headers;
    std::string     _key;
    std::string     _value;

    //open input file as stream
    input_file.open(input_file_name.c_str());
	if (!input_file.is_open())
	{
		std::cerr << "Error: could not open file " << input_file_name << std::endl;
		return (false);
	}

    //read out the file, skip header(first line)
    std::getline(input_file, headers);

    // while (input_file.peek() != EOF)
    while (std::getline(input_file, line))
    {
        std::stringstream ss(line);
        std::getline(ss, _key, delimiter);
        std::getline(ss, _value);
        
        try
        {
            Date _date;
            extract_key(_key, &_date);
            if (delimiter == ',')
                m_input_db[_date] = extract_value(_value);
            else if (delimiter == '|')
                convert_and_print(&_date, extract_value(_value));
        }
        catch (const std::exception& e)
		{
			if (delimiter == ',')
            {
                std::cerr << "Error in file " << input_file_name << std::endl;
                input_file.close();
                return (false);
            }
            continue;
		}
    }

    // OPTIONAL print m_input_db
    // std::cout << headers << std::endl;
    // for(std::map<Date, float>::iterator it = m_input_db.begin(); it != m_input_db.end(); ++it)
    //     std::cout << it->first << " | " << it->second << std::endl;

    input_file.close();
    return (true);
}

void    BitcoinExchange::extract_key(std::string const _key, Date *_date)
{
    int day = -1;
    int month = -1;
    int year = -1;
    int i = 0;
    std::stringstream ss(_key);
    std::string t;

    while (std::getline(ss, t, '-'))
    {
        if (_key.find_first_not_of("0123456789- ") != _key.npos || i > 2)
        {
            std::cerr << "Error: bad input => " << _key << std::endl;
            throw std::exception();       
        }
        if (i == 0)
            year = atoi(t.c_str());
        else if (i == 1)
            month = atoi(t.c_str());
        else if (i == 2)
            day = atoi(t.c_str());
        i++;
    }

    try
    {
        (*_date).set_date(year, month, day);
    }
    catch (const std::logic_error& e)
    {
        std::cerr << e.what() << _key << std::endl;
        throw std::exception();
    }
};

float   BitcoinExchange::extract_value(std::string _value)
{
    float   _value_;
    char    *_strtod_end = NULL;

    _value_ = strtod(_value.c_str(), &_strtod_end);
    while (isspace(*_strtod_end))
        _strtod_end++;
    if (*_strtod_end != '\0')
    {
        std::cerr << "Error: bad input => " << _value << std::endl;
        throw std::exception();
    }
    return (_value_);
};

int    BitcoinExchange::convert_and_print(Date *_key, float _value)
{
    if (_value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return(EXIT_FAILURE);
    }
    if (_value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return(EXIT_FAILURE);
    }
    std::cout << *_key << " => " << _value << " = " << _value * this->findClosest(*_key) << std::endl;
    return (EXIT_SUCCESS);
}

float	BitcoinExchange::findClosest(Date const &key) const
{
	std::map<Date, float>::const_iterator it = this->m_input_db.begin();
	float	valueAtKey = 0;

    //as soon as key date is greater (more recent than) a database record, break to take the previous value
	while (it != this->m_input_db.end())
	{
		if (key < it->first)
			break;
		valueAtKey = it->second;
		it++;
	}
	return (valueAtKey);
}
