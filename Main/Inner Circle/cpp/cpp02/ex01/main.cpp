/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:12 by seojin            #+#    #+#             */
/*   Updated: 2022/11/07 16:48:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	std::cout << "-------------------------" << std::endl;
	Fixed const b( -4.289789f );
	std::cout << "-------------------------" << std::endl;
	Fixed const c( 42.42f );
	std::cout << "-------------------------" << std::endl;
	Fixed const d( b );
	std::cout << "-------------------------" << std::endl;
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "a is " << a.getRawBits() << " as raw Value" << std::endl;
	std::cout << "b is " << b.getRawBits() << " as raw Value" << std::endl;
	std::cout << "c is " << c.getRawBits() << " as raw Value" << std::endl;
	std::cout << "d is " << d.getRawBits() << " as raw Value" << std::endl;
	return 0;
}