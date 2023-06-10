/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:45:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 21:03:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors & Destructor */
Fixed::Fixed() : fixedNum(0) {}
Fixed::Fixed( const int intNum ) : fixedNum(intNum << fractionalBit) {}
Fixed::Fixed( const float floatNum ) : fixedNum(roundf(floatNum * 256)) {}
Fixed::Fixed( const Fixed &f ) : fixedNum(f.getRawBits()) {}
Fixed::~Fixed() {}



/* operator oveload */
Fixed &Fixed::operator=( const Fixed &f )
{
	if (this != &f)
		this->fixedNum = f.getRawBits();
	return *this; 
}

std::ostream &operator<<( std::ostream &out, const Fixed &f )
{
	out << f.toFloat();
	return (out);
}

bool Fixed::operator==( const Fixed &f ) const { return ((this->getFixedNum() == f.getFixedNum())); }
bool Fixed::operator!=( const Fixed &f ) const { return ((this->getFixedNum() != f.getFixedNum())); }
bool Fixed::operator>=( const Fixed &f ) const { return ((this->getFixedNum() >= f.getFixedNum())); }
bool Fixed::operator<=( const Fixed &f ) const { return ((this->getFixedNum() <= f.getFixedNum())); }
bool Fixed::operator>( const Fixed &f ) const { return ((this->getFixedNum() > f.getFixedNum())); }
bool Fixed::operator<( const Fixed &f ) const { return ((this->getFixedNum() < f.getFixedNum())); }

Fixed Fixed::operator+( const Fixed &f )const 
{
	if (this->getFixedNum() & 255 || f.getFixedNum() & 255)
		return (Fixed(this->toFloat() + f.toFloat()));
	else
		return (Fixed(this->toInt() + f.toInt()));
}

Fixed Fixed::operator-( const Fixed &f )const 
{
	if (this->getFixedNum() & 255 || f.getFixedNum() & 255)
		return (Fixed(this->toFloat() - f.toFloat()));
	else
		return (Fixed(this->toInt() - f.toInt()));
}

Fixed Fixed::operator*( const Fixed &f )const 
{
	if (this->getFixedNum() & 255 || f.getFixedNum() & 255)
		return (Fixed(this->toFloat() * f.toFloat()));
	else
		return (Fixed(this->toInt() * f.toInt()));
}

Fixed Fixed::operator/( const Fixed &f )const 
{
	if (this->getFixedNum() & 255 || f.getFixedNum() & 255)
		return (Fixed(this->toFloat() / f.toFloat()));
	else
		return (Fixed(this->toInt() / f.toInt()));
}


Fixed &Fixed::operator++( void ) { this->fixedNum += 1; return *this; }
Fixed Fixed::operator++( int ) { Fixed tmp; tmp.setRawBits(this->getRawBits()); this->fixedNum += 1; return tmp; }
Fixed &Fixed::operator--( void ) { this->fixedNum -= 1; return *this; }
Fixed Fixed::operator--( int ) { Fixed tmp; tmp.setRawBits(this->getRawBits()); this->fixedNum -= 1; return tmp; }



/* public member functions */
int Fixed::getFixedNum( void ) const { return this->fixedNum; }

int Fixed::getRawBits( void ) const
{
	return fixedNum;
}

void Fixed::setRawBits( int const raw )
{
	this->fixedNum = raw;
}

int Fixed::toInt( void ) const { return (this->fixedNum >> 8); }
float Fixed::toFloat( void ) const
{
	float _f = (float)this->fixedNum;
	return (_f / 256);
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a > b)
		return b;
	else
		return a;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b )
{
	if (a.fixedNum > b.fixedNum)
		return b;
	else
		return a;
}

Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a.fixedNum > b.fixedNum)
		return a;
	else
		return b;
}
