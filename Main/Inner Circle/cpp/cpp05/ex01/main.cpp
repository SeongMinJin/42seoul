/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:32:46 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 16:55:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat personA("JAE-SEOK", 1);
	Bureaucrat personB("HONG-CHUL", 50);

	Form A("GO HOME", 10, 10);
	Form B("BUY STUFF", 50, 50);
	Form C("CLASSIFIED", 1, 1);
	Form D("DUMMY", 0, 0);
	std::cout << "=====================" << std::endl;

	personA.signForm(A);
	personA.signForm(B);
	personA.signForm(C);

	std::cout << "=====================" << std::endl;
	personB.signForm(A);
	personB.signForm(B);
	personB.signForm(C);

	std::cout << "=====================" << std::endl;
}