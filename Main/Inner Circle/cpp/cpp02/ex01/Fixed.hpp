/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:09:14 by seojin            #+#    #+#             */
/*   Updated: 2022/12/08 20:06:16 by seojin           ###   ########.fr       */
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

	int getRawBits( void ) const ;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;


	Fixed();
	Fixed( const int intNum );
	Fixed( const float floatNum );
	Fixed( const Fixed &f );
	~Fixed();
	

	Fixed &operator=( const Fixed &f );
};

std::ostream &operator<<( std::ostream &out , const Fixed &f );

#endif
