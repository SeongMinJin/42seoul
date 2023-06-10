/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:12 by seojin            #+#    #+#             */
/*   Updated: 2022/12/09 17:26:35 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{

	Point A(2, 2);
	Point B(0, -4);
	Point C(-3, 0);
	Point P(1, 3);

	Point::bsp(A, B, C, P) ? std::cout << "inside" : std::cout << "outside";
	std::cout << std::endl;

	Point P2;
	Point::bsp(A, B, C, P2) ? std::cout << "inside" : std::cout << "outside";
	std::cout << std::endl;

	Point P3(-1.5f, 0);
	Point::bsp(A, B, C, P3) ? std::cout << "inside" : std::cout << "outside";
	std::cout << std::endl;

	Point P4(2, 2);
	Point::bsp(A, B, C, P4) ? std::cout << "inside" : std::cout << "outside";
	std::cout << std::endl;


	return 0;
}