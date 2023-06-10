/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatsAndDogs.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:23:38 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:32:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatsAndDogs.hpp"




/* for Cat */
Cat::Cat() : Animal( "Cat" ) { brain = new Brain(); std::cout << "Cat default constructor is called." << std::endl; }
Cat::Cat( const Cat &c ) : Animal( c.getType() )
{
	brain = new Brain();

	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, c.brain->getIdea(i));
	this->type = c.getType();
	std::cout << "Cat copy constructor is called." << std::endl;
}
Cat::~Cat() { delete this->brain; std::cout << "Cat destructor is called." << std::endl; }

Cat &Cat::operator=( const Cat &c )
{
	if (this != &c)
	{
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, c.brain->getIdea(i));
		std::cout << "Cat copy assignment is called." << std::endl;
		this->type = c.getType();
	}
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "Meow..." << std::endl; }
std::string Cat::getIdea( int idx ) const
{
	if (idx < 0 || idx > 100)
		return "Error: Invalid brain index.";
	else
		return this->brain->getIdea( idx );
}
void Cat::setIdea( int idx, std::string idea )
{
	if (idx < 0 || idx > 100)
		std::cout << "Error: Invalid brain index." << std::endl;
	else
		this->brain->setIdea( idx, idea );
}



/* for Dog */
Dog::Dog() : Animal( "Dog" ) { brain = new Brain(); std::cout << "Dog default constructor is called." << std::endl; }
Dog::Dog( const Dog &c ) : Animal( c.getType() )
{
	brain = new Brain();

	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, c.brain->getIdea(i));
	this->type = c.getType();
	std::cout << "Dog copy constructor is called." << std::endl;
}
Dog::~Dog() { delete this->brain; std::cout << "Dog destructor is called." << std::endl; }

Dog &Dog::operator=( const Dog &c )
{
	if (this != &c)
	{
		for (int i = 0; i < 100; i++)
			this->brain->setIdea(i, c.brain->getIdea(i));
		std::cout << "Dog copy assignment is called." << std::endl;
		this->type = c.getType();
	}
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "WoW! WoW!" << std::endl; }
std::string Dog::getIdea( int idx ) const
{
	if (idx < 0 || idx > 100)
		return "Error: Invalid brain index.";
	else
		return this->brain->getIdea( idx );
}
void Dog::setIdea( int idx, std::string idea )
{
	if (idx < 0 || idx > 100)
		std::cout << "Error: Invalid brain index." << std::endl;
	else
		this->brain->setIdea( idx, idea );
}



