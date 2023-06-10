/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatsAndDogs.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:23:10 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:20:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CatSANDDogS_HPP
#define CatSANDDogS_HPP


#include "Animal.hpp"
#include "Brain.hpp"


/* for Cat & Dog */

class Cat : public Animal
{
private:
	Brain *brain;

public:
	void makeSound( void ) const;
	std::string getIdea( int idx ) const;
	void setIdea( int idx, std::string idea );

	Cat();
	Cat( const Cat &c );
	~Cat();
	Cat &operator=( const Cat &c );
};


class Dog : public Animal
{
private:
	Brain *brain;

public:
	void makeSound( void ) const;
	std::string getIdea( int idx ) const;
	void setIdea( int idx, std::string idea );

	Dog();
	Dog( const Dog &c );
	~Dog();
	Dog &operator=( const Dog &c );
};

#endif
