/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:19:50 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:27:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Nothing"), target("No_Target"), isSigned(false), signGrade(1), executeGrade(1) {}
Form::Form( std::string name, std::string target, int signGrade, int executeGrade ) : name(name), target(target), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
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

Form::Form( const Form &f ) : name(f.getName()), target(f.getTarget()), isSigned(f.getIsSigned()), signGrade(f.getSignGrade()), executeGrade(f.getExecuteGrade())
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
const std::string Form::getTarget( void ) const { return this->target; }
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
bool Form::execute( const Bureaucrat &b ) const
{
	try
	{
		if (this->getIsSigned() == false)
			throw Form::NotSigned();
		if (b.getGrade() > this->getExecuteGrade())
			throw Form::GradeTooLowException();
		this->executeForm();
		return true;
	}
	catch ( const Form::NotSigned &ns )
	{
		ns.print();
		return false;
	}
	catch( const Form::GradeTooLowException &gl )
	{
		gl.print();
		return false;
	}
}


void Form::setIsSigned( bool val ) { this->isSigned = val; }










/* Exception class functions */

void Form::GradeTooHighException::print( void ) const
{
	std::cout << "Grade is too high" << std::endl;
}

void Form::GradeTooLowException::print( void ) const
{
	std::cout << "Grade is too low" << std::endl;
}

void Form::NotSigned::print( void ) const
{
	std::cout << "Form is not signed yet..." << std::endl;
}









std::ostream &operator<<( std::ostream &out, const Form &f )
{
	out << "Form name    : " << f.getName() << std::endl;
	out << "Is signed    : " << (f.getIsSigned() ? "YES" : "NO") << std::endl;
	out << "SignQualGrade: " << f.getSignGrade() << std::endl;
	out << "ExecQualGrade: " << f.getExecuteGrade() << std::endl;
	return out;
}
