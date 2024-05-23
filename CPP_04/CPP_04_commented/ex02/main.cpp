/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:42:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:23:13 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NUMBER_ANIMALS 10

int	main(void)
{
	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Subject main" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;

	const A_Animal* i = new Cat();
	const A_Animal* j = new Dog();

	delete i;
	delete j;
	
	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Loop for Animal array" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;

	A_Animal* k[NUMBER_ANIMALS];

	for (int index = 0; index < NUMBER_ANIMALS ; index++)
	{
		if (index < 5)
			k[index] = new Cat();
		else if (index >= 5)
			k[index] = new Dog();
	}
	
	k[0]->makeSound();
	k[NUMBER_ANIMALS - 1]->makeSound();

	for (int index = 0; index < NUMBER_ANIMALS; index++)
		delete k[index];

	// std::cout << std::endl << "----------------------------------" << std::endl;
	// std::cout << "Attempt to instantiate Animal" << std::endl;
	// std::cout << "----------------------------------" << std::endl << std::endl;
	// A_Animal nope;
	
	return (0);
}
