/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:17 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:51:54 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatsAndDogs.hpp"

int main()
{
	// Animal animal;
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	cat->makeSound();
	dog->makeSound();

	return 0;
}