/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:48:57 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:42:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* Constructors & Destructor */
Intern::Intern()
{
	formList[0] = "shrubbery creation";
	formList[1] = "robotomy request";
	formList[2] = "presidential pardon";
}
Intern::Intern( const Intern &i )
{
	formList[0] = i.formList[0];
	formList[1] = i.formList[1];
	formList[2] = i.formList[2];
}
Intern::~Intern() {}
Intern &Intern::operator=( const Intern &i )
{ 
	if (this != &i)
	{
		formList[0] = i.formList[0];
		formList[1] = i.formList[1];
		formList[2] = i.formList[2];
	}
	return *this;
}





Form *Intern::makeForm( std::string name, std::string target ) const
{
	int idx = 0;
	Form *newForm;

	while (formList[idx].compare(name) && idx < 3)
		idx++;

	switch (idx)
	{
	case 0:
		newForm = new ShrubberyCreationForm(target);
		return newForm;
	case 1:
		newForm = new RobotomyRequestForm(target);
		return newForm;
	case 2:
		newForm = new PresidentialPardonForm(target);
		return newForm;
	default:
		std::cout << name << " : No such form." << std::endl;
		return NULL;
	}
}