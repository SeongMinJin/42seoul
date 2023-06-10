/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:09:35 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:11:30 by seojin           ###   ########.fr       */
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

	std::string getType( void ) const;
	virtual void makeSound( void ) const;
	virtual std::string getIdea( int idx ) const;
	virtual void setIdea( int idx, std::string idea );

	Animal();
	Animal( std::string type );
	Animal( const Animal &animal );
	virtual ~Animal();
	Animal &operator=( const Animal &animal );
};

#endif
