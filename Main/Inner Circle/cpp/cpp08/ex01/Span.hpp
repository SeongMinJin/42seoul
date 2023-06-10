/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:55:14 by seojin            #+#    #+#             */
/*   Updated: 2022/11/24 06:57:33 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{

private:
	std::vector<int> arr;

public:
	std::vector<int>::const_iterator begin( void ) const;
	std::vector<int>::const_iterator end( void ) const;

	void addNumber( int num );
	void fillNumber( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end );
	void randomFill( void );

	int shortestSpan( void ) const;
	int longestSpan( void ) const;

	Span();
	Span( unsigned int );
	Span( const Span &s );
	~Span();

	Span &operator=( const Span &s );


	class NoSpace : public std::exception
	{
		virtual const char *what( void ) const throw();
	};
	class ShortLen : public std::exception
	{
		virtual const char *what( void ) const throw();
	};
};


#endif
