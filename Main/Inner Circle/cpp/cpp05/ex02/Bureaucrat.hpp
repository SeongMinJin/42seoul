/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:14:36 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:33:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{

private:
	const std::string name;
	int grade;


public:

	const std::string getName( void ) const;
	int getGrade( void ) const;
	void decrementGrade( void );
	void incrementGrade( void );
	void signForm( Form &f ) const;
	void executeForm( Form const &f ) const;
	

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

	class PermisionDenyed
	{
		public:
		void print( void ) const;
	};


	Bureaucrat();
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &b );
	~Bureaucrat();
	Bureaucrat &operator=( const Bureaucrat &b );
};

std::ostream &operator<<( std::ostream &out, const Bureaucrat &b );

#endif