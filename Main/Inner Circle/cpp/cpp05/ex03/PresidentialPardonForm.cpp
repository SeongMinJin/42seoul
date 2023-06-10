/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:37 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:36:56 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form( "PresidentialPardonForm", "No_Target", 25, 55) {}
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form( "PresidentialPardonForm", target, 25, 55) {}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &ppf ) : Form( ppf.getName(), ppf.getTarget(), ppf.getSignGrade(), ppf.getExecuteGrade() ) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &ppf )
{
	if (this != &ppf)
		this->setIsSigned(ppf.getIsSigned());
	return *this;
}

void PresidentialPardonForm::executeForm( void ) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
