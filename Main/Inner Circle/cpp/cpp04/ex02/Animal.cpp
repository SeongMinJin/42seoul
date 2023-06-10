/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:08:35 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:47:30 by seojin           ###   ########.fr       */
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
