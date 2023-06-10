/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:21:36 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:29 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

Base *Base::generate( void )
{
	srand(getpid());
	int randomNum = rand() % 3;
	switch (randomNum)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return NULL;
}

void Base::identify( Base *p )
{
	try
	{
		if (A *a = dynamic_cast<A *>(p))
			throw Base::_A();
		if (B *b = dynamic_cast<B *>(p))
			throw Base::_B();
		if (C *c = dynamic_cast<C *>(p))
			throw Base::_C();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Base::identify( Base &p )
{
	static int idx;

	A a;
	B b;
	C c;
	try
	{
		switch (idx)
		{
		case 0:
			a = dynamic_cast<A &>(p);
			(void) a;
			std::cout << "This is A." << std::endl;
			idx = 0;
			break;
		case 1:
			b = dynamic_cast<B &>(p);
			(void) b;
			std::cout << "This is B." << std::endl;
			idx = 0;
			break;
		case 2:
			c = dynamic_cast<C &>(p);
			(void) c;
			std::cout << "This is C." << std::endl;
			idx = 0;
			break;
		}
	}
	catch (std::exception &e)
	{
		(void) e;
		++idx;
		Base::identify(p);
	}
}


const char *Base::_A::what( void ) const throw() { return "This is A."; }
const char *Base::_B::what( void ) const throw() { return "This is B."; }
const char *Base::_C::what( void ) const throw() { return "This is C."; }
