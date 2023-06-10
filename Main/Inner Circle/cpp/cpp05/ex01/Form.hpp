/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:20:09 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 10:48:16 by seojin           ###   ########.fr       */
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
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:

	const std::string getName( void ) const;
	bool getIsSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecuteGrade( void ) const;
	void beSigned( const Bureaucrat &b );


	Form();
	Form( std::string name, int signGrade, int executeGrade);
	Form( const Form &f );
	~Form();

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


};

std::ostream &operator<<( std::ostream &out, const Form &f );

#endif
