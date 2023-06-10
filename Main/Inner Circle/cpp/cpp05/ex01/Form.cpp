/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:19:50 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:01:47 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Nothing"), isSigned(false), signGrade(1), executeGrade(1) {}
Form::Form( std::string name, int signGrade, int executeGrade ) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	try
	{
		if (this->getSignGrade() < 1)
			throw Form::GradeTooHighException();
		else if (this->getSignGrade() > 150)
			throw Form::GradeTooLowException();
	}
	catch( const Form::GradeTooHighException &gh )
	{
		gh.print();
		std::cout << "No one can sign " << this->getName() << " form." << std::endl;
	}
	catch( const Form::GradeTooLowException &gl )
	{
		gl.print();
		std::cout << "Everybody can sign " << this->getName() << " form." << std::endl;
	}
	
	try
	{
		if (this->getExecuteGrade() < 1)
			throw Form::GradeTooHighException();
		else if (this->getExecuteGrade() > 150)
			throw Form::GradeTooLowException();
	}
	catch( const Form::GradeTooHighException &gh )
	{
		gh.print();
		std::cout << "No one can execute " << this->getName() << " form." << std::endl;
	}
	catch( const Form::GradeTooLowException &gl )
	{
		gl.print();
		std::cout << "Everybody can execute " << this->getName() << " form." << std::endl;
	}
}
Form::Form( const Form &f ) : name(f.getName()), isSigned(f.getIsSigned()), signGrade(f.getSignGrade()), executeGrade(f.getExecuteGrade())
{
	try
	{
		if (this->getSignGrade() < 1)
			throw Form::GradeTooHighException();
		else if (this->getSignGrade() > 150)
			throw Form::GradeTooLowException();
	}
	catch( const Form::GradeTooHighException &gh )
	{
		gh.print();
		std::cout << "No one can sign " << this->getName() << " form." << std::endl;
	}
	catch( const Form::GradeTooLowException &gl )
	{
		gl.print();
		std::cout << "Everybody can sign " << this->getName() << " form." << std::endl;
	}
	
	try
	{
		if (this->getExecuteGrade() < 1)
			throw Form::GradeTooHighException();
		else if (this->getExecuteGrade() > 150)
			throw Form::GradeTooLowException();
	}
	catch( const Form::GradeTooHighException &gh )
	{
		gh.print();
		std::cout << "No one can execute " << this->getName() << " form." << std::endl;
	}
	catch( const Form::GradeTooLowException &gl )
	{
		gl.print();
		std::cout << "Everybody can execute " << this->getName() << " form." << std::endl;
	}
}
Form::~Form() {}

Form &Form::operator=( const Form &f )
{
	if (this != &f)
		this->isSigned = f.getIsSigned();
	return *this;
}




/* Member functions */
const std::string Form::getName( void ) const { return this->name; }
bool Form::getIsSigned( void ) const { return this->isSigned; }
int Form::getSignGrade( void ) const { return this->signGrade; }
int Form::getExecuteGrade( void ) const { return this->executeGrade; }
void Form::beSigned( const Bureaucrat &b )
{
	try
	{
		if (b.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		this->isSigned = true;
	}
	catch( Form::GradeTooLowException &gl )
	{
		gl.print();
	}
	
}


/* Exception class functions */

void Form::GradeTooHighException::print( void ) const
{
	std::cout << "Grade is too high" << std::endl;
}

void Form::GradeTooLowException::print( void ) const
{
	std::cout << "Grade is too low" << std::endl;
}













std::ostream &operator<<( std::ostream &out, const Form &f )
{
	out << "Form name    : " << f.getName() << std::endl;
	out << "Is signed    : " << (f.getIsSigned() ? "YES" : "NO") << std::endl;
	out << "SignQualGrade: " << f.getSignGrade() << std::endl;
	out << "ExecQualGrade: " << f.getExecuteGrade() << std::endl;
	return out;
}
