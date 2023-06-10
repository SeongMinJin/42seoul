/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:09:35 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 11:28:39 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{

protected:
	std::string type;

public:

	virtual std::string getType( void ) const;
	virtual void makeSound( void ) const;

	Animal();
	Animal( std::string type );
	Animal( const Animal &animal );
	virtual ~Animal();
	Animal &operator=( const Animal &animal );
};

class wrongAnimal
{

protected:
	std::string type;

public:

	std::string getType( void ) const;
	void makeSound( void ) const;

	wrongAnimal();
	wrongAnimal( std::string type );
	wrongAnimal( const wrongAnimal &wrongAnimal );
	~wrongAnimal();


	wrongAnimal &operator=( const wrongAnimal &wrongAnimal );

};


#endif
