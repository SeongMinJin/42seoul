/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:37 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:37:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form( "RobotomyRequestForm", "No_Target", 72, 45 ) {}
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form( "RobotomyRequestForm", target, 72, 45 ) {}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &rrf ) : Form( rrf.getName(), rrf.getTarget(), rrf.getSignGrade(), rrf.getExecuteGrade() ) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &rrf )
{
	if (this != &rrf )
		this->setIsSigned(rrf.getIsSigned());
	return *this;
}

void RobotomyRequestForm::executeForm( void ) const
{
	int seed = 0;
	int randomNum;

	srand(reinterpret_cast<unsigned long>(&seed));
	randomNum = rand() % 10;
	std::cout << "mmmmm, nhhmm.........." << std::endl;
	if (randomNum > 4)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << this->getTarget() << " failed to be robot..." << std::endl;
}
