/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:32:46 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:41:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat personA("JAE-SEOK", 1);
	Bureaucrat personB("HONG-CHUL", 50);
	Bureaucrat personC("MYEONG-SU", 150);
	Intern GIL;

	Form *A = GIL.makeForm("shrubbery creation", "my home");
	Form *B = GIL.makeForm("robotomy request", "HA-HA");
	Form *C = GIL.makeForm("presidential pardon", "JOON HA");
	Form *D = GIL.makeForm("SOME FORM", "SOME ONE");
	if (!D)
		std::cout << "If such file form is not exist, this sentence will be showed." << std::endl;

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