/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 07:35:25 by seojin            #+#    #+#             */
/*   Updated: 2022/11/22 12:40:01 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


#include <cstddef>
#include <iostream>


// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

template <typename T>
void myPrint(const T& t) { std::cout << t << std::endl; }

template <typename T>
void quadra(T &t) { t += 4; }

template <typename T>
void iter(const T *start, size_t len, void(*fun)(const T& t))
{
	for(size_t i = 0; i < len; i++)
		fun(start[i]);
}

template <typename T>
void iter(T *start, size_t len, void(*fun)(T& t))
{
	for(size_t i = 0; i < len; i++)
		fun(start[i]);
}



// class Awesome
// {
// private:
// 	int _n;

// public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }




#endif