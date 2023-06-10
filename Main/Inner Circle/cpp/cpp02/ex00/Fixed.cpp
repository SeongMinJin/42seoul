/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:45:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 16:11:27 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* Constructors & destructor */
Fixed::Fixed() : fixedNum(0) { std::cout << "Default constructor is called." << std::endl; }
Fixed::Fixed( const Fixed &f ) : fixedNum(f.getRawBits()) { std::cout << "Copy constructor is called." << std::endl; }
Fixed::~Fixed() { std::cout << "Destructor is called." << std::endl; }

/* operator overload */
Fixed &Fixed::operator=( const Fixed &f )
{
	if (this != &f)
	{
		std::cout << "Copy assignment operator is called." << std::endl;
		this->fixedNum = f.getRawBits();
	}
	return *this;
}



/* public member functions */
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits function is called." << std::endl;
	return fixedNum;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits function is called." << std::endl;
	this->fixedNum = raw;
}
