/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:17 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:32:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatsAndDogs.hpp"

int main()
{
	Animal *animals[2];

	/* Cat Test */
	animals[0] = new Cat();
	animals[0]->makeSound();
	std::cout << animals[0]->getIdea(5) << std::endl;
	animals[0]->setIdea(5, "Sam Gyeop Sal...");
	std::cout << animals[0]->getIdea(5) << std::endl;
	std::cout << "================================" << std::endl;
	{
		Cat catA, catB;
		std::cout << "================================" << std::endl;

		catA.setIdea(27, "Hungry....");
		catB = catA;
		std::cout << "================================" << std::endl;
		std::cout << "catA's brain:" << catA.getIdea(27) << std::endl;
		std::cout << "catB's brain:" << catB.getIdea(27) << std::endl;
		std::cout << "================================" << std::endl;
		Cat catC(catA);
		std::cout << "catC's brain:" << catC.getIdea(27) << std::endl;
		std::cout << "================================" << std::endl;
	}

	std::cout << "================================" << std::endl;

	/* Dog Test */
	animals[1] = new Dog();
	animals[1]->makeSound();
	std::cout << animals[1]->getIdea(42) << std::endl;
	animals[1]->setIdea(42, "Sleepy...");
	std::cout << animals[1]->getIdea(42) << std::endl;
	


	std::cout << "================================" << std::endl;
	delete animals[0];
	delete animals[1];
	system("leaks $PPID");
	return 0;
}