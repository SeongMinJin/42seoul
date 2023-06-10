/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:12 by seojin            #+#    #+#             */
/*   Updated: 2022/11/14 16:11:51 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	std::cout << "===================" << std::endl;
	Fixed b( a );
	std::cout << "===================" << std::endl;
	Fixed c = b;
	std::cout << "===================" << std::endl;
	Fixed d;
	std::cout << "===================" << std::endl;

	a.setRawBits(40);
	b.setRawBits(100);
	std::cout << "===================" << std::endl;
	std::cout << "===================" << std::endl;
	d.operator=(a);
	std::cout << "===================" << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	std::cout << "===================" << std::endl;

	return (0);
}