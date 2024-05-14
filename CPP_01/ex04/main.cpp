/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:30:08 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/08 16:03:03 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>	// redirect input/output streams
#include <cstring>	// conversion to cstring

int	ft_checkinputs(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout
			<< "invalid input, try:"
			<< std::endl
			<< "./sed <filename> search_string replace_string"
			<< std::endl;
		return (1);
	}
	if (std::string (argv[2]).compare("") == 0)
	{
		std::cout
			<< "invalid search string"
			<< std::endl;
		return (1);
	}
	return (0);
}

static bool	_open_files(std::string inname, 
						std::string outname, 
						std::ifstream &infile,
						std::ofstream &outfile)
{
	infile.open(inname.c_str());
	if (infile.good() == false)
	{
		std::cout << "input file: open fail" << std::endl;
		return (1);
	}
	outfile.open(outname.c_str());
	if (outfile.good() == false)
	{
		std::cout << "output file: open fail" << std::endl;
		infile.close();
		return (1);
	}
	return (0);
}

static void _replace_str(std::string find_str,
							std::string replace_str,
							std::ifstream &infile,
							std::ofstream &outfile)
{
	std::string	buffer;
	std::size_t	pos = 0;
	std::size_t find_len = find_str.length();

	std::getline(infile, buffer, '\0');
	while (1)
	{
		pos = buffer.find(find_str);
		if (pos > buffer.length())
			break;
		buffer.erase(pos, find_len);
		buffer.insert(pos, replace_str);
	}
	outfile << buffer;
	return ;
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (ft_checkinputs(argc, argv) != 0)
		return (1);
	if (_open_files(argv[1], std::string(argv[1]) + ".replace", infile, outfile) != 0)
		return (1);
	_replace_str(argv[2], argv[3], infile, outfile);
	infile.close();
	outfile.close();
	return (0);
}