/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:09:14 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 16:10:56 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

private:

	int fixedNum;
	static const int fractionalBit = 8;



public:

	int getRawBits( void ) const ;
	void setRawBits( int const raw );

	Fixed();
	Fixed( const Fixed &f );

	Fixed &operator = ( const Fixed &f );

	~Fixed();


};

#endif
