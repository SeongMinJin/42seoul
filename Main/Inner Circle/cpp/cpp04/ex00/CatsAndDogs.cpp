/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatsAndDogs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:23:38 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:16:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatsAndDogs.hpp"



/* for Cat */
Cat::Cat() : Animal( "Cat" ) { std::cout << "Cat default constructor is called." << std::endl; }
Cat::Cat( const Cat &c ) : Animal( c.getType() ) { std::cout << "Cat copy constructor is called." << std::endl; }
Cat::~Cat() { std::cout << "Cat destructor is called." << std::endl; }

Cat &Cat::operator=( const Cat &c )
{
	if (this != &c)
	{
		std::cout << "Cat copy assignment is called." << std::endl;
		Animal::type = c.getType();
	}
	return *this;
}
void Cat::makeSound( void ) const { std::cout << "Meow..." << std::endl; }




/* for Dog */
Dog::Dog() : Animal( "Dog" ) { std::cout << "Dog default constructor is called." << std::endl; }
Dog::Dog( const Dog &d ) : Animal( d.getType() ) { std::cout << "Dog copy constructor is called." << std::endl; }
Dog::~Dog() { std::cout << "Dog destructor is called." << std::endl; }

Dog &Dog::operator=( const Dog &d )
{
	if (this != &d)
	{
		std::cout << "Dog copy assignment is called." << std::endl;
		this->type =d.getType();
	}
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "Wow Wow!" << std::endl; }



/* for wrongCat */
wrongCat::wrongCat() : wrongAnimal( "wrongCat" ) { std::cout << "wrongCat constructor is called." << std::endl; }
wrongCat::wrongCat( const wrongCat &c ) : wrongAnimal( c.getType() ) { std::cout << "wrongCat copy constructor is called." << std::endl; }
wrongCat::~wrongCat() { std::cout << "wrongCat destructor is called." << std::endl; }

wrongCat &wrongCat::operator=( const wrongCat &c )
{
	if (this != &c)
	{
		std::cout << "wrongCat copy assignment is called." << std::endl;
		wrongAnimal::type = c.getType();
	}
	return *this;
}

void wrongCat::makeSound( void ) const { std::cout << "Meow..." << std::endl; }




/* for wrongDog */
wrongDog::wrongDog() : wrongAnimal( "worngCat" ) { std::cout << "wrongDog constructor is called." << std::endl; }
wrongDog::wrongDog( const wrongDog &c ) : wrongAnimal( c.getType() ) { std::cout << "wrongDog copy constructor is called." << std::endl; }
wrongDog::~wrongDog() { std::cout << "wrongDog destructor is called." << std::endl; }

wrongDog &wrongDog::operator=( const wrongDog &c )
{
	if (this != &c)
	{
		std::cout << "wrongDog copy assignment is called." << std::endl;
		wrongAnimal::type =c.getType();
	}
	return *this;
}

void wrongDog::makeSound( void ) const { std::cout << "Wow Wow!" << std::endl; }






