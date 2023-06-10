/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:20:09 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:28:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{

private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
	virtual void executeForm( void ) const = 0;

public:

	const std::string getName( void ) const;
	const std::string getTarget( void ) const;
	bool getIsSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecuteGrade( void ) const;
	void setIsSigned( bool val );
	void beSigned( const Bureaucrat &b );
	bool execute( const Bureaucrat &b ) const;


	Form();
	Form( std::string name, std::string target, int signGrade, int executeGrade );
	Form( const Form &f );
	virtual ~Form();

	Form &operator=( const Form &f );

	class GradeTooHighException
	{
		public:
		void print( void ) const;
	};

	class GradeTooLowException
	{
		public:
		void print( void ) const;
	};

	class NotSigned
	{
		public:
		void print( void ) const;
	};

};

std::ostream &operator<<( std::ostream &out, const Form &f );

#endif
