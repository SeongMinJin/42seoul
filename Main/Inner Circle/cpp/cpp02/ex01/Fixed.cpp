/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:45:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 13:16:00 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors & Destructor */
Fixed::Fixed() : fixedNum(0)
{
	std::cout << "Default constructor is called." << std::endl;
}
Fixed::Fixed( const int intNum ) : fixedNum(intNum << fractionalBit)
{
	std::cout << "Int constructor is called." << std::endl;
}
Fixed::Fixed( const float floatNum ) : fixedNum(roundf(floatNum * 256))
{
	std::cout << "Float constructor is called." << std::endl;
}
Fixed::Fixed( const Fixed &f ) : fixedNum(f.getRawBits())
{
	std::cout << "Copy constructor is called." << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor is called." << std::endl;
}



/* operator oveload */
Fixed &Fixed::operator=( const Fixed &f )
{
	if (this != &f)
	{
		this->fixedNum = f.getRawBits();
		std::cout << "Copy assignment operator is called." << std::endl;
	}
	return *this; 
}
std::ostream &operator<<( std::ostream &out, const Fixed &f )
{
	out << f.toFloat();
	return (out);
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
int Fixed::toInt( void ) const
{
	return (this->fixedNum >> 8);
}
float Fixed::toFloat( void ) const
{
	float _f = (float)this->fixedNum;
	return (_f / 256);
}
