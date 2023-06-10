/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:09:14 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 21:02:58 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

private:

	int fixedNum;
	static const int fractionalBit = 8;



public:

	int getFixedNum( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;



	Fixed();
	Fixed( const int intNum );
	Fixed( const float floatNum );
	Fixed( const Fixed &f );
	~Fixed();
	
	Fixed &operator=( const Fixed &f );
	bool operator==( const Fixed &f ) const;
	bool operator!=( const Fixed &f ) const;
	bool operator>=( const Fixed &f ) const;
	bool operator<=( const Fixed &f ) const;
	bool operator>( const Fixed &f ) const;
	bool operator<( const Fixed &f ) const;

	Fixed operator+( const Fixed &f ) const;
	Fixed operator-( const Fixed &f ) const;
	Fixed operator*( const Fixed &f ) const;
	Fixed operator/( const Fixed &f ) const;

	Fixed &operator++( void );
	Fixed operator++( int );
	Fixed &operator--( void );
	Fixed operator--( int );

	static Fixed &min( Fixed &a, Fixed &b );
	static const Fixed &min( const Fixed &a, const Fixed &b );
	static Fixed &max( Fixed &a, Fixed &b );
	static const Fixed &max( const Fixed &a, const Fixed &b );

};

std::ostream &operator<<( std::ostream &out , const Fixed &f );

#endif
