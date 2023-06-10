/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:55:03 by seojin            #+#    #+#             */
/*   Updated: 2022/11/24 06:53:31 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Span.hpp"

#include "Span.hpp"

int main()
{
	/* Subject test */
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "=========================" << std::endl;


	/* My test */
	Span mySp = Span(10000);
	mySp.randomFill();
	std::cout << mySp.shortestSpan() << std::endl;
	std::cout << mySp.longestSpan() << std::endl;
	std::cout << "=========================" << std::endl;


	Span mySp2 = Span(5000);
	mySp2.fillNumber(mySp.begin(), mySp.end());
	try
	{
		std::cout << mySp2.shortestSpan() << std::endl;
		std::cout << mySp2.longestSpan() << std::endl;
	}
	catch( const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "=========================" << std::endl;


	Span mySp3(15000);
	mySp3.fillNumber(mySp.begin(), mySp.end());
	std::cout << mySp3.shortestSpan() << std::endl;
	std::cout << mySp3.longestSpan() << std::endl;
	std::cout << "=========================" << std::endl;


	// Span mySp4(mySp3);
	// std::cout << mySp4.shortestSpan() << std::endl;
	// std::cout << mySp4.longestSpan() << std::endl;
	// std::cout << "=========================" << std::endl;


	// Span mySp5, mySp6;
	// mySp5 = mySp6;
	// mySp5 = mySp3;
	// std::cout << "=========================" << std::endl;


	// Span mySp7(10000);
	// mySp7 = mySp3;
	// std::cout << mySp7.shortestSpan() << std::endl;
	// std::cout << mySp7.longestSpan() << std::endl;
	// std::cout << "=========================" << std::endl;


	return 0;
}