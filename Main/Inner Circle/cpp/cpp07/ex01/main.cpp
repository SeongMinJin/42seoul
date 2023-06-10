/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 07:35:41 by seojin            #+#    #+#             */
/*   Updated: 2022/11/22 12:33:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


int main()
{
	int arr[10];
	for(int i = 0 ; i < 10; i++)
		arr[i] = i + 4;
	::iter(arr, sizeof(arr) / sizeof(int), ::quadra);
	::iter(arr, sizeof(arr) / sizeof(int), ::myPrint);
	std::cout << "=================" << std::endl;

	char str[6] = "HELLO";
	::iter(str, sizeof(str) / sizeof(char), ::myPrint);
	std::cout << "=================" << std::endl;


	std::string name = "seojin";
	::iter(&name[0], name.length(), ::myPrint);
	std::cout << "=================" << std::endl;

	// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	// Awesome tab2[5];

	// ::iter( tab, 5, print<int> );
	// ::iter( tab2, 5, print<Awesome> );


	return 0;
}
