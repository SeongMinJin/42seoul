/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatsAndDogs.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:23:10 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 11:26:07 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CatSANDDogS_HPP
#define CatSANDDogS_HPP


#include "Animal.hpp"


/* for Cat & Dog */
class Cat : public Animal
{
public:
	void makeSound( void ) const;

	Cat();
	Cat( const Cat &c );
	~Cat();
	Cat &operator=( const Cat &c );
};



class Dog : public Animal
{
public:
	void makeSound( void ) const;

	Dog();
	Dog( const Dog &d );
	~Dog();
	Dog &operator=( const Dog &d );

};






/* for wrongCat & wrongDog */
class wrongCat : public wrongAnimal
{
public:
	void makeSound( void ) const;

	wrongCat();
	wrongCat( const wrongCat &c );
	~wrongCat();
	wrongCat &operator=( const wrongCat &c );
};



class wrongDog : public wrongAnimal
{
public:
	void makeSound( void ) const;

	wrongDog();
	wrongDog( const wrongDog &d );
	~wrongDog();
	wrongDog &operator=( const wrongDog &d );
};

#endif
