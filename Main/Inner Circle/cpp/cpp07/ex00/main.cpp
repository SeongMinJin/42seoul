/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 07:11:25 by seojin            #+#    #+#             */
/*   Updated: 2022/11/22 10:23:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{

	/* Subject's sample */
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "==================================" << std::endl;






	/* My sample */
	char cA, cB;

	cA = 'r';
	cB = 'X';
	::swap(cA, cB);
	std::cout << "A  :" << cA << std::endl;
	std::cout << "B  :" << cB << std::endl;
	std::cout << "min:" << min(cA, cB) << std::endl;
	std::cout << "max:" << max(cA, cB) << std::endl;
	std::cout << "==================================" << std::endl;


	int iA, iB;

	iA = 42759;
	iB = 424242;
	::swap(iA, iB);
	std::cout << "A  :" << iA << std::endl;
	std::cout << "B  :" << iB << std::endl;
	std::cout << "min:" << min(iA, iB) << std::endl;
	std::cout << "max:" << max(iA, iB) << std::endl;
	std::cout << "==================================" << std::endl;


	double dA, dB;

	dA = 3.141592;
	dB = 42.4242;
	::swap(iA, iB);
	std::cout << "A  :" << iA << std::endl;
	std::cout << "B  :" << iB << std::endl;
	std::cout << "min:" << min(iA, iB) << std::endl;
	std::cout << "max:" << max(iA, iB) << std::endl;
	std::cout << "==================================" << std::endl;

	return 0;
}