/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:17 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:49:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatsAndDogs.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "=====================================" << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << "=====================================" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();


	std::cout << "=====================================" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	std::cout << "=====================================" << std::endl;



	const wrongAnimal *wrong = new wrongAnimal();
	const wrongAnimal *a = new wrongDog();
	const wrongAnimal *b = new wrongCat();

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;
	wrong->makeSound();
	a->makeSound();
	b->makeSound();

	delete wrong;
	delete a;
	delete b;
	std::cout << "=====================================" << std::endl;

	
	return 0;
}