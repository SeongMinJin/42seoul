/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:32:46 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 10:43:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat personA("JAE-SEOK", 1);
	Bureaucrat personB("HA-HA", 150);
	Bureaucrat personC("GIL", -20);
	Bureaucrat personD("HONG-CHUL", 152);

	std::cout << "=====================" << std::endl;

	std::cout << personA << std::endl;
	std::cout << personB << std::endl;
	std::cout << personC << std::endl;
	std::cout << personD << std::endl;

	std::cout << "=====================" << std::endl;

	personA.incrementGrade();
	std::cout << personA << std::endl;
	personA.decrementGrade();
	std::cout << personA << std::endl;
	personA.incrementGrade();
	personA.incrementGrade();
	std::cout << personA << std::endl;

	std::cout << "=====================" << std::endl;

	personB.decrementGrade();
	std::cout << personB << std::endl;
	personB.incrementGrade();
	std::cout << personB << std::endl;
	personB.decrementGrade();
	personB.decrementGrade();
	std::cout << personB << std::endl;

	std::cout << "=====================" << std::endl;
}