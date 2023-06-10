/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:01:28 by seojin            #+#    #+#             */
/*   Updated: 2022/11/23 20:09:49 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>


template <typename T>
class MutantStack : public std::stack<T>
{

public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() : std::stack<T>() { std::cout << "Default constructor is called." << std::endl; }
	MutantStack( const MutantStack &m ) : std::stack<T>(m) { std::cout << "Copy constructor is called." << std::endl; }
	~MutantStack() { std::cout << "Destructor is called." << std::endl; }
	MutantStack &operator=( const MutantStack &m )
	{
		std::cout << "Copy assignment is called." << std::endl;
		if (this == &m)
			return *this;
		this = *m;
		return *this;
	}

	const iterator begin( void ) const { return this->c.begin(); }
	iterator begin( void ) { return this->c.begin(); }
	const iterator end( void ) const { return this->c.end(); }
	iterator end( void ) { return this->c.end(); }
	const iterator rbegin( void ) const { return this->c.rbegin(); }
	iterator rbegin( void ) { return this->c.rbegin(); }
	const iterator rend( void ) const { return this->c.rend(); }
	iterator rend( void ) { return this->c.rend(); }

private:
	
};


#endif