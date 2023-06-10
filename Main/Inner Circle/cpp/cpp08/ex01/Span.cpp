/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:20:34 by seojin            #+#    #+#             */
/*   Updated: 2022/12/16 17:16:57 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() { std::cout << "Default constructor is called." << std::endl; }
Span::Span( unsigned int N )
{
	std::cout << "Unsigned int constructor is called." << std::endl;
	arr.reserve(N);
}
Span::Span( const Span &s )
{
	std::cout << "Copy constructor is called." << std::endl;
	if (s.arr.capacity())
	{
		arr.reserve(s.arr.capacity());
		for (std::vector<int>::const_iterator it = s.arr.begin(); it != s.arr.end(); ++it)
			arr.push_back(*it);
	}
}
Span::~Span() { std::cout << "Deestructor is called." << std::endl; }

Span &Span::operator=( const Span &s )
{
	std::cout << "Copy assignedment is called." << std::endl;
	if (this == &s)
		return *this;
	if (arr.capacity() < s.arr.capacity())
	{
		std::cout << "Not enough capacity." << std::endl;
		return *this;
	}
	arr.clear();
	for (std::vector<int>::const_iterator it = s.arr.begin(); it != s.arr.end(); ++it)
		arr.push_back(*it);
	return *this;
}


std::vector<int>::const_iterator Span::begin( void ) const { return arr.begin(); }
std::vector<int>::const_iterator Span::end( void ) const { return arr.end(); }

void Span::addNumber( int num )
{
	try
	{
		if (arr.size() == arr.capacity())
			throw Span::NoSpace();
		arr.push_back(num);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


void Span::fillNumber( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end )
{
	try
	{
		if (static_cast<size_t>(end - start) > arr.capacity())
			throw Span::NoSpace();
		arr.clear();
		while (start != end)
		{
			arr.push_back(*start);
			++start;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Span::randomFill( void )
{
	int seed = 0;
	srand(reinterpret_cast<size_t>(&seed));
	arr.clear();
	for (size_t i = 0; i < arr.capacity(); ++i)
		arr.push_back(rand());
}

int Span::shortestSpan( void ) const
{
	int diff = INT_MAX;
	int tmpDiff;

	if (arr.size() < 2)
		throw Span::ShortLen();


	std::vector<int> tmp(arr.begin(), arr.end());

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end() - 1; ++it)
	{
		tmpDiff = *(it + 1) - *it;
		if (tmpDiff == 0)
			return 0;
		if (tmpDiff < diff)
			diff = tmpDiff;
	}
	return diff;
}

int Span::longestSpan( void ) const
{
	if (arr.size() < 2)
		throw Span::ShortLen();
	int min, max;
	min = *std::min_element(arr.begin(), arr.end());
	max = *std::max_element(arr.begin(), arr.end());
	return max - min;
}


const char* Span::NoSpace::what( void ) const throw()
{
	return "Not enough space.";
}

const char* Span::ShortLen::what( void ) const throw()
{
	return "Too short.";
}
