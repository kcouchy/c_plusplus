/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:42:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:55 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Subject main" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;

	const A_Animal* meta = new A_Animal();
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Wrong section" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;

	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;

	k->makeSound();
	w->makeSound();

	delete k;
	delete w;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Custom main" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
	A_Animal	a;
	Cat		c;
	Dog		d;

	a.makeSound();
	c.makeSound();
	d.makeSound();

	return (0);
}