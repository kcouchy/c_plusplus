/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:42:04 by kcouchma          #+#    #+#             */
/*   Updated: 2024/05/21 13:20:05 by kcouchma         ###   ########.fr       */
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

	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Wrong section" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;

	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	WrongCat l = WrongCat();
	const WrongCat* m = new WrongCat();

	std::cout << w->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l.getType() << " " << std::endl;
	std::cout << m->getType() << " " << std::endl;

	w->makeSound();
	k->makeSound();
	l.makeSound();
	m->makeSound();

	delete w;
	delete k;
	delete m;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "Custom main" << std::endl;
	std::cout << "----------------------------------" << std::endl << std::endl;
	Animal	a;
	Cat		c;
	Dog		d;

	a.makeSound();
	c.makeSound();
	d.makeSound();

	return (0);
}