/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:33:15 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>

#define IMPOSSIBLE "Imposible"
#define NONDISPLAYABLE "Non displayable"

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;

	char c;
	int intNum;
	float floatNum;
	double doubleNum;

	std::cout.flags(std::ios::showpoint);
	std::cout.precision(20);
	if (strlen(av[1]) == 1 && !isdigit(av[1][0]))
	{
		c = av[1][0];
		intNum = static_cast<int>(c);
		floatNum = static_cast<float>(c);
		doubleNum = static_cast<double>(c);
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: " << NONDISPLAYABLE << std::endl;
		std::cout << "int: " << intNum << std::endl;
		std::cout << "float: " << floatNum << "f" << std::endl;
		std::cout << "double: " << doubleNum << std::endl;
	}
	else
	{
		doubleNum = strtod(av[1], NULL);
		floatNum = static_cast<float>(doubleNum);
		if (isnan(doubleNum) || isinf(doubleNum))
		{
			std::cout << "char: " << IMPOSSIBLE << std::endl;
			std::cout << "int: " << IMPOSSIBLE << std::endl;
			std::cout << "float: " << floatNum << "f" << std::endl;
			std::cout << "double: " << doubleNum << std::endl;
		}
		else
		{
			c = static_cast<char>(doubleNum);
			intNum = static_cast<int>(doubleNum);
			if (isprint(c))
				std::cout << "char: " << c << std::endl;
			else
				std::cout << "char: " << NONDISPLAYABLE << std::endl;
			std::cout << "int: " << intNum << std::endl;
			std::cout << "float: " << floatNum << "f" << std::endl;
			std::cout << "double: " << doubleNum << std::endl;
		}
	}
	return 0;
}
