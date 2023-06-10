/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:42:31 by seojin            #+#    #+#             */
/*   Updated: 2022/11/23 07:43:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <iostream>


int main()
{
	std::array<int, 13> myArr = { 2, 55, 14, 29, 9, 0, 1 ,14, 42, 32, 27, 23, 89 };
	std::vector<int> vecArr(myArr.begin(), myArr.end());

	try
	{
		std::cout << *easyfind(myArr, 99) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "No such number" << std::endl;
	}

	try
	{
		std::cout << *easyfind(vecArr, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "No such number" << std::endl;
	}
	
	
	return 0;
}