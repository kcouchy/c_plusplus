/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:14:30 by kcouchma          #+#    #+#             */
/*   Updated: 2024/11/01 10:58:57 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

void	print_output(std::vector<unsigned int> &input, 
	std::vector<unsigned int> &sorted_vector,
	std::deque<unsigned int> &sorted_deque,
	long time_vector, long time_deque, int argc)
{
	std::cout	<< "Before:\t\t" << input << std::endl
				<< "After (v):\t" << sorted_vector << std::endl
				<< "After (d):\t" << sorted_deque << std::endl
				<< "Time to process a range of " << argc - 1 << " elements with std::vector:  " 
				<< time_vector * 1000 << "µs" << std::endl
				<< "Time to process a range of " << argc - 1 << " elements with std::deque:   " 
				<< time_deque * 1000 << "µs" << std::endl;
}

int	main(int argc, char **argv)
{
	struct timespec time1, time2, time3, time4;
	long time_vector, time_deque;
	std::vector<unsigned int>	vector_before;
	std::vector<unsigned int>	sorted_vector;
	std::deque<unsigned int>	sorted_deque;

	clock_gettime(CLOCK_REALTIME, &time1);

	try
	{
		PmergeMe	hehe(argc, argv);

		vector_before = hehe.getVecBefore();
		clock_gettime(CLOCK_REALTIME, &time2);

		sorted_vector = hehe.vectorFordJohnson();
		clock_gettime(CLOCK_REALTIME, &time3);

		sorted_deque = hehe.dequeFordJohnson();
		clock_gettime(CLOCK_REALTIME, &time4);

		time_vector = time3.tv_nsec - time1.tv_nsec;
		time_deque = (time4.tv_nsec - time3.tv_nsec) + (time2.tv_nsec - time1.tv_nsec);

		print_output(vector_before, sorted_vector, sorted_deque, time_vector, time_deque, argc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
