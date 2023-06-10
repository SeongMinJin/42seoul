/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:42:26 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 10:57:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Constructors & Destructor */
Bureaucrat::Bureaucrat() : name("Nobody"), grade(150) {}
Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade = grade;
	}
	catch(Bureaucrat::GradeTooHighException &gh)
	{
		gh.print();
		this->grade = 1;
	}
	catch(Bureaucrat::GradeTooLowException &gl)
	{
		gl.print();
		this->grade = 150;
	}
}
Bureaucrat::Bureaucrat( const Bureaucrat &b ) : name(b.getName()), grade(b.getGrade()) {}
Bureaucrat::~Bureaucrat() {}

/* Operator overload */
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &b )
{
	if (this != &b)
		this->grade = b.getGrade();
	return *this;
}

/* Member functions */
const std::string Bureaucrat::getName( void ) const { return this->name; }
int Bureaucrat::getGrade( void ) const { return this->grade; }
void Bureaucrat::decrementGrade( void )
{
	try
	{
		if (this->getGrade() == 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
	}
	catch( const Bureaucrat::GradeTooLowException &gl )
	{
		gl.print();
	}
	
}
void Bureaucrat::incrementGrade( void )
{
	try
	{
		if (this->getGrade() == 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade--;
	}
	catch( const Bureaucrat::GradeTooHighException &gh )
	{
		gh.print();
	}
}
void Bureaucrat::signForm( Form &f )
{
	try
	{
		if (this->getGrade() > f.getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << "." << std::endl;
	}
	catch( const Bureaucrat::GradeTooLowException & gl )
	{
		gl.print();
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << this->getName() << "'s grade is lower than form's sign qualification grade." << std::endl;
	}
}

/* Functions for Exception class */
void Bureaucrat::GradeTooHighException::print( void ) const
{
	std::cout << "Grade is Too High" << std::endl;
}
void Bureaucrat::GradeTooLowException::print( void ) const
{
	std::cout << "Grade is Too Low" << std::endl;
}


std::ostream &operator<<( std::ostream &out, const Bureaucrat &b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
