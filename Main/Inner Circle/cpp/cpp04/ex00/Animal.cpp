/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:08:35 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:17:07 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


/* for Animal */
Animal::Animal() : type("Nobody") { std::cout << "Animal default constructor is called." << std::endl; }
Animal::Animal( std::string type ) : type(type) { std::cout << "Animal string constructor is called." << std::endl; }
Animal::Animal( const Animal &animal ) : type(animal.getType()) { std::cout << "Animal copy constructor is called." << std::endl; }
Animal::~Animal() { std::cout << "Animall destructor is called." << std::endl; }
Animal &Animal::operator=( const Animal &animal )
{
	if (this != &animal)
	{
		this->type = animal.getType();
		std::cout << "Animal copy assingnment is called." << std::endl;
	}
	return *this;
}
std::string Animal::getType( void ) const { return this->type; }
void Animal::makeSound( void ) const { std::cout << "I have no specific sound..." << std::endl; }





/* for wrongAnimal */
wrongAnimal::wrongAnimal() : type("Nobody") { std::cout << "wrongAnimal constructor is called." << std::endl; }
wrongAnimal::wrongAnimal( std::string type ) : type(type) { std::cout << "wrongAnimal string constructor is called." << std::endl; }
wrongAnimal::wrongAnimal( const wrongAnimal &wrongAnimal ) : type(wrongAnimal.getType()) { std::cout << "wrongAnimal copy constructor is called." << std::endl; }
wrongAnimal::~wrongAnimal() { std::cout << "wrongAnimall destructor is called." << std::endl; }
wrongAnimal &wrongAnimal::operator=( const wrongAnimal &wrongAnimal )
{
	if (this != &wrongAnimal)
	{
		this->type = wrongAnimal.getType();
		std::cout << "wrongAnimal copy assingnment is called." << std::endl;
	}
	return *this;
}
std::string wrongAnimal::getType( void ) const { return this->type; }
void wrongAnimal::makeSound( void ) const { std::cout << "I have no specific sound..." << std::endl; }
