/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:32:46 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:39:26 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat personA("JAE-SEOK", 1);
	Bureaucrat personB("HONG-CHUL", 50);
	Bureaucrat personC("MYEONG-SU", 150);

	Form *A = new ShrubberyCreationForm("Home");
	Form *B = new RobotomyRequestForm("SEOJIN");
	Form *C = new PresidentialPardonForm("SEOJIN");

	std::cout << "=========================" << std::endl;
	personA.signForm(*A);
	personA.executeForm(*A);
	std::cout << "=========================" << std::endl;
	personA.signForm(*B);
	personA.executeForm(*B);
	std::cout << "=========================" << std::endl;
	personC.signForm(*C);
	personB.executeForm(*C);
	personC.executeForm(*C);
	std::cout << "=========================" << std::endl;

	delete A;
	delete B;
	delete C;

	return 0;
}