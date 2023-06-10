/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:11:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:22 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

class Base
{
private:

public:
	virtual ~Base() {}
	static Base *generate( void );
	static void identify( Base *p );
	static void identify( Base &p );
	virtual void print(void) { std::cout << "Base" << std::endl; }

	class _A : public std::bad_cast
	{
		const char *what( void ) const throw();
	};

	class _B : public std::bad_cast
	{
		const char *what( void ) const throw();
	};

	class _C : public std::bad_cast
	{
		const char *what( void ) const throw();
	};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


#endif